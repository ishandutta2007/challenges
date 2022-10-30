#!/usr/bin/env python

"""

Task
There is a set of numbers x, such that x^2 divides 7^x-1.

Your task is to find these numbers. Given an input of n, the code will print the nth number that follows this rule.

Examples 1-index
In   Out
3    3
9    24
31   1140
The relevant sequence can be found here.

Rules
Shortest answer will be the winner*

Standard golfing rules apply

Loopholes are not allowed

Your answer can either be 0 or 1 indexed, please state in your answer

"""

# http://oeis.org/A127107
def seq(n):
    if n < 1:
        return 0

    r = 1
    x = 1
    i = 0
    while i < n:
        if (7**x - 1) % x**2 == 0:
            r = x
            i += 1
        x += 1
    return r

def main():
    assert(seq(3) == 3)
    assert(seq(9) == 24)
    assert(seq(31) == 1140)

main()
