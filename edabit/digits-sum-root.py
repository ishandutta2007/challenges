#!/usr/bin/env python3

"""
Create a function that takes a number and returns one digit that is the result of summing all the digits of the input number.
When the sum of the digits consists of more than one digit, repeat summing until you get one digit.

Examples

rootDigit(123) ➞ 6
// 1 + 2 + 3 = 6

rootDigit(999888777) ➞ 9

rootDigit(1238763636555555555555) ➞ 6

Notes

Recursion is allowed.
"""

def rootdigit(x):
    r = 0
    while x > 0:
        r += (x % 10)
        x //= 10
    if r >= 10:
        return rootdigit(r)
    return r

def main():
    assert(rootdigit(123) == 6)
    assert(rootdigit(999888777) == 9)
    assert(rootdigit(1238763636555555555555) == 6)
    assert(rootdigit(1111177999888777999888777999888777) == 1)
    assert(rootdigit(1238222222222222222263612387636361238763636) == 7)
    assert(rootdigit(0) == 0)

main()
