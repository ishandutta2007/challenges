#!/usr/bin/env python

"""

Create a function Brackets() that takes a string and checks that the brackets in the math expression are correct. The function should return true or false.

Examples

Brackets("(a*(b-c)..... )") ➞ true

Brackets(")(a-b-45/7*(a-34))") ➞ false

Brackets("sin(90...)+.............cos1)") ➞ false

Notes

    The string may not contain brackets, then return true.
    String may contain spaces.
    The string may be empty.

"""

def brackets(s):
    p = 0
    for c in s:
        if c == '(':
            p += 1
        elif c == ')':
            if p <= 0:
                return False
            p -= 1
    return p == 0

def main():
    assert(brackets("(a*(b-c)     )") == True)
    assert(brackets(" ) (a-b-45/7*(a-34))") == False)
    assert(brackets("sin(90       )+      cos1)") == False)
    assert(brackets(" (...). .%_.(.... )") == True)
    assert(brackets(" (...)...(..(...).... )  ") == True)
    assert(brackets(") .. .() (        ).. . (") == False)
    assert(brackets(")))(((") == False)
    assert(brackets("  (...).!.)...(") == False)
    assert(brackets("a+b") == True)
    assert(brackets("") == True)
    assert(brackets("(a+f).`!£=.)...) ") == False)

main()

