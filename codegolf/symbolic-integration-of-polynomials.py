#!/usr/bin/env python

"""

Apply an indefinite integral to a given string. The only rules you will be using are defined as such:

∫cx^(n)dx = (c/(n+1))x^(n+1) + C, n ≠ -1
c, C, and n are all constants.

Specifications:
You must be able to integrate polynomials with any of the possible features:
A coefficient, possibly a fraction in the format (numerator/denominator).
Recognition that e and π are constants, and in their use, be able to form fractions or expressions containing them (can be held in a fraction like (e/denominator) or (numerator/e), or, if in exponents, x^(e+1))
Aside of these two special constants, all coefficients will be rational, real numbers.
An exponent, possibly a fraction, in the format x^(exponent)
Expressions with e or π in them, aside of themselves, will not be in exponents. (you will not have to integrate stuff like x^(e+1), but you might integrate x^(e))
Can use non-x 1-char variables (i.e. f)
This is only for ASCII ranges 65-90 and 97-122.
You do not have to use chain rule or integrate x^(-1).
Output must have padding (separation between terms, i.e. x^2 + x + C.
If it is unknown how to integrate with the above features, the program should print out "Cannot integrate "+input.
It must be a full program.

Bonuses:
-10% if you print out the "pretty" exponents formatted for markdown (instead of x^2, x<sup>2</sup>).
-10% if you print out the equation (i.e. ∫xdx = (1/2)x^2 + C)

Examples:

Input:

x
Output:

(1/2)x^(2) + C
Input:

-f^(-2)
Output:

f^(-1) + C
Input:

(1/7)x^(1/7) + 5
Output:

(1/56)x^(8/7) + 5x + C
Input:

πx^e
Output:

(π/(e+1))x^(e+1) + C
Input:

(f+1)^(-1)
Output:

Cannot integrate (f+1)^(-1)

"""

from sympy import *
from sympy.abc import *

def integral(s):
    return integrate(s) + C

def main():
    pretty_print(integral("x"))
    pretty_print(integral("-f^(-2)"))
    pretty_print(integral("(1/7)*x^(1/7) + 5"))
    pretty_print(integral("pi*x^exp(1)"))
    pretty_print(integral("(f+1)^(-1)"))

main()
