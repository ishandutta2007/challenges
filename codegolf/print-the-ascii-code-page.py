#!/usr/bin/env python

"""

Goal
You have to print the ASCII printable characters' code page (0x20-0x7E). The output should look like this:

 !"#$%&'()*+,-./
0123456789:;<=>?
@ABCDEFGHIJKLMNO
PQRSTUVWXYZ[\]^_
`abcdefghijklmno
pqrstuvwxyz{|}~

Rules
The output should be exactly like shown above, but trailing whitespace is OK.
No builtins that trivialize the question (e.g. the ones that print the ASCII table) ! They can be posted for documentation purposes, but will not be in the leaderboards.
Standard rules for I/O and loopholes apply.
Lowest bytecount wins.
Good Luck!
P.S. This challenge is well-known, but a straight "print every single printable ASCII character" has somehow never been done here.

"""

def table():
    n = 0
    for i in range(0x20, 0x7f):
        print(chr(i), end='')
        n = (n + 1) & 0xf
        if n == 0:
            print()
    print()

def main():
    table()

main()
