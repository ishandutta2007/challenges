#!/usr/bin/env python

"""

You are to write a program which takes an integer polynomial in t

as input and outputs the Laplace transform of this polynomial. Some definitions and properties:

    The Laplace transform of a given function f(t)

    is

L{f(t)}=F(s)=∫∞0f(t)e−stdt

    The Laplace transform of f(t)=tn,n=0,1,2,...

    is

L{tn}=n!sn+1

    Laplace transforms distribute over addition:

L{f(t)+g(t)}=L{f(t)}+L{g(t)}

    The Laplace transform of a constant multiplied by a function equals the constant multiplied by the transform:

L{af(t)}=aL{f(t)}

    An integer polynomial is a polynomial where each term has an integer coefficient, and a non-negative order

An worked example:

L{3t4+2t2+t−4}=L{3t4}+L{2t2}+L{t}−L{4}=3L{t4}+2L{t2}+L{t}−4L{1}=3(4!s5)+2(2!s3)+(1!s2)−4(0!s)=72s5+4s3+1s2−4s

You may take input in a standard representation of a polynomial. Some examples (for 3x4+2x2+x−4

as an example) are:

    A list of coefficients. [-4, 1, 2, 0, 3] or [3, 0, 2, 1, -4]
    Pairs of coefficients and powers. [[3, 4], [2, 2], [1, 1], [-4, 0]] and various different orderings
    A string, using whatever variable you like. 3x^4+2x^2+x-4

Similarly, as the output will be a polynomial with negative orders, you may output in similar formats, such as (using L{3x4+2x2+x−4}=72s5+4s3+1s2−4s

):

    A list of coefficients. [72, 0, 4, 1, -4] or [-4, 1, 4, 0, 72]
    Pairs of coefficients and powers. [[72, -5], [4, -3], [1, -2], [-4, -1]] and various different orderings (or the positive versions of the powers)
    A string, using whatever variable you like. 72s^-5+4s^-3+s^-2-4s^-1

If you have an alternative I/O method you're unsure about, please comment below to ask.

This is code-golf so the shortest code in bytes wins.

"""

from sympy import *
from sympy.abc import *

def test(f):
    L = laplace_transform(f, t, s)
    pretty_print(expand(L[0]))

def main():
    test(3*t**4 + 2*t**2 + t - 4)
    test(1)
    test(20*t - 40*t**20)

main()
