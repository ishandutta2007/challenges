#!/usr/bin/env python

"""

I need this down to as few characters as possible. I would use Test-NetConnection but I need PSv2 compatability. Any help would be appreciated.

$socket = new-object Net.Sockets.TcpClient
$socket.Connect("192.168.5.5",445)
$socket.Connected
As a note I have tried this but it doesn't work

(new-object Net.Sockets.TcpClient).Connect("192.168.5.5",445).Connected

"""

import socket
import sys

def usage():
    print("usage: <host> <port>")
    exit(2)

def main():
    if len(sys.argv) != 3:
        usage()

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(5)
    s.connect((sys.argv[1], int(sys.argv[2])))
    s.close()

main()
