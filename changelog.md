2.0.3
- Return static from setOpt method, it was documented in the api but never implemented?
- Replace what should be all direct accesses to php strings internals with macros
- Theoretically fixed pie not setting the extension version correctly

2.0.2
- Fix config.m4 not testing pkg-config return correctly on some machines

2.0.1
- Update poll method to use new zend parsing macros

2.0.0
- Dropped support for libzmq below version 4
- Dropped support for PHP versions lower than 8.1
- Removed czmq support
- Updated to use PHP's new arginfo generator
- Updated all functions to use php's new parameter parsing api, except for one func

1.0.4
- Added 3.2.x context options
- Added 3.2.x socket options
- Added unbind and disconnect for 3.2.x

1.0.0rc1
- Changed poll timeout to milliseconds rather than microseconds
- ZMQ::MODE_NOBLOCK is now called ZMQ::MODE_DONTWAIT, the old constant is 
  kept for backwards compatibility
- ZMQ::SOCKOPT_HWM sets both ZMQ::SOCKOPT_SNDHWM and ZMQ::SOCKOPT_RCVHWM,
  the latter constants are available if compiled against version 3.x of ZeroMQ
- ZMQ::SOCKOPT_MCAST_LOOP has been removed
- ZMQ::SOCKOPT_SWAP has been removed
- The devices has been refactored: the constructor now takes two arguments, front
  and back socket. Starting the device has been moved to separate run method and 
  two new methods setIdleTimeout and setIdleCallback has been added.
- ZMQSocket::send/recv have been deprecated in favour of ZMQSocket::sendmsg/recvmsg.
  The old methods will be removed in the next major version.
- Changed ZMQPoll::poll to take readable and writable arrays by reference, possibly 
  breaks code that tries to pass 'null' or 'false'
- Added ZMQ::SOCKOPT_SNDTIMEO and ZMQ::SOCKOPT_RCVTIMEO (Ben Gray)

0.9.0
- Added SOCKET_ROUTER and SOCKET_DEALER
- Fixed GH-29: Cannot set ZMQ_LINGER to -1

0.8.0
- Added sendmulti and receivemulti functions for simple multipart messaging

0.7.0
- Added callback for connecting/binding sockets
- Make sure that passed param types are not modified in setSockOpt
- EAGAIN in send/recv doesn't cause exception
