#!/usr/bin/env python

"""

The exercise today asks you to validate a telephone number, as if written on an input form.
Telephone numbers can be written as ten digits, or with dashes, spaces, or dots between the three segments, or with the area code parenthesized;
both the area code and any white space between segments are optional.

Thus, all of the following are valid telephone numbers: 1234567890, 123-456-7890, 123.456.7890, (123)456-7890, (123) 456-7890 (note the white space following the area code), and 456-7890.

The following are not valid telephone numbers: 123-45-6789, 123:4567890, and 123/456-7890.

source: programmingpraxis.com

"""

def isdigit(c):
    return '0' <= c and c <= '9'

def issep(c):
    return c == '-' or c == ' ' or c == '.'

def check(s, f):
    i, j = 0, 0
    while i < len(s) and j < len(f):
        if f[j] == 'x':
            if not isdigit(s[i]):
                return False
        elif f[j] == '-':
            if isdigit(s[i]):
                j += 1
                continue
            if not issep(s[i]):
                return False
        elif f[j] == '(' or f[j] == ')':
            if s[i] != f[j]:
                return False

        i += 1
        j += 1

    return i == len(s) and j == len(f)

def phone(s):
    fmts = ["xxx-xxx-xxxx", "(xxx)-xxx-xxxx", "xxx-xxxx"]
    for f in fmts:
        if check(s, f):
            return True
    return False

def main():
    assert(phone("1234567890") == True)
    assert(phone("123-456-7890") == True)
    assert(phone("123.456.7890") == True)
    assert(phone("(123)456-7890") == True)
    assert(phone("(123) 456-7890") == True)
    assert(phone("456-7890") == True)

    assert(phone("123-45-6789") == False)
    assert(phone("123:4567890") == False)
    assert(phone("123/456-7890") == False)

main()
