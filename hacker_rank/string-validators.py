#!/usr/bin/env python

"""
You are given a string S.
Your task is to find out if the string S contains:
alphanumeric characters, alphabetical characters, digits, lowercase and uppercase characters.
"""

def validate(s):
    isalnum = False
    isalpha = False
    isdigit = False
    islower = False
    isupper = False
    for i in range(len(s)):
        if s[i].isalnum():
            isalnum = True
        if s[i].isalpha():
            isalpha = True
        if s[i].isdigit():
            isdigit = True
        if s[i].islower():
            islower = True
        if s[i].isupper():
            isupper = True

    print(s)
    print("alnum:", isalnum)
    print("alpha:", isalpha)
    print("digit:", isdigit)
    print("lower:", islower)
    print("upper:", isupper)
    print("\n")

validate("ab123")
validate("ab123#")
validate("abcD")
validate("abcd1")
validate("1234")
validate("123edsd")
validate("abcd123#")
validate("Abcd123#")
validate("ABCD123#")
validate("Abcd123#")
validate("qA2")
