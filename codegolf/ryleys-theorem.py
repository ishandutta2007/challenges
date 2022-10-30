#!/usr/bin/env python

"""

S. Ryley proved following theorem in 1825:

Every rational number can be expressed as a sum of three rational cubes.

Challenge
Given some rational number r∈Q find three rational numbers a,b,c∈Q such that
r=a^3+b^3+c^3.

Details
Your submission should be able to compute a solution for every input given enough time and memory, that means having for instance two 32-bit int representing a fraction is not sufficient.

30 = 3982933876681^3 - 636600549515^3 - 3977505554546^3
52 = 60702901317^3 + 23961292454^3 - 61922712865^3
307/1728 = (1/2)^3 + (1/3)^3 + (1/4)^3
0 = 0^3 + 0^3 + 0^3
1 = (1/2)^3 + (2/3)^3 + (5/6)^3
42 = (1810423/509232)^3 + (-14952/10609)^3 + (-2545/4944)^3

"""

from sympy import Rational

"""

@alephalpha
This formula is given in: Richmond, H. (1930). On Rational Solutions of x^3+y^3+z^3=R. Proceedings of the Edinburgh Mathematical Society, 2(2), 92-100.

"""

def ryley(r):
    a = (27*r**3 + 1) / (27*r**2 - 9*r + 3)
    b = (-27*r**3 + 9*r - 1) / (27*r**2 - 9*r + 3)
    c = (-27*r**2 + 9*r) / (27*r**2 - 9*r + 3)
    return (a, b, c)

def test(s):
    r = Rational(s)
    (a, b, c) = ryley(r)
    print("%s = (%s)**3 + (%s)**3 + (%s)**3" % (r, a, b, c))
    assert(a**3 + b**3 + c**3 == r)

def main():
    test("30")
    test("52")
    test("307/1728")
    test("0")
    test("1")
    test("42")

main()
