#!/usr/bin/env python
# -*- coding: utf-8 -*-

u"""
Create a function that takes an array and returns the sum of all numbers in the array.
Examples

getSumOfItems([2, 7, 4]) ➞ 13

getSumOfItems([45, 3, 0]) ➞ 48

getSumOfItems([-2, 84, 23]) ➞ 105
"""

import operator

def sum(xs):
    return reduce(operator.add, xs)

assert(sum([2, 7, 4]) == 13)
assert(sum([45, 3, 0]) == 48)
assert(sum([-2, 84, 23]) == 105)

