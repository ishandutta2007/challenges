#!/usr/bin/env python

"""

Write a self-contained program which when given a polynomial and a bound will find all real roots of that polynomial to an absolute error not exceeding the bound.

Constraints
I know that Mathematica and probably some other languages have a one-symbol solution, and that's boring, so you should stick to primitive operations (addition, subtraction, multiplication, division).

There is certain flexibility on the input and output formats. You may take input via stdin or command-line arguments in any reasonable format.
You may allow floating point or require that some representation of rational numbers be used.
You may take the bound or the reciprocal of the bound, and if you're using floating point you may assume that the bound will not be less than 2 ulp.
The polynomial should be expressed as a list of monomial coefficients, but it may be big- or little-endian.

You must be able to justify why your program will always work (modulo numerical issues), although it's not necessary to supply full proofs inline.

The program must handle polynomials with repeated roots.

Example
x^2 - 2 = 0 (error bound 0.01)
Input could be e.g.

-2 0 1 0.01
100 1 0 -2
1/100 ; x^2-2
Output could be e.g.

-1.41 1.42
but not

-1.40 1.40
as that has absolute errors of about 0.014...

Test cases
Simple:

x^2 - 2 = 0 (error bound 0.01)

x^4 + 0.81 x^2 - 0.47 x + 0.06 (error bound 10^-6)
Multiple root:

x^4 - 8 x^3 + 18 x^2 - 27 (error bound 10^-6)
Wilkinson's polynomial:

x^20 - 210 x^19 + 20615 x^18 - 1256850 x^17 + 53327946 x^16 -1672280820 x^15 +
    40171771630 x^14 - 756111184500 x^13 + 11310276995381 x^12 - 135585182899530 x^11 +
    1307535010540395 x^10 - 10142299865511450 x^9 + 63030812099294896 x^8 -
    311333643161390640 x^7 + 1206647803780373360 x^6 -3599979517947607200 x^5 +
    8037811822645051776 x^4 - 12870931245150988800 x^3 + 13803759753640704000 x^2 -
    8752948036761600000 x + 2432902008176640000  (error bound 2^-32)
NB This question was in the Sandbox for approximately 3 months. If you think it needed improving before posting, visit the Sandbox and comment on the other proposed questions before they are posted on Main.

"""

import numpy as np

def real_roots(p, eps=1e-9):
    r = []
    l = np.roots(p)
    for z in l:
        if z.imag < eps:
            r.append(z.real)
    return r

def main():
    print(real_roots([1, 0, -2]))
    print(real_roots([1, 0, 0.81, -0.47, 0.06]))
    print(real_roots([1, -8, 18, 0, -27]))
    print(real_roots([1, -210, 20615, -1256850, 53327946, -1672280820, 40171771630, -756111184500, 11310276995381, -135585182899530, 1307535010540395, -10142299865511450, 63030812099294896, -311333643161390640, 1206647803780373360, -3599979517947607200, 8037811822645051776, -12870931245150988800, 13803759753640704000, -8752948036761600000, 2432902008176640000]))

main()
