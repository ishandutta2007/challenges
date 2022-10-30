#!/usr/bin/env python

"""

Your task is to write some code in Python 2 or 3 such that this expression:

(a+b)(c+d) == a*c + b*c + a*d + b*d
will evaluate to True without raising any exceptions.

To clarify, I will copy your code into a file, then from the file import *. Then I will type the expression into the console and verify that it is True.

This is code-golf, so the answer with the shortest length (in bytes) wins.

"""

class adder(int):
    __add__ = type

def main():
    a = b = adder()
    c = d = 0
    v = ((a + b)(c + d) == a*c + b*c + a*d + b*d)
    print(v)
    assert(v == True)

main()
