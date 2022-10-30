#!/usr/bin/env python

"""

Introduction
A pure word (or perfect word), as defined by me, is a word where the sum of the position in the alphabet of each letter in the word is perfectly divisible by the total length of the word. For example, abcb is a perfect word because 1 + 2 + 3 + 2 = 8, and 8 / 4 = 2.

Your task
Given a word as input, output whether or not it is a perfect word. The word may always be assumed to be lowercase.

Scoring
This is code-golf, so shortest program in bytes wins.

Examples
abcb: truthy
ccc: truthy
aaa: truthy
pure: truthy
word: truthy
bed: falsy
code: falsy
bode: falsy

"""

def pure(s):
    r = 0
    n = 0
    for c in s:
        if 'A' <= c and c <= 'Z':
            r += ord(c) - ord('A') + 1
        elif 'a' <= c and c <= 'z':
            r += ord(c) - ord('a') + 1
        else:
            return False
        n += 1
    return r%n == 0

def main():
    assert(pure("abcb") == True)
    assert(pure("ccc") == True)
    assert(pure("aaa") == True)
    assert(pure("pure") == True)
    assert(pure("word") == True)
    assert(pure("bed") == False)
    assert(pure("code") == False)
    assert(pure("bode") == False)

main()
