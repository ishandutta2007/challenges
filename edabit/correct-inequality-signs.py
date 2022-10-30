#!/usr/bin/env python

"""

Create a function that returns True if a given inequality expression is correct and False otherwise.

Examples

correct_signs("3 < 7 < 11") ➞ True

correct_signs("13 > 44 > 33 > 1") ➞ False

correct_signs("1 < 2 < 6 < 9 > 3") ➞ True

Notes

N/A

"""


def inequality(s):
    return eval(s) == True

def main():
    assert(inequality("3 < 7 < 11") == True)
    assert(inequality("13 > 44 > 33 > 1") == False)
    assert(inequality("1 < 2 < 6 < 9 > 3") == True)
    assert(inequality("4 > 3 > 2 > 1") == True)
    assert(inequality("5 < 7 > 1") == True)
    assert(inequality("5 > 7 > 1") == False)
    assert(inequality("9 < 9") == False)

main()
