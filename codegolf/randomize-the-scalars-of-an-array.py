#!/usr/bin/env python

"""

You must fill an array with every number from 0-n inclusive. No numbers should repeat. However they must be in a random order.

Rules

All standard code-golf rules and standard loopholes are banned

The array must be generated pseudo-randomly. Every possible permutation should have a equal probability.
Input

n in any way allowed in the I/O post on meta.
Output

The array of numbers scrambled from 0-n inclusive.

"""

import random

def perm(n):
    l = []
    for i in range(n+1):
        l.append(i)
    random.shuffle(l)
    return l

def main():
    print(perm(100))

main()
