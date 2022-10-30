#!/usr/bin/env python

"""
Given an integer, n, print the following values for each integer i from 1 to n:

Decimal
Octal
Hexadecimal (capitalized)
Binary
The four values must be printed on a single line in the order specified above for each i from 1 to n.
Each value should be space-padded to match the width of the binary value of n.
"""

def values(n):
    l = len("{0:b}".format(n + 1))
    f = "{0:>%d} {0:>%o} {0:>%X} {0:>%b}".replace("%", str(l))
    for i in range(n):
        v = i + 1
        print(f.format(v, v, v, v))

values(100)
