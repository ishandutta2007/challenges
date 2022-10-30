#!/usr/bin/env python

"""

Create strings that, when evaluated with eval(), equal the number associated with the string name. The only alphanumeric characters allowed is the substring "chr".

Examples

zero = "write"
one = "your"
two = "strings"
fifty = "here"

eval(zero) ➞ 0

eval(one) ➞ 1

eval(two) ➞ 2

eval(fifty) ➞ 50

Notes

    Hint: The equality operator returns a boolean value, and boolean values can be coerced.
    The rest of the collection can be found here.

"""

zero = "0"
one = "1"
two = "2"
fifty = "50"

assert(eval(zero) == 0)
assert(eval(one) == 1)
assert(eval(two) == 2)
assert(eval(fifty) == 50)
