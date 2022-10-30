#!/bin/sh

cat << EOF >/dev/null

Your challenge, should you choose to accept it, is simple:

Implement RFC 862, also known as the Echo Protocol:

The Echo protocol
An echo service simply sends back to the originating source any data it receives.

TCP Based Echo Service
One echo service is defined as a connection based application on TCP. A server listens for TCP connections on TCP port 7. Once a connection is established any data received is sent back. This continues until the calling user terminates the connection.

UDP Based Echo Service
Another echo service is defined as a datagram based application on UDP. A server listens for UDP datagrams on UDP port 7. When a datagram is received, the data from it is sent back in an answering datagram.

Scoring
The score is one point for every byte of code as encoded in UTF-8 or a language-specific code page, whichever is smaller.
If the program incompletely implements RFC 862 by providing only UDP or only TCP, the score is doubled.
If the program incorrectly implements RFC 862 by either using a port other than 7 or by dropping or transforming certain bytes due to language limitations or corner cutting, the score is quadrupled. (This stacks with the preceding point if applicable.)
If the program is invalid, the score is ω.
Rules
A valid program:

Does not use standard loopholes.
Per connection:
Accepts connections and receive incoming data.
Sends outgoing data in an amount that is always less than or equal to the amount of data received.
Does not invoke programs external to itself. (Spawning children to deal with multiple connections is fine, spinning up inetd or its local equivalent is not.)
Does not use library functions specifically designed to start and maintain an echo service.
This is code golf, so lowest score wins.

EOF

PORT=1234

# server
socat -v tcp-l:$PORT,fork exec:'/bin/cat'

# client
# nc serverip 1234
