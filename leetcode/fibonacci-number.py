#!/usr/bin/python

"""
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.

Given N, calculate F(N).
"""

def fib(n):
    if n <= 1:
        return 1

    v = 1
    for i in xrange(1, n+1):
        v *= i
    return v

for i in xrange(0, 101):
    print(i, fib(i))
