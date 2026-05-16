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
	 * @cvalue ZMQ_EFSM
	 */
	const ERR_EFSM = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_ETERM
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

	// const SOCKOPT_TOS = UNKNOWN;
	// const SOCKOPT_ROUTER_HANDOVER = UNKNOWN;
	// const SOCKOPT_CONNECT_RID = UNKNOWN;
	// const SOCKOPT_HANDSHAKE_IVL = UNKNOWN;
	// const SOCKOPT_SOCKS_PROXY = UNKNOWN;
	// const SOCKOPT_XPUB_NODROP = UNKNOWN;
	// const SOCKOPT_ROUTER_MANDATORY = UNKNOWN;
	// const SOCKOPT_PROBE_ROUTER = UNKNOWN;
	// const SOCKOPT_REQ_RELAXED = UNKNOWN;
	// const SOCKOPT_REQ_CORRELATE = UNKNOWN;
	// const SOCKOPT_CONFLATE = UNKNOWN;
	// const SOCKOPT_ZAP_DOMAIN = UNKNOWN;
	// const SOCKOPT_MECHANISM = UNKNOWN;
	// const SOCKOPT_PLAIN_SERVER = UNKNOWN;
	// const SOCKOPT_PLAIN_USERNAME = UNKNOWN;
	// const SOCKOPT_PLAIN_PASSWORD = UNKNOWN;
	// const SOCKOPT_CURVE_SERVER = UNKNOWN;
	// const SOCKOPT_CURVE_PUBLICKEY = UNKNOWN;
	// const SOCKOPT_CURVE_SECRETKEY = UNKNOWN;
	// const SOCKOPT_CURVE_SERVERKEY = UNKNOWN;
	// const SOCKOPT_GSSAPI_SERVER = UNKNOWN;
	// const SOCKOPT_GSSAPI_PLAINTEXT = UNKNOWN;
	// const SOCKOPT_GSSAPI_PRINCIPAL = UNKNOWN;
	// const SOCKOPT_GSSAPI_SERVICE_PRINCIPAL = UNKNOWN;
	// const SOCKOPT_IPV6 = UNKNOWN;
	// const SOCKOPT_IMMEDIATE = UNKNOWN;
	// const SOCKOPT_SNDHWM = UNKNOWN;
	// const SOCKOPT_RCVHWM = UNKNOWN;
	// const SOCKOPT_MAXMSGSIZE = UNKNOWN;
	// const SOCKOPT_MULTICAST_HOPS = UNKNOWN;
	// const SOCKOPT_XPUB_VERBOSE = UNKNOWN;
	// const SOCKOPT_TCP_KEEPALIVE = UNKNOWN;
	// const SOCKOPT_TCP_KEEPALIVE_IDLE = UNKNOWN;
	// const SOCKOPT_TCP_KEEPALIVE_CNT = UNKNOWN;
	// const SOCKOPT_TCP_KEEPALIVE_INTVL = UNKNOWN;
	// const SOCKOPT_TCP_ACCEPT_FILTER = UNKNOWN;
	// const SOCKOPT_LAST_ENDPOINT = UNKNOWN;
	// const SOCKOPT_ROUTER_RAW = UNKNOWN;
	// const SOCKOPT_IPV4ONLY = UNKNOWN;
	// const SOCKOPT_DELAY_ATTACH_ON_CONNECT = UNKNOWN;

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
	 * @cvalue ZMQ_SOCKOPT_RATE
	 */
	const SOCKOPT_RATE = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_RECOVERY_IVL
	 */
	const SOCKOPT_RECOVERY_IVL = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_RECOVERT_IVL_MSEC
	 */
	const SOCKOPT_RECOVERY_IVL_MSEC = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_MCAST_LOOP
	 */
	const SOCKOPT_MCAST_LOOP = UNKNOWN;

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
	 * @cvalue ZMQ_RCBUF
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
	 * @cvalue ZMQ_FD
	 */
	const SOCKOPT_FD = UNKNOWN;

	/**
	 * @var int
	 * @cvalue ZMQ_EVENTS
	 */
	const SOCKOPT_EVENTS = UNKNOWN;
	// const CTXOPT_MAX_SOCKETS = UNKNOWN;
	// const CTXOPT_MAX_SOCKETS_DEFAULT = UNKNOWN;

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
	public function clock(): int {}

	public function z85encode(string $data): string|false {}

	public function z85decode(string $data): string|false {}

	public function curvekeypair(): void {}
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
	public function __construct(int $io_threads = 1, bool $persistent = true) {}

	/**
	 * Acquires a handle to the request global context
	 * 
	 * @return ZMQContext
	 */
	public function acquire(): ZMQContext {}

	public function getsocketcount(): int {}

	public function getsocket(int $type, ?string $dsn = null, bool $on_new_socket = false): ZMQSocket {}

	public function ispersistent(): bool {}

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
	public function __construct(ZMQContext $ZMQContext, int $type, ?string $persistent_id = null, bool $on_new_socket = false) {}

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

	public function monitor(string $dsn, int $events = 0): static {}

	public function recvevent(int $flags = 0): array {}

	/**
	 * Unbind the socket from an endpoint
	 * 
	 * @param string $dsn
	 * @return ZMQSocket
	 */
	public function unbind(string $dsn): static {}

	/**
	 * Disconnect the socket from an endpoint
	 * 
	 * @param string $dsn
	 * @return ZMQSocket
	 */
	public function disconnect(string $dsn): static {}

	public function setsockopt(int $key, mixed $value): void {}

	public function getendpoints(): array {}

	public function getsockettype(): int {}

	public function ispersistent(): bool {}

	public function getpersistentid(): ?string {}

	public function getsockopt(int $key): int {}

	public function sendmsg(string $message, int $mode = 0): static|false {}

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

	public function setidlecallback(callable $idle_callback, int $timeout, ?object $user_data = null): static {}

	public function setidletimeout(int $timeout): static {}

	public function getidletimeout(): int {}

	public function settimercallback(callable $idle_callback, int $timeout, ?object $user_data = null): static {}

	public function settimertimeout(int $timeout): static {}

	public function gettimertimeout(): int {}
}

class ZMQException extends Exception {}

class ZMQContextException extends ZMQException {}

class ZMQSocketException extends ZMQException {}

class ZMQPollException extends ZMQException {}

class ZMQDeviceException extends ZMQException {}
