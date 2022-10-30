#!/usr/bin/env python

"""

You have to make something that takes in one input from a default I/O method (as an integer), and prints out the sum of all the permutations of that number (not necessarily unique)

For example:

10 would return 11 because 10 can have 2 permutations (10 and 01), and the sum of those two numbers would be 11

202 would have 6 permutations (202, 220, 022, 022, 202, 220), so the sum would be 888.

The input is positive, and the input can be taken as any type, but your program's output must be a number.

Standard loopholes are not allowed, and as usual, since this is code golf, the shortest answer in bytes wins!

"""

from itertools import permutations

def digits(n):
    d = []
    while True:
        d.append(n % 10)
        n //= 10
        if n == 0:
            break
    return d

def number(d):
    r = 0
    for i in d:
        r = (10 * r) + i
    return r

def sumperm(n):
    d = digits(n)
    s = 0
    for p in permutations(d):
        s += number(p)
    return s

def main():
    assert(sumperm(10) == 11)
    assert(sumperm(202) == 888)

main()
