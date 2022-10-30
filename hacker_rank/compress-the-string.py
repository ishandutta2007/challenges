#!/usr/bin/env python

"""
In this task, we would like for you to appreciate the usefulness of the groupby() function of itertools.
To read more about this function, refer to https://docs.python.org/2/library/itertools.html#itertools.groupby.

You are given a string S. Suppose a character 'c' occurs consecutively X times in the string.
Replace these consecutive occurrences of the character 'c' with (X,c) in the string.

For a better understanding of the problem, check the explanation.
"""

from itertools import groupby

def compress(s):
    p = ""
    for k, g in groupby(s):
        p += "(%d, %s) " % (len(list(g)), k)
    return p[:-1]

print(compress("1222311"))
