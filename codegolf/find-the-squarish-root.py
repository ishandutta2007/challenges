#!/usr/bin/env python

"""

Write code that when given a positive number x as input, outputs the largest positive divisor of x less than or equal to the square root of x.

In other words find the largest n>0 such that

∃m≥n:m⋅n=x
(Exists m greater than or equal to n such that m times n is x)

For example if the input were 12 the divisors are 1, 2, 3, 4, 6, and 12. 1, 2 and 3 all multiply by larger numbers to get 12, but 3 is the largest so we return 3.

This is code-golf so answers will be scored in bytes with fewer bytes being considered a better score.

Test Cases
(1,1)
(2,1)
(3,1)
(4,2)
(5,1)
(6,2)
(7,1)
(8,2)
(9,3)
(10,2)
(11,1)
(12,3)
(13,1)
(14,2)
(15,3)
(16,4)
(17,1)
(18,3)
(19,1)
(20,4)
(21,3)
(22,2)
(23,1)
(24,4)
(25,5)
(26,2)
(27,3)
(28,4)
(29,1)
(30,5)
(31,1)
(32,4)
(33,3)
(34,2)
(35,5)
(36,6)
(37,1)
(38,2)
(39,3)
(40,5)
(41,1)
(42,6)
(43,1)
(44,4)
(45,5)
(46,2)
(47,1)
(48,6)
(49,7)
(50,5)

"""

from sympy import divisors

# http://oeis.org/A033676
def squarish(n):
    d = divisors(n)
    i = len(d) - 1
    return d[i//2]

def main():
    tab = [
        1, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 3, 1, 2, 3, 4, 1, 3, 1, 4, 3, 2, 1, 4, 5, 2, 3, 4, 1, 5,
        1, 4, 3, 2, 5, 6, 1, 2, 3, 5, 1, 6, 1, 4, 5, 2, 1, 6, 7, 5, 3, 4, 1, 6, 5, 7, 3, 2, 1, 6,
        1, 2, 7, 8, 5, 6, 1, 4, 3, 7, 1, 8, 1, 2, 5, 4, 7, 6, 1, 8, 9, 2, 1, 7, 5, 2, 3
    ]

    for i in range(len(tab)):
        assert(squarish(i+1) == tab[i])

main()
