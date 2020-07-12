# OneWireCommunication
High performance Bit-Bang One Wire Arduino Library
This library is a unidirectional one-wire communication library. The inspiration came from needing to read a voltage from an isolated source, through an attiny and an opto-isolator.
two modes: buffered and unbuffered
Unbuffered creates a sketch size just small enough to fit on a attiny13, buffered can go about 2x faster bit rates than unbuffered (8us vs 4us)
Start and stop bits?
First bit is driven from a LOW to a HIGH, signifies a start bit. The first 1/(bitrate) is ignored, then a counter counts out 16 bits, sampling each one in the middle of the cycle. Once the 16 bit "register" is filled, it will time out another bit, then it will be ready to wait for another LOW-HIGH transition signal.
How high performance you may ask?
The code in between each bang takes about 4 microseconds to run on a 16MHZ nano. The fastest you'll get is 1/4us = 250kbits/sec.
