#!/usr/bin/env python

"""

Create a function that takes an array of integers and returns all pairs of integers that have a difference of two. The resulting array should be sorted in ascending order of values.

Examples

differenceTwo([1, 2, 3, 4]) ➞ [[1, 3], [2, 4]]

differenceTwo([1, 23, 3, 4, 7]) ➞ [[1, 3]]

differenceTwo([4, 3, 1, 5, 6]) ➞ [[1, 3], [3, 5], [4, 6]]

Notes

Assume there are no duplicate integers in the array. The order of the integers in the input array should not matter.

"""

def difference_two(a):
    m = {}
    r = []
    for v in a:
        m[v] = True
    for v in a:
        if v+2 in m:
            r.append([v, v+2])
    r.sort()
    return r

def main():
    assert(difference_two([1, 2, 3, 4]) == [[1, 3], [2, 4]])
    assert(difference_two([1, 23, 3, 4, 7]) == [[1, 3]])
    assert(difference_two([4, 3, 1, 5, 6]) == [[1, 3], [3, 5], [4, 6]])

main()

