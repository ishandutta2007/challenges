#!/usr/bin/env python

"""

Write a program or function which takes a string of text as input and outputs the number of non-alphabetical characters in it (standard I/O rules apply). A non-alphabetical character is any character not appearing in this string:

abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
In terms of ASCII character codes, that's anything not in ranges 65-90 inclusive or 97-122 inclusive.

Rules
Your program must be able to handle all of printable ASCII, as well as any characters that appear in your code.
In other words, you may assume input will not contain any characters iff they are in neither printable ASCII nor your solution.
Printable ASCII here means ASCII's character codes 32-126 inclusive as well as character code 10 (Meaning you will have to count spaces and newlines).

You may assume that input will not be empty.

Scoring
Your score is the number of non-alphabetical characters (not bytes!) in your code. Lowest score wins, with code-golf as a tie-breaker.

Examples
"input" => output
"example" => 0
"3xampl3" => 2
"Hello, World!" => 3
"abc.def-" => 2
"     " => 5
"IT'S NORMAL" => 2
"•¥¥€???!!!" => 10
"abc
def" => 1

"""

def count(s):
    r = 0
    for c in s:
        if not (('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z')):
            r += 1
    return r

def main():
    assert(count("example") == 0)
    assert(count("3xampl3") == 2)
    assert(count("Hello, World!") == 3)
    assert(count("abc.def-") == 2)
    assert(count("     ") == 5)
    assert(count("IT'S NORMAL") == 2)
    assert(count("•¥¥€???!!!") == 10)
    assert(count("abc\ndef") == 1)

main()
