#!/usr/bin/env python

"""

Implement polynomial long division, an algorithm that divides two polynomials and gets the quotient and remainder:

(12x^3 - 5x^2 + 3x - 1) / (x^2 - 5) = 12x - 5 R 63x - 26

In your programs, you will represent polynomials as an array, with the constant term on the tail. for example, x^5 - 3x^4 + 2x^2 - x + 1 will become [1, -3, 0, 2, -1, 1].

The long division function you are going to write will return two values: the quotient and the remainder.
You do not need to handle numerical imprecisions and arithmetic errors. Do not use math library to do your job, however, you may make your function able to deal with symbolic values. Shortest code wins.

EXAMPLE: div([12, -5, 3, -1], [1, 0, -5]) == ([12, -5], [63, -26])

"""

import numpy as np

def div(n, d):
    p, q = np.polydiv(n, d)
    return (p.tolist(), q.tolist())

def main():
    print(div([12, -5, 3, -1], [1, 0, -5]))

main()

