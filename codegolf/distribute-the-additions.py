#!/usr/bin/env python

"""

Challenge: Given an expressions made of additions and multiplications, output an expression that is a sum of products.
The output must be equivalent to the input modulo the law of distribution. For example, 1+((2+5×6)×(3+4)) becomes 1+2×3+2×4+5×6×3+5×6×4. This is code-golf.

This task is useful in automatic theorem proving, since the conversion to disjunctive normal forms is exactly the same task. (Oops, that gives away a Mathematica builtin!)

Clarifications:

You can assume the numbers are whatever you want, integers, floats, or even just strings of symbols, as long as it's convenient.
You can use the law of distribution, commutativity and associativity of addition and multiplication. But you cannot use any other property of addition or multiplication. So e.g. 3×(1+3)→3+3×3 is not acceptable.
This means that answers are not unique, the test cases are just a reference.
Parentheses are optional, you won't need them anyway.
You can assume any reasonable input form.
Test cases:

2 -> 2 (Corner case, you can ignore this.)
1+3 -> 1+3
1+(3*4) -> 1+3*4
1+3*4 -> 1+3*4
(1+3)*4 -> 1*4+3*4
(1+2+3)*(4+5+6) -> 1*4+2*4+3*4+1*5+2*5+3*5+1*6+2*6+3*6
(1+2*(3+4))*((5+6)*7)+8 -> 1*5*7+1*6*7+2*3*5*7+2*3*6*7+2*4*5*7+2*4*6*7+8

"""

from sympy import *

def isdigit(c):
    return '0' <= c and c <= '9'

def number(s):
    r = ""
    i = 0
    while i < len(s) and isdigit(s[i]):
        r += s[i]
        i += 1
    return (r, i)

def distribute(s):
    m = {}
    x = 0
    
    p = ""
    i = 0
    while i < len(s):
        v, j = number(s[i])
        if j != 0:
            t = "x{}".format(x)
            m[t] = v
            x += 1
            p += t
            i += j
        else:
            p += s[i]
            i += 1

    r = str(expand(p))
    for k in m:
        r = r.replace(k, m[k])
    
    return r

def test(s, r):
    p = distribute(s)
    print(p)
    assert(eval(p) == eval(s))

def main():
    test("2", "2")
    test("1+3", "1+3")
    test("1+3*4", "1+3*4")
    test("(1+3)*4", "1*4+3*4")
    test("(1+2+3)*(4+5+6)", "1*4+2*4+3*4+1*5+2*5+3*5+1*6+2*6+3*6")
    test("(1+2*(3+4))*((5+6)*7)+8", "1*5*7+1*6*7+2*3*5*7+2*3*6*7+2*4*5*7+2*4*6*7+8")

main()
