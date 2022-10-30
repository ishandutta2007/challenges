#!/usr/bin/env python

"""

Create a function that sums up all the elements in the list recursively. The use of the sum() built-in function is not allowed, thus, the approach is recursive.

Examples

recur_add([1, 2, 3, 4, 10, 11]) ➞ 31

recur_add([-3, 4, 11, 10, 21, 32, -9]) ➞ 66

recur_add([-21, -7, 19, 3, 4, -8]) ➞ -10

Notes

    You're expected to solve this challenge using a recursive approach.
    You can read on more topics about recursion (see Resources tab) if you aren't familiar with it yet or haven't fully understood the concept behind it before taking up this challenge.

"""

def add(a):
    if len(a) == 0:
        return 0
    return a[0] + add(a[1:])

def main():
    itab = [[1, 2, 3, 4, 10, 11], [-3, 4, 11, 10, 21, 32, -9], [3, 7, -3, -7, 4, 6, -4, -6], [-21, -7, 19, 3, 4, -8], [], [16]]
    otab = [31, 66, 0, -10, 0, 16]
    for i in range(len(itab)):
        assert(add(itab[i]) == otab[i])

main()

