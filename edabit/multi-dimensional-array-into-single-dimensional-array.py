#!/usr/bin/env python

"""

Write a recursive function that transforms a multi-dimensional array into a single-dimensional array.

Examples

flatten([[17.2, 500, "code"], "generate"]) ➞ [17.2, 500, "code", "generate"]

flatten([[[[[2, 14, "core"]]], 2, 3, 4]]) ➞ [2, 14, "core", 2, 3, 4]

flatten([["dimension"], "vertical", [["objective"]]]) ➞ ["dimension", "vertical", "objective"]

flatten([[[[[["construct"]]]]]]) ➞ ["construct"]

Notes

    Array contains at least one element.
    A recursive approach to solving this challenge is gretly advised and is more convenient than the iterative approach.
    A similar version of this challenge can be found here..
    If you think recursion is fun, a collection of those challenges can be found here.

"""

def flatten(l):
    p = []
    for v in l:
        if isinstance(v, list):
            p += flatten(v)
        else:
            p.append(v)
    return p

def main():
    assert(flatten([[17.2, 500, "code"], "generate"]) == [17.2, 500, "code", "generate"])
    assert(flatten([[[[2, 14, "core"]]], 2, 3, 4]) == [2, 14, "core", 2, 3, 4])
    assert(flatten([["dimension"], "vertical", [[["objective"]]]]) == ["dimension", "vertical", "objective"])
    assert(flatten([[[["construct"]]]]) == ["construct"])
    assert(flatten([0, [12, "recurrence", [[[2]]]]]) == [0, 12, "recurrence", 2])
    assert(flatten([[3.1415926, 3.2e5, "absolute", "edabit"]]) == [3.1415926, 320000.0, "absolute", "edabit"])
    assert(flatten([4, 6, 6, 6, [579, 466, 876, 696]]) == [4, 6, 6, 6, 579, 466, 876, 696])
    assert(flatten([3.14, [1.59, [2.65, [3.58, [9.79]]]]]) == [3.14, 1.59, 2.65, 3.58, 9.79])

main()
