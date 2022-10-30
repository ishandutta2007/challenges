#!/usr/bin/env python

"""

Write the shortest program that answers "Hello, World" to a network connection.

Conditions:

    Program shall listen on port 12345
    When a client connects, program shall write "Hello, World" to the newly opened socket connection and then close the connection
    Program shall accept connections in a loop, i.e. handle any number of connects
    Program does not need to handle parallel connections

Test:

prompt> telnet localhost 12345

"""

import socket

HOST = '127.0.0.1'
PORT = 12345

def main():
    print("Listening on {}:{}".format(HOST, PORT))
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen()
    while True:
        try:
            c, a = s.accept()
            print("Connection from {}".format(a))
            c.sendall(str.encode("Hello, World\n"))
            c.close()
        except:
            break
    s.close()

main()
