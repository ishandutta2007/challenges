#!/usr/bin/env python

"""

Write the shortest possible code which converts tabs to spaces in the input. Tab size should be supplied as a parameter or be hardcoded in the code in a single place.

Spaces on output should point to the right column, e.g. (\t represents a tab character):

a\tb
aa\tb
aaa\tb
aaaa\tb
should become (for tab size 4):

a   b
aa  b
aaa b
aaaa    b
Of course there can be more than one tab in a line.

Line separator and tab character should match the system defaults (e.g. ASCII 10 and 9 on Unix).

"""

def convert(s):
    r = ""
    i = 0
    for c in s:
        if c != '\t':
            r += c
        else:
            r += " " * (4 - (i % 4))
        i += 1
    return r

def main():
    assert(convert("a\tb") == "a   b")
    assert(convert("aa\tb") == "aa  b")
    assert(convert("aaa\tb") == "aaa b")
    assert(convert("aaaa\tb") == "aaaa    b")

main()
