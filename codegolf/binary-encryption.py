#!/usr/bin/env python

"""

This is based on xkcd #153.

Make a program or named function which takes 2 parameters, each of which is a string or a list or array of bytes or characters.
The second parameter will only contain characters drawn from lrfu (or the equivalent ASCII bytes).
It should be interpreted as a series of instructions to be performed on a bit sequence represented by the first parameter.

The processing performed must be equivalent to the following:

Convert the first parameter into a single bitstring formed by concatenating the bits of each character (interpreted as one of 7-bit ASCII, an 8-bit extended ASCII, or a standard Unicode encoding).
E.g. if the first parameter is "AB" then this would be one of 10000011000010 (7-bit), 0100000101000010 (8-bit or UTF-8), 00000000010000010000000001000010, or 01000001000000000100001000000000 (UTF-16 in the two endiannesses), etc.
For each character in the second parameter, in order, execute the corresponding instruction:
l rotates the bitstring left one. E.g. 10000011000010 becomes 00000110000101.
r rotates the bitstring right one. E.g. 10000011000010 becomes 01000001100001.
f flips (or inverts) each bit in the bitstring. E.g. 10000011000010 becomes 01111100111101.
u reverses the bitstring. E.g. 10000011000010 becomes 01000011000001.
Convert the bitstring into an ASCII string which uses one character per bit. E.g. 10000011000010 becomes "10000011000010". This is because not all sets of 7/8 bits have a character assigned to them.
Example (in Python):

>>> f("b", "rfu")
01110011
It turns "b" into its 8-bit ASCII binary representation 01100010, rotates it right (00110001), flips each bit (11001110), and reverses it (01110011).

Flexibility
Other characters may be used instead of the characters l, r, f, and u, but they must be clearly documented.

"""

def number(s):
    r = ""
    for i in range(len(s)):
        b = bin(ord(s[i]))[2:]
        l = len(b)
        if l < 8:
            b = '0'*(8-l) + b
        r += b
    return r

def rotl(s):
    return s[1:] + s[0]

def rotr(s):
    return s[-1] + s[:len(s)-1]

def flip(s):
    r = ""
    for i in range(len(s)):
        if s[i] == '1':
            r += "0"
        else:
            r += "1"
    return r

def interpret(s, p):
    for c in s:
        if c == 'r':
            p = rotr(p)
        elif c == 'l':
            p = rotl(p)
        elif c == 'f':
            p = flip(p)
        elif c == 'u':
            p = p[::-1]
    return p

def encrypt(s, t):
    return interpret(t, number(s))

def main():
    assert(encrypt("b", "rfu") == "01110011")
    assert(encrypt("AB", "") == "0100000101000010")
    assert(encrypt("AB", "l") == "1000001010000100")
    assert(encrypt("AB", "ll") == "0000010100001001")

main()
