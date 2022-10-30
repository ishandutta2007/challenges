#!/usr/bin/env python

"""

Introduction
According to the Riemann Hypothesis, all zeroes of the Riemann zeta function are either negative even integers (called trivial zeroes) or complex numbers of the form 1/2 ± i*t for some real t value (called non-trivial zeroes).
For this challenge, we will be considering only the non-trivial zeroes whose imaginary part is positive, and we will be assuming the Riemann Hypothesis is true.
These non-trivial zeroes can be ordered by the magnitude of their imaginary parts. The first few are approximately 0.5 + 14.1347251i, 0.5 + 21.0220396i, 0.5 + 25.0108576i, 0.5 + 30.4248761i, 0.5 + 32.9350616i.

The Challenge
Given an integer N, output the imaginary part of the Nth non-trivial zero of the Riemann zeta function, rounded to the nearest integer (rounded half-up, so 13.5 would round to 14).

Rules
The input and output will be within the representable range of integers for your language.
As previously stated, for the purposes of this challenge, the Riemann Hypothesis is assumed to be true.
You may choose whether the input is zero-indexed or one-indexed.
Test Cases
The following test cases are one-indexed.

1       14
2       21
3       25
4       30
5       33
6       38
7       41
8       43
9       48
10      50
50      143
100     237
OEIS Entry
This is OEIS sequence A002410.

"""

from sage.lfunctions.all import *

# http://oeis.org/A002410
def term(n):
    l = lcalc.zeros(n)
    return l[n-1].round()

def main():
    tab = [
        [1, 14],
        [2, 21],
        [3, 25],
        [4, 30],
        [5, 33],
        [6, 38],
        [7, 41],
        [8, 43],
        [9, 48],
        [10, 50],
        [50, 143],
        [100, 237],
    ]
    for v in tab:
        assert(term(v[0]) == v[1])

main()
