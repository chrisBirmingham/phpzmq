/*
+-----------------------------------------------------------------------------------+
|  ZMQ extension for PHP                                                            |
|  Copyright (c) 2010-2013, Mikko Koppanen <mkoppanen@php.net>                      |
|  All rights reserved.                                                             |
+-----------------------------------------------------------------------------------+
|  Redistribution and use in source and binary forms, with or without               |
|  modification, are permitted provided that the following conditions are met:      |
|     * Redistributions of source code must retain the above copyright              |
|       notice, this list of conditions and the following disclaimer.               |
|     * Redistributions in binary form must reproduce the above copyright           |
|       notice, this list of conditions and the following disclaimer in the         |
|       documentation and/or other materials provided with the distribution.        |
|     * Neither the name of the copyright holder nor the                            |
|       names of its contributors may be used to endorse or promote products        |
|       derived from this software without specific prior written permission.       |
+-----------------------------------------------------------------------------------+
|  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  |
|  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED    |
|  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           |
|  DISCLAIMED. IN NO EVENT SHALL MIKKO KOPPANEN BE LIABLE FOR ANY                   |
|  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES       |
|  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;     |
|  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND      |
|  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       |
|  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS    |
|  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                     |
+-----------------------------------------------------------------------------------+
*/

#include "php_zmq.h"
#include "php_zmq_private.h"
#include "php_zmq_pollset.h"
#include "zend.h"
#include "zend_API.h"
#include "zend_attributes.h"
#include "zmq_arginfo.h"

ZEND_DECLARE_MODULE_GLOBALS(php_zmq);

static zend_class_entry *php_zmq_sc_entry;
static zend_class_entry *php_zmq_context_sc_entry;
static zend_class_entry *php_zmq_socket_sc_entry;
static zend_class_entry *php_zmq_poll_sc_entry;
static zend_class_entry *php_zmq_device_sc_entry;

static zend_class_entry *php_zmq_exception_sc_entry;
static zend_class_entry *php_zmq_context_exception_sc_entry;
static zend_class_entry *php_zmq_socket_exception_sc_entry;
static zend_class_entry *php_zmq_poll_exception_sc_entry;
static zend_class_entry *php_zmq_device_exception_sc_entry;

static zend_object_handlers zmq_object_handlers;
static zend_object_handlers zmq_socket_object_handlers;
static zend_object_handlers zmq_context_object_handlers;
static zend_object_handlers zmq_poll_object_handlers;
static zend_object_handlers zmq_device_object_handlers;

zend_class_entry *php_zmq_context_exception_sc_entry_get ()
{
	return php_zmq_context_exception_sc_entry;
}

zend_class_entry *php_zmq_socket_exception_sc_entry_get (void)
{
	return php_zmq_socket_exception_sc_entry;
}

zend_class_entry *php_zmq_device_exception_sc_entry_get (void)
{
	return php_zmq_device_exception_sc_entry;
}

static zend_long php_zmq_context_socket_count_get(php_zmq_context *context)
{
	return (context->use_shared_ctx)
		? php_zmq_shared_ctx_socket_count()
		: context->socket_count;
}

static void php_zmq_context_socket_count_incr(php_zmq_context *context)
{
	if (context->use_shared_ctx) {
		php_zmq_shared_ctx_socket_count_incr();
	} else {
		context->socket_count++;
	}
}

static void php_zmq_context_socket_count_decr(php_zmq_context *context)
{
	if (context->use_shared_ctx) {
		php_zmq_shared_ctx_socket_count_decr();
	} else {
		context->socket_count--;
	}
}

/* list entries */
static int le_zmq_socket, le_zmq_context;

/** {{{ static int php_zmq_socket_list_entry(void)
*/
static inline int php_zmq_socket_list_entry(void)
{
	return le_zmq_socket;
}
/* }}} */

/* {{{ static int php_zmq_context_list_entry(void)
*/
static inline int php_zmq_context_list_entry(void)
{
	return le_zmq_context;
}
/* }}} */

/* {{{ static void php_zmq_context_destroy(php_zmq_context *context)
	Destroy the context
*/
static void php_zmq_context_destroy(php_zmq_context *context)
{
	if (context->pid == getpid()) {
		(void) zmq_term(context->z_ctx);
	}
	pefree(context, context->is_persistent);
}
/* }}} */

/* {{{ static void php_zmq_socket_destroy(php_zmq_socket *zmq_sock)
	Destroy the socket (note: does not touch context)
*/
static void php_zmq_socket_destroy(php_zmq_socket *zmq_sock)
{
	zend_hash_destroy(&(zmq_sock->connect));
	zend_hash_destroy(&(zmq_sock->bind));

	/* Decrement socket count */
	php_zmq_context_socket_count_decr(zmq_sock->ctx);

	if (zmq_sock->pid == getpid ()) {
		(void)zmq_close(zmq_sock->z_socket);
	}
	pefree(zmq_sock, zmq_sock->is_persistent);
}
/* }}} */

/* --- START ZMQContext --- */

/* {{{ static php_zmq_context *php_zmq_context_new(zend_long io_threads, zend_bool is_persistent, zend_bool use_shared_ctx)
	Create a new zmq context
*/
static php_zmq_context *php_zmq_context_new(zend_long io_threads, bool is_persistent, bool use_shared_ctx)
{
	php_zmq_context *context = pecalloc(1, sizeof(php_zmq_context), is_persistent);

	if (use_shared_ctx) {
		php_zmq_shared_ctx_assign_to(context);
	} else {
		context->z_ctx = zmq_init(io_threads);
	}

	if (!context->z_ctx) {
		pefree(context, is_persistent);
		return NULL;
	}

	context->io_threads = io_threads;
	context->is_persistent  = is_persistent;
	context->pid = getpid();
	context->socket_count = 0;
	context->use_shared_ctx = use_shared_ctx;
	return context;
}
/* }}} */

/* {{{ static php_zmq_context *php_zmq_context_get(zend_long io_threads, zend_bool is_persistent)
*/
static php_zmq_context *php_zmq_context_get(zend_long io_threads, bool is_persistent)
{
	php_zmq_context *context;
	zend_string *plist_key = NULL;

	if (is_persistent) {
		zend_resource *le_p = NULL;
		plist_key = strpprintf(0, "zmq_context=[%ld]", (long)io_threads);

		if ((le_p = zend_hash_find_ptr(&EG(persistent_list), plist_key)) != NULL) {
			if (le_p->type == php_zmq_context_list_entry()) {

				if (plist_key) {
					zend_string_release(plist_key);
				}
				return (php_zmq_context *) le_p->ptr;
			}
		}
	}

	context = php_zmq_context_new(io_threads, is_persistent, 0);

	if (!context) {
		if (plist_key) {
			zend_string_release(plist_key);
		}
		return NULL;
	}

	if (is_persistent) {

		zend_resource le;
		le.type = php_zmq_context_list_entry();
		le.ptr  = context;

		GC_SET_REFCOUNT(&le, 1);

		/* plist_key is not a persistent allocated key, thus we use str_update here */
		if (zend_hash_str_update_mem(&EG(persistent_list), plist_key->val, plist_key->len, &le, sizeof(le)) == NULL) {
			if (plist_key) {
				zend_string_release(plist_key);
			}
			php_error_docref(NULL, E_ERROR, "Could not register persistent entry for the context");
			/* not reached */
		}
	}
	if (plist_key) {
		zend_string_release(plist_key);
	}
	return context;
}
/* }}} */

/* {{{ proto ZMQ ZMQ::__construct()
	Private constructor
*/
PHP_METHOD(ZMQ, __construct) {}
/* }}} */

/* {{{ proto integer ZMQ::clock()
	A monotonic clock
*/
PHP_METHOD(ZMQ, clock)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((long)php_zmq_clock(ZMQ_G(clock_ctx)));
}
/* }}} */

#ifdef PHP_ZMQ_HAVE_Z85

/* {{{ proto string ZMQ::z85Encode(string $data)
	
*/
PHP_METHOD(ZMQ, z85encode)
{
	char *data = NULL;
	size_t data_len = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(data, data_len)
	ZEND_PARSE_PARAMETERS_END();

	if (data_len == 0) {
		RETURN_NULL();
	}

	size_t buffer_size = 5 * data_len / 4 + 1;
	char *buffer = emalloc(buffer_size);

	if (!zmq_z85_encode(buffer, (const uint8_t *)data, data_len)) {
		efree(buffer);
		RETURN_NULL();
	}

	RETVAL_STRINGL(buffer, buffer_size - 1);
	efree(buffer);
}
/* }}} */

/* {{{ proto string ZMQ::z85Decode(string $z85_encoded_data)
	
*/
PHP_METHOD(ZMQ, z85decode)
{
	char *data = NULL;
	size_t data_len = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(data, data_len)
	ZEND_PARSE_PARAMETERS_END();

	if (data_len == 0) {
		RETURN_NULL();
	}

	size_t buffer_size = 4 * data_len / 5;
	char *buffer = emalloc(buffer_size);

	if (!zmq_z85_decode((uint8_t *)buffer, data)) {
		efree(buffer);
		RETURN_NULL();
	}

	RETVAL_STRINGL(buffer, buffer_size);
	efree(buffer);
}
/* }}} */
#endif

#ifdef PHP_ZMQ_HAVE_CURVE_KEYPAIR

#define PHP_ZMQ_KEY_SIZE 41

/* {{{ proto array ZMQ::curveKeypair()
	
*/
PHP_METHOD(ZMQ, curvekeypair)
{
	char public_key[PHP_ZMQ_KEY_SIZE], secret_key[PHP_ZMQ_KEY_SIZE];

	ZEND_PARSE_PARAMETERS_NONE();

	array_init(return_value);
	if (zmq_curve_keypair(public_key, secret_key) == 0) {
		add_assoc_stringl(return_value, "public_key", public_key, PHP_ZMQ_KEY_SIZE - 1);
		add_assoc_stringl(return_value, "secret_key", secret_key, PHP_ZMQ_KEY_SIZE - 1);
	}
}
/* }}} */

#endif


/* {{{ proto ZMQContext ZMQContext::__construct(integer $io_threads[, boolean $is_persistent = true])
	Build a new ZMQContext object
*/
PHP_METHOD(ZMQContext, __construct)
{
	php_zmq_context_object *intern;
	zend_long io_threads = 1;
	bool is_persistent = 1;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(io_threads)
		Z_PARAM_BOOL(is_persistent)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_CONTEXT_OBJECT(ZEND_THIS);
	intern->context = php_zmq_context_get(io_threads, is_persistent);

	if (!intern->context) {
		zend_throw_exception_ex(php_zmq_context_exception_sc_entry, errno, "Error creating context: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}
}
/* }}} */

/* {{{ proto ZMQContext ZMQContext::acquire()
	Acquires a handle to the process global context
*/
PHP_METHOD(ZMQContext, acquire)
{
	php_zmq_context *context;
	php_zmq_context_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	context = php_zmq_context_new(1, true, true);

	// Create a global context
	object_init_ex(return_value, php_zmq_context_sc_entry);
	intern = php_zmq_context_fetch_object(Z_OBJ_P(return_value));
	intern->context = context;
}
/* }}} */

/* {{{ proto integer ZMQContext::getSocketCount()
	Number of active sockets in this context
*/
PHP_METHOD(ZMQContext, getSocketCount)
{
	php_zmq_context_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_CONTEXT_OBJECT(ZEND_THIS);
	RETURN_LONG(php_zmq_context_socket_count_get(intern->context));
}
/* }}} */

#ifdef PHP_ZMQ_HAVE_CTX_OPTIONS
/* {{{ proto ZMQContext ZMQContext::setOpt(int option, int value)
	Set a context option
*/
PHP_METHOD(ZMQContext, setOpt)
{
	php_zmq_context_object *intern;
	zend_long option, value;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(option)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_CONTEXT_OBJECT(ZEND_THIS);

	switch (option) {
#if ZMQ_VERSION_MAJOR >= 4
		case ZMQ_BLOCKY:
		case ZMQ_THREAD_SCHED_POLICY:
		case ZMQ_THREAD_PRIORITY:
		case ZMQ_THREAD_AFFINITY_CPU_ADD:
		case ZMQ_THREAD_AFFINITY_CPU_REMOVE:
		case ZMQ_THREAD_NAME_PREFIX:
		case ZMQ_MAX_MSGSZ:
#ifdef ZMQ_ZERO_COPY_RECV
		case ZMQ_ZERO_COPY_RECV:
#endif
		case ZMQ_IPV6:
#endif
		case ZMQ_IO_THREADS:
		case ZMQ_MAX_SOCKETS:
			if (zmq_ctx_set(intern->context->z_ctx, option, value) != 0) {
				zend_throw_exception_ex(php_zmq_context_exception_sc_entry_get(), errno, "Failed to set the context option value: %s", zmq_strerror(errno));
				RETURN_THROWS();
			}
			break;
		default:
			zend_throw_exception(php_zmq_context_exception_sc_entry_get(), "Unknown option key", PHP_ZMQ_INTERNAL_ERROR);
			RETURN_THROWS();
	}
}
/* }}} */

/* {{{ proto ZMQContext ZMQContext::getOpt(int option)
	Set a context option
*/
PHP_METHOD(ZMQContext, getOpt)
{
	php_zmq_context_object *intern;
	zend_long option;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(option)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_CONTEXT_OBJECT(ZEND_THIS);

	switch (option) {
#if ZMQ_VERSION_MAJOR >= 4
		case ZMQ_BLOCKY:
		case ZMQ_THREAD_SCHED_POLICY:
		case ZMQ_THREAD_PRIORITY:
		case ZMQ_THREAD_AFFINITY_CPU_ADD:
		case ZMQ_THREAD_AFFINITY_CPU_REMOVE:
		case ZMQ_THREAD_NAME_PREFIX:
		case ZMQ_MAX_MSGSZ:
#ifdef ZMQ_ZERO_COPY_RECV
		case ZMQ_ZERO_COPY_RECV:
#endif
		case ZMQ_IPV6:
#endif
		case ZMQ_IO_THREADS:
		case ZMQ_MAX_SOCKETS:
			{
				int value = zmq_ctx_get(intern->context->z_ctx, option);
				if (value < 0) {
					zend_throw_exception_ex(php_zmq_context_exception_sc_entry_get(), errno, "Failed to get the context option value: %s", zmq_strerror(errno));
					RETURN_THROWS();
				}
				RETURN_LONG(value);
			}
			break;
		default:
			zend_throw_exception(php_zmq_context_exception_sc_entry_get(), "Unknown option key", PHP_ZMQ_INTERNAL_ERROR);
			RETURN_THROWS();
	}
}
/* }}} */
#endif


/* {{{ static php_zmq_socket *php_zmq_socket_new(php_zmq_context *context, int type, zend_bool is_persistent)
	Create a new zmq socket
*/
static php_zmq_socket *php_zmq_socket_new(php_zmq_context *context, zend_long type, bool is_persistent)
{
	php_zmq_socket *zmq_sock;

	zmq_sock = pecalloc(1, sizeof(php_zmq_socket), is_persistent);
	zmq_sock->z_socket = zmq_socket(context->z_ctx, type);
	zmq_sock->pid = getpid();
	zmq_sock->ctx = context;
	zmq_sock->socket_type = type;

	if (!zmq_sock->z_socket) {
		pefree(zmq_sock, is_persistent);
		return NULL;
	}

	/* Increment socket count */
	php_zmq_context_socket_count_incr(context);
	zmq_sock->is_persistent = is_persistent;

	zend_hash_init(&(zmq_sock->connect), 0, NULL, NULL, is_persistent);
	zend_hash_init(&(zmq_sock->bind), 0, NULL, NULL, is_persistent);
	return zmq_sock;
}
/* }}} */

static zend_string *php_zmq_socket_plist_key(zend_long type, zend_string *persistent_id, bool use_shared_ctx)
{
	return strpprintf(0, "zmq_socket:[%ld]-[%s]-[%d]", (long)type, persistent_id->val, use_shared_ctx);
}

static void php_zmq_socket_store(php_zmq_socket *zmq_sock_p, zend_long type, zend_string *persistent_id, bool use_shared_ctx)
{
	zend_string *plist_key = NULL;

	zend_resource le;
	le.type = php_zmq_socket_list_entry();
	le.ptr = zmq_sock_p;

	GC_SET_REFCOUNT(&le, 1);

	plist_key = php_zmq_socket_plist_key(type, persistent_id, use_shared_ctx);

	/* plist_key is not a persistent allocated key, thus we use str_update here */
	if (zend_hash_str_update_mem(&EG(persistent_list), plist_key->val, plist_key->len, &le, sizeof(le)) == NULL) {
		if (plist_key) {
			zend_string_release(plist_key);
		}
		php_error_docref(NULL, E_ERROR, "Could not register persistent entry for the socket");
		/* not reached */
	}

	if (plist_key) {
		zend_string_release(plist_key);
	}
}

/* {{{ static php_zmq_socket *php_zmq_socket_get(php_zmq_context *context, zend_long type, zend_string *persistent_id, zend_bool *is_new)
	Tries to get context from plist and allocates a new context if context does not exist
*/
static php_zmq_socket *php_zmq_socket_get(php_zmq_context *context, zend_long type, zend_string *persistent_id, bool *is_new)
{
	php_zmq_socket *zmq_sock_p;
	zend_string *plist_key = NULL;
	bool is_persistent = (context->is_persistent && persistent_id && persistent_id->len);
	*is_new = false;

	if (is_persistent) {
		zend_resource *le_p = NULL;

		plist_key = php_zmq_socket_plist_key(type, persistent_id, context->use_shared_ctx);

		if ((le_p = zend_hash_find_ptr(&EG(persistent_list), plist_key)) != NULL) {
			if (le_p->type == php_zmq_socket_list_entry()) {
				if (plist_key) {
					zend_string_release(plist_key);
				}
				return (php_zmq_socket *) le_p->ptr;
			}
		}
	}
	zmq_sock_p = php_zmq_socket_new(context, type, is_persistent);

	if (plist_key) {
		zend_string_release(plist_key);
	}

	if (!zmq_sock_p) {
		return NULL;
	}

	*is_new = true;
	return zmq_sock_p;
}
/* }}} */

static bool php_zmq_connect_callback(zval *socket, zend_fcall_info *fci, zend_fcall_info_cache *fci_cache, zend_string *persistent_id)
{
	zval retval;
	zval params[2];
	bool rv = true;

	/* Call the cb */
	params[0] = *socket;

	if (persistent_id && persistent_id->len) {
		ZVAL_STR(&params[1], zend_string_copy(persistent_id));
	} else {
		ZVAL_NULL(&params[1]);
	}

	fci->params = params;
	fci->param_count = 2;
	fci->retval = &retval;

	if (zend_call_function(fci, fci_cache) == FAILURE) {
		if (!EG(exception)) {
			char *func_name = php_zmq_printable_func(fci, fci_cache);
			zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, 0, "Failed to invoke 'on_new_socket' callback %s()", func_name);
			efree(func_name);
		}
		rv = false;
	}

	zval_ptr_dtor(&params[1]);

	if (Z_TYPE(retval) != IS_UNDEF) {
		zval_ptr_dtor(&retval);
	}

	if (EG(exception)) {
		rv = false;
	}
	return rv;
}

/* {{{ proto ZMQContext ZMQContext::getSocket(integer $type[, string $persistent_id = null[, callback $on_new_socket = null]])
	Build a new ZMQContext object
*/
PHP_METHOD(ZMQContext, getSocket)
{
	php_zmq_socket *socket;
	php_zmq_socket_object *interns;
	php_zmq_context_object *intern;
	zend_long type;
	zend_string *persistent_id = NULL;
	bool is_new;

	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;

	fci.size = 0;

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_LONG(type)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(persistent_id)
		Z_PARAM_FUNC_OR_NULL(fci, fci_cache)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_CONTEXT_OBJECT(ZEND_THIS);
	socket = php_zmq_socket_get(intern->context, type, persistent_id, &is_new);

	if (!socket) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Error creating socket: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}

	object_init_ex(return_value, php_zmq_socket_sc_entry);
	interns = PHP_ZMQ_SOCKET_OBJECT(return_value);
	interns->socket = socket;

	/* Need to add refcount if context is not persistent */
	if (!intern->context->is_persistent) {
		ZVAL_OBJ(&interns->context_obj, &intern->std);
		Z_ADDREF(interns->context_obj);
	}

	if (is_new) {
		if (fci.size) {
			if (!php_zmq_connect_callback(return_value, &fci, &fci_cache, persistent_id)) {
				php_zmq_socket_destroy(socket);
				interns->socket = NULL;
				RETURN_THROWS();
			}
		}
		if (socket->is_persistent) {
			php_zmq_socket_store(socket, type, persistent_id, intern->context->use_shared_ctx);
		}
	}
	if (socket->is_persistent) {
		interns->persistent_id = estrdup(persistent_id->val);
	}
}
/* }}} */

/* {{{ proto ZMQContext ZMQContext::isPersistent()
	Whether the context is persistent
*/
PHP_METHOD(ZMQContext, isPersistent)
{
	php_zmq_context_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_CONTEXT_OBJECT(ZEND_THIS);
	RETURN_BOOL(intern->context->is_persistent);
}
/* }}} */

/* {{{ proto ZMQContext ZMQContext::__clone()
	Clones the instance of the ZMQContext class
*/
PHP_METHOD(ZMQContext, __clone) { }
/* }}} */

/* --- END ZMQContext --- */

/* --- START ZMQSocket --- */

/* {{{ proto ZMQSocket ZMQSocket::__construct(ZMQContext $context, integer $type[, string $persistent_id = null[, callback $on_new_socket = null]])
	Build a new ZMQSocket object
*/
PHP_METHOD(ZMQSocket, __construct)
{
	php_zmq_socket *socket;
	php_zmq_socket_object *intern;
	php_zmq_context_object *internc;
	zend_long type;
	zend_string *persistent_id = NULL;
	zval *obj;
	bool is_new;

	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;

	fci.size = 0;

	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_OBJECT_OF_CLASS(obj, php_zmq_context_sc_entry)
		Z_PARAM_LONG(type)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(persistent_id)
		Z_PARAM_FUNC_OR_NULL(fci, fci_cache)
	ZEND_PARSE_PARAMETERS_END();

	internc = php_zmq_context_fetch_object(Z_OBJ_P(obj));
	socket = php_zmq_socket_get(internc->context, type, persistent_id, &is_new);

	if (!socket) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Error creating socket: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);
	intern->socket = socket;

	/* Need to add refcount if context is not persistent */
	if (!internc->context->is_persistent) {
		ZVAL_OBJ(&intern->context_obj, &internc->std);
		Z_ADDREF(intern->context_obj);
	}

	if (is_new) {
		if (fci.size) {
			if (!php_zmq_connect_callback(getThis(), &fci, &fci_cache, persistent_id)) {
				php_zmq_socket_destroy(socket);
				intern->socket = NULL;
				RETURN_THROWS();
			}
		}
		if (socket->is_persistent) {
			php_zmq_socket_store(socket, type, persistent_id, internc->context->use_shared_ctx);
		}
	}
	if (socket->is_persistent) {
		intern->persistent_id = estrdup(persistent_id->val);
	}
}
/* }}} */

/* {{{ static zend_bool php_zmq_send(php_zmq_socket_object *intern, char *message_param, long flags)
*/
static zend_result php_zmq_send(php_zmq_socket_object *intern, zend_string *message_param, zend_long flags)
{
	zmq_msg_t message;

	if (zmq_msg_init_size(&message, message_param->len) != 0) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to initialize message structure: %s", zmq_strerror(errno));
		return FAILURE;
	}
	memcpy(zmq_msg_data(&message), message_param->val, message_param->len);

	if (zmq_sendmsg(intern->socket->z_socket, &message, flags) < 0) {
		zmq_msg_close(&message);
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to send message: %s", zmq_strerror(errno));
		return FAILURE;
	}

	zmq_msg_close(&message);
	return SUCCESS;
}
/* }}} */

/* {{{ proto ZMQSocket ZMQSocket::send(string $message[, integer $flags = 0])
	Send a message. Return true if message was sent and false on EAGAIN
*/
PHP_METHOD(ZMQSocket, send)
{
	php_zmq_socket_object *intern;
	zend_string *message_param;
	size_t message_len;
	zend_long flags = 0;
	bool ret;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(message_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	if (php_zmq_send(intern, message_param, flags) == FAILURE) {
		RETURN_THROWS();
	}

	ZMQ_RETURN_THIS;
}

/* }}} */

static int php_zmq_send_cb(zval *zv, int num_args, va_list args, zend_hash_key *hash_key)
{
	php_zmq_socket_object *intern;
	int flags, *to_send;
	zend_result *rc;

	intern = va_arg(args, php_zmq_socket_object *);
	flags = va_arg(args, int);
	to_send = va_arg(args, int *);
	rc = va_arg(args, zend_result *);

	if (--(*to_send)) {
		flags = flags | ZMQ_SNDMORE;
	} else {
		flags = flags & ~ZMQ_SNDMORE;
	}

	zend_string *str = zval_get_string(zv);
	*rc = php_zmq_send(intern, str, flags);

	zend_string_release(str);

	if (*rc == FAILURE) {
		return ZEND_HASH_APPLY_STOP;
	}
	return ZEND_HASH_APPLY_KEEP;
}

/* {{{ proto ZMQSocket ZMQSocket::sendmulti(arrays $messages[, integer $flags = 0])
	Send a multipart message. Return true if message was sent and false on EAGAIN
*/
PHP_METHOD(ZMQSocket, sendmulti)
{
	zval *messages;
	php_zmq_socket_object *intern;
	int to_send = 0;
	zend_long flags = 0;
	zend_result ret;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(messages)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);
	to_send = zend_hash_num_elements(Z_ARRVAL_P(messages));
	zend_hash_apply_with_arguments(Z_ARRVAL_P(messages), (apply_func_args_t) php_zmq_send_cb, 4, intern, flags, &to_send, &ret);

	if (ret == FAILURE) {
		RETURN_THROWS();
	}

	ZMQ_RETURN_THIS;
}

/* {{{ static zend_bool php_zmq_recv(php_zmq_socket_object *intern, long flags, zval *return_value)
*/
static zend_string *php_zmq_recv(php_zmq_socket_object *intern, zend_long flags)
{
	zmq_msg_t message;
	zend_string *str = NULL;

	if (zmq_msg_init(&message) != 0) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to initialize message structure: %s", zmq_strerror(errno));
		return NULL;
	}

	if (zmq_recvmsg(intern->socket->z_socket, &message, flags) < 0) {
		zmq_msg_close(&message);
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to receive message: %s", zmq_strerror(errno));
		return NULL;
	}

	str = zend_string_init(zmq_msg_data(&message), zmq_msg_size(&message), 0);
	zmq_msg_close(&message);
	return str;
}
/* }}} */

/* {{{ proto string ZMQ::recv([integer $flags = 0])
	Receive a message
*/
PHP_METHOD(ZMQSocket, recv)
{
	zend_string *str = NULL;
	php_zmq_socket_object *intern;
	zend_long flags = 0;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);
	str = php_zmq_recv(intern, flags);

	if (!str) {
		RETURN_THROWS();
	}

	RETURN_STR(str);
}

/* }}} */

/* {{{ proto array ZMQ::recvmulti([integer $flags = 0])
	Receive an array of message parts
*/
PHP_METHOD(ZMQSocket, recvmulti)
{
	php_zmq_socket_object *intern;
	size_t value_len;
	zend_long flags = 0;
	int value;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);
	array_init(return_value);
	value_len = sizeof(value);

	do {
		zend_string *part = php_zmq_recv(intern, flags);
		if (!part) {
			zval_dtor(return_value);
			RETURN_THROWS();
		}
		add_next_index_str(return_value, part);
		zmq_getsockopt(intern->socket->z_socket, ZMQ_RCVMORE, &value, &value_len);
	} while (value > 0);
}
/* }}} */

#if PHP_ZMQ_HAVE_SOCKET_MONITOR

/* {{{ proto array ZMQ::recvevent([integer $flags = 0])
	Receive an event from monitor endpoint
*/
PHP_METHOD(ZMQSocket, recvevent)
{
	php_zmq_socket_object *intern;
	zend_long flags = 0;
	int value;
	uint8_t *data;
	uint16_t event;
	zend_string *metadata, *address;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	metadata = php_zmq_recv(intern, flags);
	if (!metadata || metadata->len != sizeof (uint16_t) + sizeof (uint32_t)) {
		if (metadata) {
			zend_string_release(metadata);
		}
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Invalid monitor message received: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}
	address = php_zmq_recv(intern, flags);
	if (!address) {
		zend_string_release(metadata);
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Invalid monitor message received: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}

	data = (uint8_t *)metadata->val;
	event = *(uint16_t *)(data);
	value = *(uint32_t *)(data + sizeof(uint16_t));

	array_init(return_value);

	add_assoc_long(return_value, "event", event);
	add_assoc_long(return_value, "value", value);
	add_assoc_str(return_value, "address", address);

	zend_string_release(metadata);
}
/* }}} */

/* {{{ proto ZMQSocket ZMQ::monitor(string $dsn[, integer $events = ZMQ::EVENTS_ALL])
	Add a monitor
*/
PHP_METHOD(ZMQSocket, monitor)
{
	php_zmq_socket_object *intern;
	char *dsn;
	size_t dsn_len;
	zend_long events = ZMQ_EVENT_ALL;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STRING(dsn, dsn_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(events)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	if (zmq_socket_monitor(intern->socket->z_socket, dsn, events) != 0) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to add socket monitor: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}
	ZMQ_RETURN_THIS;
}
/* }}} */

#endif

PHP_METHOD(ZMQSocket, setSockOpt)
{
	php_zmq_socket_object *intern;
	zend_long key;
	zval *val;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(key)
		Z_PARAM_ZVAL(val)
	ZEND_PARSE_PARAMETERS_END();

	int type = Z_TYPE(*val);
	if (type != IS_STRING && type != IS_LONG) {
		zend_argument_type_error(2, "must either be a number or a string");
		RETURN_THROWS();
	}

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	if (php_zmq_socket_setsockopt(intern->socket->z_socket, intern->socket->socket_type, key, val) == FAILURE) {
		RETURN_THROWS();
	}

	ZMQ_RETURN_THIS;
}

PHP_METHOD(ZMQSocket, getSockOpt)
{
	php_zmq_socket_object *intern;
	zend_long key;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(key)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	if (php_zmq_socket_getsockopt(intern->socket->z_socket, intern->socket->socket_type, key, return_value) == FAILURE) {
		RETURN_THROWS();
	}
}

/** {{{ string ZMQ::getPersistentId() 
	Returns the persistent id of the object
*/
PHP_METHOD(ZMQSocket, getPersistentId)
{
	php_zmq_socket_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	if (intern->socket->is_persistent && intern->persistent_id) {
		RETURN_STRING(intern->persistent_id);
	}
	RETURN_NULL();
}
/* }}} */

/* {{{ proto ZMQSocket ZMQSocket::bind(string $dsn[, boolean $force = false])
	Bind the socket to an endpoint
*/
PHP_METHOD(ZMQSocket, bind)
{
	php_zmq_socket_object *intern;
	char *dsn;
	size_t dsn_len;
	bool force = false;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STRING(dsn, dsn_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(force)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	/* already connected ? */
	if (!force && zend_hash_str_exists(&(intern->socket->bind), dsn, dsn_len)) {
		ZMQ_RETURN_THIS;
	}

	if (zmq_bind(intern->socket->z_socket, dsn) != 0) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to bind the ZMQ: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}

	zend_hash_str_add_empty_element(&(intern->socket->bind), dsn, dsn_len);
	ZMQ_RETURN_THIS;
}
/* }}} */

/* {{{ proto ZMQSocket ZMQSocket::connect(string $dsn[, boolean $force = false])
	Connect the socket to an endpoint
*/
PHP_METHOD(ZMQSocket, connect)
{
	php_zmq_socket_object *intern;
	char *dsn;
	size_t dsn_len;
	bool force = false;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STRING(dsn, dsn_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(force)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	/* already connected ? */
	if (!force && zend_hash_str_exists(&(intern->socket->connect), dsn, dsn_len)) {
		ZMQ_RETURN_THIS;
	}

	if (zmq_connect(intern->socket->z_socket, dsn) != 0) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to connect the ZMQ: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}

	zend_hash_str_add_empty_element(&(intern->socket->connect), dsn, dsn_len);
	ZMQ_RETURN_THIS;
}
/* }}} */

#ifdef PHP_ZMQ_HAVE_UNBIND
/* {{{ proto ZMQSocket ZMQSocket::unbind(string $dsn)
	Unbind the socket from an endpoint
*/
PHP_METHOD(ZMQSocket, unbind)
{
	php_zmq_socket_object *intern;
	char *dsn;
	size_t dsn_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(dsn, dsn_len)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	if (zmq_unbind(intern->socket->z_socket, dsn) != 0) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to unbind the ZMQ socket: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}

	zend_hash_str_del(&(intern->socket->bind), dsn, dsn_len);
	ZMQ_RETURN_THIS;
}
/* }}} */
#endif

#ifdef PHP_ZMQ_HAVE_DISCONNECT
/* {{{ proto ZMQSocket ZMQSocket::disconnect(string $dsn)
	Disconnect the socket from an endpoint
*/
PHP_METHOD(ZMQSocket, disconnect)
{
	php_zmq_socket_object *intern;
	char *dsn;
	size_t dsn_len;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(dsn, dsn_len)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);

	if (zmq_disconnect(intern->socket->z_socket, dsn) != 0) {
		zend_throw_exception_ex(php_zmq_socket_exception_sc_entry, errno, "Failed to disconnect the ZMQ socket: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}

	zend_hash_str_del(&(intern->socket->connect), dsn, dsn_len);
	ZMQ_RETURN_THIS;
}
/* }}} */
#endif


static int php_zmq_get_keys(zval *ppzval, int num_args, va_list args, zend_hash_key *hash_key)
{
	zval *retval = va_arg(args, zval *);
	add_next_index_string(retval, hash_key->key->val);
	return ZEND_HASH_APPLY_KEEP;
}
/* }}} */

/* {{{ proto array ZMQ::getEndpoints()
	Returns endpoints where this socket is connected/bound to. Contains two keys ('bind', 'connect')
*/
PHP_METHOD(ZMQSocket, getEndpoints)
{
	php_zmq_socket_object *intern;
	zval connect, bind;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);
	array_init(return_value);

	array_init(&connect);
	array_init(&bind);

	zend_hash_apply_with_arguments(&(intern->socket->connect), (apply_func_args_t) php_zmq_get_keys, 1, &connect);
	zend_hash_apply_with_arguments(&(intern->socket->bind), (apply_func_args_t) php_zmq_get_keys, 1, &bind);

	add_assoc_zval(return_value, "connect", &connect);
	add_assoc_zval(return_value, "bind", &bind);
}
/* }}} */

/* {{{ proto integer ZMQSocket::getSocketType()
	Returns the socket type
*/
PHP_METHOD(ZMQSocket, getSocketType)
{
	int type;
	size_t type_siz;
	php_zmq_socket_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);
	type_siz = sizeof(int);

	if (zmq_getsockopt(intern->socket->z_socket, ZMQ_TYPE, &type, &type_siz) != -1) {
		RETURN_LONG(type);
	}
	RETURN_LONG(-1);
}
/* }}} */

/* {{{ proto boolean ZMQSocket::isPersistent()
	Whether the socket is persistent
*/
PHP_METHOD(ZMQSocket, isPersistent)
{
	php_zmq_socket_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_SOCKET_OBJECT(ZEND_THIS);
	RETURN_BOOL(intern->socket->is_persistent);
}
/* }}} */

/* {{{ proto ZMQSocket ZMQSocket::__clone()
	Clones the instance of the ZMQSocket class
*/
PHP_METHOD(ZMQSocket, __clone) { }
/* }}} */

/* -- END ZMQSocket--- */

/* -- START ZMQPoll --- */

/* {{{ proto integer ZMQPoll::add(ZMQSocket $object, integer $events)
	Add a ZMQSocket object into the pollset
*/
PHP_METHOD(ZMQPoll, add)
{
	php_zmq_poll_object *intern;
	zval *object;
	zend_long events;
	int error;
	zend_string *key;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(object)
		Z_PARAM_LONG(events)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_POLL_OBJECT(ZEND_THIS);

	switch (Z_TYPE_P(object)) {
		case IS_OBJECT:
			if (!instanceof_function(Z_OBJCE_P(object), php_zmq_socket_sc_entry)) {
				zend_throw_exception(php_zmq_poll_exception_sc_entry, "The first argument must be an instance of ZMQSocket or a resource", PHP_ZMQ_INTERNAL_ERROR);
				RETURN_THROWS();
			}
			break;
		case IS_RESOURCE:
			/* noop */
			break;
		default:
			zend_throw_exception(php_zmq_poll_exception_sc_entry, "The first argument must be an instance of ZMQSocket or a resource", PHP_ZMQ_INTERNAL_ERROR);
			RETURN_THROWS();
	}

	key = php_zmq_pollset_add(intern->set, object, events, &error);

	if (!key) {
		const char *message = NULL;

		switch (error) {
			case PHP_ZMQ_POLLSET_ERR_NO_STREAM:
				message = "The supplied resource is not a valid stream resource";
				break;
			case PHP_ZMQ_POLLSET_ERR_CANNOT_CAST:
				message = "The supplied resource is not castable";
				break;
			case PHP_ZMQ_POLLSET_ERR_CAST_FAILED:
				message = "Failed to cast the supplied stream resource";
				break;
			case PHP_ZMQ_POLLSET_ERR_NO_INIT:
				message = "The ZMQSocket object has not been initialized properly";
				break;
			case PHP_ZMQ_POLLSET_ERR_NO_POLL:
				message = "The ZMQSocket object has not been initialized with polling";
				break;
			default:
				message = "Unknown error";
		}

		zend_throw_exception(php_zmq_poll_exception_sc_entry, message, PHP_ZMQ_INTERNAL_ERROR);
		RETURN_THROWS();
	}
	RETURN_STR(key);
}
/* }}} */

/* {{{ proto boolean ZMQPoll::remove(mixed $item)
	Remove item from poll set
*/
PHP_METHOD(ZMQPoll, remove)
{
	php_zmq_poll_object *intern;
	zval *item;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(item)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_POLL_OBJECT(ZEND_THIS);

	if (php_zmq_pollset_num_items(intern->set) == 0) {
		zend_throw_exception(php_zmq_poll_exception_sc_entry, "No sockets assigned to the ZMQPoll", PHP_ZMQ_INTERNAL_ERROR);
		RETURN_THROWS();
	}

	switch (Z_TYPE_P(item)) {

		case IS_OBJECT:
			if (!instanceof_function(Z_OBJCE_P(item), php_zmq_socket_sc_entry)) {
				zend_throw_exception(php_zmq_poll_exception_sc_entry, "The object must be an instanceof ZMQSocket", PHP_ZMQ_INTERNAL_ERROR);
				RETURN_THROWS();
			}
			/* break intentionally missing */
		case IS_RESOURCE:
			RETVAL_BOOL(php_zmq_pollset_delete(intern->set, item));
		break;

		default: {
			zend_string *str = zval_get_string(item);
			zend_bool retval;

			retval = php_zmq_pollset_delete_by_key(intern->set, str);
			zend_string_release(str);

			RETVAL_BOOL(retval);
		} break;
	}
}
/* }}} */

/* {{{ proto integer ZMQPoll::poll(array &$readable, array &$writable[, integer $timeout = -1])
	Poll the sockets
*/
PHP_METHOD(ZMQPoll, poll)
{
	php_zmq_poll_object *intern;
	zval *r_array, *w_array;

	zend_long timeout = -1;
	int rc;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "a!/a!/|l", &r_array, &w_array, &timeout) == FAILURE) {
    return;
  }

	intern = PHP_ZMQ_POLL_OBJECT(ZEND_THIS);

	if (php_zmq_pollset_num_items(intern->set) == 0) {
		zend_throw_exception(php_zmq_poll_exception_sc_entry, "No sockets assigned to the ZMQPoll", PHP_ZMQ_INTERNAL_ERROR);
		RETURN_THROWS();
	}

	rc = php_zmq_pollset_poll(intern->set, timeout * PHP_ZMQ_TIMEOUT, r_array, w_array);

	if (rc == -1) {
		zend_throw_exception_ex(php_zmq_poll_exception_sc_entry, errno, "Poll failed: %s", zmq_strerror(errno));
		RETURN_THROWS();
	}
	RETURN_LONG(rc);
}
/* }}} */

/* {{{ proto integer ZMQPoll::count()
	Returns the number of items in the set
*/
PHP_METHOD(ZMQPoll, count)
{
	php_zmq_poll_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_POLL_OBJECT(ZEND_THIS);
	RETURN_LONG(php_zmq_pollset_num_items(intern->set));
}
/* }}} */

/* {{{ proto ZMQPoll ZMQPoll::clear()
	Clear the pollset
*/
PHP_METHOD(ZMQPoll, clear)
{
	php_zmq_poll_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_POLL_OBJECT(ZEND_THIS);

	php_zmq_pollset_clear(intern->set);
	ZMQ_RETURN_THIS;
}
/* }}} */

/* {{{ proto array ZMQPoll::items()
	Clear the pollset
*/
PHP_METHOD(ZMQPoll, items)
{
	php_zmq_poll_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_POLL_OBJECT(ZEND_THIS);

	array_init(return_value);
	php_zmq_pollset_items(intern->set, return_value);
}
/* }}} */

/* {{{ proto array ZMQPoll::getLastErrors()
	Returns last errors
*/
PHP_METHOD(ZMQPoll, getLastErrors)
{
	php_zmq_poll_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_POLL_OBJECT(ZEND_THIS);
	RETVAL_ZVAL(php_zmq_pollset_errors(intern->set), 1, 0);
}
/* }}} */

/* {{{ proto ZMQPoll ZMQPoll::__clone()
	Clones the instance of the ZMQPoll class
*/
PHP_METHOD(ZMQPoll, __clone) { }
/* }}} */

/* -- END ZMQPoll */

/* {{{ proto void ZMQDevice::__construct(ZMQSocket frontend, ZMQSocket backend)
	Construct a device
*/
PHP_METHOD(ZMQDevice, __construct)
{
	php_zmq_device_object *intern;
	zval *f, *b, *c = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(f, php_zmq_socket_sc_entry)
		Z_PARAM_OBJECT_OF_CLASS(b, php_zmq_socket_sc_entry)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(c, php_zmq_socket_sc_entry)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_DEVICE_OBJECT(ZEND_THIS);

	ZVAL_OBJ(&intern->front, Z_OBJ_P(f));
	Z_ADDREF(intern->front);

	ZVAL_OBJ(&intern->back, Z_OBJ_P(b));
	Z_ADDREF(intern->back);

	if (c) {
		ZVAL_OBJ(&intern->capture, Z_OBJ_P(c));
		Z_ADDREF(intern->capture);
	} else {
		ZVAL_UNDEF(&intern->capture);
	}
}
/* }}} */

/* {{{ proto void ZMQDevice::run()
	Start a device
*/
PHP_METHOD(ZMQDevice, run)
{
	php_zmq_device_object *intern;
	bool rc;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_DEVICE_OBJECT(ZEND_THIS);
	rc = php_zmq_device(intern);

	if (!rc && !EG(exception)) {
		zend_throw_exception_ex(php_zmq_device_exception_sc_entry, errno, "Failed to start the device: %s", zmq_strerror (errno));
		RETURN_THROWS();
	}
}
/* }}} */

static void s_clear_device_callback(php_zmq_device_cb_t *cb)
{
	if (cb->initialized) {
		zval_ptr_dtor(&cb->fci.function_name);
		cb->fci.size = 0;

		if (!Z_ISUNDEF(cb->user_data)) {
			zval_ptr_dtor(&cb->user_data);
		}
		memset(cb, 0, sizeof (php_zmq_device_cb_t));
		cb->initialized = false;
	}
}

static void s_init_device_callback(php_zmq_device_cb_t *cb, zend_fcall_info *fci, zend_fcall_info_cache *fci_cache, zend_long timeout, zval *user_data)
{
	memcpy(&cb->fci, fci, sizeof (zend_fcall_info));
	memcpy(&cb->fci_cache, fci_cache, sizeof (zend_fcall_info_cache));

	Z_TRY_ADDREF(fci->function_name);
	cb->initialized  = true;
	cb->scheduled_at = php_zmq_clock(ZMQ_G (clock_ctx)) + timeout;
	cb->timeout = timeout;

	if (user_data) {
		ZVAL_COPY(&cb->user_data, user_data);
	} else {
		ZVAL_NULL(&cb->user_data);
	}
}

/* {{{ proto void ZMQDevice::setIdleTimeout (int $milliseconds)
	Set the idle timeout value
*/
PHP_METHOD(ZMQDevice, setIdleTimeout)
{
	php_zmq_device_object *intern;
	zend_long timeout;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_DEVICE_OBJECT(ZEND_THIS);
	intern->idle_cb.timeout = timeout;
	ZMQ_RETURN_THIS;
}
/* }}} */

PHP_METHOD(ZMQDevice, getIdleTimeout)
{
	php_zmq_device_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_DEVICE_OBJECT(ZEND_THIS);
	RETURN_LONG(intern->idle_cb.timeout);
}

PHP_METHOD(ZMQDevice, setTimerTimeout)
{
	php_zmq_device_object *intern;
	zend_long timeout;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_DEVICE_OBJECT(ZEND_THIS);
	intern->timer_cb.timeout = timeout;
	ZMQ_RETURN_THIS;
}

PHP_METHOD(ZMQDevice, getTimerTimeout)
{
	php_zmq_device_object *intern;

	ZEND_PARSE_PARAMETERS_NONE();

	intern = PHP_ZMQ_DEVICE_OBJECT(ZEND_THIS);
	RETURN_LONG(intern->timer_cb.timeout);
}

/* {{{ proto void ZMQDevice::setIdleCallback (callable $function, integer timeout [, mixed $userdata])
	Set the idle timeout value
*/
PHP_METHOD(ZMQDevice, setIdleCallback)
{
	php_zmq_device_object *intern;
	zval *user_data = NULL;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	zend_long timeout = 0;

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_FUNC(fci, fci_cache)
		Z_PARAM_LONG(timeout)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(user_data)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_DEVICE_OBJECT(ZEND_THIS);

	/* Hack for backwards compatible behaviour */
	if (!timeout && intern->idle_cb.timeout) {
		timeout = intern->idle_cb.timeout;
	}

	s_clear_device_callback(&intern->idle_cb);

	if (fci.size > 0) {
		s_init_device_callback(&intern->idle_cb, &fci, &fci_cache, timeout, user_data);
	}
	ZMQ_RETURN_THIS;

}
/* }}} */

/* {{{ proto void ZMQDevice::setTimerCallback (callable $function, integer timeout [, mixed $userdata])
	Set the timer function
*/
PHP_METHOD(ZMQDevice, setTimerCallback)
{
	php_zmq_device_object *intern;
	zval *user_data = NULL;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	zend_long timeout;

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_FUNC(fci, fci_cache)
		Z_PARAM_LONG(timeout)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(user_data)
	ZEND_PARSE_PARAMETERS_END();

	intern = PHP_ZMQ_DEVICE_OBJECT(ZEND_THIS);

	s_clear_device_callback(&intern->timer_cb);
	if (fci.size > 0) {
		s_init_device_callback (&intern->timer_cb, &fci, &fci_cache, timeout, user_data);
	}
	ZMQ_RETURN_THIS;
}
/* }}} */

/* {{{ proto ZMQDevice ZMQDevice::__clone()
	Clones the instance of the ZMQDevice class
*/
PHP_METHOD(ZMQDevice, __clone) { }
/* }}} */

/* -- END ZMQPoll */

static void php_zmq_context_object_free_storage(zend_object *object)
{
	php_zmq_context_object *intern = php_zmq_context_fetch_object(object);

	if (!intern) {
		return;
	}

	if (intern->context && !intern->context->is_persistent) {
		php_zmq_context_destroy(intern->context);
	}

	zend_object_std_dtor(&intern->std);
}

static void php_zmq_socket_object_free_storage(zend_object *object)
{
	php_zmq_socket_object *intern = php_zmq_socket_fetch_object(object);

	if (!intern) {
		return;
	}

	if (intern->socket) {
		if (intern->socket->is_persistent && intern->persistent_id) {
			efree(intern->persistent_id);
		}
		if (!intern->socket->is_persistent) {
			php_zmq_socket_destroy(intern->socket);
		}
	}

	if (!Z_ISUNDEF(intern->context_obj)) {
		zval_ptr_dtor(&intern->context_obj);
	}
	zend_object_std_dtor(&intern->std);
}

static void php_zmq_poll_object_free_storage(zend_object *object)
{
	php_zmq_poll_object *intern = php_zmq_poll_fetch_object(object);

	if (!intern) {
		return;
	}
	php_zmq_pollset_destroy(&intern->set);
	zend_object_std_dtor(&intern->std);
}

static void php_zmq_device_object_free_storage(zend_object *object)
{
	php_zmq_device_object *intern = php_zmq_device_fetch_object(object);

	if (!intern) {
		return;
	}

	s_clear_device_callback (&intern->idle_cb);
	s_clear_device_callback (&intern->timer_cb);

	if (!Z_ISUNDEF(intern->front)) {
		zval_ptr_dtor(&intern->front);
	}

	if (!Z_ISUNDEF(intern->back)) {
		zval_ptr_dtor(&intern->back);
	}

	if (!Z_ISUNDEF(intern->capture)) {
		zval_ptr_dtor(&intern->capture);
	}
	zend_object_std_dtor(&intern->std);
}

static zend_object *php_zmq_context_object_new(zend_class_entry *ce)
{
	php_zmq_context_object *intern = zend_object_alloc(sizeof(php_zmq_context_object), ce);

	/* Context is initialized in the constructor */
	intern->context = NULL;

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = &zmq_context_object_handlers;
	return &intern->std;
}

static zend_object *php_zmq_socket_object_new(zend_class_entry *ce)
{
	php_zmq_socket_object *intern = zend_object_alloc(sizeof(php_zmq_socket_object), ce);
	intern->socket = NULL;
	intern->persistent_id = NULL;
	ZVAL_UNDEF(&intern->context_obj);
	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = &zmq_socket_object_handlers;
	return &intern->std;
}

static zend_object *php_zmq_poll_object_new(zend_class_entry *ce)
{
	php_zmq_poll_object *intern = zend_object_alloc(sizeof(php_zmq_poll_object), ce);
	intern->set = php_zmq_pollset_init();
	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = &zmq_poll_object_handlers;
	return &intern->std;
}

static zend_object *php_zmq_device_object_new(zend_class_entry *ce)
{
	php_zmq_device_object *intern = zend_object_alloc(sizeof(php_zmq_device_object), ce);
	memset(&intern->idle_cb, 0, sizeof(php_zmq_device_cb_t));
	memset(&intern->timer_cb, 0, sizeof(php_zmq_device_cb_t));

	ZVAL_UNDEF(&intern->front);
	ZVAL_UNDEF(&intern->back);
	ZVAL_UNDEF(&intern->capture);

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = &zmq_device_object_handlers;
	return &intern->std;
}

ZEND_RSRC_DTOR_FUNC(php_zmq_context_dtor)
{
	if (res->ptr) {
		php_zmq_context *ctx = (php_zmq_context *)res->ptr;
		php_zmq_context_destroy(ctx);
		res->ptr = NULL;
	}
}

ZEND_RSRC_DTOR_FUNC(php_zmq_socket_dtor)
{
	if (res->ptr) {
		php_zmq_socket *zms = (php_zmq_socket *)res->ptr;
		php_zmq_socket_destroy(zms);
		res->ptr = NULL;
	}
}

static void php_zmq_init_globals(zend_php_zmq_globals *zmq_globals)
{
	zmq_globals->clock_ctx = NULL;
}

PHP_MINIT_FUNCTION(zmq)
{
	le_zmq_context = zend_register_list_destructors_ex(NULL, php_zmq_context_dtor, "ZMQ persistent context", module_number);
	le_zmq_socket  = zend_register_list_destructors_ex(NULL, php_zmq_socket_dtor, "ZMQ persistent socket", module_number);

	php_zmq_exception_sc_entry = register_class_ZMQException(zend_ce_exception);
	php_zmq_socket_exception_sc_entry = register_class_ZMQSocketException(php_zmq_exception_sc_entry);
	php_zmq_context_exception_sc_entry = register_class_ZMQContextException(php_zmq_exception_sc_entry);
	php_zmq_poll_exception_sc_entry = register_class_ZMQPollException(php_zmq_exception_sc_entry);
	php_zmq_device_exception_sc_entry = register_class_ZMQDeviceException(php_zmq_exception_sc_entry);

	memcpy(&zmq_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	memcpy(&zmq_context_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	memcpy(&zmq_socket_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	memcpy(&zmq_poll_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	memcpy(&zmq_device_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));

	php_zmq_sc_entry = register_class_ZMQ();
	php_zmq_sc_entry->create_object = NULL;
	zmq_object_handlers.clone_obj = NULL;

	php_zmq_context_sc_entry = register_class_ZMQContext();
	php_zmq_context_sc_entry->create_object = php_zmq_context_object_new;
	zmq_context_object_handlers.offset = XtOffsetOf(php_zmq_context_object, std);
	zmq_context_object_handlers.clone_obj = NULL;
	zmq_context_object_handlers.free_obj  = php_zmq_context_object_free_storage;

	php_zmq_socket_sc_entry = register_class_ZMQSocket();
	php_zmq_socket_sc_entry->create_object = php_zmq_socket_object_new;
	zmq_socket_object_handlers.offset = XtOffsetOf(php_zmq_socket_object, std);
	zmq_socket_object_handlers.clone_obj = NULL;
	zmq_socket_object_handlers.free_obj = php_zmq_socket_object_free_storage;

	php_zmq_poll_sc_entry = register_class_ZMQPoll();
	php_zmq_poll_sc_entry->create_object = php_zmq_poll_object_new;
	zmq_poll_object_handlers.offset = XtOffsetOf(php_zmq_poll_object, std);
	zmq_poll_object_handlers.clone_obj = NULL;
	zmq_poll_object_handlers.free_obj = php_zmq_poll_object_free_storage;

	php_zmq_device_sc_entry = register_class_ZMQDevice();
	php_zmq_device_sc_entry->create_object = php_zmq_device_object_new;
	zmq_device_object_handlers.offset = XtOffsetOf(php_zmq_device_object, std);
	zmq_device_object_handlers.clone_obj = NULL;
	zmq_device_object_handlers.free_obj = php_zmq_device_object_free_storage;

	ZEND_INIT_MODULE_GLOBALS(php_zmq, php_zmq_init_globals, NULL);

	ZMQ_G(clock_ctx) = php_zmq_clock_init();

	if (!ZMQ_G(clock_ctx)) {
		php_error_docref(NULL, E_WARNING, "Failed to initialise clock");
		return FAILURE;
	}

	if (!php_zmq_shared_ctx_init()) {
		return FAILURE;
	}
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(zmq)
{
	php_zmq_shared_ctx_destroy();
	php_zmq_clock_destroy(&ZMQ_G (clock_ctx));
	return SUCCESS;
}

PHP_MINFO_FUNCTION(zmq)
{
	char *version = php_zmq_get_libzmq_version();

	php_info_print_table_start();
	php_info_print_table_header(2, "ZMQ extension", "enabled");
	php_info_print_table_row(2, "ZMQ extension version", PHP_ZMQ_VERSION);
	php_info_print_table_row(2, "libzmq version", version);
	php_info_print_table_end();

	efree(version);
}

zend_module_entry zmq_module_entry =
{
	STANDARD_MODULE_HEADER,
	PHP_ZMQ_EXTNAME,
	NULL,			/* Functions */
	PHP_MINIT(zmq),			/* MINIT */
	PHP_MSHUTDOWN(zmq),		/* MSHUTDOWN */
	NULL,					/* RINIT */
	NULL,					/* RSHUTDOWN */
	PHP_MINFO(zmq),			/* MINFO */
	PHP_ZMQ_VERSION,		/* version */
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_ZMQ
ZEND_GET_MODULE(zmq)
#endif /* COMPILE_DL_ZMQ */
