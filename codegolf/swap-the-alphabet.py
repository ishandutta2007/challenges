#!/usr/bin/env python

"""

In this challenge, you will be "reversing" the alphabet or swapping a-z with z-a. This is commonly known as the Atbash cypher.

Because this transformation makes the output look like some foreign language, your code will need to be as short as possible.

Examples
abcdefghijklmnopqrstuvwxyz
zyxwvutsrqponmlkjihgfedcba

Programming Puzzles & Code Golf
Kiltiznnrmt Kfaaovh & Xlwv Tlou

Hello, World!
Svool, Dliow!
Specification
The input may contain multiple lines, and will be ASCII-only
No additional whitespace should be added to the output
Case must be preserved

"""

def atbash(s):
    r = ""
    for c in s:
        if 'A' <= c and c <= 'Z':
            r += chr(ord('A') + ord('Z') - ord(c))
        elif 'a' <= c and c <= 'z':
            r += chr(ord('a') + ord('z') - ord(c))
        else:
            r += c
    return r

def main():
    assert(atbash("abcdefghijklmnopqrstuvwxyz") == "zyxwvutsrqponmlkjihgfedcba")
    assert(atbash("Programming Puzzles & Code Golf") == "Kiltiznnrmt Kfaaovh & Xlwv Tlou")
    assert(atbash("Hello, World!") == "Svool, Dliow!")

main()
