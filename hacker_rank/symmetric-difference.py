#!/usr/bin/env python

"""
Given 2 sets of integers, M and N, print their symmetric difference in ascending order.
The term symmetric difference indicates those values that exist in either M or N but do not exist in both.
"""

def symmetric_difference(a, b):
    x = a.union(b)
    y = a.intersection(b)
    return x.difference(y)

def do(a, b):
    l = sorted(list(symmetric_difference(a, b)))
    for v in l:
        print(v)

a = set([2, 4, 5, 9])
b = set([2, 4, 11, 12])
do(a, b)
