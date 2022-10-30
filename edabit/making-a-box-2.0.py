#!/usr/bin/env python

"""

This is based on Helen Yu's Making a Box challenge. This challenge is the same except that instead of an array of strings, your function should output a matrix of characters.

Examples

charBox(1) ➞ [
  ["#"]
]

charBox(4) ➞ [
  ["#", "#", "#", "#"],
  ["#", " ", " ", "#"],
  ["#", " ", " ", "#"],
  ["#", "#", "#", "#"]
]

charBox(2) ➞ [
  ["#", "#"],
  ["#", "#"]
]

Notes

As an added bonus, try making charBox(0) output [[]] and make any strings, non-integers, and negative numbers output -1.

"""

def box(n):
    if not isinstance(n, int) or n < 0:
        return -1
    if n == 0:
        return [[]]

    l = []
    for i in range(n):
        if i == 0 or i+1 >= n:
            l.append(list("#"*n))
        else:
            l.append(list("#" + " "*(n-2) + "#"))
    return l

def main():
    assert(box(1) == [["#"]])
    assert(box(2) == [["#", "#"], ["#", "#"]])
    assert(box(4) == [["#", "#", "#", "#"], ["#", " ", " ", "#"], ["#", " ", " ", "#"], ["#", "#", "#", "#"]])
    assert(box(3) == [["#", "#", "#"], ["#", " ", "#"], ["#", "#", "#"]])
    assert(box(10) == [["#", "#", "#", "#", "#", "#", "#", "#", "#", "#"], ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#"], ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#"], ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#"], ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#"], ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#"], ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#"], ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#"], ["#", " ", " ", " ", " ", " ", " ", " ", " ", "#"], ["#", "#", "#", "#", "#", "#", "#", "#", "#", "#"]])
    assert(box(0) == [[]])
    assert(box("Hi") == -1)
    assert(box(-23) == -1)
    assert(box(-4) == -1)

main()
