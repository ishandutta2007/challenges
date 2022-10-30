#!/usr/bin/env python

"""

In this challenge, you have to verify that every, or some, of the given variables, pass a given test condition. There are seven parameters:

    test: A string being the condition to verify.
    val: A string with two possible values:
        everybody if every variable has to pass the test;
        somebody if at least one of the variables has to pass the test.
    a, b, c, d, e: The variables being integers or booleans.

Create a function that returns True or False, depending on the result of the test applied to the variables.

Examples

every_some(">= 1", "everybody", 1, 1, -1, 1, 1) ➞ False
# Is every variable >= 1?

every_some(">= 1", "somebody", -1, -1, -1, -1, 1) ➞ True
# Is some variable >= 1?

every_some("< 4 / 2", "everybody", 1, 2, 1, 0, -10) ➞ False
# Is every variable < 2?

Notes

N/A

"""

def every_some(t, v, a, b, c, d, e):
    if v != "everybody" and v != "somebody":
        return False

    for u in [a, b, c, d, e]:
        r = eval(str(u) + t)
        if v == "everybody" and not r:
            return False
        elif v == "somebody" and r:
            return True
    return v != "somebody"

def main():
    assert(every_some(">= 1", "everybody", 1, 1, -1, 1, 1) == False)
    assert(every_some(">= 1", "somebody", -1, -1, -1, -1, 1) == True)
    assert(every_some("< 4 / 2", "everybody", 1, 2, 1, 0, -10) == False)
    assert(every_some("!= 0", "everybody", False, False, False, False, False) == False)
    assert(every_some("<= 10 * 2", "somebody", 21, 68, 104, 20, 3) == True)
    assert(every_some("!= 1", "everybody", True, True, True, True, True) == False)
    assert(every_some("== 9 % 9", "somebody", 9, 1, 81, 218, 33) == False)

main()

