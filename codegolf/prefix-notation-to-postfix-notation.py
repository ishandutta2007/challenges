#!/usr/bin/env python

"""

Disclaimer: No, this is not a joke challenge to reverse a string.

Task
There is only one operation to support: subtraction (-).

You also only have two atoms to support: zero (0) and one (1).

Here, the prefix notation -AB is equivalent to the postfix notation AB-, where A and B are expressions.

Your task is to (recursively) convert an expression in prefix notation to its equivalent in postfix notation.

Definitions
An expression in prefix notation is generated by the following grammar:

S > -SS
S > 0
S > 1
An expression in postfix notation is generated by the following grammar:

S > SS-
S > 0
S > 1
Example

Prefix notation:  --01-0-01
Parentheses:      -(-01)(-0(-01))

Convert:          (01-)(0(01-)-)-
Postfix notation: 01-001--
-
Rules and freedom
You may rename the operation and the atoms to whichever character, as long as it is consistent.
The input format must be consistent with the output format (apart from the fact that the input is in prefix notation and the output is in postfix notation).
Testcase
Input       Output
1           1
0           0
-01         01-
-10         10-
--01-0-01   01-001---
Testcases credits to Dada.

"""

def operator(c):
    return c == '-'

def pre2post(s):
    p = []
    i = len(s) - 1
    while i >= 0:
        if operator(s[i]):
            a = p.pop()
            b = p.pop()
            p.append(a + b + s[i])
        else:
            p.append(s[i])
        i -= 1
    return p[0]

def main():
    assert(pre2post("1") == "1")
    assert(pre2post("0") == "0")
    assert(pre2post("-01") == "01-")
    assert(pre2post("-10") == "10-")
    assert(pre2post("--01-0-01") == "01-001---")

main()