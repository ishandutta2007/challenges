#!/usr/bin/env python

"""

Write a function that returns the greatest common divisor of all list elements.
If the greatest common divisor is 1, return 1.

Examples

GCD([10, 20, 40]) ➞ 10

GCD([1, 2, 3, 100]) ➞ 1

GCD([1024, 192, 2048, 512]) ➞ 64

Notes

    List elements are always greater than 0.
    There is a minimum of two list elements given.

"""

def gcd(a, b):
    while b != 0:
        a, b = b, a%b
    return a

def gcdl(l):
    if len(l) == 0:
        return 0

    v = l[0]
    i = 1
    while i < len(l):
        v = gcd(v, l[i])
        i += 1
    return v

def main():
    assert(gcdl([1, 2, 3, 100]) == 1)
    assert(gcdl([1024, 192, 2048, 512]) == 64)
    assert(gcdl([10, 20, 40]) == 10)
    assert(gcdl([7, 11]) == 1)
    assert(gcdl([156, 84, 60, 1188, 252]) == 12)
    assert(gcdl([1, 2, 3, 4, 5]) == 1)
    assert(gcdl([777, 77, 7, 14]) == 7)
    assert(gcdl([20, 20, 40, 100]) == 20)
    assert(gcdl([731, 43, 473, 2623]) == 43)

main()
