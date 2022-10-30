#!/usr/bin/env python

"""

Write a program that will use the FOIL method to solve multiplying binomials. Your program will accept a binomial algebraic formula as input and you will parse the data, use the FOIL method to reduce the formula, and print out the solution.
You decide how you want to represent exponents (could use caret, or just write out the value after the variable).

Sample Run:

Enter Binomials:  (2x + 6)(7x + 3)
Result:  14x^2 + 48x + 18
Enter Binomials: (2x2 + 3x)(5x2 + 9x)
Result:  10x4 + 33x3 + 27x2
Bonus: Support trinomials

"""

from sympy import *
from sympy.abc import *

def main():
    p1 = (2*x + 6)*(7*x + 3)
    p2 = (2*x**2 + 3*x)*(5*x**2 + 9*x)
    p3 = (a + b + c)*(d**2 + e**3 + f**4)
    p4 = (f + o + i + l)*(m + e + t + h + o + d)
    print(expand(p1))
    print(expand(p2))
    print(expand(p3))
    print(expand(p4))

main()
