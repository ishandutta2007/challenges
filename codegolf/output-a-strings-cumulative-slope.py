#!/usr/bin/env python

"""

Challenge

Given a string such as Hello World!, break it down into its character values: 72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100, 33.

Then calculate the difference between each consecutive pair of characters: 29, 7, 0, 3, -79, 55, 24, 3, -6, -8, -67.

Finally, sum them and print the final result: -39.

Rules

Standard loopholes apply
No using pre-made functions that perform this exact task
Creative solutions encouraged
Have fun
This is marked as code-golf, the shortest answer in bytes wins but will not be selected.

"""

def string_slope(s):
    r = 0
    for i in range(1, len(s)):
        r += (ord(s[i]) - ord(s[i-1]))
    return r

def main():
    assert(string_slope("Hello World!") == -39)

main()
