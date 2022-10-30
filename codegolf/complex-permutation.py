#!/usr/bin/env python

"""

Given an array of numbers as input, find all permutations that do not have the same number next to each other, then print them all out.
If no permutations were found, print "Nothing". Note that the original array can be a permutation.

Test cases:

[0, 1, 1, 0] -> [1, 0, 1, 0], [0, 1, 0, 1]
[0, 1, 2, 0] -> [0, 1, 2, 0], [0, 2, 1, 0], [1, 0, 2, 0], [0, 1, 0, 2], [2, 0, 1, 0], [0, 2, 0, 1]
[0, 1, 0] -> [0, 1, 0]
[1, 1, 1] -> Nothing
[0, 0, 1, 1] -> [0, 1, 0, 1], [1, 0, 1, 0]
Remember that this is code golf, so the shortest answer (in bytes) wins!

"""

from itertools import *

def sameness(p):
    for i in range(len(p)-1):
        if p[i] == p[i+1]:
            return False
    return True

def permute(a):
    l = []
    n = len(a)
    for p in permutations(a):
        if sameness(p):
            l.append(p)
    return set(l)

def main():
    print(permute([0, 1, 1, 0]))
    print(permute([0, 1, 2, 0]))
    print(permute([0, 1, 0]))
    print(permute([1, 1, 1]))
    print(permute([0, 0, 1, 1]))

main()
