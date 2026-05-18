<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

class ZMQ
{
    /**
     * @var int
     * @cvalue ZMQ_PAIR
     */
    const SOCKET_PAIR = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_PUB
     */
    const SOCKET_PUB = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_SUB
     */
    const SOCKET_SUB = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_REQ
     */
    const SOCKET_REQ = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_REP
     */
    const SOCKET_REP = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_XREQ
     */
    const SOCKET_XREQ = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_XREP
     */
    const SOCKET_XREP = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_PUSH
     */
    const SOCKET_PUSH = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_PULL
     */
    const SOCKET_PULL = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_DEALER
     */
    const SOCKET_DEALER = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_ROUTER
     */
    const SOCKET_ROUTER = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_XSUB
     */
    const SOCKET_XSUB = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_XPUB
     */
    const SOCKET_XPUB = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_STREAM
     */
    const SOCKET_STREAM = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_PULL
     */
    const SOCKET_UPSTREAM = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_PUSH
     */
    const SOCKET_DOWNSTREAM = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_POLLIN
     */
    const POLL_IN = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_POLLOUT
     */
    const POLL_OUT = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_SNDMORE
     */
    const MODE_SNDMORE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_DONTWAIT
     */
    const MODE_NOBLOCK = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_DONTWAIT
     */
    const MODE_DONTWAIT = UNKNOWN;

    /**
     * @var int
     * @cvalue PHP_ZMQ_INTERNAL_ERROR
     */
    const ERR_INTERNAL = UNKNOWN;

    /**
     * @var int
     * @cvalue EAGAIN
     */
    const ERR_EAGAIN = UNKNOWN;

    /**
     * @var int
     * @cvalue ENOTSUP
     */
    const ERR_ENOTSUP = UNKNOWN;

    /**
     * @var int
     * @cvalue EFSM
     */
    const ERR_EFSM = UNKNOWN;

    /**
     * @var int
     * @cvalue ETERM
     */
    const ERR_ETERM = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_VERSION_MAJOR
     */
    const LIBZMQ_VERSION_MAJOR = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_VERSION_MINOR
     */
    const LIBZMQ_VERSION_MINOR = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_VERSION_PATCH
     */
    const LIBZMQ_VERSION_PATCH = UNKNOWN;

#if ZMQ_VERSION_MAJOR == 4
#if ZMQ_VERSION_MINOR >= 3
#ifdef ZMQ_ONLY_FIRST_SUBSCRIBE
    /**
     * @var int
     * @cvalue ZMQ_ONLY_FIRST_SUBSCRIBE
     */
  	const SOCKOPT_ONLY_FIRST_SUBSCRIBE = UNKNOWN;
#endif
#ifdef ZMQ_WSS_TRUST_SYSTEM
    /**
     * @var int
     * @cvalue ZMQ_WSS_TRUST_SYSTEM
     */
    const SOCKOPT_WSS_TRUST_SYSTEM = UNKNOWN;
#endif
#ifdef ZMQ_WSS_HOSTNAME
    /**
     * @var int
     * @cvalue ZMQ_WSS_HOSTNAME
     */
  	const SOCKOPT_WSS_HOSTNAME = UNKNOWN;
#endif
#ifdef ZMQ_WSS_TRUST_PEM
  	/**
     * @var int
     * @cvalue ZMQ_WSS_TRUST_PEM
     */
  	const SOCKOPT_WSS_TRUST_PEM = UNKNOWN;
#endif
#ifdef ZMQ_WSS_CERT_PEM
  	/**
     * @var int
     * @cvalue ZMQ_WSS_CERT_PEM
     */
  	const SOCKOPT_WSS_CERT_PEM = UNKNOWN;
#endif
#ifdef ZMQ_WSS_KEY_PEM
  	/**
     * @var int
     * @cvalue ZMQ_WSS_KEY_PEM
     */
  	const SOCKOPT_WSS_KEY_PEM = UNKNOWN;
#endif
#ifdef ZMQ_OUT_BATCH_SIZE
  	/**
     * @var int
     * @cvalue ZMQ_OUT_BATCH_SIZE
     */
  	const SOCKOPT_OUT_BATCH_SIZE = UNKNOWN;
#endif
#ifdef ZMQ_IN_BATCH_SIZE
  	/**
     * @var int
     * @cvalue ZMQ_IN_BATCH_SIZE
     */
  	const SOCKOPT_IN_BATCH_SIZE = UNKNOWN;
#endif
#ifdef ZMQ_SOCKS_PASSWORD
  	/**
     * @var int
     * @cvalue ZMQ_SOCKS_PASSWORD
     */
  	const SOCKOPT_SOCKS_PASSWORD = UNKNOWN;
#endif
#ifdef ZMQ_SOCKS_USERNAME
  	/**
     * @var int
     * @cvalue ZMQ_SOCKS_USERNAME
     */
  	const SOCKOPT_SOCKS_USERNAME = UNKNOWN;
#endif
#ifdef ZMQ_XPUB_MANUAL_LAST_VALUE
  	/**
     * @var int
     * @cvalue ZMQ_XPUB_MANUAL_LAST_VALUE
     */
  	const SOCKOPT_XPUB_MANUAL_LAST_VALUE = UNKNOWN;
#endif
#ifdef ZMQ_ROUTER_NOTIFY
  	/**
     * @var int
     * @cvalue ZMQ_ROUTER_NOTIFY
     */
  	const SOCKOPT_ROUTER_NOTIFY = UNKNOWN;
#endif
#ifdef ZMQ_MULTICAST_LOOP
    /**
     * @var int
     * @cvalue ZMQ_MULTICAST_LOOP
     */
  	const SOCKOPT_MULTICAST_LOOP = UNKNOWN;
#endif
#ifdef ZMQ_METADATA
  	/**
     * @var int
     * @cvalue ZMQ_METADATA
     */
  	const SOCKOPT_METADATA = UNKNOWN;
#endif
#ifdef ZMQ_LOOPBACK_FASTPATH
  	/**
     * @var int
     * @cvalue ZMQ_LOOPBACK_FASTPATH
     */
  	const SOCKOPT_LOOPBACK_FASTPATH = UNKNOWN;
#endif
#ifdef ZMQ_ZAP_ENFORCE_DOMAIN
  	/**
     * @var int
     * @cvalue ZMQ_ZAP_ENFORCE_DOMAIN
     */
 	const SOCKOPT_ZAP_ENFORCE_DOMAIN = UNKNOWN;
#endif
#ifdef ZMQ_GSSAPI_PRINCIPAL_NAMETYPE
  	/**
     * @var int
     * @cvalue ZMQ_GSSAPI_PRINCIPAL_NAMETYPE
     */
  	const SOCKOPT_GSSAPI_PRINCIPAL_NAMETYPE = UNKNOWN;
#endif
#ifdef ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE
  	/**
     * @var int
     * @cvalue ZMQ_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE
     */
  	const SOCKOPT_GSSAPI_SERVICE_PRINCIPAL_NAMETYPE = UNKNOWN;
#endif
#ifdef ZMQ_BINDTODEVICE
  	/**
     * @var int
     * @cvalue ZMQ_BINDTODEVICE
     */
  	const SOCKOPT_BINDTODEVICE = UNKNOWN;
#endif
#endif
#if ZMQ_VERSION_MINOR >= 2
  	/**
     * @var int
     * @cvalue ZMQ_HEARTBEAT_IVL
     */
  	const SOCKOPT_HEARTBEAT_IVL = UNKNOWN;

  	/**
     * @var int
     * @cvalue ZMQ_HEARTBEAT_TTL
     */
  	const SOCKOPT_HEARTBEAT_TTL = UNKNOWN;

  	/**
     * @var int
     * @cvalue ZMQ_HEARTBEAT_TIMEOUT
     */
  	const SOCKOPT_HEARTBEAT_TIMEOUT = UNKNOWN;

  	/**
     * @var int
     * @cvalue ZMQ_USE_FD
     */
  	const SOCKOPT_USE_FD = UNKNOWN;

  	/**
     * @var int
     * @cvalue ZMQ_XPUB_MANUAL
     */
  	const SOCKOPT_XPUB_MANUAL = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_XPUB_WELCOME_MSG
   	 */
  	const SOCKOPT_XPUB_WELCOME_MSG = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_STREAM_NOTIFY
   	 */
  	const SOCKOPT_STREAM_NOTIFY = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_INVERT_MATCHING
   	 */
  	const SOCKOPT_INVERT_MATCHING = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_XPUB_VERBOSER
   	 */
    const SOCKOPT_XPUB_VERBOSER = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_CONNECT_TIMEOUT
   	 */
  	const SOCKOPT_CONNECT_TIMEOUT = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_TCP_MAXRT
   	 */
  	const SOCKOPT_TCP_MAXRT = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_MULTICAST_MAXTPDU
   	 */
  	const SOCKOPT_MULTICAST_MAXTPDU = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_VMCI_BUFFER_SIZE
   	 */
  	const SOCKOPT_VMCI_BUFFER_SIZE = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_VMCI_BUFFER_MIN_SIZE
   	 */
  	const SOCKOPT_VMCI_BUFFER_MIN_SIZE = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_VMCI_BUFFER_MAX_SIZE
   	 */
  	const SOCKOPT_VMCI_BUFFER_MAX_SIZE = UNKNOWN;

    /**
   	 * @var int
   	 * @cvalue ZMQ_VMCI_CONNECT_TIMEOUT
   	 */
  	const SOCKOPT_VMCI_CONNECT_TIMEOUT = UNKNOWN;
#endif
#if ZMQ_VERSION_MINOR >= 1

    /**
   	 * @var int
   	 * @cvalue ZMQ_TOS
   	 */
  	const SOCKOPT_TOS = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_ROUTER_HANDOVER
   	 */
  	const ZMQ_ROUTER_HANDOVER = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_CONNECT_RID
	 */
	const SOCKOPT_CONNECT_RID = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_HANDSHAKE_IVL
	 */
	const SOCKOPT_HANDSHAKE_IVL = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_SOCKS_PROXY
	 */
	const SOCKOPT_SOCKS_PROXY = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_XPUB_NODROP
	 */
	const SOCKOPT_XPUB_NODROP = UNKNOWN;
#endif

  	/**
   	 * @var int
   	 * @cvalue ZMQ_ROUTER_MANDATORY
   	 */
  	const SOCKOPT_ROUTER_MANDATORY = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_PROBE_ROUTER
   	 */
  	const SOCKOPT_PROBE_ROUTER = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_REQ_RELAXED
   	 */
  	const SOCKOPT_REQ_RELAXED = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_REQ_CORRELATE
   	 */
  	const SOCKOPT_REQ_CORRELATE = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_CONFLATE
   	 */
  	const SOCKOPT_CONFLATE = UNKNOWN;

  	/**
     * @var int
     * @cvalue ZMQ_ZAP_DOMAIN
     */
  	const SOCKOPT_ZAP_DOMAIN = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_MECHANISM
   	 */
  	const SOCKOPT_MECHANISM = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_PLAIN_SERVER
   	 */
  	const SOCKOPT_PLAIN_SERVER = UNKNOWN;

  	/**
   	 * @var int
   	 * @cvalue ZMQ_PLAIN_USERNAME
   	 */
  	const SOCKOPT_PLAIN_USERNAME = UNKNOWN;

  	/**
     * @var int
     * @cvalue ZMQ_PLAIN_PASSWORD
     */
  	const SOCKOPT_PLAIN_PASSWORD = UNKNOWN;
#ifdef ZMQ_CURVE_SERVER
  	/**
   	 * @var int
   	 * @cvalue ZMQ_CURVE_SERVER
   	 */
  	const SOCKOPT_CURVE_SERVER = UNKNOWN;
#endif
#ifdef ZMQ_CURVE_PUBLICKEY
  	/**
   	 * @var int
   	 * @cvalue ZMQ_CURVE_PUBLICKEY
   	 */
  	const SOCKOPT_CURVE_PUBLICKEY = UNKNOWN;
#endif
#ifdef ZMQ_CURVE_SECRETKEY
  	/**
   	 * @var int
   	 * @cvalue ZMQ_CURVE_SECRETKEY
   	 */
  	const SOCKOPT_CURVE_SECRETKEY = UNKNOWN;
#endif
#ifdef ZMQ_CURVE_SERVERKEY
  	/**
   	 * @var int
   	 * @cvalue ZMQ_CURVE_SERVERKEY
   	 */
    const SOCKOPT_CURVE_SERVERKEY = UNKNOWN;
#endif
#ifdef ZMQ_GSSAPI_SERVER
  	/**
   	 * @var int
   	 * @cvalue ZMQ_GSSAPI_SERVER
   	 */
    const SOCKOPT_GSSAPI_SERVER = UNKNOWN;
#endif
#ifdef ZMQ_GSSAPI_PLAINTEXT
    /**
   	 * @var int
   	 * @cvalue ZMQ_GSSAPI_PLAINTEXT
   	 */
    const SOCKOPT_GSSAPI_PLAINTEXT = UNKNOWN;
#endif
#ifdef ZMQ_GSSAPI_PRINCIPAL
  	/**
   	 * @var int
   	 * @cvalue ZMQ_GSSAPI_PRINCIPAL
   	 */
  	const SOCKOPT_GSSAPI_PRINCIPAL = UNKNOWN;
#endif
#ifdef ZMQ_GSSAPI_SERVICE_PRINCIPAL
    /**
     * @var int
     * @cvalue ZMQ_GSSAPI_SERVICE_PRINCIPAL
     */
    const SOCKOPT_GSSAPI_SERVICE_PRINCIPAL = UNKNOWN;
#endif

  	/**
   	 * @var int
   	 * @cvalue ZMQ_IPV6
   	 */
	const SOCKOPT_IPV6 = UNKNOWN;

	/**
     * @var int
   	 * @cvalue ZMQ_IMMEDIATE
   	 */
	const SOCKOPT_IMMEDIATE = UNKNOWN;
#endif

    /**
     * @var int
     * @cvalue ZMQ_SNDHWM
     */
    const SOCKOPT_SNDHWM = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_RCVHWM
     */
    const SOCKOPT_RCVHWM = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_MAXMSGSIZE
     */
    const SOCKOPT_MAXMSGSIZE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_MULTICAST_HOPS
     */
    const SOCKOPT_MULTICAST_HOPS = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_XPUB_VERBOSE
     */
    const SOCKOPT_XPUB_VERBOSE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_TCP_KEEPALIVE
     */
    const SOCKOPT_TCP_KEEPALIVE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_TCP_KEEPALIVE_IDLE
     */
    const SOCKOPT_TCP_KEEPALIVE_IDLE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_TCP_KEEPALIVE_CNT
     */
    const SOCKOPT_TCP_KEEPALIVE_CNT = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_TCP_KEEPALIVE_INTVL
     */
    const SOCKOPT_TCP_KEEPALIVE_INTVL = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_TCP_ACCEPT_FILTER
     */
    const SOCKOPT_TCP_ACCEPT_FILTER = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_LAST_ENDPOINT
     */
    const SOCKOPT_LAST_ENDPOINT = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_ROUTER_RAW
     */
    const SOCKOPT_ROUTER_RAW = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_IPV4ONLY
     */
    const SOCKOPT_IPV4ONLY = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_DELAY_ATTACH_ON_CONNECT
     */
    const SOCKOPT_DELAY_ATTACH_ON_CONNECT = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_HWM
     */
    const SOCKOPT_HWM = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_AFFINITY
     */
    const SOCKOPT_AFFINITY = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_IDENTITY
     */
    const SOCKOPT_IDENTITY = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_RECOVERY_IVL
     */
    const SOCKOPT_RECOVERY_IVL = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_RCVTIMEO
     */
    const SOCKOPT_RCVTIMEO = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_SNDTIMEO
     */
    const SOCKOPT_SNDTIMEO = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_SNDBUF
     */
    const SOCKOPT_SNDBUF = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_RCVBUF
     */
    const SOCKOPT_RCVBUF = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_LINGER
     */
    const SOCKOPT_LINGER = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_RECONNECT_IVL
     */
    const SOCKOPT_RECONNECT_IVL = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_RECONNECT_IVL_MAX
     */
    const SOCKOPT_RECONNECT_IVL_MAX = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_BACKLOG
     */
    const SOCKOPT_BACKLOG = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_SUBSCRIBE
     */
    const SOCKOPT_SUBSCRIBE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_UNSUBSCRIBE
     */
    const SOCKOPT_UNSUBSCRIBE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_TYPE
     */
    const SOCKOPT_TYPE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_RCVMORE
     */
    const SOCKOPT_RCVMORE = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENTS
     */
    const SOCKOPT_EVENTS = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_CONNECTED
     */
    const EVENT_CONNECTED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_CONNECT_DELAYED
     */
    const EVENT_CONNECT_DELAYED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_CONNECT_RETRIED
     */
    const EVENT_CONNECT_RETRIED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_LISTENING
     */
    const EVENT_LISTENING = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_BIND_FAILED
     */
    const EVENT_BIND_FAILED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_ACCEPTED
     */
    const EVENT_ACCEPTED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_ACCEPT_FAILED
     */
    const EVENT_ACCEPT_FAILED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_CLOSED
     */
    const EVENT_CLOSED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_CLOSE_FAILED
     */
    const EVENT_CLOSE_FAILED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_DISCONNECTED
     */
    const EVENT_DISCONNECTED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_MONITOR_STOPPED
     */
    const EVENT_MONITOR_STOPPED = UNKNOWN;

    /**
     * @var int
     * @cvalue ZMQ_EVENT_ALL
     */
    const EVENT_ALL = UNKNOWN;

    /**
     * A monotonic clock
     */
    public static function clock(): int {}

#if PHP_ZMQ_HAVE_Z85
    public static function z85encode(string $data): ?string {}

    public static function z85decode(string $data): ?string {}
#endif

#if PHP_ZMQ_HAVE_CURVE_KEYPAIR
    public static function curvekeypair(): void {}
#endif
}

class ZMQContext
{
    /**
     * Build a new ZMQContext object
     *
     * @param integer $io_threads
     * @param boolean $is_persistent
     * @return ZMQContext
     */
    public function __construct(int $ioThreads = 1, bool $persistent = true) {}

    /**
     * Acquires a handle to the request global context
     *
     * @return ZMQContext
     */
    public static function acquire(): ZMQContext {}

    public function getsocketcount(): int {}

    public function getsocket(int $type, ?string $dsn = null, bool $onNewSocket = false): ZMQSocket {}

    public function ispersistent(): bool {}

#if PHP_ZMQ_HAVE_CTX_OPTIONS
    /**
     * Set a context option
     *
     * @param int $option
     * @param int $value
     * @return ZMQContext
     */
    public function setOpt(int $option, int $value): void {}

    /**
     * Set a context option
     *
     * @param int $option
     * @return ZMQContext
     */
    public function getOpt(int $option): int {}
#endif
}

class ZMQSocket
{
    /**
     * Build a new ZMQSocket object
     *
     * @param ZMQContext $context
     * @param integer $type
     * @param string $persistent_id
     * @param callback $on_new_socket
     * @return ZMQSocket
     */
    public function __construct(ZMQContext $ZMQContext, int $type, ?string $persistentId = null, bool $onNewSocket = false) {}

    /**
     * Send a message. Return true if message was sent and false on EAGAIN
     *
     * @param string $message
     * @param integer $flags
     * @return ZMQSocket
     */
    public function send(string $message, int $mode = 0): static|false {}

    public function recv(int $mode = 0): string|false {}

    /**
     * Send a multipart message. Return true if message was sent and false on EAGAIN
     *
     * @param string[] $messages
     * @param integer $flags
     * @return ZMQSocket
     */
    public function sendmulti(array $message, int $mode = 0): static|false {}

    public function recvmulti(int $mode = 0): array|false {}

    /**
     * Bind the socket to an endpoint
     *
     * @param string $dsn
     * @param boolean $force
     * @return ZMQSocket
     */
    public function bind(string $dsn, bool $force = false): static {}

    /**
     * Connect the socket to an endpoint
     *
     * @param string $dsn
     * @param boolean $force
     * @return ZMQSocket
     */
    public function connect(string $dsn, bool $force = false): static {}

#if PHP_ZMQ_HAVE_SOCKET_MONITOR
    public function monitor(string $dsn, int $events = 0): static {}
#endif

    public function recvevent(int $flags = 0): array {}

#if PHP_ZMQ_HAVE_UNBIND
    /**
     * Unbind the socket from an endpoint
     *
     * @param string $dsn
     * @return ZMQSocket
     */
    public function unbind(string $dsn): static {}
#endif

#if PHP_ZMQ_HAVE_DISCONNECT
    /**
     * Disconnect the socket from an endpoint
     *
     * @param string $dsn
     * @return ZMQSocket
     */
    public function disconnect(string $dsn): static {}
#endif

    public function setsockopt(int $key, string|int $value): static {}

    public function getendpoints(): array {}

    public function getsockettype(): int {}

    public function ispersistent(): bool {}

    public function getpersistentid(): ?string {}

    public function getsockopt(int $key): string|int {}

    /**
     * @implementation-alias ZMQSocket::send
     */
    public function sendmsg(string $message, int $mode = 0): static|false {}

    /**
     * @implementation-alias ZMQSocket::recv
     */
    public function recvmsg(int $mode = 0): string|false {}
}

class ZMQPoll
{
    /**
     * Add a ZMQSocket object into the pollset
     *
     * @param ZMQSocket $object
     * @param integer $events
     * @return integer
     */
    public function add(ZMQSocket $entry, int $type): int {}

    /**
     * Poll the sockets
     *
     * @param array $readable
     * @param array $writable
     * @param integer $timeout
     * @return integer
     */
    public function poll(array &$readable, array &$writable, int $timeout = -1): long {}

    public function getlasterrors(): Object {}

    /**
     * Remove item from poll set
     *
     * @param mixed $item
     * @return boolean
     */
    public function remove(mixed $remove): bool {}

    /**
     * Returns the number of items in the set
     *
     * @return integer
     */
    public function count(): int {}

    /**
     * Clear the pollset
     *
     * @return ZMQPoll
     */
    public function clear(): ZMQPoll {}

    /**
     * Clear the pollset
     *
     * @return array
     */
    public function items(): array {}
}


class ZMQDevice
{
    /**
     * Construct a device
     *
     * @param ZMQSocket $frontend
     * @param ZMQSocket $backend
     * @return void
     */
    public function __construct(ZMQSocket $frontend, ZMQSocket $backend, ?ZMQSocket $capture = null) {}
    /**
     * Start a device
     *
     * @return void
     */
    public function run(): void {}

    public function setidlecallback(callable $idleCallback, int $timeout, ?object $user_data = null): static {}

    public function setidletimeout(int $timeout): static {}

    public function getidletimeout(): int {}

    public function settimercallback(callable $idleCallback, int $timeout, ?object $user_data = null): static {}

    public function settimertimeout(int $timeout): static {}

    public function gettimertimeout(): int {}
}

class ZMQException extends Exception {}

class ZMQContextException extends ZMQException {}

class ZMQSocketException extends ZMQException {}

class ZMQPollException extends ZMQException {}

class ZMQDeviceException extends ZMQException {}
