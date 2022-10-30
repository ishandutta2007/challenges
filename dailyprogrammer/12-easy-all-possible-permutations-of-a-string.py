#!/usr/bin/env python

"""

Write a small program that can take a string:

"hi!"

and print all the possible permutations of the string:

"hi!"

"ih!"

"!hi"

"h!i"

"i!h"

etc...

thanks to hewts for this challenge!

"""

import itertools

def strperm(s):
    l = itertools.permutations(s)
    for i in l:
        print(''.join(i));

def main():
    strperm("hi!")

main()
