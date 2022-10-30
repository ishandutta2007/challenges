#!/usr/bin/env python

"""

Imagine each letter and its position within the alphabet. Now assign each letter its corresponding value ie a=1, b=2,... z=26.
When given a list of words, order the words by the sum of the values of the letters in their names.

Example: Shoe and Hat

Hat: 8+1+20 = 29

Shoe: 19+8+15+5 = 47

So the order would be Hat, Shoe.

For extra points, divide by the sum by the number of letters in that word and then rank them.

thanks to SpontaneousHam for the challenge at r/dailyprogrammer_ideas .. link

Please note that [difficult] challenge has been changed since it was already asked

http://www.reddit.com/r/dailyprogrammer/comments/tmnfn/5142012_challenge_52_difficult/

fortunately, someone informed it very early :)

"""

from functools import *

def value(s):
    r = 0
    for c in s:
        if 'a' <= c and c <= 'z':
            r += ord(c) - ord('a') + 1
        elif 'A' <= c and c <= 'Z':
            r += ord(c) - ord('A') + 1
        else:
            r += ord(c)
    return r

def wordcmp(a, b):
    x = value(a)
    y = value(b)
    if x < y:
        return -1
    if x > y:
        return 1
    return 0

def wordsort(l):
    return sorted(l, key=cmp_to_key(wordcmp))

def main():
    assert(wordsort(['Shoe', 'Hat']) == ['Hat', 'Shoe'])
    assert(wordsort(['za', 'az']) == ['za', 'az'])
    assert(wordsort(['z', 'y', 'abc']) == ['abc', 'y', 'z'])

main()
