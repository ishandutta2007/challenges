#!/usr/bin/env python

"""

Write a snippet to calculate the mode (most common number) of a list of positive integers.

For example, the mode of

d = [4,3,1,0,6,1,6,4,4,0,3,1,7,7,3,4,1,1,2,8]

is 1, because it occurs the maximum of 5 times.

You may assume that the list is stored in a variable such as d and has a unique mode.

e.g.: Python, 49

max(((i,d.count(i))for i in set(d)), key=lambda x:x[1])

This is code-golf, so the shortest solution in bytes wins.

"""

def mode(l):
    return max(l, key=l.count)

def main():
    assert(mode([4,3,1,0,6,1,6,4,4,0,3,1,7,7,3,4,1,1,2,8]) == 1)

main()
