# PHP ZMQ

PHP bindings for 0MQ. The documentation is available [here][1]

This is a hardfork of the [PHP Extension][2], updated for a PHP's newer extension sensibilities and API functions. As such, support for versions of PHP older than 8.1 and versions of libzmq below version 4 have been dropped.

Additionally the support for libczmq has been dropped as it wasn't documented and wasn't used at $work. Will be added back at a later date should it be required.

## Prerequisites

* libzmq 4.0.0 and above
* PHP 8.1 and above

## Insallation (PIE)

You can install this extension using [PIE][3]

```sh
pie install intermaterium/phpzmq
```

## Installation (Build from source)

You can also use the old phpize method to install the extension

```sh
git clone --recursive --depth=1 https://github.com/chrisBirmingham/phpzmq.git
cd phpzmq
phpize
./configure
make
make install
```

The API is roughly as follows:

```php
<?php

/* Create new queue object */
$queue = new ZMQSocket(new ZMQContext(), ZMQ::SOCKET_REQ, "MySock1");

/* Connect to an endpoint */
$queue->connect("tcp://127.0.0.1:5555");

/* send and receive */
var_dump($queue->send("hello there, using socket 1")->recv());

?>
```

[1]: https://php.net/zmq
[2]: https://github.com/zeromq/php-zmq
[3]: https://github.com/php/pie
