#!/usr/bin/env python

"""

Given two polynomials f,g of arbitrary degree over the integers, your program/function should evaluate the first polynomial in the second polynomial. f(g(x)) (a.k.a. the composition (fog)(x) of the two polynomials)

Details

Builtins are allowed. You can assume any reasonable formatting as input/output, but the input and output format should match. E.g. formatting as a string

x^2+3x+5

or as as list of coefficients:

[1,3,5] or alternatively [5,3,1]

Furthermore the input polynomials can be assumed to be fully expanded, and the outputs are also expected to be fully expanded.
Examples

A(x) = x^2 + 3x + 5, B(y) = y+1
A(B(y)) = (y+1)^2 + 3(y+1) + 5 = y^2 + 5y + 9

A(x) = x^6 + x^2 + 1, B(y) = y^2 - y
A(B(y))= y^12 - 6y^11 + 15y^10 - 20y^9 + 15y^8 - 6y^7 + y^6 + y^4 - 2 y^3 + y^2 + 1

A(x) = 24x^3 - 144x^2 + 288x - 192, B(y) = y + 2
A(B(y)) = 24y^3

A(x) = 3x^4 - 36x^3 + 138x^2 - 180x + 27, B(y) = 2y + 3
A(B(y)) = 48y^4 - 96y^2

"""

from sympy import *
from sympy.abc import *

def apply(f, g, x):
    print(expand(simplify(f(g(x)))))

def main():
    A = lambda x: x**2 + 3*x + 5
    B = lambda y: y + 1
    apply(A, B, y)

    A = lambda x: x**6 + x**2 + 1
    B = lambda y: y**2 - y
    apply(A, B, y)

    A = lambda x: 24*x**3 - 144*x**2 + 288*x - 192
    B = lambda y: y + 2
    apply(A, B, y)

    A = lambda x: 3*x**4 - 36*x**3 + 138*x**2 - 180*x + 27
    B = lambda y: 2*y + 3
    apply(A, B, y)

main()
