#!/usr/bin/env python

"""

Create a program that will find all prime numbers below 2000

"""

import sympy

def main():
    primes = list(sympy.primerange(0, 2000))
    print(primes)

main()

