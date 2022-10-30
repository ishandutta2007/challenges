#!/usr/bin/env python

"""
Given the names and grades for each student in a Physics class of N students,
store them in a nested list and print the name(s) of any student(s) having the second lowest grade.

Note: If there are multiple students with the same grade, order their names alphabetically and print each name on a new line.
"""

from operator import itemgetter

def isclose(a, b, rel_tol=1e-09, abs_tol=0.0):
    return abs(a - b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)


def grade(l):
    p = sorted(l, key=lambda x: (x[1], x[0]))
    i = 0
    while i < len(p) - 1 and isclose(p[i][1], p[i + 1][1]):
        i += 1
    i += 1

    while i < len(p) - 1:
        print(p[i][0])
        if not isclose(p[i][1], p[i + 1][1]):
            break
        i += 1


students = [
    ['Harry', 37.21],
    ['Berry', 37.21],
    ['Tina', 37.2],
    ['Akriti', 41],
    ['Harsh', 39],
]
grade(students)
