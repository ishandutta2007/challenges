#!/usr/bin/env python

"""

Given an expression like 4 / 2 + 3, determine whether the expression has the same value in Python 2 and Python 3.
Recall that in Python 2 division rounds down (so that 5 / 2 -> 2), whereas in Python 3 division returns a float (so that 5 / 2 -> 2.5).

For simplicity's sake, we will only consider expressions of the form:

a o1 b o2 c
Where

a, b, and c are numbers between 1 and 5 inclusive; and
o1 and o2 are either the addition, multiplication or division operators (+, *, /)
Note that the restrictions mean the expression will always be the same length and will never have any zero division issues.

Operator precedence is the same as in Python (* and / have equal and higher precedence to +, evaluated left to right).

Since this is in part a parsing challenge, you must take the input exactly as given including spacing in a string-like form appropriate for your language (and not, for example, a preparsed AST).

You can print or return any two distinct consistent values to indicate true or false.

Test cases
1 + 2 + 3 -> true
2 * 3 + 5 -> true
3 / 3 + 3 -> true
4 / 2 * 2 -> true
2 * 2 / 4 -> true
4 / 2 / 1 -> true
5 + 4 / 2 -> true

1 / 2 + 3 -> false
5 / 2 * 2 -> false
3 / 2 * 4 -> false
2 + 3 / 5 -> false
4 / 4 / 4 -> false

Scoring
This is code golf, shortest code in bytes wins.

"""

def safe(s):
    t = s.replace("/", "//")
    try:
        x = eval(s)
        y = eval(t)
    except:
        return False
    return x == y

def main():
    assert(safe("1 + 2 + 3") == True)
    assert(safe("2 * 3 + 5") == True)
    assert(safe("3 / 3 + 3") == True)
    assert(safe("4 / 2 * 2") == True)
    assert(safe("2 * 2 / 4") == True)
    assert(safe("4 / 2 / 1") == True)
    assert(safe("5 + 4 / 2") == True)

    assert(safe("1 / 2 + 3") == False)
    assert(safe("5 / 2 * 2") == False)
    assert(safe("3 / 2 * 4") == False)
    assert(safe("2 + 3 / 5") == False)
    assert(safe("4 / 4 / 4") == False)

main()
