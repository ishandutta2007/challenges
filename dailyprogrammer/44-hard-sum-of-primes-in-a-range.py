#!/usr/bin/env python

"""

Write a function that takes two arguments a and b, and finds all primes that are between a and a + b (specifically, find all primes p such that a ≤ p < a + b). So for instance, for a = 1234 and b = 100, it should return the following 15 primes:

1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327

The sum of those primes are 19339. The number of primes for a = 9! and b = 8! is 3124 and the sum of those primes is 1196464560.

How many primes are there for a = 16! and b = 10!, and what is their sum?

Note 1: In this problem, n! refers to the factorial of n, 1*2*3*...*(n-1)*n, so 9! is equal to 362880.

Note 2: All numbers and solutions in this problem fit into 64-bit integers.

EDIT: changed some incorrect numbers, thanks ixid!

"""

from math import *
from sympy import *

def primesum(a, b):
    p = list(primerange(a, a+b))
    return (len(p), sum(p))

def main():
    assert(primesum(1234, 100) == (15, 19339))
    assert(primesum(factorial(9), factorial(8)) == (3124, 1196464560))
    assert(primesum(factorial(16), factorial(10)) == (118163, 2472299836292782219))

main()
