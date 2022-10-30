#!/usr/bin/env python

"""

The goal of this code-golf is to create a program that takes a string as input, and you have to output the SHA-1 hash value as a hexadecimal number. You can find the pseudocode for SHA-1 here

Other rules:

No network access
You're not allowed to run external programs
You're not allowed to use built-in methods to hash the input
The shortest code wins
It's only necessary to handle ASCII input
Output can be either lowercase or uppercase
The input can be provided using:

Prompting for input
Using command-line arguments
Using STDIN
Test cases:

Input: The quick brown fox jumps over the lazy dog
Output: 2fd4e1c67a2d28fced849ee1bb76e7391b93eb12
----------------------------------------------------------
Input: The quick brown fox jumps right over the lazy dog
Output: 1c3aff41d97ada6a25ae62f9522e4abd358d741f
------------------------------------------------------------
Input: This is a code golf challenge
Output: f52ff9edd95d98e707bd16a7dead459cb8db8693

"""

import hashlib

def sha1sum(s):
    h = hashlib.sha1()
    h.update(s)
    return h.hexdigest()

def main():
    assert(sha1sum(b"The quick brown fox jumps over the lazy dog") == "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12")
    assert(sha1sum(b"The quick brown fox jumps right over the lazy dog") == "1c3aff41d97ada6a25ae62f9522e4abd358d741f")
    assert(sha1sum(b"This is a code golf challenge") == "f52ff9edd95d98e707bd16a7dead459cb8db8693")

main()
