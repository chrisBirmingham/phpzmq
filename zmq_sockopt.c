/*
+-----------------------------------------------------------------------------------+
|  ZMQ extension for PHP                                                            |
|  Copyright (c) 2010-2020, Mikko Koppanen <mkoppanen@php.net>                      |
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
#include "zend_types.h"
#include <sys/socket.h>
#include <zmq.h>

#define SOCKOPTS_GET_INT(NAME, TYPE) \
{ \
  TYPE value; \
  value_len = sizeof(TYPE); \
  if (zmq_getsockopt(z_socket, (int)key, &value, &value_len) != 0) { \
    zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get(), errno, \
            "Failed to get the option ZMQ::SOCKOPT_" #NAME" value: %s", zmq_strerror(errno)); \
    return FAILURE; \
  } \
  ZVAL_LONG(retval, value); \
  return SUCCESS; \
}

#define SOCKOPTS_GET_STRING(NAME, LEN, BINARY) \
{ \
  char value[LEN]; \
  value_len = LEN; \
  if (zmq_getsockopt(z_socket, (int)key, &value, &value_len) != 0) { \
    zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get(), errno, \
            "Failed to get the option ZMQ::SOCKOPT_" #NAME " value: %s", zmq_strerror(errno)); \
    return FAILURE; \
  } \
  ZVAL_STRINGL(retval, value, (BINARY == 1) ? value_len : value_len - 1); \
  return SUCCESS; \
}

/* {{{ proto mixed ZMQSocket::getSockOpt()
    Get a socket option
*/
zend_result php_zmq_socket_getsockopt(void *z_socket, int socket_type, zend_long key, zval *retval)
{
    size_t value_len;

    if (key > INT_MAX) {
        zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get (), PHP_ZMQ_INTERNAL_ERROR, "The key must be smaller than or equal to %d", INT_MAX);
        return FAILURE;
    }

#if (ZMQ_VERSION_MAJOR >= 4)
#   if (ZMQ_VERSION_MINOR >= 3)

    switch (key) {
# ifdef ZMQ_ONLY_FIRST_SUBSCRIBE

        case ZMQ_ONLY_FIRST_SUBSCRIBE:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_ONLY_FIRST_SUBSCRIBE is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_ONLY_FIRST_SUBSCRIBE */
# ifdef ZMQ_WSS_TRUST_SYSTEM

        case ZMQ_WSS_TRUST_SYSTEM:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_WSS_TRUST_SYSTEM is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_WSS_TRUST_SYSTEM */
# ifdef ZMQ_WSS_HOSTNAME

        case ZMQ_WSS_HOSTNAME:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_WSS_HOSTNAME is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_WSS_HOSTNAME */
# ifdef ZMQ_WSS_TRUST_PEM

        case ZMQ_WSS_TRUST_PEM:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_WSS_TRUST_PEM is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_WSS_TRUST_PEM */
# ifdef ZMQ_WSS_CERT_PEM

        case ZMQ_WSS_CERT_PEM:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_WSS_CERT_PEM is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_WSS_CERT_PEM */
# ifdef ZMQ_WSS_KEY_PEM

        case ZMQ_WSS_KEY_PEM:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_WSS_KEY_PEM is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_WSS_KEY_PEM */
# ifdef ZMQ_OUT_BATCH_SIZE

        case ZMQ_OUT_BATCH_SIZE:
	        SOCKOPTS_GET_INT(OUT_BATCH_SIZE, int);
# endif /* ZMQ_OUT_BATCH_SIZE */
# ifdef ZMQ_IN_BATCH_SIZE

        case ZMQ_IN_BATCH_SIZE:
	        SOCKOPTS_GET_INT(IN_BATCH_SIZE, int);
# endif /* ZMQ_IN_BATCH_SIZE */
# ifdef ZMQ_SOCKS_PASSWORD

        case ZMQ_SOCKS_PASSWORD:
	        SOCKOPTS_GET_STRING(SOCKS_PASSWORD, 255, 0)
# endif /* ZMQ_SOCKS_PASSWORD */
# ifdef ZMQ_SOCKS_USERNAME

        case ZMQ_SOCKS_USERNAME:
	        SOCKOPTS_GET_STRING(SOCKS_USERNAME, 255, 0)
# endif /* ZMQ_SOCKS_USERNAME */
# ifdef ZMQ_XPUB_MANUAL_LAST_VALUE

        case ZMQ_XPUB_MANUAL_LAST_VALUE:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_XPUB_MANUAL_LAST_VALUE is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_XPUB_MANUAL_LAST_VALUE */
# ifdef ZMQ_ROUTER_NOTIFY

        case ZMQ_ROUTER_NOTIFY:
	        SOCKOPTS_GET_INT(ROUTER_NOTIFY, int);
# endif /* ZMQ_ROUTER_NOTIFY */
# ifdef ZMQ_MULTICAST_LOOP

        case ZMQ_MULTICAST_LOOP:
	        SOCKOPTS_GET_INT(MULTICAST_LOOP, int);
# endif /* ZMQ_MULTICAST_LOOP */
# ifdef ZMQ_METADATA

        case ZMQ_METADATA:
	        SOCKOPTS_GET_STRING(METADATA, 255, 0)
# endif /* ZMQ_METADATA */
# ifdef ZMQ_LOOPBACK_FASTPATH

        case ZMQ_LOOPBACK_FASTPATH:
	        SOCKOPTS_GET_INT(LOOPBACK_FASTPATH, int);
# endif /* ZMQ_LOOPBACK_FASTPATH */
# ifdef ZMQ_ZAP_ENFORCE_DOMAIN

        case ZMQ_ZAP_ENFORCE_DOMAIN:
	        SOCKOPTS_GET_INT(ZAP_ENFORCE_DOMAIN, int);
# endif /* ZMQ_ZAP_ENFORCE_DOMAIN */
# ifdef ZMQ_GSSAPI_PRINCIPAL_NAMETYPE

        case ZMQ_GSSAPI_PRINCIPAL_NAMETYPE:
	        SOCKOPTS_GET_INT(GSSAPI_PRINCIPAL_NAMETYPE, int);
# endif /* ZMQ_GSSAPI_PRINCIPAL_NAMETYPE */
# ifdef ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE

        case ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE:
	        SOCKOPTS_GET_INT(GSSAPI_SERVICE_PRINCIPAL_NAMETYPE, int);
# endif /* ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE */
# ifdef ZMQ_BINDTODEVICE

        case ZMQ_BINDTODEVICE:
	        SOCKOPTS_GET_STRING(BINDTODEVICE, 255, 0)
# endif /* ZMQ_BINDTODEVICE */
    }

# endif

#endif /* ZMQ_VERSION_MAJOR == 4 */
#if (ZMQ_VERSION_MAJOR >= 4)
#   if (ZMQ_VERSION_MINOR >= 2)

    switch (key) {
# ifdef ZMQ_HEARTBEAT_IVL

        case ZMQ_HEARTBEAT_IVL:
	        SOCKOPTS_GET_INT(HEARTBEAT_IVL, int);
# endif /* ZMQ_HEARTBEAT_IVL */
# ifdef ZMQ_HEARTBEAT_TTL

        case ZMQ_HEARTBEAT_TTL:
	        SOCKOPTS_GET_INT(HEARTBEAT_TTL, int);
# endif /* ZMQ_HEARTBEAT_TTL */
# ifdef ZMQ_HEARTBEAT_TIMEOUT

        case ZMQ_HEARTBEAT_TIMEOUT:
	        SOCKOPTS_GET_INT(HEARTBEAT_TIMEOUT, int);
# endif /* ZMQ_HEARTBEAT_TIMEOUT */
# ifdef ZMQ_USE_FD

        case ZMQ_USE_FD:
	        SOCKOPTS_GET_INT(USE_FD, int);
# endif /* ZMQ_USE_FD */
# ifdef ZMQ_XPUB_MANUAL

        case ZMQ_XPUB_MANUAL:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_XPUB_MANUAL is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_XPUB_MANUAL */
# ifdef ZMQ_XPUB_WELCOME_MSG

        case ZMQ_XPUB_WELCOME_MSG:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_XPUB_WELCOME_MSG is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_XPUB_WELCOME_MSG */
# ifdef ZMQ_STREAM_NOTIFY

        case ZMQ_STREAM_NOTIFY:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_STREAM_NOTIFY is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_STREAM_NOTIFY */
# ifdef ZMQ_INVERT_MATCHING

        case ZMQ_INVERT_MATCHING:
{
        if (socket_type != ZMQ_XPUB &&
            socket_type != ZMQ_PUB &&
            socket_type != ZMQ_SUB) {
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_INVERT_MATCHING is not valid for this socket type", errno);
            return FAILURE;
        }
}
	        SOCKOPTS_GET_INT(INVERT_MATCHING, int);
# endif /* ZMQ_INVERT_MATCHING */
# ifdef ZMQ_XPUB_VERBOSER

        case ZMQ_XPUB_VERBOSER:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_XPUB_VERBOSER is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_XPUB_VERBOSER */
# ifdef ZMQ_CONNECT_TIMEOUT

        case ZMQ_CONNECT_TIMEOUT:
	        SOCKOPTS_GET_INT(CONNECT_TIMEOUT, int);
# endif /* ZMQ_CONNECT_TIMEOUT */
# ifdef ZMQ_TCP_MAXRT

        case ZMQ_TCP_MAXRT:
	        SOCKOPTS_GET_INT(TCP_MAXRT, int);
# endif /* ZMQ_TCP_MAXRT */
# ifdef ZMQ_THREAD_SAFE

        case ZMQ_THREAD_SAFE:
	        SOCKOPTS_GET_INT(THREAD_SAFE, int);
# endif /* ZMQ_THREAD_SAFE */
# ifdef ZMQ_MULTICAST_MAXTPDU

        case ZMQ_MULTICAST_MAXTPDU:
	        SOCKOPTS_GET_INT(MULTICAST_MAXTPDU, int);
# endif /* ZMQ_MULTICAST_MAXTPDU */
# ifdef ZMQ_VMCI_BUFFER_SIZE

        case ZMQ_VMCI_BUFFER_SIZE:
	        SOCKOPTS_GET_INT(VMCI_BUFFER_SIZE, uint64_t);
# endif /* ZMQ_VMCI_BUFFER_SIZE */
# ifdef ZMQ_VMCI_BUFFER_MIN_SIZE

        case ZMQ_VMCI_BUFFER_MIN_SIZE:
	        SOCKOPTS_GET_INT(VMCI_BUFFER_MIN_SIZE, uint64_t);
# endif /* ZMQ_VMCI_BUFFER_MIN_SIZE */
# ifdef ZMQ_VMCI_BUFFER_MAX_SIZE

        case ZMQ_VMCI_BUFFER_MAX_SIZE:
	        SOCKOPTS_GET_INT(VMCI_BUFFER_MAX_SIZE, uint64_t);
# endif /* ZMQ_VMCI_BUFFER_MAX_SIZE */
# ifdef ZMQ_VMCI_CONNECT_TIMEOUT

        case ZMQ_VMCI_CONNECT_TIMEOUT:
	        SOCKOPTS_GET_INT(VMCI_CONNECT_TIMEOUT, int);
# endif /* ZMQ_VMCI_CONNECT_TIMEOUT */
    }

# endif

#endif /* ZMQ_VERSION_MAJOR == 4 */
#if (ZMQ_VERSION_MAJOR >= 4)
#   if (ZMQ_VERSION_MINOR >= 1)

    switch (key) {
# ifdef ZMQ_TOS

        case ZMQ_TOS:
	        SOCKOPTS_GET_INT(TOS, int);
# endif /* ZMQ_TOS */
# ifdef ZMQ_ROUTER_HANDOVER

        case ZMQ_ROUTER_HANDOVER:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_ROUTER_HANDOVER is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_ROUTER_HANDOVER */
# ifdef ZMQ_CONNECT_RID

        case ZMQ_CONNECT_RID:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_CONNECT_RID is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_CONNECT_RID */
# ifdef ZMQ_HANDSHAKE_IVL

        case ZMQ_HANDSHAKE_IVL:
	        SOCKOPTS_GET_INT(HANDSHAKE_IVL, int);
# endif /* ZMQ_HANDSHAKE_IVL */
# ifdef ZMQ_SOCKS_PROXY

        case ZMQ_SOCKS_PROXY:
	        SOCKOPTS_GET_STRING(SOCKS_PROXY, 255, 0)
# endif /* ZMQ_SOCKS_PROXY */
# ifdef ZMQ_XPUB_NODROP

        case ZMQ_XPUB_NODROP:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_XPUB_NODROP is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_XPUB_NODROP */
    }

# endif

#endif /* ZMQ_VERSION_MAJOR == 4 */
#if (ZMQ_VERSION_MAJOR >= 4)

    switch (key) {
# ifdef ZMQ_ROUTER_MANDATORY

        case ZMQ_ROUTER_MANDATORY:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_ROUTER_MANDATORY is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_ROUTER_MANDATORY */
# ifdef ZMQ_PROBE_ROUTER

        case ZMQ_PROBE_ROUTER:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_PROBE_ROUTER is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_PROBE_ROUTER */
# ifdef ZMQ_REQ_RELAXED

        case ZMQ_REQ_RELAXED:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_REQ_RELAXED is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_REQ_RELAXED */
# ifdef ZMQ_REQ_CORRELATE

        case ZMQ_REQ_CORRELATE:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_REQ_CORRELATE is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_REQ_CORRELATE */
# ifdef ZMQ_CONFLATE

        case ZMQ_CONFLATE:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_CONFLATE is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_CONFLATE */
# ifdef ZMQ_ZAP_DOMAIN

        case ZMQ_ZAP_DOMAIN:
	        SOCKOPTS_GET_STRING(ZAP_DOMAIN, 255, 0)
# endif /* ZMQ_ZAP_DOMAIN */
# ifdef ZMQ_MECHANISM

        case ZMQ_MECHANISM:
	        SOCKOPTS_GET_INT(MECHANISM, int);
# endif /* ZMQ_MECHANISM */
# ifdef ZMQ_PLAIN_SERVER

        case ZMQ_PLAIN_SERVER:
	        SOCKOPTS_GET_INT(PLAIN_SERVER, int);
# endif /* ZMQ_PLAIN_SERVER */
# ifdef ZMQ_PLAIN_USERNAME

        case ZMQ_PLAIN_USERNAME:
	        SOCKOPTS_GET_STRING(PLAIN_USERNAME, 255, 0)
# endif /* ZMQ_PLAIN_USERNAME */
# ifdef ZMQ_PLAIN_PASSWORD

        case ZMQ_PLAIN_PASSWORD:
	        SOCKOPTS_GET_STRING(PLAIN_PASSWORD, 255, 0)
# endif /* ZMQ_PLAIN_PASSWORD */
# ifdef ZMQ_CURVE_SERVER

        case ZMQ_CURVE_SERVER:
	        SOCKOPTS_GET_INT(CURVE_SERVER, int);
# endif /* ZMQ_CURVE_SERVER */
# ifdef ZMQ_CURVE_PUBLICKEY

        case ZMQ_CURVE_PUBLICKEY:
	        SOCKOPTS_GET_STRING(CURVE_PUBLICKEY, 32, 1)
# endif /* ZMQ_CURVE_PUBLICKEY */
# ifdef ZMQ_CURVE_SECRETKEY

        case ZMQ_CURVE_SECRETKEY:
	        SOCKOPTS_GET_STRING(CURVE_SECRETKEY, 32, 1)
# endif /* ZMQ_CURVE_SECRETKEY */
# ifdef ZMQ_CURVE_SERVERKEY

        case ZMQ_CURVE_SERVERKEY:
	        SOCKOPTS_GET_STRING(CURVE_SERVERKEY, 32, 1)
# endif /* ZMQ_CURVE_SERVERKEY */
# ifdef ZMQ_GSSAPI_SERVER

        case ZMQ_GSSAPI_SERVER:
	        SOCKOPTS_GET_INT(GSSAPI_SERVER, int);
# endif /* ZMQ_GSSAPI_SERVER */
# ifdef ZMQ_GSSAPI_PLAINTEXT

        case ZMQ_GSSAPI_PLAINTEXT:
	        SOCKOPTS_GET_INT(GSSAPI_PLAINTEXT, int);
# endif /* ZMQ_GSSAPI_PLAINTEXT */
# ifdef ZMQ_GSSAPI_PRINCIPAL

        case ZMQ_GSSAPI_PRINCIPAL:
	        SOCKOPTS_GET_STRING(GSSAPI_PRINCIPAL, 255, 0)
# endif /* ZMQ_GSSAPI_PRINCIPAL */
# ifdef ZMQ_GSSAPI_SERVICE_PRINCIPAL

        case ZMQ_GSSAPI_SERVICE_PRINCIPAL:
	        SOCKOPTS_GET_STRING(GSSAPI_SERVICE_PRINCIPAL, 255, 0)
# endif /* ZMQ_GSSAPI_SERVICE_PRINCIPAL */
# ifdef ZMQ_IPV6

        case ZMQ_IPV6:
	        SOCKOPTS_GET_INT(IPV6, int);
# endif /* ZMQ_IPV6 */
# ifdef ZMQ_IMMEDIATE

        case ZMQ_IMMEDIATE:
	        SOCKOPTS_GET_INT(IMMEDIATE, int);
# endif /* ZMQ_IMMEDIATE */
    }


#endif /* ZMQ_VERSION_MAJOR == 4 */
#if (ZMQ_VERSION_MAJOR >= 3)

    switch (key) {
# ifdef ZMQ_SNDHWM

        case ZMQ_SNDHWM:
	        SOCKOPTS_GET_INT(SNDHWM, int);
# endif /* ZMQ_SNDHWM */
# ifdef ZMQ_RCVHWM

        case ZMQ_RCVHWM:
	        SOCKOPTS_GET_INT(RCVHWM, int);
# endif /* ZMQ_RCVHWM */
# ifdef ZMQ_MAXMSGSIZE

        case ZMQ_MAXMSGSIZE:
	        SOCKOPTS_GET_INT(MAXMSGSIZE, int64_t);
# endif /* ZMQ_MAXMSGSIZE */
# ifdef ZMQ_MULTICAST_HOPS

        case ZMQ_MULTICAST_HOPS:
	        SOCKOPTS_GET_INT(MULTICAST_HOPS, int);
# endif /* ZMQ_MULTICAST_HOPS */
# ifdef ZMQ_XPUB_VERBOSE

        case ZMQ_XPUB_VERBOSE:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_XPUB_VERBOSE is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_XPUB_VERBOSE */
# ifdef ZMQ_TCP_KEEPALIVE

        case ZMQ_TCP_KEEPALIVE:
	        SOCKOPTS_GET_INT(TCP_KEEPALIVE, int);
# endif /* ZMQ_TCP_KEEPALIVE */
# ifdef ZMQ_TCP_KEEPALIVE_IDLE

        case ZMQ_TCP_KEEPALIVE_IDLE:
	        SOCKOPTS_GET_INT(TCP_KEEPALIVE_IDLE, int);
# endif /* ZMQ_TCP_KEEPALIVE_IDLE */
# ifdef ZMQ_TCP_KEEPALIVE_CNT

        case ZMQ_TCP_KEEPALIVE_CNT:
	        SOCKOPTS_GET_INT(TCP_KEEPALIVE_CNT, int);
# endif /* ZMQ_TCP_KEEPALIVE_CNT */
# ifdef ZMQ_TCP_KEEPALIVE_INTVL

        case ZMQ_TCP_KEEPALIVE_INTVL:
	        SOCKOPTS_GET_INT(TCP_KEEPALIVE_INTVL, int);
# endif /* ZMQ_TCP_KEEPALIVE_INTVL */
# ifdef ZMQ_TCP_ACCEPT_FILTER

        case ZMQ_TCP_ACCEPT_FILTER:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_TCP_ACCEPT_FILTER is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_TCP_ACCEPT_FILTER */
# ifdef ZMQ_LAST_ENDPOINT

        case ZMQ_LAST_ENDPOINT:
	        SOCKOPTS_GET_STRING(LAST_ENDPOINT, 255, 0)
# endif /* ZMQ_LAST_ENDPOINT */
# ifdef ZMQ_ROUTER_RAW

        case ZMQ_ROUTER_RAW:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_ROUTER_RAW is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_ROUTER_RAW */
# ifdef ZMQ_IPV4ONLY

        case ZMQ_IPV4ONLY:
	        SOCKOPTS_GET_INT(IPV4ONLY, int);
# endif /* ZMQ_IPV4ONLY */
    }


#endif /* ZMQ_VERSION_MAJOR == 3 */
#if (ZMQ_VERSION_MAJOR >= 2)

    switch (key) {
# ifdef ZMQ_HWM

        case ZMQ_HWM:
	        SOCKOPTS_GET_INT(HWM, uint64_t);
# endif /* ZMQ_HWM */
# ifdef ZMQ_SWAP

        case ZMQ_SWAP:
	        SOCKOPTS_GET_INT(SWAP, int64_t);
# endif /* ZMQ_SWAP */
# ifdef ZMQ_AFFINITY

        case ZMQ_AFFINITY:
	        SOCKOPTS_GET_INT(AFFINITY, uint64_t);
# endif /* ZMQ_AFFINITY */
# ifdef ZMQ_IDENTITY

        case ZMQ_IDENTITY:
{
        if (socket_type != ZMQ_REQ &&
            socket_type != ZMQ_REP &&
            socket_type != ZMQ_DEALER &&
            socket_type != ZMQ_ROUTER) {
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_IDENTITY is not valid for this socket type", errno);
            return FAILURE;
        }
}
	        SOCKOPTS_GET_STRING(IDENTITY, 255, 1)
# endif /* ZMQ_IDENTITY */
# ifdef ZMQ_RATE

        case ZMQ_RATE:
# if ZMQ_VERSION_MAJOR < 3
	        SOCKOPTS_GET_INT(RATE, int64_t);
# else
	        SOCKOPTS_GET_INT(RATE, int);
# endif
# endif /* ZMQ_RATE */
# ifdef ZMQ_RECOVERY_IVL

        case ZMQ_RECOVERY_IVL:
# if ZMQ_VERSION_MAJOR < 3
	        SOCKOPTS_GET_INT(RECOVERY_IVL, int64_t);
# else
	        SOCKOPTS_GET_INT(RECOVERY_IVL, int);
# endif
# endif /* ZMQ_RECOVERY_IVL */
# ifdef ZMQ_RECOVERY_IVL_MSEC

        case ZMQ_RECOVERY_IVL_MSEC:
	        SOCKOPTS_GET_INT(RECOVERY_IVL_MSEC, int64_t);
# endif /* ZMQ_RECOVERY_IVL_MSEC */
# ifdef ZMQ_MCAST_LOOP

        case ZMQ_MCAST_LOOP:
	        SOCKOPTS_GET_INT(MCAST_LOOP, int64_t);
# endif /* ZMQ_MCAST_LOOP */
# ifdef ZMQ_RCVTIMEO

        case ZMQ_RCVTIMEO:
	        SOCKOPTS_GET_INT(RCVTIMEO, int);
# endif /* ZMQ_RCVTIMEO */
# ifdef ZMQ_SNDTIMEO

        case ZMQ_SNDTIMEO:
	        SOCKOPTS_GET_INT(SNDTIMEO, int);
# endif /* ZMQ_SNDTIMEO */
# ifdef ZMQ_SNDBUF

        case ZMQ_SNDBUF:
# if ZMQ_VERSION_MAJOR < 3
	        SOCKOPTS_GET_INT(SNDBUF, uint64_t);
# else
	        SOCKOPTS_GET_INT(SNDBUF, int);
# endif
# endif /* ZMQ_SNDBUF */
# ifdef ZMQ_RCVBUF

        case ZMQ_RCVBUF:
# if ZMQ_VERSION_MAJOR < 3
	        SOCKOPTS_GET_INT(RCVBUF, uint64_t);
# else
	        SOCKOPTS_GET_INT(RCVBUF, int);
# endif
# endif /* ZMQ_RCVBUF */
# ifdef ZMQ_LINGER

        case ZMQ_LINGER:
	        SOCKOPTS_GET_INT(LINGER, int);
# endif /* ZMQ_LINGER */
# ifdef ZMQ_RECONNECT_IVL

        case ZMQ_RECONNECT_IVL:
	        SOCKOPTS_GET_INT(RECONNECT_IVL, int);
# endif /* ZMQ_RECONNECT_IVL */
# ifdef ZMQ_RECONNECT_IVL_MAX

        case ZMQ_RECONNECT_IVL_MAX:
	        SOCKOPTS_GET_INT(RECONNECT_IVL_MAX, int);
# endif /* ZMQ_RECONNECT_IVL_MAX */
# ifdef ZMQ_BACKLOG

        case ZMQ_BACKLOG:
	        SOCKOPTS_GET_INT(BACKLOG, int);
# endif /* ZMQ_BACKLOG */
# ifdef ZMQ_SUBSCRIBE

        case ZMQ_SUBSCRIBE:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_SUBSCRIBE is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_SUBSCRIBE */
# ifdef ZMQ_UNSUBSCRIBE

        case ZMQ_UNSUBSCRIBE:
            zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "Getting ZMQ::SOCKOPT_UNSUBSCRIBE is not supported", PHP_ZMQ_INTERNAL_ERROR);
            return FAILURE;
# endif /* ZMQ_UNSUBSCRIBE */
# ifdef ZMQ_TYPE

        case ZMQ_TYPE:
	        SOCKOPTS_GET_INT(TYPE, int);
# endif /* ZMQ_TYPE */
# ifdef ZMQ_RCVMORE

        case ZMQ_RCVMORE:
# if ZMQ_VERSION_MAJOR < 3
	        SOCKOPTS_GET_INT(RCVMORE, int64_t);
# else
	        SOCKOPTS_GET_INT(RCVMORE, int);
# endif
# endif /* ZMQ_RCVMORE */
# ifdef ZMQ_EVENTS

        case ZMQ_EVENTS:
# if ZMQ_VERSION_MAJOR < 3
	        SOCKOPTS_GET_INT(EVENTS, uint32_t);
# else
	        SOCKOPTS_GET_INT(EVENTS, int);
# endif
# endif /* ZMQ_EVENTS */
    }


#endif /* ZMQ_VERSION_MAJOR == 2 */

    zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get (), PHP_ZMQ_INTERNAL_ERROR, "Unknown option key " ZEND_LONG_FMT, key);
    return FAILURE;
}
/* }}} */

#define SOCKOPTS_SET_INT(NAME, TYPE) \
{ \
  TYPE value = (TYPE) zval_get_long(val); \
  if (zmq_setsockopt(z_socket, key, &value, sizeof(TYPE)) != 0) { \
    zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get(), errno, \
            "Failed to set socket ZMQ::" #NAME " option: %s", zmq_strerror(errno)); \
    return FAILURE; \
  } \
  break; \
}

#define SOCKOPTS_SET_STRING(NAME) \
{ \
  int rc; \
  zend_string *str = zval_get_string(val); \
  rc = zmq_setsockopt(z_socket, key, str->val, str->len); \
  zend_string_release(str); \
  if (rc != 0) { \
    zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get(), errno, \
            "Failed to set socket ZMQ::SOCKOPT_" #NAME " option: %s", zmq_strerror(errno)); \
    return FAILURE; \
  } \
  break; \
}

/* {{{ proto ZMQSocket ZMQSocket::setSockOpt(integer $SOCKOPT, mixed $value)
    Set a socket option
*/
zend_result php_zmq_socket_setsockopt(void *z_socket, int socket_type, zend_long key, zval *val)
{
  if (key > INT_MAX) {
    zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get (), PHP_ZMQ_INTERNAL_ERROR, "The key must be smaller than %d", INT_MAX);
    return FAILURE;
  }

  /* Support setting rcvhwm and sndhwm in one call for backwards compatibility */
  if (key == ZMQ_HWM) {
    int snd_hwm;
    size_t snd_hwm_len = sizeof(int);

    int value = (int) zval_get_long(val);

    /* Get current value if we need to try to restore */
    if (zmq_getsockopt(z_socket, ZMQ_SNDHWM, &snd_hwm, &snd_hwm_len) != 0) {
      zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get (), errno, "Failed to set socket ZMQ::SOCKOPT_HWM option: %s", zmq_strerror(errno));
      return FAILURE;
    }

    /* First set snd hwm */
    if (zmq_setsockopt (z_socket, ZMQ_SNDHWM, &value, sizeof (int)) != 0) {
      zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get (), errno, "Failed to set socket ZMQ::SOCKOPT_HWM option: %s", zmq_strerror(errno));
      return FAILURE;
    }

    /* Next try to set rcv hwm */
    if (zmq_setsockopt(z_socket, ZMQ_RCVHWM, &value, sizeof (int)) != 0) {
      /* Setting rcv failed, try to roll back snd */
      if (zmq_setsockopt (z_socket, ZMQ_SNDHWM, &snd_hwm, sizeof (int)) != 0) {
        zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get (), errno, "Failed to set socket ZMQ::SOCKOPT_HWM option (ZMQ::SOCKOPT_SNDHWM changed): %s", zmq_strerror(errno));
        return FAILURE;
      }
      zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get (), errno, "Failed to set socket ZMQ::SOCKOPT_HWM option: %s", zmq_strerror(errno));
      return FAILURE;
    }
    return SUCCESS;
  }

  switch (key) {
#if ZMQ_VERSION_MAJOR == 4
#if ZMQ_VERSION_MINOR >= 3
#ifdef ZMQ_ONLY_FIRST_SUBSCRIBE
    case ZMQ_ONLY_FIRST_SUBSCRIBE:
      if (socket_type != ZMQ_XPUB &&
          socket_type != ZMQ_XSUB) {
          zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_ONLY_FIRST_SUBSCRIBE is not valid for this socket type", errno);
          return FAILURE;
      }
      SOCKOPTS_SET_INT(ONLY_FIRST_SUBSCRIBE, int)
#endif
#ifdef ZMQ_WSS_TRUST_SYSTEM
    case ZMQ_WSS_TRUST_SYSTEM:
      SOCKOPTS_SET_INT(WSS_TRUST_SYSTEM, int)
#endif
#ifdef ZMQ_WSS_HOSTNAME
    case ZMQ_WSS_HOSTNAME:
      SOCKOPTS_SET_STRING(WSS_HOSTNAME)
#endif
#ifdef ZMQ_WSS_TRUST_PEM
    case ZMQ_WSS_TRUST_PEM:
      SOCKOPTS_SET_STRING(WSS_TRUST_PEM)
#endif
#ifdef ZMQ_WSS_CERT_PEM
    case ZMQ_WSS_CERT_PEM:
      SOCKOPTS_SET_STRING(WSS_CERT_PEM)
#endif
#ifdef ZMQ_WSS_KEY_PEM
    case ZMQ_WSS_KEY_PEM:
      SOCKOPTS_SET_STRING(WSS_KEY_PEM)
#endif
#ifdef ZMQ_OUT_BATCH_SIZE
    case ZMQ_OUT_BATCH_SIZE:
      SOCKOPTS_SET_INT(OUT_BATCH_SIZE, int)
#endif
#ifdef ZMQ_IN_BATCH_SIZE
    case ZMQ_IN_BATCH_SIZE:
      SOCKOPTS_SET_INT(IN_BATCH_SIZE, int)
#endif
#ifdef ZMQ_SOCKS_PASSWORD
    case ZMQ_SOCKS_PASSWORD:
      SOCKOPTS_SET_STRING(SOCKS_PASSWORD)
#endif
#ifdef ZMQ_SOCKS_USERNAME
    case ZMQ_SOCKS_USERNAME:
      SOCKOPTS_SET_STRING(SOCKS_USERNAME)
#endif
#ifdef ZMQ_XPUB_MANUAL_LAST_VALUE
    case ZMQ_XPUB_MANUAL_LAST_VALUE:
      if (socket_type != ZMQ_XPUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_XPUB_MANUAL_LAST_VALUE is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(XPUB_MANUAL_LAST_VALUE, int)
#endif
#ifdef ZMQ_ROUTER_NOTIFY
    case ZMQ_ROUTER_NOTIFY:
      SOCKOPTS_SET_INT(ROUTER_NOTIFY, int)
#endif
#ifdef ZMQ_MULTICAST_LOOP
    case ZMQ_MULTICAST_LOOP:
      SOCKOPTS_SET_INT(MULTICAST_LOOP, int)
#endif
#ifdef ZMQ_METADATA
    case ZMQ_METADATA:
      SOCKOPTS_SET_STRING(METADATA)
#endif
#ifdef ZMQ_LOOPBACK_FASTPATH
    case ZMQ_LOOPBACK_FASTPATH:
      SOCKOPTS_SET_INT(LOOPBACK_FASTPATH, int)
#endif
#ifdef ZMQ_ZAP_ENFORCE_DOMAIN
    case ZMQ_ZAP_ENFORCE_DOMAIN:
      SOCKOPTS_SET_INT(ZAP_ENFORCE_DOMAIN, int)
#endif
#ifdef ZMQ_GSSAPI_PRINCIPAL_NAMETYPE
    case ZMQ_GSSAPI_PRINCIPAL_NAMETYPE:
      SOCKOPTS_SET_INT(GSSAPI_PRINCIPAL_NAMETYPE, int)
#endif
#ifdef ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE
    case ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE:
      SOCKOPTS_SET_INT(GSSAPI_SERVICE_PRINCIPAL_NAMETYPE, int)
#endif
#ifdef ZMQ_BINDTODEVICE
    case ZMQ_BINDTODEVICE:
      SOCKOPTS_SET_STRING(BINDTODEVICE)
#endif
#endif
#if ZMQ_VERSION_MINOR >= 2
    case ZMQ_HEARTBEAT_IVL:
      SOCKOPTS_SET_INT(HEARTBEAT_IVL, int)
    case ZMQ_HEARTBEAT_TTL:
      SOCKOPTS_SET_INT(HEARTBEAT_TTL, int)
    case ZMQ_HEARTBEAT_TIMEOUT:
      SOCKOPTS_SET_INT(HEARTBEAT_TIMEOUT, int)
    case ZMQ_USE_FD:
      SOCKOPTS_SET_INT(USE_FD, int)
    case ZMQ_XPUB_MANUAL:
      if (socket_type != ZMQ_XPUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_XPUB_MANUAL is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(XPUB_MANUAL, int)
    case ZMQ_XPUB_WELCOME_MSG:
      if (socket_type != ZMQ_XPUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_XPUB_WELCOME_MSG is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_STRING(XPUB_WELCOME_MSG)
    case ZMQ_STREAM_NOTIFY:
      if (socket_type != ZMQ_STREAM) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_STREAM_NOTIFY is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(STREAM_NOTIFY, int)
    case ZMQ_INVERT_MATCHING:
      if (socket_type != ZMQ_XPUB &&
          socket_type != ZMQ_PUB &&
          socket_type != ZMQ_SUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_INVERT_MATCHING is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(INVERT_MATCHING, int)
    case ZMQ_XPUB_VERBOSER:
      if (socket_type != ZMQ_XPUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_XPUB_VERBOSER is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(XPUB_VERBOSER, int)
    case ZMQ_CONNECT_TIMEOUT:
      SOCKOPTS_SET_INT(CONNECT_TIMEOUT, int)
    case ZMQ_TCP_MAXRT:
      SOCKOPTS_SET_INT(TCP_MAXRT, int)
    case ZMQ_MULTICAST_MAXTPDU:
      SOCKOPTS_SET_INT(MULTICAST_MAXTPDU, int)
    case ZMQ_VMCI_BUFFER_SIZE:
      SOCKOPTS_SET_INT(VMCI_BUFFER_SIZE, uint64_t)
    case ZMQ_VMCI_BUFFER_MIN_SIZE:
      SOCKOPTS_SET_INT(VMCI_BUFFER_MIN_SIZE, uint64_t)
    case ZMQ_VMCI_BUFFER_MAX_SIZE:
      SOCKOPTS_SET_INT(VMCI_BUFFER_MAX_SIZE, uint64_t)
    case ZMQ_VMCI_CONNECT_TIMEOUT:
      SOCKOPTS_SET_INT(VMCI_CONNECT_TIMEOUT, int)
#endif
#if ZMQ_VERSION_MINOR >= 1
    case ZMQ_TOS:
      SOCKOPTS_SET_INT(ZMQ_TOS, int)
    case ZMQ_ROUTER_HANDOVER:
      if (socket_type != ZMQ_ROUTER) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_ROUTER_HANDOVER is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(ZMQ_ROUTER_HANDOVER, int)
    case ZMQ_CONNECT_RID:
      if (socket_type != ZMQ_ROUTER &&
          socket_type != ZMQ_STREAM) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_CONNECT_RID is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_STRING(ZMQ_CONNECT_RID)
    case ZMQ_HANDSHAKE_IVL:
      SOCKOPTS_SET_INT(ZMQ_HANDSHAKE_IVL, int)
    case ZMQ_SOCKS_PROXY:
      SOCKOPTS_SET_STRING(ZMQ_SOCKS_PROXY)
    case ZMQ_XPUB_NODROP:
      if (socket_type != ZMQ_XPUB &&
          socket_type != ZMQ_PUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_XPUB_NODROP is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(ZMQ_XPUB_NODROP, int)
#endif
    case ZMQ_ROUTER_MANDATORY:
      if (socket_type != ZMQ_ROUTER) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_ROUTER_MANDATORY is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(ZMQ_ROUTER_MANDATORY, int)
    case ZMQ_PROBE_ROUTER:
      if (socket_type != ZMQ_ROUTER &&
          socket_type != ZMQ_DEALER &&
          socket_type != ZMQ_REQ) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_PROBE_ROUTER is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(ZMQ_PROBE_ROUTER, int)
    case ZMQ_REQ_RELAXED:
      if (socket_type != ZMQ_REQ) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_REQ_RELAXED is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(ZMQ_REQ_RELAXED, int)
    case ZMQ_REQ_CORRELATE:
      if (socket_type != ZMQ_REQ) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_REQ_CORRELATE is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(ZMQ_REQ_CORRELATE, int)
    case ZMQ_CONFLATE:
      if (socket_type != ZMQ_PUSH &&
          socket_type != ZMQ_PULL &&
          socket_type != ZMQ_PUB &&
          socket_type != ZMQ_SUB &&
          socket_type != ZMQ_ROUTER) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_CONFLATE is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_INT(ZMQ_CONFLATE, int)
    case ZMQ_ZAP_DOMAIN:
      SOCKOPTS_SET_STRING(ZMQ_ZAP_DOMAIN)
    case ZMQ_MECHANISM:
      SOCKOPTS_SET_INT(ZMQ_MECHANISM, int)
    case ZMQ_PLAIN_SERVER:
      SOCKOPTS_SET_INT(ZMQ_PLAIN_SERVER, int)
    case ZMQ_PLAIN_USERNAME:
      SOCKOPTS_SET_STRING(ZMQ_PLAIN_USERNAME)
    case ZMQ_PLAIN_PASSWORD:
      SOCKOPTS_SET_STRING(ZMQ_PLAIN_PASSWORD)
#ifdef ZMQ_CURVE_SERVER
    case ZMQ_CURVE_SERVER:
      SOCKOPTS_SET_INT(CURVE_SERVER, int)
#endif
#ifdef ZMQ_CURVE_PUBLICKEY
    case ZMQ_CURVE_PUBLICKEY:
      SOCKOPTS_SET_STRING(CURVE_PUBLICKEY)
#endif
#ifdef ZMQ_CURVE_SECRETKEY
    case ZMQ_CURVE_SECRETKEY:
      SOCKOPTS_SET_STRING(CURVE_SECRETKEY)
#endif
#ifdef ZMQ_CURVE_SERVERKEY
    case ZMQ_CURVE_SERVERKEY:
      SOCKOPTS_SET_STRING(CURVE_SERVERKEY)
#endif
#ifdef ZMQ_GSSAPI_SERVER
    case ZMQ_GSSAPI_SERVER:
      SOCKOPTS_SET_INT(GSSAPI_SERVER, int)
#endif
#ifdef ZMQ_GSSAPI_PLAINTEXT
    case ZMQ_GSSAPI_PLAINTEXT:
      SOCKOPTS_SET_INT(GSSAPI_PLAINTEXT, int)
#endif
#ifdef ZMQ_GSSAPI_PRINCIPAL
    case ZMQ_GSSAPI_PRINCIPAL:
      SOCKOPTS_SET_STRING(GSSAPI_PRINCIPAL)
#endif
#ifdef ZMQ_GSSAPI_SERVICE_PRINCIPAL
    case ZMQ_GSSAPI_SERVICE_PRINCIPAL:
      SOCKOPTS_SET_STRING(GSSAPI_SERVICE_PRINCIPAL)
#endif
    case ZMQ_IPV6:
      SOCKOPTS_SET_INT(ZMQ_IPV6, int)
    case ZMQ_IMMEDIATE:
      SOCKOPTS_SET_INT(ZMQ_IMMEDIATE, int)
#endif
    case ZMQ_SNDHWM:
			SOCKOPTS_SET_INT(SNDHWM, int)
    case ZMQ_RCVHWM:
			SOCKOPTS_SET_INT(RCVHWM, int)
    case ZMQ_MAXMSGSIZE:
			SOCKOPTS_SET_INT(MAXMSGSIZE, int64_t)
    case ZMQ_MULTICAST_HOPS:
			SOCKOPTS_SET_INT(MULTICAST_HOPS, int)
    case ZMQ_XPUB_VERBOSE:
      if (socket_type != ZMQ_XPUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_XPUB_VERBOSE is not valid for this socket type", errno);
        return FAILURE;
      }
			SOCKOPTS_SET_INT(XPUB_VERBOSE, int)
    case ZMQ_TCP_KEEPALIVE:
			SOCKOPTS_SET_INT(TCP_KEEPALIVE, int)
    case ZMQ_TCP_KEEPALIVE_IDLE:
			SOCKOPTS_SET_INT(TCP_KEEPALIVE_IDLE, int)
    case ZMQ_TCP_KEEPALIVE_CNT:
			SOCKOPTS_SET_INT(TCP_KEEPALIVE_CNT, int)
    case ZMQ_TCP_KEEPALIVE_INTVL:
			SOCKOPTS_SET_INT(TCP_KEEPALIVE_INTVL, int)
    case ZMQ_TCP_ACCEPT_FILTER:
      SOCKOPTS_SET_STRING(TCP_ACCEPT_FILTER)
    case ZMQ_ROUTER_RAW:
      if (socket_type != ZMQ_ROUTER) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_ROUTER_RAW is not valid for this socket type", errno);
        return FAILURE;
      }
			SOCKOPTS_SET_INT(ROUTER_RAW, int)
    case ZMQ_IPV4ONLY:
			SOCKOPTS_SET_INT(IPV4ONLY, int)
    case ZMQ_AFFINITY:
			SOCKOPTS_SET_INT(AFFINITY, uint64_t)
    case ZMQ_IDENTITY:
      if (socket_type != ZMQ_REQ &&
          socket_type != ZMQ_REP &&
          socket_type != ZMQ_DEALER &&
          socket_type != ZMQ_ROUTER) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_IDENTITY is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_STRING(IDENTITY)
    case ZMQ_RATE:
			SOCKOPTS_SET_INT(RATE, int)
    case ZMQ_RECOVERY_IVL:
			SOCKOPTS_SET_INT(RECOVERY_IVL, int)
    case ZMQ_RCVTIMEO:
			SOCKOPTS_SET_INT(RCVTIMEO, int)
    case ZMQ_SNDTIMEO:
			SOCKOPTS_SET_INT(SNDTIMEO, int)
    case ZMQ_SNDBUF:
			SOCKOPTS_SET_INT(SNDBUF, int)
    case ZMQ_RCVBUF:
			SOCKOPTS_SET_INT(RCVBUF, int)
    case ZMQ_LINGER:
			SOCKOPTS_SET_INT(LINGER, int)
    case ZMQ_RECONNECT_IVL:
			SOCKOPTS_SET_INT(RECONNECT_IVL, int)
    case ZMQ_RECONNECT_IVL_MAX:
			SOCKOPTS_SET_INT(RECONNECT_IVL_MAX, int)
    case ZMQ_BACKLOG:
			SOCKOPTS_SET_INT(BACKLOG, int)
    case ZMQ_SUBSCRIBE:
      if (socket_type != ZMQ_SUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_SUBSCRIBE is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_STRING(SUBSCRIBE)
    case ZMQ_UNSUBSCRIBE:
      if (socket_type != ZMQ_SUB) {
        zend_throw_exception(php_zmq_socket_exception_sc_entry_get (), "ZMQ::SOCKOPT_UNSUBSCRIBE is not valid for this socket type", errno);
        return FAILURE;
      }
      SOCKOPTS_SET_STRING(UNSUBSCRIBE)
    default:
      zend_throw_exception_ex(php_zmq_socket_exception_sc_entry_get (), PHP_ZMQ_INTERNAL_ERROR, "Unknown option key " ZEND_LONG_FMT, key);
      return FAILURE;
  }

  return SUCCESS;
}
/* }}} */
