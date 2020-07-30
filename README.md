# OneWireCommunication
High performance Bit-Bang One Wire Arduino Library
This library is a unidirectional one-wire communication library. The inspiration came from needing to read a voltage from an isolated source, through an attiny and an opto-isolator.

# Start and stop bits?
1010, each pulse lasting 1/(baudrate * 4) seconds. It will count out the appropriate amount of bits (32) then stop.
# How high performance you may ask?
With using digitalRead/digitalWrite, the code in between each bang takes about 4 microseconds to run on a 16MHZ nano. 1/4us = 250kbits/sec. I have since refactored the code to do with register manipulation. A good knowledge of assembly really helps understand this.
** its acually higher performance than that, now that register manipulation is used
# Library wrapper?
no, high level libraries don't allow optimal performance, as there is more compiler intervention.
# Liscense
Joesphan Lu
Software is without warranty.
Free for non-commerical, personal use. This prohibits use from organizations, for profit and non-profit unless otherwise stated.
