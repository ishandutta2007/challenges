#!/usr/bin/env python

"""

The Challenge

Write a program that can take an input of a single-line string containing any ASCII printable characters, and output the same string encoded in Base85 (using a big-endian convention). You can assume that the input will always be ≤ 100 characters.

A Guide to Base85
Four octets are encoded into (usually) five Base85 characters.

Base85 characters range from ! to u (ASCII 33 - 117) and z (ASCII 122).

To encode, you continuously perform division by 85 on the four octets (a 32-bit number), and add 33 to the remainder (after each division) to get the ASCII character for the encoded value.
For example, the first application of this process produces the rightmost character in the encoded block.

If a set of four octets contains only null bytes, they are encoded as a z instead of !!!!!.

If the last block is shorter than four octets, it's padded with null bytes. After encoding, the same number of characters that were added as padding, are removed from the end of the output.

The encoded value should be preceded by <~ and followed by ~>.

The encoded value should contain no whitespace (for this challenge).

Examples
In: easy
Out: <~ARTY*~>

In: test
Out: <~FCfN8~>

In: code golf
Out: <~@rGmh+D5V/Ac~>

In: Programming Puzzles
Out: <~:i^JeEa`g%Bl7Q+:j%)1Ch7Y~>
The following snippet will encode a given input to Base85.

"""

import base64

def encode(s):
    b = s.encode("UTF-8")
    e = base64.a85encode(b)
    r = e.decode("UTF-8")
    return "<~" + r + "~>"

def main():
    assert(encode("easy") == "<~ARTY*~>")
    assert(encode("test") == "<~FCfN8~>")
    assert(encode("code golf") == "<~@rGmh+D5V/Ac~>")
    assert(encode("Programming Puzzles") == "<~:i^JeEa`g%Bl7Q+:j%)1Ch7Y~>")

main()
