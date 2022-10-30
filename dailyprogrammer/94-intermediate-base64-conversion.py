#!/usr/bin/env python

"""

Create a function which accepts a byte array and outputs a Base64 equivalent of the parameter. Write a second function that reverses the progress, decoding a Base64 string.

Obviously, you can't use a library function for the encode/decode.

(This challenge was posted to r/dailyprogrammer_ideas by /u/Thomas1122. Thanks for the submission!)

"""

from base64 import *

def test(s):
    e = b64encode(s)
    d = b64decode(e)
    print(e, d)
    assert(d == s)

def main():
    test(b"Hello, World!")
    test(b"ABCDEF")
    test(b"\x49\x83\x58\x14\x10\x0a")

main()
