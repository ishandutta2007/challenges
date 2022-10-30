#!/usr/bin/env python

"""

Your task is to find the nth Fibonacci number, but n is not necessarily an integer.

The Fibonacci sequence, 0-indexed, goes as follows:

0, 1, 2, 3, 4, 5,  6,  7, ...

1, 1, 2, 3, 5, 8, 13, 21, ...

However, what happens if we want the 2.4th number?

The 2.4th number is 0.4 times the difference between the 3rd and 2nd Fibonacci numbers plus the 2nd Fibonacci number. So, the 2.4th Fibonacci number is 2 + 0.4 * (3 – 2) = 2.4.

Similarly, the 6.35th Fibonacci number is 13 + 0.35 * (21 – 13) = 15.8.

Your task is to find the nth Fibonacci number, such that n is greater than or equal to 0.

You may do this zero- or one-indexed, just please say which one you are using.
This is code-golf, so shortest code in bytes wins!

Some more examples:

0        1
4.5    6.5
0.7      1
7       21

"""

import numpy as np
from math import *

def fib(n):
    F = np.matrix([[1, 1], [1, 0]])
    return (F**n)[0, 0]

def fibli(n):
    a = fib(floor(n))
    b = fib(ceil(n))
    t = modf(n)[0]
    return a + t*(b-a)

def test(n, r):
    v = fibli(n)
    print(v)
    assert(abs(r - v) < 1e-6)

def main():
    test(2.4, 2.4)
    test(6.35, 15.8)
    test(0, 1)
    test(4.5, 6.5)
    test(0.7, 1)
    test(7, 21)

main()
