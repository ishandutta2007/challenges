#!/usr/bin/env python

"""

The factorial of a positive number n is the product of all numbers from 1 to n.

5! = 5 x 4 x 3 x 2 x 1 = 120

The semifactorial (also known as the double factorial) of a positive number n is the product of all numbers from 1 to n that have the same parity (i.e. odd or even) as n.

12!! = 12 x 10 x 8 x 6 x 4 x 2 = 46,080

7!! = 7 x 5 x 3 x 1 = 105

The alternating factorial of a positive number n is the sum of the consecutive factorials from n to 1, where every other factorial is multiplied by -1.

Alternating factorial of 1:

af(1) = 1!

Alternating factorial of 2:

af(2) = 2! + (-1)x(1!) = 2! - 1! = 2 -1 = 1

Alternating factorial of 3:

af(3) = 3! - 2! + 1! = 6 - 2 + 1 = 5

Create a function that takes a number n and returns the difference between the alternating factorial and semifactorial of n.
Examples

altSemi(1) ➞ 0

altSemi(2) ➞ -1

altSemi(3)➞ 2

Notes

N/A

"""

def sf(n):
    if n <= 1:
        return 1

    r = 1
    while n > 1:
        r *= n
        n -= 2
    return r

def af(n):
    if n <= 1:
        return 1

    r = 0
    p = 1
    s = 1
    if n&1 == 0:
        s = -s
    for i in range(1, n+1):
        p *= i
        r += s * p
        s = -s
    return r

def altsemi(n):
    return af(n) - sf(n)

def main():
    assert(altsemi(1) == 0)
    assert(altsemi(3) == 2)
    assert(altsemi(4) == 11)
    assert(altsemi(6) == 571)
    assert(altsemi(9) == 326036)
    assert(altsemi(16) == 19696498855099)
    assert(altsemi(21) == 48773618867405512406)

main()
