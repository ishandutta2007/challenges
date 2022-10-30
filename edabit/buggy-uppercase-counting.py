#!/usr/bin/env python

"""

In the Code tab is a function which is meant to return how many uppercase letters there are in a list of various words.
Fix the list comprehension so that the code functions normally!

Examples

count_uppercase(["SOLO", "hello", "Tea", "wHat"]) ➞ 6

count_uppercase(["little", "lower", "down"]) ➞ 0

count_uppercase(["EDAbit", "Educate", "Coding"]) ➞ 5

Notes

Check the Resources for some helpful tutorials on list comprehensions.

"""

def count_uppercase(l):
    r = 0
    for s in l:
        for c in s:
            if c.isupper():
                r += 1
    return r

def main():
    assert(count_uppercase(["SOLO", "hello", "Tea", "wHat"]) == 6)
    assert(count_uppercase(["little", "lower", "down"]) == 0)
    assert(count_uppercase(["EDAbit", "Educate", "Coding"]) == 5)

main()

