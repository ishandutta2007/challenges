#!/usr/bin/env python

"""

Given a list of integers, such as {1, 4, 2, 8, 10}, TI-Basic's ΔList will determine the difference between every overlapping pair of items. In the given example, it would be {3, -2, 6, 2}.

Task:

Take a list of integers as input, in any reasonable way. All overlapping pairs {x, y} should become y - x, and the resulting list returned. It should always be one item shorter. You can assume the list will never be shorter than two items.

Test cases:

{1, 2}                  {1}
{1, 2, 4}               {1, 2}
{2, 1}                  {-1}
{2, 2, 2}               {0, 0}
{-1, 0, 0, -1}          {1, 0, -1}
{0, 1, 2, 1, 1, 0}      {1, 1, -1, 0, -1}
Other:

This is code-golf. Shortest answer (in bytes) per language wins!

"""

def delta(l):
    p = []
    i = 1
    while i < len(l):
        p.append(l[i] - l[i-1])
        i += 1
    return p

def main():
    assert(delta([1, 2]) == [1])
    assert(delta([1, 2, 4]) == [1, 2])
    assert(delta([2, 1]) == [-1])
    assert(delta([2, 2, 2]) == [0, 0])
    assert(delta([-1, 0, 0, -1]) == [1, 0, -1])
    assert(delta([0, 1, 2, 1, 1, 0]) == [1, 1, -1, 0, -1])

main()
