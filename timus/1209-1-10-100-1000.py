#!/usr/bin/env python

"""

Let's consider an infinite sequence of digits constructed of ascending powers of 10 written one after another.
Here is the beginning of the sequence: 110100100010000… You are to find out what digit is located at the definite position of the sequence.

Input

There is the only integer N in the first line (1 ≤ N ≤ 65535). The i-th of N left lines contains the integer Ki — the number of position in the sequence (1 ≤ Ki ≤ 2^31 − 1).

Output

You are to output N digits 0 or 1 separated with a space. More precisely, the i-th digit of output is to be equal to the Ki-th digit of described above sequence.

"""

from math import *

def quadratic(a, b, c):
    d = b*b - 4*a*c
    if d < 0:
        return (-1, -1)
    
    s = sqrt(d)
    r0 = (-b+s) / (2*a)
    r1 = (-b-s) / (2*a)
    return (r0, r1)

# https://oeis.org/A000217
def digit(n):
    r = quadratic(0.5, 0.5, -n+1)
    if r[0] < 0:
        return -1

    a = floor(r[0])
    b = ceil(r[0])
    if int(a) == int(b):
        return 1
    return 0

def main():
    assert(digit(3) == 0)
    assert(digit(14) == 0)
    assert(digit(7) == 1)
    assert(digit(6) == 0)
    assert(digit(1) == 1)
    assert(digit(2) == 1)

main()
