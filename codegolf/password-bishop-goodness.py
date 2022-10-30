#!/usr/bin/env python

"""

Given a string, answer (truthy/falsy or two consistent values) if it constitutes a good Bishop password, which is when all the following conditions are met:

it has at least 10 characters

it has at least 3 digits ([0-9])

it is not a palindrome (identical to itself when reversed)

You get 0 bytes bonus if your code is a good Bishop password.

Warning: Do not use Bishop goodness as a measure of actual password strength!

Examples
Good Bishop passwords
PPCG123GCPP
PPCG123PPCG
PPCG123gcpp
0123456789
Tr0ub4dor&3

Not Good Bishop passwords
PPCG123 (too short)
correct horse battery staple (not enough digits)
PPCG121GCPP (palindrome)
 (too short and not enough digits)
abc121cba (too short and palindrome)
aaaaaaaaaaaa (palindrome and not enough digits)
abc99cba (everything wrong)

"""

def good_bishop(s):
    d = 0
    n = 0
    for c in s:
        if '0' <= c and c <= '9':
            d += 1
        n += 1
    return n >= 10 and d >= 3 and s != s[::-1]

def main():
    assert(good_bishop("PPCG123GCPP") == True)
    assert(good_bishop("PPCG123PPCG") == True)
    assert(good_bishop("PPCG123gcpp") == True)
    assert(good_bishop("0123456789") == True)
    assert(good_bishop("Tr0ub4dor&3") == True)

    assert(good_bishop("PPCG123") == False)
    assert(good_bishop("correct horse battery staple") == False)
    assert(good_bishop("PPCG121GCPP") == False)
    assert(good_bishop("") == False)
    assert(good_bishop("abc121cba") == False)
    assert(good_bishop("aaaaaaaaaaaa") == False)
    assert(good_bishop("abc99cba") == False)

main()
