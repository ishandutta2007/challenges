#!/usr/bin/env python

"""

Modify the inefficient code in the Code tab so it can pass the tests.

Examples

mod(1, 1) ➞ 0

mod(5, 5) ➞ 34

mod(13, 27 ) ➞ 522956314

mod(8000, 30) ➞ 9157958657951075573395300940314

Notes

    The variables will be natural numbers.
    If necessary, there is a hint in the Tests tab.

"""


from math import factorial

def mod(b, k):
    p = factorial(k)
    f = 1
    r = 0
    for i in range(b):
        r = (r + f) % p
        f = (f * (i + 1)) % p
    return r

def main():
    assert(mod(1, 1) == 0)
    assert(mod(5, 5) == 34)
    assert(mod(13, 27) == 522956314)
    assert(mod(8000, 30) == 9157958657951075573395300940314)
    assert(mod(1000000, 31) == 274410818470142134209703780940314)
    assert(mod(1000001, 42) == 34289376947494122614363304694584807557656420940314)

main()

