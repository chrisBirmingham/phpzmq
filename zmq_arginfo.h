/* This is a generated file, edit zmq.stub.php instead.
 * Stub hash: 85efe8de09f8fd97d21df7eec87c57aa19ecc53a */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQ_clock, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PHP_ZMQ_HAVE_Z85
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQ_z85encode, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ZMQ_z85decode arginfo_class_ZMQ_z85encode
#endif

#if PHP_ZMQ_HAVE_CURVE_KEYPAIR
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQ_curvekeypair, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ZMQContext___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ioThreads, IS_LONG, 0, "1")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, persistent, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ZMQContext_acquire, 0, 0, ZMQContext, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ZMQContext_getsocketcount arginfo_class_ZMQ_clock

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ZMQContext_getsocket, 0, 1, ZMQSocket, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, dsn, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, onNewSocket, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQContext_ispersistent, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#if PHP_ZMQ_HAVE_CTX_OPTIONS
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQContext_setOpt, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, option, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQContext_getOpt, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, option, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ZMQSocket___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, ZMQContext, ZMQContext, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, persistentId, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, onNewSocket, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_ZMQSocket_send, 0, 1, MAY_BE_STATIC|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mode, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_ZMQSocket_recv, 0, 0, MAY_BE_STRING|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mode, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_ZMQSocket_sendmulti, 0, 1, MAY_BE_STATIC|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, message, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mode, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_ZMQSocket_recvmulti, 0, 0, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mode, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQSocket_bind, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, dsn, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, force, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_class_ZMQSocket_connect arginfo_class_ZMQSocket_bind

#if PHP_ZMQ_HAVE_SOCKET_MONITOR
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQSocket_monitor, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, dsn, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, events, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQSocket_recvevent, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

#if PHP_ZMQ_HAVE_UNBIND
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQSocket_unbind, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, dsn, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

#if PHP_ZMQ_HAVE_DISCONNECT
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQSocket_disconnect, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, dsn, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQSocket_setsockopt, 0, 2, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_LONG, 0)
	ZEND_ARG_TYPE_MASK(0, value, MAY_BE_STRING|MAY_BE_LONG, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQSocket_getendpoints, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ZMQSocket_getsockettype arginfo_class_ZMQ_clock

#define arginfo_class_ZMQSocket_ispersistent arginfo_class_ZMQContext_ispersistent

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQSocket_getpersistentid, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_ZMQSocket_getsockopt, 0, 1, MAY_BE_STRING|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, key, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ZMQSocket_sendmsg arginfo_class_ZMQSocket_send

#define arginfo_class_ZMQSocket_recvmsg arginfo_class_ZMQSocket_recv

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQPoll_add, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, entry, ZMQSocket, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ZMQPoll_poll, 0, 2, long, 0)
	ZEND_ARG_TYPE_INFO(1, readable, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(1, writable, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQPoll_getlasterrors, 0, 0, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQPoll_remove, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, remove, IS_MIXED, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ZMQPoll_count arginfo_class_ZMQ_clock

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_ZMQPoll_clear, 0, 0, ZMQPoll, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ZMQPoll_items arginfo_class_ZMQSocket_getendpoints

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ZMQDevice___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, frontend, ZMQSocket, 0)
	ZEND_ARG_OBJ_INFO(0, backend, ZMQSocket, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, capture, ZMQSocket, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQDevice_run, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQDevice_setidlecallback, 0, 2, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, idleCallback, IS_CALLABLE, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, user_data, IS_OBJECT, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ZMQDevice_setidletimeout, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ZMQDevice_getidletimeout arginfo_class_ZMQ_clock

#define arginfo_class_ZMQDevice_settimercallback arginfo_class_ZMQDevice_setidlecallback

#define arginfo_class_ZMQDevice_settimertimeout arginfo_class_ZMQDevice_setidletimeout

#define arginfo_class_ZMQDevice_gettimertimeout arginfo_class_ZMQ_clock

ZEND_METHOD(ZMQ, clock);
#if PHP_ZMQ_HAVE_Z85
ZEND_METHOD(ZMQ, z85encode);
ZEND_METHOD(ZMQ, z85decode);
#endif
#if PHP_ZMQ_HAVE_CURVE_KEYPAIR
ZEND_METHOD(ZMQ, curvekeypair);
#endif
ZEND_METHOD(ZMQContext, __construct);
ZEND_METHOD(ZMQContext, acquire);
ZEND_METHOD(ZMQContext, getsocketcount);
ZEND_METHOD(ZMQContext, getsocket);
ZEND_METHOD(ZMQContext, ispersistent);
#if PHP_ZMQ_HAVE_CTX_OPTIONS
ZEND_METHOD(ZMQContext, setOpt);
ZEND_METHOD(ZMQContext, getOpt);
#endif
ZEND_METHOD(ZMQSocket, __construct);
ZEND_METHOD(ZMQSocket, send);
ZEND_METHOD(ZMQSocket, recv);
ZEND_METHOD(ZMQSocket, sendmulti);
ZEND_METHOD(ZMQSocket, recvmulti);
ZEND_METHOD(ZMQSocket, bind);
ZEND_METHOD(ZMQSocket, connect);
#if PHP_ZMQ_HAVE_SOCKET_MONITOR
ZEND_METHOD(ZMQSocket, monitor);
#endif
ZEND_METHOD(ZMQSocket, recvevent);
#if PHP_ZMQ_HAVE_UNBIND
ZEND_METHOD(ZMQSocket, unbind);
#endif
#if PHP_ZMQ_HAVE_DISCONNECT
ZEND_METHOD(ZMQSocket, disconnect);
#endif
ZEND_METHOD(ZMQSocket, setsockopt);
ZEND_METHOD(ZMQSocket, getendpoints);
ZEND_METHOD(ZMQSocket, getsockettype);
ZEND_METHOD(ZMQSocket, ispersistent);
ZEND_METHOD(ZMQSocket, getpersistentid);
ZEND_METHOD(ZMQSocket, getsockopt);
ZEND_METHOD(ZMQPoll, add);
ZEND_METHOD(ZMQPoll, poll);
ZEND_METHOD(ZMQPoll, getlasterrors);
ZEND_METHOD(ZMQPoll, remove);
ZEND_METHOD(ZMQPoll, count);
ZEND_METHOD(ZMQPoll, clear);
ZEND_METHOD(ZMQPoll, items);
ZEND_METHOD(ZMQDevice, __construct);
ZEND_METHOD(ZMQDevice, run);
ZEND_METHOD(ZMQDevice, setidlecallback);
ZEND_METHOD(ZMQDevice, setidletimeout);
ZEND_METHOD(ZMQDevice, getidletimeout);
ZEND_METHOD(ZMQDevice, settimercallback);
ZEND_METHOD(ZMQDevice, settimertimeout);
ZEND_METHOD(ZMQDevice, gettimertimeout);

static const zend_function_entry class_ZMQ_methods[] = {
	ZEND_ME(ZMQ, clock, arginfo_class_ZMQ_clock, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_ZMQ_HAVE_Z85
	ZEND_ME(ZMQ, z85encode, arginfo_class_ZMQ_z85encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(ZMQ, z85decode, arginfo_class_ZMQ_z85decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if PHP_ZMQ_HAVE_CURVE_KEYPAIR
	ZEND_ME(ZMQ, curvekeypair, arginfo_class_ZMQ_curvekeypair, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	ZEND_FE_END
};

static const zend_function_entry class_ZMQContext_methods[] = {
	ZEND_ME(ZMQContext, __construct, arginfo_class_ZMQContext___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQContext, acquire, arginfo_class_ZMQContext_acquire, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(ZMQContext, getsocketcount, arginfo_class_ZMQContext_getsocketcount, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQContext, getsocket, arginfo_class_ZMQContext_getsocket, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQContext, ispersistent, arginfo_class_ZMQContext_ispersistent, ZEND_ACC_PUBLIC)
#if PHP_ZMQ_HAVE_CTX_OPTIONS
	ZEND_ME(ZMQContext, setOpt, arginfo_class_ZMQContext_setOpt, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQContext, getOpt, arginfo_class_ZMQContext_getOpt, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static const zend_function_entry class_ZMQSocket_methods[] = {
	ZEND_ME(ZMQSocket, __construct, arginfo_class_ZMQSocket___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, send, arginfo_class_ZMQSocket_send, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, recv, arginfo_class_ZMQSocket_recv, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, sendmulti, arginfo_class_ZMQSocket_sendmulti, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, recvmulti, arginfo_class_ZMQSocket_recvmulti, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, bind, arginfo_class_ZMQSocket_bind, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, connect, arginfo_class_ZMQSocket_connect, ZEND_ACC_PUBLIC)
#if PHP_ZMQ_HAVE_SOCKET_MONITOR
	ZEND_ME(ZMQSocket, monitor, arginfo_class_ZMQSocket_monitor, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(ZMQSocket, recvevent, arginfo_class_ZMQSocket_recvevent, ZEND_ACC_PUBLIC)
#if PHP_ZMQ_HAVE_UNBIND
	ZEND_ME(ZMQSocket, unbind, arginfo_class_ZMQSocket_unbind, ZEND_ACC_PUBLIC)
#endif
#if PHP_ZMQ_HAVE_DISCONNECT
	ZEND_ME(ZMQSocket, disconnect, arginfo_class_ZMQSocket_disconnect, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(ZMQSocket, setsockopt, arginfo_class_ZMQSocket_setsockopt, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, getendpoints, arginfo_class_ZMQSocket_getendpoints, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, getsockettype, arginfo_class_ZMQSocket_getsockettype, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, ispersistent, arginfo_class_ZMQSocket_ispersistent, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, getpersistentid, arginfo_class_ZMQSocket_getpersistentid, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQSocket, getsockopt, arginfo_class_ZMQSocket_getsockopt, ZEND_ACC_PUBLIC)
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY("sendmsg", zim_ZMQSocket_send, arginfo_class_ZMQSocket_sendmsg, ZEND_ACC_PUBLIC, NULL, NULL)
#else
	ZEND_RAW_FENTRY("sendmsg", zim_ZMQSocket_send, arginfo_class_ZMQSocket_sendmsg, ZEND_ACC_PUBLIC)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY("recvmsg", zim_ZMQSocket_recv, arginfo_class_ZMQSocket_recvmsg, ZEND_ACC_PUBLIC, NULL, NULL)
#else
	ZEND_RAW_FENTRY("recvmsg", zim_ZMQSocket_recv, arginfo_class_ZMQSocket_recvmsg, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static const zend_function_entry class_ZMQPoll_methods[] = {
	ZEND_ME(ZMQPoll, add, arginfo_class_ZMQPoll_add, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQPoll, poll, arginfo_class_ZMQPoll_poll, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQPoll, getlasterrors, arginfo_class_ZMQPoll_getlasterrors, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQPoll, remove, arginfo_class_ZMQPoll_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQPoll, count, arginfo_class_ZMQPoll_count, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQPoll, clear, arginfo_class_ZMQPoll_clear, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQPoll, items, arginfo_class_ZMQPoll_items, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_ZMQDevice_methods[] = {
	ZEND_ME(ZMQDevice, __construct, arginfo_class_ZMQDevice___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQDevice, run, arginfo_class_ZMQDevice_run, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQDevice, setidlecallback, arginfo_class_ZMQDevice_setidlecallback, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQDevice, setidletimeout, arginfo_class_ZMQDevice_setidletimeout, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQDevice, getidletimeout, arginfo_class_ZMQDevice_getidletimeout, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQDevice, settimercallback, arginfo_class_ZMQDevice_settimercallback, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQDevice, settimertimeout, arginfo_class_ZMQDevice_settimertimeout, ZEND_ACC_PUBLIC)
	ZEND_ME(ZMQDevice, gettimertimeout, arginfo_class_ZMQDevice_gettimertimeout, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_ZMQ(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQ", class_ZMQ_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	zval const_SOCKET_PAIR_value;
	ZVAL_LONG(&const_SOCKET_PAIR_value, ZMQ_PAIR);
	zend_string *const_SOCKET_PAIR_name = zend_string_init_interned("SOCKET_PAIR", sizeof("SOCKET_PAIR") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_PAIR_name, &const_SOCKET_PAIR_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_PAIR_name, true);

	zval const_SOCKET_PUB_value;
	ZVAL_LONG(&const_SOCKET_PUB_value, ZMQ_PUB);
	zend_string *const_SOCKET_PUB_name = zend_string_init_interned("SOCKET_PUB", sizeof("SOCKET_PUB") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_PUB_name, &const_SOCKET_PUB_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_PUB_name, true);

	zval const_SOCKET_SUB_value;
	ZVAL_LONG(&const_SOCKET_SUB_value, ZMQ_SUB);
	zend_string *const_SOCKET_SUB_name = zend_string_init_interned("SOCKET_SUB", sizeof("SOCKET_SUB") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_SUB_name, &const_SOCKET_SUB_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_SUB_name, true);

	zval const_SOCKET_REQ_value;
	ZVAL_LONG(&const_SOCKET_REQ_value, ZMQ_REQ);
	zend_string *const_SOCKET_REQ_name = zend_string_init_interned("SOCKET_REQ", sizeof("SOCKET_REQ") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_REQ_name, &const_SOCKET_REQ_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_REQ_name, true);

	zval const_SOCKET_REP_value;
	ZVAL_LONG(&const_SOCKET_REP_value, ZMQ_REP);
	zend_string *const_SOCKET_REP_name = zend_string_init_interned("SOCKET_REP", sizeof("SOCKET_REP") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_REP_name, &const_SOCKET_REP_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_REP_name, true);

	zval const_SOCKET_XREQ_value;
	ZVAL_LONG(&const_SOCKET_XREQ_value, ZMQ_XREQ);
	zend_string *const_SOCKET_XREQ_name = zend_string_init_interned("SOCKET_XREQ", sizeof("SOCKET_XREQ") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_XREQ_name, &const_SOCKET_XREQ_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_XREQ_name, true);

	zval const_SOCKET_XREP_value;
	ZVAL_LONG(&const_SOCKET_XREP_value, ZMQ_XREP);
	zend_string *const_SOCKET_XREP_name = zend_string_init_interned("SOCKET_XREP", sizeof("SOCKET_XREP") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_XREP_name, &const_SOCKET_XREP_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_XREP_name, true);

	zval const_SOCKET_PUSH_value;
	ZVAL_LONG(&const_SOCKET_PUSH_value, ZMQ_PUSH);
	zend_string *const_SOCKET_PUSH_name = zend_string_init_interned("SOCKET_PUSH", sizeof("SOCKET_PUSH") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_PUSH_name, &const_SOCKET_PUSH_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_PUSH_name, true);

	zval const_SOCKET_PULL_value;
	ZVAL_LONG(&const_SOCKET_PULL_value, ZMQ_PULL);
	zend_string *const_SOCKET_PULL_name = zend_string_init_interned("SOCKET_PULL", sizeof("SOCKET_PULL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_PULL_name, &const_SOCKET_PULL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_PULL_name, true);

	zval const_SOCKET_DEALER_value;
	ZVAL_LONG(&const_SOCKET_DEALER_value, ZMQ_DEALER);
	zend_string *const_SOCKET_DEALER_name = zend_string_init_interned("SOCKET_DEALER", sizeof("SOCKET_DEALER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_DEALER_name, &const_SOCKET_DEALER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_DEALER_name, true);

	zval const_SOCKET_ROUTER_value;
	ZVAL_LONG(&const_SOCKET_ROUTER_value, ZMQ_ROUTER);
	zend_string *const_SOCKET_ROUTER_name = zend_string_init_interned("SOCKET_ROUTER", sizeof("SOCKET_ROUTER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_ROUTER_name, &const_SOCKET_ROUTER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_ROUTER_name, true);

	zval const_SOCKET_XSUB_value;
	ZVAL_LONG(&const_SOCKET_XSUB_value, ZMQ_XSUB);
	zend_string *const_SOCKET_XSUB_name = zend_string_init_interned("SOCKET_XSUB", sizeof("SOCKET_XSUB") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_XSUB_name, &const_SOCKET_XSUB_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_XSUB_name, true);

	zval const_SOCKET_XPUB_value;
	ZVAL_LONG(&const_SOCKET_XPUB_value, ZMQ_XPUB);
	zend_string *const_SOCKET_XPUB_name = zend_string_init_interned("SOCKET_XPUB", sizeof("SOCKET_XPUB") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_XPUB_name, &const_SOCKET_XPUB_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_XPUB_name, true);

	zval const_SOCKET_STREAM_value;
	ZVAL_LONG(&const_SOCKET_STREAM_value, ZMQ_STREAM);
	zend_string *const_SOCKET_STREAM_name = zend_string_init_interned("SOCKET_STREAM", sizeof("SOCKET_STREAM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_STREAM_name, &const_SOCKET_STREAM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_STREAM_name, true);

	zval const_SOCKET_UPSTREAM_value;
	ZVAL_LONG(&const_SOCKET_UPSTREAM_value, ZMQ_PULL);
	zend_string *const_SOCKET_UPSTREAM_name = zend_string_init_interned("SOCKET_UPSTREAM", sizeof("SOCKET_UPSTREAM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_UPSTREAM_name, &const_SOCKET_UPSTREAM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_UPSTREAM_name, true);

	zval const_SOCKET_DOWNSTREAM_value;
	ZVAL_LONG(&const_SOCKET_DOWNSTREAM_value, ZMQ_PUSH);
	zend_string *const_SOCKET_DOWNSTREAM_name = zend_string_init_interned("SOCKET_DOWNSTREAM", sizeof("SOCKET_DOWNSTREAM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKET_DOWNSTREAM_name, &const_SOCKET_DOWNSTREAM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKET_DOWNSTREAM_name, true);

	zval const_POLL_IN_value;
	ZVAL_LONG(&const_POLL_IN_value, ZMQ_POLLIN);
	zend_string *const_POLL_IN_name = zend_string_init_interned("POLL_IN", sizeof("POLL_IN") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_POLL_IN_name, &const_POLL_IN_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_POLL_IN_name, true);

	zval const_POLL_OUT_value;
	ZVAL_LONG(&const_POLL_OUT_value, ZMQ_POLLOUT);
	zend_string *const_POLL_OUT_name = zend_string_init_interned("POLL_OUT", sizeof("POLL_OUT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_POLL_OUT_name, &const_POLL_OUT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_POLL_OUT_name, true);

	zval const_MODE_SNDMORE_value;
	ZVAL_LONG(&const_MODE_SNDMORE_value, ZMQ_SNDMORE);
	zend_string *const_MODE_SNDMORE_name = zend_string_init_interned("MODE_SNDMORE", sizeof("MODE_SNDMORE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_MODE_SNDMORE_name, &const_MODE_SNDMORE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_MODE_SNDMORE_name, true);

	zval const_MODE_NOBLOCK_value;
	ZVAL_LONG(&const_MODE_NOBLOCK_value, ZMQ_DONTWAIT);
	zend_string *const_MODE_NOBLOCK_name = zend_string_init_interned("MODE_NOBLOCK", sizeof("MODE_NOBLOCK") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_MODE_NOBLOCK_name, &const_MODE_NOBLOCK_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_MODE_NOBLOCK_name, true);

	zval const_MODE_DONTWAIT_value;
	ZVAL_LONG(&const_MODE_DONTWAIT_value, ZMQ_DONTWAIT);
	zend_string *const_MODE_DONTWAIT_name = zend_string_init_interned("MODE_DONTWAIT", sizeof("MODE_DONTWAIT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_MODE_DONTWAIT_name, &const_MODE_DONTWAIT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_MODE_DONTWAIT_name, true);

	zval const_ERR_INTERNAL_value;
	ZVAL_LONG(&const_ERR_INTERNAL_value, PHP_ZMQ_INTERNAL_ERROR);
	zend_string *const_ERR_INTERNAL_name = zend_string_init_interned("ERR_INTERNAL", sizeof("ERR_INTERNAL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_ERR_INTERNAL_name, &const_ERR_INTERNAL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_ERR_INTERNAL_name, true);

	zval const_ERR_EAGAIN_value;
	ZVAL_LONG(&const_ERR_EAGAIN_value, EAGAIN);
	zend_string *const_ERR_EAGAIN_name = zend_string_init_interned("ERR_EAGAIN", sizeof("ERR_EAGAIN") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_ERR_EAGAIN_name, &const_ERR_EAGAIN_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_ERR_EAGAIN_name, true);

	zval const_ERR_ENOTSUP_value;
	ZVAL_LONG(&const_ERR_ENOTSUP_value, ENOTSUP);
	zend_string *const_ERR_ENOTSUP_name = zend_string_init_interned("ERR_ENOTSUP", sizeof("ERR_ENOTSUP") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_ERR_ENOTSUP_name, &const_ERR_ENOTSUP_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_ERR_ENOTSUP_name, true);

	zval const_ERR_EFSM_value;
	ZVAL_LONG(&const_ERR_EFSM_value, EFSM);
	zend_string *const_ERR_EFSM_name = zend_string_init_interned("ERR_EFSM", sizeof("ERR_EFSM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_ERR_EFSM_name, &const_ERR_EFSM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_ERR_EFSM_name, true);

	zval const_ERR_ETERM_value;
	ZVAL_LONG(&const_ERR_ETERM_value, ETERM);
	zend_string *const_ERR_ETERM_name = zend_string_init_interned("ERR_ETERM", sizeof("ERR_ETERM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_ERR_ETERM_name, &const_ERR_ETERM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_ERR_ETERM_name, true);

	zval const_LIBZMQ_VERSION_MAJOR_value;
	ZVAL_LONG(&const_LIBZMQ_VERSION_MAJOR_value, ZMQ_VERSION_MAJOR);
	zend_string *const_LIBZMQ_VERSION_MAJOR_name = zend_string_init_interned("LIBZMQ_VERSION_MAJOR", sizeof("LIBZMQ_VERSION_MAJOR") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_LIBZMQ_VERSION_MAJOR_name, &const_LIBZMQ_VERSION_MAJOR_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_LIBZMQ_VERSION_MAJOR_name, true);

	zval const_LIBZMQ_VERSION_MINOR_value;
	ZVAL_LONG(&const_LIBZMQ_VERSION_MINOR_value, ZMQ_VERSION_MINOR);
	zend_string *const_LIBZMQ_VERSION_MINOR_name = zend_string_init_interned("LIBZMQ_VERSION_MINOR", sizeof("LIBZMQ_VERSION_MINOR") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_LIBZMQ_VERSION_MINOR_name, &const_LIBZMQ_VERSION_MINOR_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_LIBZMQ_VERSION_MINOR_name, true);

	zval const_LIBZMQ_VERSION_PATCH_value;
	ZVAL_LONG(&const_LIBZMQ_VERSION_PATCH_value, ZMQ_VERSION_PATCH);
	zend_string *const_LIBZMQ_VERSION_PATCH_name = zend_string_init_interned("LIBZMQ_VERSION_PATCH", sizeof("LIBZMQ_VERSION_PATCH") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_LIBZMQ_VERSION_PATCH_name, &const_LIBZMQ_VERSION_PATCH_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_LIBZMQ_VERSION_PATCH_name, true);
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_ONLY_FIRST_SUBSCRIBE)

	zval const_SOCKOPT_ONLY_FIRST_SUBSCRIBE_value;
	ZVAL_LONG(&const_SOCKOPT_ONLY_FIRST_SUBSCRIBE_value, ZMQ_ONLY_FIRST_SUBSCRIBE);
	zend_string *const_SOCKOPT_ONLY_FIRST_SUBSCRIBE_name = zend_string_init_interned("SOCKOPT_ONLY_FIRST_SUBSCRIBE", sizeof("SOCKOPT_ONLY_FIRST_SUBSCRIBE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_ONLY_FIRST_SUBSCRIBE_name, &const_SOCKOPT_ONLY_FIRST_SUBSCRIBE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_ONLY_FIRST_SUBSCRIBE_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_WSS_TRUST_SYSTEM)

	zval const_SOCKOPT_WSS_TRUST_SYSTEM_value;
	ZVAL_LONG(&const_SOCKOPT_WSS_TRUST_SYSTEM_value, ZMQ_WSS_TRUST_SYSTEM);
	zend_string *const_SOCKOPT_WSS_TRUST_SYSTEM_name = zend_string_init_interned("SOCKOPT_WSS_TRUST_SYSTEM", sizeof("SOCKOPT_WSS_TRUST_SYSTEM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_WSS_TRUST_SYSTEM_name, &const_SOCKOPT_WSS_TRUST_SYSTEM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_WSS_TRUST_SYSTEM_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_WSS_HOSTNAME)

	zval const_SOCKOPT_WSS_HOSTNAME_value;
	ZVAL_LONG(&const_SOCKOPT_WSS_HOSTNAME_value, ZMQ_WSS_HOSTNAME);
	zend_string *const_SOCKOPT_WSS_HOSTNAME_name = zend_string_init_interned("SOCKOPT_WSS_HOSTNAME", sizeof("SOCKOPT_WSS_HOSTNAME") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_WSS_HOSTNAME_name, &const_SOCKOPT_WSS_HOSTNAME_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_WSS_HOSTNAME_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_WSS_TRUST_PEM)

	zval const_SOCKOPT_WSS_TRUST_PEM_value;
	ZVAL_LONG(&const_SOCKOPT_WSS_TRUST_PEM_value, ZMQ_WSS_TRUST_PEM);
	zend_string *const_SOCKOPT_WSS_TRUST_PEM_name = zend_string_init_interned("SOCKOPT_WSS_TRUST_PEM", sizeof("SOCKOPT_WSS_TRUST_PEM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_WSS_TRUST_PEM_name, &const_SOCKOPT_WSS_TRUST_PEM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_WSS_TRUST_PEM_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_WSS_CERT_PEM)

	zval const_SOCKOPT_WSS_CERT_PEM_value;
	ZVAL_LONG(&const_SOCKOPT_WSS_CERT_PEM_value, ZMQ_WSS_CERT_PEM);
	zend_string *const_SOCKOPT_WSS_CERT_PEM_name = zend_string_init_interned("SOCKOPT_WSS_CERT_PEM", sizeof("SOCKOPT_WSS_CERT_PEM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_WSS_CERT_PEM_name, &const_SOCKOPT_WSS_CERT_PEM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_WSS_CERT_PEM_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_WSS_KEY_PEM)

	zval const_SOCKOPT_WSS_KEY_PEM_value;
	ZVAL_LONG(&const_SOCKOPT_WSS_KEY_PEM_value, ZMQ_WSS_KEY_PEM);
	zend_string *const_SOCKOPT_WSS_KEY_PEM_name = zend_string_init_interned("SOCKOPT_WSS_KEY_PEM", sizeof("SOCKOPT_WSS_KEY_PEM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_WSS_KEY_PEM_name, &const_SOCKOPT_WSS_KEY_PEM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_WSS_KEY_PEM_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_OUT_BATCH_SIZE)

	zval const_SOCKOPT_OUT_BATCH_SIZE_value;
	ZVAL_LONG(&const_SOCKOPT_OUT_BATCH_SIZE_value, ZMQ_OUT_BATCH_SIZE);
	zend_string *const_SOCKOPT_OUT_BATCH_SIZE_name = zend_string_init_interned("SOCKOPT_OUT_BATCH_SIZE", sizeof("SOCKOPT_OUT_BATCH_SIZE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_OUT_BATCH_SIZE_name, &const_SOCKOPT_OUT_BATCH_SIZE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_OUT_BATCH_SIZE_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_IN_BATCH_SIZE)

	zval const_SOCKOPT_IN_BATCH_SIZE_value;
	ZVAL_LONG(&const_SOCKOPT_IN_BATCH_SIZE_value, ZMQ_IN_BATCH_SIZE);
	zend_string *const_SOCKOPT_IN_BATCH_SIZE_name = zend_string_init_interned("SOCKOPT_IN_BATCH_SIZE", sizeof("SOCKOPT_IN_BATCH_SIZE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_IN_BATCH_SIZE_name, &const_SOCKOPT_IN_BATCH_SIZE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_IN_BATCH_SIZE_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_SOCKS_PASSWORD)

	zval const_SOCKOPT_SOCKS_PASSWORD_value;
	ZVAL_LONG(&const_SOCKOPT_SOCKS_PASSWORD_value, ZMQ_SOCKS_PASSWORD);
	zend_string *const_SOCKOPT_SOCKS_PASSWORD_name = zend_string_init_interned("SOCKOPT_SOCKS_PASSWORD", sizeof("SOCKOPT_SOCKS_PASSWORD") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_SOCKS_PASSWORD_name, &const_SOCKOPT_SOCKS_PASSWORD_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_SOCKS_PASSWORD_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_SOCKS_USERNAME)

	zval const_SOCKOPT_SOCKS_USERNAME_value;
	ZVAL_LONG(&const_SOCKOPT_SOCKS_USERNAME_value, ZMQ_SOCKS_USERNAME);
	zend_string *const_SOCKOPT_SOCKS_USERNAME_name = zend_string_init_interned("SOCKOPT_SOCKS_USERNAME", sizeof("SOCKOPT_SOCKS_USERNAME") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_SOCKS_USERNAME_name, &const_SOCKOPT_SOCKS_USERNAME_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_SOCKS_USERNAME_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_XPUB_MANUAL_LAST_VALUE)

	zval const_SOCKOPT_XPUB_MANUAL_LAST_VALUE_value;
	ZVAL_LONG(&const_SOCKOPT_XPUB_MANUAL_LAST_VALUE_value, ZMQ_XPUB_MANUAL_LAST_VALUE);
	zend_string *const_SOCKOPT_XPUB_MANUAL_LAST_VALUE_name = zend_string_init_interned("SOCKOPT_XPUB_MANUAL_LAST_VALUE", sizeof("SOCKOPT_XPUB_MANUAL_LAST_VALUE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_XPUB_MANUAL_LAST_VALUE_name, &const_SOCKOPT_XPUB_MANUAL_LAST_VALUE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_XPUB_MANUAL_LAST_VALUE_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_ROUTER_NOTIFY)

	zval const_SOCKOPT_ROUTER_NOTIFY_value;
	ZVAL_LONG(&const_SOCKOPT_ROUTER_NOTIFY_value, ZMQ_ROUTER_NOTIFY);
	zend_string *const_SOCKOPT_ROUTER_NOTIFY_name = zend_string_init_interned("SOCKOPT_ROUTER_NOTIFY", sizeof("SOCKOPT_ROUTER_NOTIFY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_ROUTER_NOTIFY_name, &const_SOCKOPT_ROUTER_NOTIFY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_ROUTER_NOTIFY_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_MULTICAST_LOOP)

	zval const_SOCKOPT_MULTICAST_LOOP_value;
	ZVAL_LONG(&const_SOCKOPT_MULTICAST_LOOP_value, ZMQ_MULTICAST_LOOP);
	zend_string *const_SOCKOPT_MULTICAST_LOOP_name = zend_string_init_interned("SOCKOPT_MULTICAST_LOOP", sizeof("SOCKOPT_MULTICAST_LOOP") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_MULTICAST_LOOP_name, &const_SOCKOPT_MULTICAST_LOOP_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_MULTICAST_LOOP_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_METADATA)

	zval const_SOCKOPT_METADATA_value;
	ZVAL_LONG(&const_SOCKOPT_METADATA_value, ZMQ_METADATA);
	zend_string *const_SOCKOPT_METADATA_name = zend_string_init_interned("SOCKOPT_METADATA", sizeof("SOCKOPT_METADATA") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_METADATA_name, &const_SOCKOPT_METADATA_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_METADATA_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_LOOPBACK_FASTPATH)

	zval const_SOCKOPT_LOOPBACK_FASTPATH_value;
	ZVAL_LONG(&const_SOCKOPT_LOOPBACK_FASTPATH_value, ZMQ_LOOPBACK_FASTPATH);
	zend_string *const_SOCKOPT_LOOPBACK_FASTPATH_name = zend_string_init_interned("SOCKOPT_LOOPBACK_FASTPATH", sizeof("SOCKOPT_LOOPBACK_FASTPATH") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_LOOPBACK_FASTPATH_name, &const_SOCKOPT_LOOPBACK_FASTPATH_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_LOOPBACK_FASTPATH_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_ZAP_ENFORCE_DOMAIN)

	zval const_SOCKOPT_ZAP_ENFORCE_DOMAIN_value;
	ZVAL_LONG(&const_SOCKOPT_ZAP_ENFORCE_DOMAIN_value, ZMQ_ZAP_ENFORCE_DOMAIN);
	zend_string *const_SOCKOPT_ZAP_ENFORCE_DOMAIN_name = zend_string_init_interned("SOCKOPT_ZAP_ENFORCE_DOMAIN", sizeof("SOCKOPT_ZAP_ENFORCE_DOMAIN") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_ZAP_ENFORCE_DOMAIN_name, &const_SOCKOPT_ZAP_ENFORCE_DOMAIN_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_ZAP_ENFORCE_DOMAIN_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_GSSAPI_PRINCIPAL_NAMETYPE)

	zval const_SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE_value;
	ZVAL_LONG(&const_SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE_value, ZMQ_GSSAPI_PRINCIPAL_NAMETYPE);
	zend_string *const_SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE_name = zend_string_init_interned("SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE", sizeof("SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE_name, &const_SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE)

	zval const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE_value;
	ZVAL_LONG(&const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE_value, ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE);
	zend_string *const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE_name = zend_string_init_interned("SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE", sizeof("SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE_name, &const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 3 && defined(ZMQ_BINDTODEVICE)

	zval const_SOCKOPT_BINDTODEVICE_value;
	ZVAL_LONG(&const_SOCKOPT_BINDTODEVICE_value, ZMQ_BINDTODEVICE);
	zend_string *const_SOCKOPT_BINDTODEVICE_name = zend_string_init_interned("SOCKOPT_BINDTODEVICE", sizeof("SOCKOPT_BINDTODEVICE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_BINDTODEVICE_name, &const_SOCKOPT_BINDTODEVICE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_BINDTODEVICE_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 2

	zval const_SOCKOPT_HEARTBEAT_IVL_value;
	ZVAL_LONG(&const_SOCKOPT_HEARTBEAT_IVL_value, ZMQ_HEARTBEAT_IVL);
	zend_string *const_SOCKOPT_HEARTBEAT_IVL_name = zend_string_init_interned("SOCKOPT_HEARTBEAT_IVL", sizeof("SOCKOPT_HEARTBEAT_IVL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_HEARTBEAT_IVL_name, &const_SOCKOPT_HEARTBEAT_IVL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_HEARTBEAT_IVL_name, true);

	zval const_SOCKOPT_HEARTBEAT_TTL_value;
	ZVAL_LONG(&const_SOCKOPT_HEARTBEAT_TTL_value, ZMQ_HEARTBEAT_TTL);
	zend_string *const_SOCKOPT_HEARTBEAT_TTL_name = zend_string_init_interned("SOCKOPT_HEARTBEAT_TTL", sizeof("SOCKOPT_HEARTBEAT_TTL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_HEARTBEAT_TTL_name, &const_SOCKOPT_HEARTBEAT_TTL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_HEARTBEAT_TTL_name, true);

	zval const_SOCKOPT_HEARTBEAT_TIMEOUT_value;
	ZVAL_LONG(&const_SOCKOPT_HEARTBEAT_TIMEOUT_value, ZMQ_HEARTBEAT_TIMEOUT);
	zend_string *const_SOCKOPT_HEARTBEAT_TIMEOUT_name = zend_string_init_interned("SOCKOPT_HEARTBEAT_TIMEOUT", sizeof("SOCKOPT_HEARTBEAT_TIMEOUT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_HEARTBEAT_TIMEOUT_name, &const_SOCKOPT_HEARTBEAT_TIMEOUT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_HEARTBEAT_TIMEOUT_name, true);

	zval const_SOCKOPT_USE_FD_value;
	ZVAL_LONG(&const_SOCKOPT_USE_FD_value, ZMQ_USE_FD);
	zend_string *const_SOCKOPT_USE_FD_name = zend_string_init_interned("SOCKOPT_USE_FD", sizeof("SOCKOPT_USE_FD") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_USE_FD_name, &const_SOCKOPT_USE_FD_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_USE_FD_name, true);

	zval const_SOCKOPT_XPUB_MANUAL_value;
	ZVAL_LONG(&const_SOCKOPT_XPUB_MANUAL_value, ZMQ_XPUB_MANUAL);
	zend_string *const_SOCKOPT_XPUB_MANUAL_name = zend_string_init_interned("SOCKOPT_XPUB_MANUAL", sizeof("SOCKOPT_XPUB_MANUAL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_XPUB_MANUAL_name, &const_SOCKOPT_XPUB_MANUAL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_XPUB_MANUAL_name, true);

	zval const_SOCKOPT_XPUB_WELCOME_MSG_value;
	ZVAL_LONG(&const_SOCKOPT_XPUB_WELCOME_MSG_value, ZMQ_XPUB_WELCOME_MSG);
	zend_string *const_SOCKOPT_XPUB_WELCOME_MSG_name = zend_string_init_interned("SOCKOPT_XPUB_WELCOME_MSG", sizeof("SOCKOPT_XPUB_WELCOME_MSG") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_XPUB_WELCOME_MSG_name, &const_SOCKOPT_XPUB_WELCOME_MSG_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_XPUB_WELCOME_MSG_name, true);

	zval const_SOCKOPT_STREAM_NOTIFY_value;
	ZVAL_LONG(&const_SOCKOPT_STREAM_NOTIFY_value, ZMQ_STREAM_NOTIFY);
	zend_string *const_SOCKOPT_STREAM_NOTIFY_name = zend_string_init_interned("SOCKOPT_STREAM_NOTIFY", sizeof("SOCKOPT_STREAM_NOTIFY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_STREAM_NOTIFY_name, &const_SOCKOPT_STREAM_NOTIFY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_STREAM_NOTIFY_name, true);

	zval const_SOCKOPT_INVERT_MATCHING_value;
	ZVAL_LONG(&const_SOCKOPT_INVERT_MATCHING_value, ZMQ_INVERT_MATCHING);
	zend_string *const_SOCKOPT_INVERT_MATCHING_name = zend_string_init_interned("SOCKOPT_INVERT_MATCHING", sizeof("SOCKOPT_INVERT_MATCHING") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_INVERT_MATCHING_name, &const_SOCKOPT_INVERT_MATCHING_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_INVERT_MATCHING_name, true);

	zval const_SOCKOPT_XPUB_VERBOSER_value;
	ZVAL_LONG(&const_SOCKOPT_XPUB_VERBOSER_value, ZMQ_XPUB_VERBOSER);
	zend_string *const_SOCKOPT_XPUB_VERBOSER_name = zend_string_init_interned("SOCKOPT_XPUB_VERBOSER", sizeof("SOCKOPT_XPUB_VERBOSER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_XPUB_VERBOSER_name, &const_SOCKOPT_XPUB_VERBOSER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_XPUB_VERBOSER_name, true);

	zval const_SOCKOPT_CONNECT_TIMEOUT_value;
	ZVAL_LONG(&const_SOCKOPT_CONNECT_TIMEOUT_value, ZMQ_CONNECT_TIMEOUT);
	zend_string *const_SOCKOPT_CONNECT_TIMEOUT_name = zend_string_init_interned("SOCKOPT_CONNECT_TIMEOUT", sizeof("SOCKOPT_CONNECT_TIMEOUT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_CONNECT_TIMEOUT_name, &const_SOCKOPT_CONNECT_TIMEOUT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_CONNECT_TIMEOUT_name, true);

	zval const_SOCKOPT_TCP_MAXRT_value;
	ZVAL_LONG(&const_SOCKOPT_TCP_MAXRT_value, ZMQ_TCP_MAXRT);
	zend_string *const_SOCKOPT_TCP_MAXRT_name = zend_string_init_interned("SOCKOPT_TCP_MAXRT", sizeof("SOCKOPT_TCP_MAXRT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_TCP_MAXRT_name, &const_SOCKOPT_TCP_MAXRT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_TCP_MAXRT_name, true);

	zval const_SOCKOPT_MULTICAST_MAXTPDU_value;
	ZVAL_LONG(&const_SOCKOPT_MULTICAST_MAXTPDU_value, ZMQ_MULTICAST_MAXTPDU);
	zend_string *const_SOCKOPT_MULTICAST_MAXTPDU_name = zend_string_init_interned("SOCKOPT_MULTICAST_MAXTPDU", sizeof("SOCKOPT_MULTICAST_MAXTPDU") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_MULTICAST_MAXTPDU_name, &const_SOCKOPT_MULTICAST_MAXTPDU_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_MULTICAST_MAXTPDU_name, true);

	zval const_SOCKOPT_VMCI_BUFFER_SIZE_value;
	ZVAL_LONG(&const_SOCKOPT_VMCI_BUFFER_SIZE_value, ZMQ_VMCI_BUFFER_SIZE);
	zend_string *const_SOCKOPT_VMCI_BUFFER_SIZE_name = zend_string_init_interned("SOCKOPT_VMCI_BUFFER_SIZE", sizeof("SOCKOPT_VMCI_BUFFER_SIZE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_VMCI_BUFFER_SIZE_name, &const_SOCKOPT_VMCI_BUFFER_SIZE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_VMCI_BUFFER_SIZE_name, true);

	zval const_SOCKOPT_VMCI_BUFFER_MIN_SIZE_value;
	ZVAL_LONG(&const_SOCKOPT_VMCI_BUFFER_MIN_SIZE_value, ZMQ_VMCI_BUFFER_MIN_SIZE);
	zend_string *const_SOCKOPT_VMCI_BUFFER_MIN_SIZE_name = zend_string_init_interned("SOCKOPT_VMCI_BUFFER_MIN_SIZE", sizeof("SOCKOPT_VMCI_BUFFER_MIN_SIZE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_VMCI_BUFFER_MIN_SIZE_name, &const_SOCKOPT_VMCI_BUFFER_MIN_SIZE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_VMCI_BUFFER_MIN_SIZE_name, true);

	zval const_SOCKOPT_VMCI_BUFFER_MAX_SIZE_value;
	ZVAL_LONG(&const_SOCKOPT_VMCI_BUFFER_MAX_SIZE_value, ZMQ_VMCI_BUFFER_MAX_SIZE);
	zend_string *const_SOCKOPT_VMCI_BUFFER_MAX_SIZE_name = zend_string_init_interned("SOCKOPT_VMCI_BUFFER_MAX_SIZE", sizeof("SOCKOPT_VMCI_BUFFER_MAX_SIZE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_VMCI_BUFFER_MAX_SIZE_name, &const_SOCKOPT_VMCI_BUFFER_MAX_SIZE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_VMCI_BUFFER_MAX_SIZE_name, true);

	zval const_SOCKOPT_VMCI_CONNECT_TIMEOUT_value;
	ZVAL_LONG(&const_SOCKOPT_VMCI_CONNECT_TIMEOUT_value, ZMQ_VMCI_CONNECT_TIMEOUT);
	zend_string *const_SOCKOPT_VMCI_CONNECT_TIMEOUT_name = zend_string_init_interned("SOCKOPT_VMCI_CONNECT_TIMEOUT", sizeof("SOCKOPT_VMCI_CONNECT_TIMEOUT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_VMCI_CONNECT_TIMEOUT_name, &const_SOCKOPT_VMCI_CONNECT_TIMEOUT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_VMCI_CONNECT_TIMEOUT_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && ZMQ_VERSION_MINOR >= 1

	zval const_SOCKOPT_TOS_value;
	ZVAL_LONG(&const_SOCKOPT_TOS_value, ZMQ_TOS);
	zend_string *const_SOCKOPT_TOS_name = zend_string_init_interned("SOCKOPT_TOS", sizeof("SOCKOPT_TOS") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_TOS_name, &const_SOCKOPT_TOS_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_TOS_name, true);

	zval const_ZMQ_ROUTER_HANDOVER_value;
	ZVAL_LONG(&const_ZMQ_ROUTER_HANDOVER_value, ZMQ_ROUTER_HANDOVER);
	zend_string *const_ZMQ_ROUTER_HANDOVER_name = zend_string_init_interned("ZMQ_ROUTER_HANDOVER", sizeof("ZMQ_ROUTER_HANDOVER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_ZMQ_ROUTER_HANDOVER_name, &const_ZMQ_ROUTER_HANDOVER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_ZMQ_ROUTER_HANDOVER_name, true);

	zval const_SOCKOPT_CONNECT_RID_value;
	ZVAL_LONG(&const_SOCKOPT_CONNECT_RID_value, ZMQ_CONNECT_RID);
	zend_string *const_SOCKOPT_CONNECT_RID_name = zend_string_init_interned("SOCKOPT_CONNECT_RID", sizeof("SOCKOPT_CONNECT_RID") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_CONNECT_RID_name, &const_SOCKOPT_CONNECT_RID_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_CONNECT_RID_name, true);

	zval const_SOCKOPT_HANDSHAKE_IVL_value;
	ZVAL_LONG(&const_SOCKOPT_HANDSHAKE_IVL_value, ZMQ_HANDSHAKE_IVL);
	zend_string *const_SOCKOPT_HANDSHAKE_IVL_name = zend_string_init_interned("SOCKOPT_HANDSHAKE_IVL", sizeof("SOCKOPT_HANDSHAKE_IVL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_HANDSHAKE_IVL_name, &const_SOCKOPT_HANDSHAKE_IVL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_HANDSHAKE_IVL_name, true);

	zval const_SOCKOPT_SOCKS_PROXY_value;
	ZVAL_LONG(&const_SOCKOPT_SOCKS_PROXY_value, ZMQ_SOCKS_PROXY);
	zend_string *const_SOCKOPT_SOCKS_PROXY_name = zend_string_init_interned("SOCKOPT_SOCKS_PROXY", sizeof("SOCKOPT_SOCKS_PROXY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_SOCKS_PROXY_name, &const_SOCKOPT_SOCKS_PROXY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_SOCKS_PROXY_name, true);

	zval const_SOCKOPT_XPUB_NODROP_value;
	ZVAL_LONG(&const_SOCKOPT_XPUB_NODROP_value, ZMQ_XPUB_NODROP);
	zend_string *const_SOCKOPT_XPUB_NODROP_name = zend_string_init_interned("SOCKOPT_XPUB_NODROP", sizeof("SOCKOPT_XPUB_NODROP") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_XPUB_NODROP_name, &const_SOCKOPT_XPUB_NODROP_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_XPUB_NODROP_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4

	zval const_SOCKOPT_ROUTER_MANDATORY_value;
	ZVAL_LONG(&const_SOCKOPT_ROUTER_MANDATORY_value, ZMQ_ROUTER_MANDATORY);
	zend_string *const_SOCKOPT_ROUTER_MANDATORY_name = zend_string_init_interned("SOCKOPT_ROUTER_MANDATORY", sizeof("SOCKOPT_ROUTER_MANDATORY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_ROUTER_MANDATORY_name, &const_SOCKOPT_ROUTER_MANDATORY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_ROUTER_MANDATORY_name, true);

	zval const_SOCKOPT_PROBE_ROUTER_value;
	ZVAL_LONG(&const_SOCKOPT_PROBE_ROUTER_value, ZMQ_PROBE_ROUTER);
	zend_string *const_SOCKOPT_PROBE_ROUTER_name = zend_string_init_interned("SOCKOPT_PROBE_ROUTER", sizeof("SOCKOPT_PROBE_ROUTER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_PROBE_ROUTER_name, &const_SOCKOPT_PROBE_ROUTER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_PROBE_ROUTER_name, true);

	zval const_SOCKOPT_REQ_RELAXED_value;
	ZVAL_LONG(&const_SOCKOPT_REQ_RELAXED_value, ZMQ_REQ_RELAXED);
	zend_string *const_SOCKOPT_REQ_RELAXED_name = zend_string_init_interned("SOCKOPT_REQ_RELAXED", sizeof("SOCKOPT_REQ_RELAXED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_REQ_RELAXED_name, &const_SOCKOPT_REQ_RELAXED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_REQ_RELAXED_name, true);

	zval const_SOCKOPT_REQ_CORRELATE_value;
	ZVAL_LONG(&const_SOCKOPT_REQ_CORRELATE_value, ZMQ_REQ_CORRELATE);
	zend_string *const_SOCKOPT_REQ_CORRELATE_name = zend_string_init_interned("SOCKOPT_REQ_CORRELATE", sizeof("SOCKOPT_REQ_CORRELATE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_REQ_CORRELATE_name, &const_SOCKOPT_REQ_CORRELATE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_REQ_CORRELATE_name, true);

	zval const_SOCKOPT_CONFLATE_value;
	ZVAL_LONG(&const_SOCKOPT_CONFLATE_value, ZMQ_CONFLATE);
	zend_string *const_SOCKOPT_CONFLATE_name = zend_string_init_interned("SOCKOPT_CONFLATE", sizeof("SOCKOPT_CONFLATE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_CONFLATE_name, &const_SOCKOPT_CONFLATE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_CONFLATE_name, true);

	zval const_SOCKOPT_ZAP_DOMAIN_value;
	ZVAL_LONG(&const_SOCKOPT_ZAP_DOMAIN_value, ZMQ_ZAP_DOMAIN);
	zend_string *const_SOCKOPT_ZAP_DOMAIN_name = zend_string_init_interned("SOCKOPT_ZAP_DOMAIN", sizeof("SOCKOPT_ZAP_DOMAIN") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_ZAP_DOMAIN_name, &const_SOCKOPT_ZAP_DOMAIN_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_ZAP_DOMAIN_name, true);

	zval const_SOCKOPT_MECHANISM_value;
	ZVAL_LONG(&const_SOCKOPT_MECHANISM_value, ZMQ_MECHANISM);
	zend_string *const_SOCKOPT_MECHANISM_name = zend_string_init_interned("SOCKOPT_MECHANISM", sizeof("SOCKOPT_MECHANISM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_MECHANISM_name, &const_SOCKOPT_MECHANISM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_MECHANISM_name, true);

	zval const_SOCKOPT_PLAIN_SERVER_value;
	ZVAL_LONG(&const_SOCKOPT_PLAIN_SERVER_value, ZMQ_PLAIN_SERVER);
	zend_string *const_SOCKOPT_PLAIN_SERVER_name = zend_string_init_interned("SOCKOPT_PLAIN_SERVER", sizeof("SOCKOPT_PLAIN_SERVER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_PLAIN_SERVER_name, &const_SOCKOPT_PLAIN_SERVER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_PLAIN_SERVER_name, true);

	zval const_SOCKOPT_PLAIN_USERNAME_value;
	ZVAL_LONG(&const_SOCKOPT_PLAIN_USERNAME_value, ZMQ_PLAIN_USERNAME);
	zend_string *const_SOCKOPT_PLAIN_USERNAME_name = zend_string_init_interned("SOCKOPT_PLAIN_USERNAME", sizeof("SOCKOPT_PLAIN_USERNAME") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_PLAIN_USERNAME_name, &const_SOCKOPT_PLAIN_USERNAME_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_PLAIN_USERNAME_name, true);

	zval const_SOCKOPT_PLAIN_PASSWORD_value;
	ZVAL_LONG(&const_SOCKOPT_PLAIN_PASSWORD_value, ZMQ_PLAIN_PASSWORD);
	zend_string *const_SOCKOPT_PLAIN_PASSWORD_name = zend_string_init_interned("SOCKOPT_PLAIN_PASSWORD", sizeof("SOCKOPT_PLAIN_PASSWORD") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_PLAIN_PASSWORD_name, &const_SOCKOPT_PLAIN_PASSWORD_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_PLAIN_PASSWORD_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && defined(ZMQ_CURVE_SERVER)

	zval const_SOCKOPT_CURVE_SERVER_value;
	ZVAL_LONG(&const_SOCKOPT_CURVE_SERVER_value, ZMQ_CURVE_SERVER);
	zend_string *const_SOCKOPT_CURVE_SERVER_name = zend_string_init_interned("SOCKOPT_CURVE_SERVER", sizeof("SOCKOPT_CURVE_SERVER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_CURVE_SERVER_name, &const_SOCKOPT_CURVE_SERVER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_CURVE_SERVER_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && defined(ZMQ_CURVE_PUBLICKEY)

	zval const_SOCKOPT_CURVE_PUBLICKEY_value;
	ZVAL_LONG(&const_SOCKOPT_CURVE_PUBLICKEY_value, ZMQ_CURVE_PUBLICKEY);
	zend_string *const_SOCKOPT_CURVE_PUBLICKEY_name = zend_string_init_interned("SOCKOPT_CURVE_PUBLICKEY", sizeof("SOCKOPT_CURVE_PUBLICKEY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_CURVE_PUBLICKEY_name, &const_SOCKOPT_CURVE_PUBLICKEY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_CURVE_PUBLICKEY_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && defined(ZMQ_CURVE_SECRETKEY)

	zval const_SOCKOPT_CURVE_SECRETKEY_value;
	ZVAL_LONG(&const_SOCKOPT_CURVE_SECRETKEY_value, ZMQ_CURVE_SECRETKEY);
	zend_string *const_SOCKOPT_CURVE_SECRETKEY_name = zend_string_init_interned("SOCKOPT_CURVE_SECRETKEY", sizeof("SOCKOPT_CURVE_SECRETKEY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_CURVE_SECRETKEY_name, &const_SOCKOPT_CURVE_SECRETKEY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_CURVE_SECRETKEY_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && defined(ZMQ_CURVE_SERVERKEY)

	zval const_SOCKOPT_CURVE_SERVERKEY_value;
	ZVAL_LONG(&const_SOCKOPT_CURVE_SERVERKEY_value, ZMQ_CURVE_SERVERKEY);
	zend_string *const_SOCKOPT_CURVE_SERVERKEY_name = zend_string_init_interned("SOCKOPT_CURVE_SERVERKEY", sizeof("SOCKOPT_CURVE_SERVERKEY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_CURVE_SERVERKEY_name, &const_SOCKOPT_CURVE_SERVERKEY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_CURVE_SERVERKEY_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && defined(ZMQ_GSSAPI_SERVER)

	zval const_SOCKOPT_GSSAPI_SERVER_value;
	ZVAL_LONG(&const_SOCKOPT_GSSAPI_SERVER_value, ZMQ_GSSAPI_SERVER);
	zend_string *const_SOCKOPT_GSSAPI_SERVER_name = zend_string_init_interned("SOCKOPT_GSSAPI_SERVER", sizeof("SOCKOPT_GSSAPI_SERVER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_GSSAPI_SERVER_name, &const_SOCKOPT_GSSAPI_SERVER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_GSSAPI_SERVER_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && defined(ZMQ_GSSAPI_PLAINTEXT)

	zval const_SOCKOPT_GSSAPI_PLAINTEXT_value;
	ZVAL_LONG(&const_SOCKOPT_GSSAPI_PLAINTEXT_value, ZMQ_GSSAPI_PLAINTEXT);
	zend_string *const_SOCKOPT_GSSAPI_PLAINTEXT_name = zend_string_init_interned("SOCKOPT_GSSAPI_PLAINTEXT", sizeof("SOCKOPT_GSSAPI_PLAINTEXT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_GSSAPI_PLAINTEXT_name, &const_SOCKOPT_GSSAPI_PLAINTEXT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_GSSAPI_PLAINTEXT_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && defined(ZMQ_GSSAPI_PRINCIPAL)

	zval const_SOCKOPT_GSSAPI_PRINCIPAL_value;
	ZVAL_LONG(&const_SOCKOPT_GSSAPI_PRINCIPAL_value, ZMQ_GSSAPI_PRINCIPAL);
	zend_string *const_SOCKOPT_GSSAPI_PRINCIPAL_name = zend_string_init_interned("SOCKOPT_GSSAPI_PRINCIPAL", sizeof("SOCKOPT_GSSAPI_PRINCIPAL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_GSSAPI_PRINCIPAL_name, &const_SOCKOPT_GSSAPI_PRINCIPAL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_GSSAPI_PRINCIPAL_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4 && defined(ZMQ_GSSAPI_SERVICE_PRINCIPAL)

	zval const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_value;
	ZVAL_LONG(&const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_value, ZMQ_GSSAPI_SERVICE_PRINCIPAL);
	zend_string *const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_name = zend_string_init_interned("SOCKOPT_GSSAPI_SERVICE_PRINCIPAL", sizeof("SOCKOPT_GSSAPI_SERVICE_PRINCIPAL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_name, &const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_name, true);
#endif
#if ZMQ_VERSION_MAJOR == 4

	zval const_SOCKOPT_IPV6_value;
	ZVAL_LONG(&const_SOCKOPT_IPV6_value, ZMQ_IPV6);
	zend_string *const_SOCKOPT_IPV6_name = zend_string_init_interned("SOCKOPT_IPV6", sizeof("SOCKOPT_IPV6") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_IPV6_name, &const_SOCKOPT_IPV6_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_IPV6_name, true);

	zval const_SOCKOPT_IMMEDIATE_value;
	ZVAL_LONG(&const_SOCKOPT_IMMEDIATE_value, ZMQ_IMMEDIATE);
	zend_string *const_SOCKOPT_IMMEDIATE_name = zend_string_init_interned("SOCKOPT_IMMEDIATE", sizeof("SOCKOPT_IMMEDIATE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_IMMEDIATE_name, &const_SOCKOPT_IMMEDIATE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_IMMEDIATE_name, true);
#endif

	zval const_SOCKOPT_SNDHWM_value;
	ZVAL_LONG(&const_SOCKOPT_SNDHWM_value, ZMQ_SNDHWM);
	zend_string *const_SOCKOPT_SNDHWM_name = zend_string_init_interned("SOCKOPT_SNDHWM", sizeof("SOCKOPT_SNDHWM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_SNDHWM_name, &const_SOCKOPT_SNDHWM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_SNDHWM_name, true);

	zval const_SOCKOPT_RCVHWM_value;
	ZVAL_LONG(&const_SOCKOPT_RCVHWM_value, ZMQ_RCVHWM);
	zend_string *const_SOCKOPT_RCVHWM_name = zend_string_init_interned("SOCKOPT_RCVHWM", sizeof("SOCKOPT_RCVHWM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_RCVHWM_name, &const_SOCKOPT_RCVHWM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_RCVHWM_name, true);

	zval const_SOCKOPT_MAXMSGSIZE_value;
	ZVAL_LONG(&const_SOCKOPT_MAXMSGSIZE_value, ZMQ_MAXMSGSIZE);
	zend_string *const_SOCKOPT_MAXMSGSIZE_name = zend_string_init_interned("SOCKOPT_MAXMSGSIZE", sizeof("SOCKOPT_MAXMSGSIZE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_MAXMSGSIZE_name, &const_SOCKOPT_MAXMSGSIZE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_MAXMSGSIZE_name, true);

	zval const_SOCKOPT_MULTICAST_HOPS_value;
	ZVAL_LONG(&const_SOCKOPT_MULTICAST_HOPS_value, ZMQ_MULTICAST_HOPS);
	zend_string *const_SOCKOPT_MULTICAST_HOPS_name = zend_string_init_interned("SOCKOPT_MULTICAST_HOPS", sizeof("SOCKOPT_MULTICAST_HOPS") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_MULTICAST_HOPS_name, &const_SOCKOPT_MULTICAST_HOPS_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_MULTICAST_HOPS_name, true);

	zval const_SOCKOPT_XPUB_VERBOSE_value;
	ZVAL_LONG(&const_SOCKOPT_XPUB_VERBOSE_value, ZMQ_XPUB_VERBOSE);
	zend_string *const_SOCKOPT_XPUB_VERBOSE_name = zend_string_init_interned("SOCKOPT_XPUB_VERBOSE", sizeof("SOCKOPT_XPUB_VERBOSE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_XPUB_VERBOSE_name, &const_SOCKOPT_XPUB_VERBOSE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_XPUB_VERBOSE_name, true);

	zval const_SOCKOPT_TCP_KEEPALIVE_value;
	ZVAL_LONG(&const_SOCKOPT_TCP_KEEPALIVE_value, ZMQ_TCP_KEEPALIVE);
	zend_string *const_SOCKOPT_TCP_KEEPALIVE_name = zend_string_init_interned("SOCKOPT_TCP_KEEPALIVE", sizeof("SOCKOPT_TCP_KEEPALIVE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_TCP_KEEPALIVE_name, &const_SOCKOPT_TCP_KEEPALIVE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_TCP_KEEPALIVE_name, true);

	zval const_SOCKOPT_TCP_KEEPALIVE_IDLE_value;
	ZVAL_LONG(&const_SOCKOPT_TCP_KEEPALIVE_IDLE_value, ZMQ_TCP_KEEPALIVE_IDLE);
	zend_string *const_SOCKOPT_TCP_KEEPALIVE_IDLE_name = zend_string_init_interned("SOCKOPT_TCP_KEEPALIVE_IDLE", sizeof("SOCKOPT_TCP_KEEPALIVE_IDLE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_TCP_KEEPALIVE_IDLE_name, &const_SOCKOPT_TCP_KEEPALIVE_IDLE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_TCP_KEEPALIVE_IDLE_name, true);

	zval const_SOCKOPT_TCP_KEEPALIVE_CNT_value;
	ZVAL_LONG(&const_SOCKOPT_TCP_KEEPALIVE_CNT_value, ZMQ_TCP_KEEPALIVE_CNT);
	zend_string *const_SOCKOPT_TCP_KEEPALIVE_CNT_name = zend_string_init_interned("SOCKOPT_TCP_KEEPALIVE_CNT", sizeof("SOCKOPT_TCP_KEEPALIVE_CNT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_TCP_KEEPALIVE_CNT_name, &const_SOCKOPT_TCP_KEEPALIVE_CNT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_TCP_KEEPALIVE_CNT_name, true);

	zval const_SOCKOPT_TCP_KEEPALIVE_INTVL_value;
	ZVAL_LONG(&const_SOCKOPT_TCP_KEEPALIVE_INTVL_value, ZMQ_TCP_KEEPALIVE_INTVL);
	zend_string *const_SOCKOPT_TCP_KEEPALIVE_INTVL_name = zend_string_init_interned("SOCKOPT_TCP_KEEPALIVE_INTVL", sizeof("SOCKOPT_TCP_KEEPALIVE_INTVL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_TCP_KEEPALIVE_INTVL_name, &const_SOCKOPT_TCP_KEEPALIVE_INTVL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_TCP_KEEPALIVE_INTVL_name, true);

	zval const_SOCKOPT_TCP_ACCEPT_FILTER_value;
	ZVAL_LONG(&const_SOCKOPT_TCP_ACCEPT_FILTER_value, ZMQ_TCP_ACCEPT_FILTER);
	zend_string *const_SOCKOPT_TCP_ACCEPT_FILTER_name = zend_string_init_interned("SOCKOPT_TCP_ACCEPT_FILTER", sizeof("SOCKOPT_TCP_ACCEPT_FILTER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_TCP_ACCEPT_FILTER_name, &const_SOCKOPT_TCP_ACCEPT_FILTER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_TCP_ACCEPT_FILTER_name, true);

	zval const_SOCKOPT_LAST_ENDPOINT_value;
	ZVAL_LONG(&const_SOCKOPT_LAST_ENDPOINT_value, ZMQ_LAST_ENDPOINT);
	zend_string *const_SOCKOPT_LAST_ENDPOINT_name = zend_string_init_interned("SOCKOPT_LAST_ENDPOINT", sizeof("SOCKOPT_LAST_ENDPOINT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_LAST_ENDPOINT_name, &const_SOCKOPT_LAST_ENDPOINT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_LAST_ENDPOINT_name, true);

	zval const_SOCKOPT_ROUTER_RAW_value;
	ZVAL_LONG(&const_SOCKOPT_ROUTER_RAW_value, ZMQ_ROUTER_RAW);
	zend_string *const_SOCKOPT_ROUTER_RAW_name = zend_string_init_interned("SOCKOPT_ROUTER_RAW", sizeof("SOCKOPT_ROUTER_RAW") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_ROUTER_RAW_name, &const_SOCKOPT_ROUTER_RAW_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_ROUTER_RAW_name, true);

	zval const_SOCKOPT_IPV4ONLY_value;
	ZVAL_LONG(&const_SOCKOPT_IPV4ONLY_value, ZMQ_IPV4ONLY);
	zend_string *const_SOCKOPT_IPV4ONLY_name = zend_string_init_interned("SOCKOPT_IPV4ONLY", sizeof("SOCKOPT_IPV4ONLY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_IPV4ONLY_name, &const_SOCKOPT_IPV4ONLY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_IPV4ONLY_name, true);

	zval const_SOCKOPT_DELAY_ATTACH_ON_CONNECT_value;
	ZVAL_LONG(&const_SOCKOPT_DELAY_ATTACH_ON_CONNECT_value, ZMQ_DELAY_ATTACH_ON_CONNECT);
	zend_string *const_SOCKOPT_DELAY_ATTACH_ON_CONNECT_name = zend_string_init_interned("SOCKOPT_DELAY_ATTACH_ON_CONNECT", sizeof("SOCKOPT_DELAY_ATTACH_ON_CONNECT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_DELAY_ATTACH_ON_CONNECT_name, &const_SOCKOPT_DELAY_ATTACH_ON_CONNECT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_DELAY_ATTACH_ON_CONNECT_name, true);

	zval const_SOCKOPT_HWM_value;
	ZVAL_LONG(&const_SOCKOPT_HWM_value, ZMQ_HWM);
	zend_string *const_SOCKOPT_HWM_name = zend_string_init_interned("SOCKOPT_HWM", sizeof("SOCKOPT_HWM") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_HWM_name, &const_SOCKOPT_HWM_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_HWM_name, true);

	zval const_SOCKOPT_AFFINITY_value;
	ZVAL_LONG(&const_SOCKOPT_AFFINITY_value, ZMQ_AFFINITY);
	zend_string *const_SOCKOPT_AFFINITY_name = zend_string_init_interned("SOCKOPT_AFFINITY", sizeof("SOCKOPT_AFFINITY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_AFFINITY_name, &const_SOCKOPT_AFFINITY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_AFFINITY_name, true);

	zval const_SOCKOPT_IDENTITY_value;
	ZVAL_LONG(&const_SOCKOPT_IDENTITY_value, ZMQ_IDENTITY);
	zend_string *const_SOCKOPT_IDENTITY_name = zend_string_init_interned("SOCKOPT_IDENTITY", sizeof("SOCKOPT_IDENTITY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_IDENTITY_name, &const_SOCKOPT_IDENTITY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_IDENTITY_name, true);

	zval const_SOCKOPT_RECOVERY_IVL_value;
	ZVAL_LONG(&const_SOCKOPT_RECOVERY_IVL_value, ZMQ_RECOVERY_IVL);
	zend_string *const_SOCKOPT_RECOVERY_IVL_name = zend_string_init_interned("SOCKOPT_RECOVERY_IVL", sizeof("SOCKOPT_RECOVERY_IVL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_RECOVERY_IVL_name, &const_SOCKOPT_RECOVERY_IVL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_RECOVERY_IVL_name, true);

	zval const_SOCKOPT_RCVTIMEO_value;
	ZVAL_LONG(&const_SOCKOPT_RCVTIMEO_value, ZMQ_RCVTIMEO);
	zend_string *const_SOCKOPT_RCVTIMEO_name = zend_string_init_interned("SOCKOPT_RCVTIMEO", sizeof("SOCKOPT_RCVTIMEO") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_RCVTIMEO_name, &const_SOCKOPT_RCVTIMEO_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_RCVTIMEO_name, true);

	zval const_SOCKOPT_SNDTIMEO_value;
	ZVAL_LONG(&const_SOCKOPT_SNDTIMEO_value, ZMQ_SNDTIMEO);
	zend_string *const_SOCKOPT_SNDTIMEO_name = zend_string_init_interned("SOCKOPT_SNDTIMEO", sizeof("SOCKOPT_SNDTIMEO") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_SNDTIMEO_name, &const_SOCKOPT_SNDTIMEO_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_SNDTIMEO_name, true);

	zval const_SOCKOPT_SNDBUF_value;
	ZVAL_LONG(&const_SOCKOPT_SNDBUF_value, ZMQ_SNDBUF);
	zend_string *const_SOCKOPT_SNDBUF_name = zend_string_init_interned("SOCKOPT_SNDBUF", sizeof("SOCKOPT_SNDBUF") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_SNDBUF_name, &const_SOCKOPT_SNDBUF_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_SNDBUF_name, true);

	zval const_SOCKOPT_RCVBUF_value;
	ZVAL_LONG(&const_SOCKOPT_RCVBUF_value, ZMQ_RCVBUF);
	zend_string *const_SOCKOPT_RCVBUF_name = zend_string_init_interned("SOCKOPT_RCVBUF", sizeof("SOCKOPT_RCVBUF") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_RCVBUF_name, &const_SOCKOPT_RCVBUF_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_RCVBUF_name, true);

	zval const_SOCKOPT_LINGER_value;
	ZVAL_LONG(&const_SOCKOPT_LINGER_value, ZMQ_LINGER);
	zend_string *const_SOCKOPT_LINGER_name = zend_string_init_interned("SOCKOPT_LINGER", sizeof("SOCKOPT_LINGER") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_LINGER_name, &const_SOCKOPT_LINGER_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_LINGER_name, true);

	zval const_SOCKOPT_RECONNECT_IVL_value;
	ZVAL_LONG(&const_SOCKOPT_RECONNECT_IVL_value, ZMQ_RECONNECT_IVL);
	zend_string *const_SOCKOPT_RECONNECT_IVL_name = zend_string_init_interned("SOCKOPT_RECONNECT_IVL", sizeof("SOCKOPT_RECONNECT_IVL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_RECONNECT_IVL_name, &const_SOCKOPT_RECONNECT_IVL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_RECONNECT_IVL_name, true);

	zval const_SOCKOPT_RECONNECT_IVL_MAX_value;
	ZVAL_LONG(&const_SOCKOPT_RECONNECT_IVL_MAX_value, ZMQ_RECONNECT_IVL_MAX);
	zend_string *const_SOCKOPT_RECONNECT_IVL_MAX_name = zend_string_init_interned("SOCKOPT_RECONNECT_IVL_MAX", sizeof("SOCKOPT_RECONNECT_IVL_MAX") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_RECONNECT_IVL_MAX_name, &const_SOCKOPT_RECONNECT_IVL_MAX_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_RECONNECT_IVL_MAX_name, true);

	zval const_SOCKOPT_BACKLOG_value;
	ZVAL_LONG(&const_SOCKOPT_BACKLOG_value, ZMQ_BACKLOG);
	zend_string *const_SOCKOPT_BACKLOG_name = zend_string_init_interned("SOCKOPT_BACKLOG", sizeof("SOCKOPT_BACKLOG") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_BACKLOG_name, &const_SOCKOPT_BACKLOG_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_BACKLOG_name, true);

	zval const_SOCKOPT_SUBSCRIBE_value;
	ZVAL_LONG(&const_SOCKOPT_SUBSCRIBE_value, ZMQ_SUBSCRIBE);
	zend_string *const_SOCKOPT_SUBSCRIBE_name = zend_string_init_interned("SOCKOPT_SUBSCRIBE", sizeof("SOCKOPT_SUBSCRIBE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_SUBSCRIBE_name, &const_SOCKOPT_SUBSCRIBE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_SUBSCRIBE_name, true);

	zval const_SOCKOPT_UNSUBSCRIBE_value;
	ZVAL_LONG(&const_SOCKOPT_UNSUBSCRIBE_value, ZMQ_UNSUBSCRIBE);
	zend_string *const_SOCKOPT_UNSUBSCRIBE_name = zend_string_init_interned("SOCKOPT_UNSUBSCRIBE", sizeof("SOCKOPT_UNSUBSCRIBE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_UNSUBSCRIBE_name, &const_SOCKOPT_UNSUBSCRIBE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_UNSUBSCRIBE_name, true);

	zval const_SOCKOPT_TYPE_value;
	ZVAL_LONG(&const_SOCKOPT_TYPE_value, ZMQ_TYPE);
	zend_string *const_SOCKOPT_TYPE_name = zend_string_init_interned("SOCKOPT_TYPE", sizeof("SOCKOPT_TYPE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_TYPE_name, &const_SOCKOPT_TYPE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_TYPE_name, true);

	zval const_SOCKOPT_RCVMORE_value;
	ZVAL_LONG(&const_SOCKOPT_RCVMORE_value, ZMQ_RCVMORE);
	zend_string *const_SOCKOPT_RCVMORE_name = zend_string_init_interned("SOCKOPT_RCVMORE", sizeof("SOCKOPT_RCVMORE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_RCVMORE_name, &const_SOCKOPT_RCVMORE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_RCVMORE_name, true);

	zval const_SOCKOPT_EVENTS_value;
	ZVAL_LONG(&const_SOCKOPT_EVENTS_value, ZMQ_EVENTS);
	zend_string *const_SOCKOPT_EVENTS_name = zend_string_init_interned("SOCKOPT_EVENTS", sizeof("SOCKOPT_EVENTS") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SOCKOPT_EVENTS_name, &const_SOCKOPT_EVENTS_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SOCKOPT_EVENTS_name, true);

	zval const_EVENT_CONNECTED_value;
	ZVAL_LONG(&const_EVENT_CONNECTED_value, ZMQ_EVENT_CONNECTED);
	zend_string *const_EVENT_CONNECTED_name = zend_string_init_interned("EVENT_CONNECTED", sizeof("EVENT_CONNECTED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_CONNECTED_name, &const_EVENT_CONNECTED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_CONNECTED_name, true);

	zval const_EVENT_CONNECT_DELAYED_value;
	ZVAL_LONG(&const_EVENT_CONNECT_DELAYED_value, ZMQ_EVENT_CONNECT_DELAYED);
	zend_string *const_EVENT_CONNECT_DELAYED_name = zend_string_init_interned("EVENT_CONNECT_DELAYED", sizeof("EVENT_CONNECT_DELAYED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_CONNECT_DELAYED_name, &const_EVENT_CONNECT_DELAYED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_CONNECT_DELAYED_name, true);

	zval const_EVENT_CONNECT_RETRIED_value;
	ZVAL_LONG(&const_EVENT_CONNECT_RETRIED_value, ZMQ_EVENT_CONNECT_RETRIED);
	zend_string *const_EVENT_CONNECT_RETRIED_name = zend_string_init_interned("EVENT_CONNECT_RETRIED", sizeof("EVENT_CONNECT_RETRIED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_CONNECT_RETRIED_name, &const_EVENT_CONNECT_RETRIED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_CONNECT_RETRIED_name, true);

	zval const_EVENT_LISTENING_value;
	ZVAL_LONG(&const_EVENT_LISTENING_value, ZMQ_EVENT_LISTENING);
	zend_string *const_EVENT_LISTENING_name = zend_string_init_interned("EVENT_LISTENING", sizeof("EVENT_LISTENING") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_LISTENING_name, &const_EVENT_LISTENING_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_LISTENING_name, true);

	zval const_EVENT_BIND_FAILED_value;
	ZVAL_LONG(&const_EVENT_BIND_FAILED_value, ZMQ_EVENT_BIND_FAILED);
	zend_string *const_EVENT_BIND_FAILED_name = zend_string_init_interned("EVENT_BIND_FAILED", sizeof("EVENT_BIND_FAILED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_BIND_FAILED_name, &const_EVENT_BIND_FAILED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_BIND_FAILED_name, true);

	zval const_EVENT_ACCEPTED_value;
	ZVAL_LONG(&const_EVENT_ACCEPTED_value, ZMQ_EVENT_ACCEPTED);
	zend_string *const_EVENT_ACCEPTED_name = zend_string_init_interned("EVENT_ACCEPTED", sizeof("EVENT_ACCEPTED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_ACCEPTED_name, &const_EVENT_ACCEPTED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_ACCEPTED_name, true);

	zval const_EVENT_ACCEPT_FAILED_value;
	ZVAL_LONG(&const_EVENT_ACCEPT_FAILED_value, ZMQ_EVENT_ACCEPT_FAILED);
	zend_string *const_EVENT_ACCEPT_FAILED_name = zend_string_init_interned("EVENT_ACCEPT_FAILED", sizeof("EVENT_ACCEPT_FAILED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_ACCEPT_FAILED_name, &const_EVENT_ACCEPT_FAILED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_ACCEPT_FAILED_name, true);

	zval const_EVENT_CLOSED_value;
	ZVAL_LONG(&const_EVENT_CLOSED_value, ZMQ_EVENT_CLOSED);
	zend_string *const_EVENT_CLOSED_name = zend_string_init_interned("EVENT_CLOSED", sizeof("EVENT_CLOSED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_CLOSED_name, &const_EVENT_CLOSED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_CLOSED_name, true);

	zval const_EVENT_CLOSE_FAILED_value;
	ZVAL_LONG(&const_EVENT_CLOSE_FAILED_value, ZMQ_EVENT_CLOSE_FAILED);
	zend_string *const_EVENT_CLOSE_FAILED_name = zend_string_init_interned("EVENT_CLOSE_FAILED", sizeof("EVENT_CLOSE_FAILED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_CLOSE_FAILED_name, &const_EVENT_CLOSE_FAILED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_CLOSE_FAILED_name, true);

	zval const_EVENT_DISCONNECTED_value;
	ZVAL_LONG(&const_EVENT_DISCONNECTED_value, ZMQ_EVENT_DISCONNECTED);
	zend_string *const_EVENT_DISCONNECTED_name = zend_string_init_interned("EVENT_DISCONNECTED", sizeof("EVENT_DISCONNECTED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_DISCONNECTED_name, &const_EVENT_DISCONNECTED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_DISCONNECTED_name, true);

	zval const_EVENT_MONITOR_STOPPED_value;
	ZVAL_LONG(&const_EVENT_MONITOR_STOPPED_value, ZMQ_EVENT_MONITOR_STOPPED);
	zend_string *const_EVENT_MONITOR_STOPPED_name = zend_string_init_interned("EVENT_MONITOR_STOPPED", sizeof("EVENT_MONITOR_STOPPED") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_MONITOR_STOPPED_name, &const_EVENT_MONITOR_STOPPED_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_MONITOR_STOPPED_name, true);

	zval const_EVENT_ALL_value;
	ZVAL_LONG(&const_EVENT_ALL_value, ZMQ_EVENT_ALL);
	zend_string *const_EVENT_ALL_name = zend_string_init_interned("EVENT_ALL", sizeof("EVENT_ALL") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_EVENT_ALL_name, &const_EVENT_ALL_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_EVENT_ALL_name, true);

	return class_entry;
}

static zend_class_entry *register_class_ZMQContext(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQContext", class_ZMQContext_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}

static zend_class_entry *register_class_ZMQSocket(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQSocket", class_ZMQSocket_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}

static zend_class_entry *register_class_ZMQPoll(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQPoll", class_ZMQPoll_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}

static zend_class_entry *register_class_ZMQDevice(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQDevice", class_ZMQDevice_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}

static zend_class_entry *register_class_ZMQException(zend_class_entry *class_entry_Exception)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQException", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Exception, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Exception);
#endif

	return class_entry;
}

static zend_class_entry *register_class_ZMQContextException(zend_class_entry *class_entry_ZMQException)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQContextException", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_ZMQException, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ZMQException);
#endif

	return class_entry;
}

static zend_class_entry *register_class_ZMQSocketException(zend_class_entry *class_entry_ZMQException)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQSocketException", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_ZMQException, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ZMQException);
#endif

	return class_entry;
}

static zend_class_entry *register_class_ZMQPollException(zend_class_entry *class_entry_ZMQException)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQPollException", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_ZMQException, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ZMQException);
#endif

	return class_entry;
}

static zend_class_entry *register_class_ZMQDeviceException(zend_class_entry *class_entry_ZMQException)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ZMQDeviceException", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_ZMQException, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_ZMQException);
#endif

	return class_entry;
}
