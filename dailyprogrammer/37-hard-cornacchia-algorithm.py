#!/usr/bin/env python

"""

Your task is to implement Cornacchia’s algorithm and use it to demonstrate that all primes of the form 4k+1 and less than 1000 can be written as the sum of two squares.

source: programmingpraxis.com

"""

from sympy import *
from math import *

def quadratic_residue(d, m):
    for i in range(m):
        if (i*i) % m == d:
            return i
    return None

# https://programmingpraxis.com/2012/04/03/cornacchias-algorithm/
# https://en.wikipedia.org/wiki/Cornacchia's_algorithm
def cornacchia(m):
    r0 = m
    r1 = quadratic_residue(m - 1, m)
    if r1 is None:
        return (-1, -1)
        
    while r1*r1 >= m:
        r2 = r0 % r1
        r0 = r1
        r1 = r2
        
    s = (m - r1*r1)
    sq = int(sqrt(s))
    if sq*sq != s:
        return (-1, -1)

    return (r1, sq)

def verify(n):
    p = set(primerange(n))
    for k in range(4, n, 4):
        m = k + 1
        if m not in p:
            continue

        (x, y) = cornacchia(m)
        if x < 0:
            print("Failed on prime", m)
            continue

        assert(x*x + y*y == m)
        print("%d^2 + %d^2 == %d" % (x, y, m))

def main():
    verify(100000)

main()
