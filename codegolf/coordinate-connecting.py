#!/usr/bin/env python

"""

Input:

Ten unique integer coordinates, between (0,0) and (100,100).

Output:

The coordinates arranged in the order/an order such that a path drawn between the coordinates in that order is the shortest path possible.

This is code golf so the shortest code wins!

"""

import random
import itertools

def distance(a, b):
    x = a[0] - b[0]
    y = a[1] - b[1]
    return x*x + y*y

def cost(v):
    d = 0
    i = 0
    while i+1 < len(v):
        d += distance(v[i], v[i+1])
        i += 1
    return d

def path(p):
    l = list(itertools.permutations(p))
    d = -1
    r = []
    for v in l:
        e = cost(v)
        if d < 0 or e < d:
            r = v
            d = e
    return r

def random_path(n):
    l = []
    for i in range(n):
        x = random.randint(0, 100)
        y = random.randint(0, 100)
        l.append((x, y))
    return l

def main():
    print(path([[0, 0], [0, 1], [1, 0], [0, 2], [2, 0], [1, 2], [2, 1], [2, 2]]))
    print()
    for i in range(10):
        p = random_path(10)
        r = path(p)
        print(p)
        print(r)
        print()

main()
