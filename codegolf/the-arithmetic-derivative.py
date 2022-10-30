#!/usr/bin/env python

"""

The derivative of a function is a cornerstone of mathematics, engineering, physics, biology, chemistry, and a large number of other sciences as well. Today we're going to be calculating something only tangentially related: the arithmetic derivative.

Definition

The arithmetic derivative a(n) or n' is defined here (A003415) by a number of properties that are similar to the derivative of a function.

a(0) = a(1) = 0,
a(p) = 1, where p is any prime, and
a(mn) = m*a(n) + n*a(m).
The third rule is based on the product rule for differentiation of functions: for functions f(x) and g(x), (fg)' = f'g + fg'. So with numbers, (ab)' = a'b + ab'.

Also of note, since the arithmetic derivative can be extended to the negative numbers via this simple relation, a(-n) = -a(n), the input may be negative.

Rules

Write a program or function that, given any integer n, returns the arithmetic derivative of n.
Inputs will be -230 < n < 230, to avoid problems with integer sizes and numbers too large to factor in a reasonable amount of time. Your algorithm should still be able to theoretically calculate the arithmetic derivative of numbers outside this range.
Built-ins for symbolic math, prime factorization and differentiation are allowed.

Examples
> a(1)
0
> a(7)
1
> a(14)   # a(7)*2 + a(2)*7 = 1*2 + 1*7 = 9
9
> a(-5)   # a(-5) = -a(5) = -1
-1
> a(8)    # a(8) = a(2**3) = 3*2**2 = 12
12
> a(225)  # a(225) = a(9)*25 + a(25)*9 = 6*25 + 10*9 = 150 + 90 = 240
240
> a(299792458)  # a(299792458) = a(2)*149896229 + a(7)*42827494 + a(73)*4106746 + a(293339)*1022 = 1*149896229 + 1*42827494 + 1*4106746 + 1*1022 = 149896229 + 42827494 + 4106746 + 1022 = 196831491
196831491

As always, if the problem is unclear, please let me know. Good luck and good golfing!

"""

from sympy import *

def a(n):
    if n < 0:
        return -a(-n)
    if n < 2:
        return 0
    if isprime(n):
        return 1
    
    m = max(primefactors(n))
    n = n // m
    return m*a(n) + n*a(m)

def main():
    assert(a(1) == 0)
    assert(a(7) == 1)
    assert(a(14) == 9)
    assert(a(-5) == -1)
    assert(a(8) == 12)
    assert(a(225) == 240)
    assert(a(299792458) == 196831491)

main()
