#!/usr/bin/env python
# -*- coding: utf-8 -*-

u"""

Write a function that returns true if k^k == n for input (n, k) and return false otherwise.
Examples

kToK(4, 2) ➞ true

kToK(387420489, 9) ➞ true
// 9^9 == 387420489

kToK(3124, 5) ➞ false

kToK(17, 3) ➞ false

Notes

The ^ operator refers to exponentiation operation, not the bitwise XOR operation.

"""

def ktok(n, k):
    return k**k == n

def main():
    assert(ktok(4, 2) == True)
    assert(ktok(387420489, 9) == True)
    assert(ktok(302875106592253, 13) == True)

    assert(ktok(3124, 5) == False)
    assert(ktok(17, 3) == False)
    assert(ktok(823544, 7) == False)

main()
