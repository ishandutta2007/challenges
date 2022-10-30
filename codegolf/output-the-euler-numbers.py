#!/usr/bin/env python

"""

Given a non-negative integer n, output the nth Euler number (OEIS A122045).

All odd-indexed Euler numbers are 0. The even-indexed Euler numbers can be computed with the following formula (i=sqrt(-1) refers to the imaginary unit):

{\displaystyle E_{2n}=i\sum _{k=1}^{2n+1}\sum _{j=0}^{k}{\binom {k}{j}}{\frac {(-1)^{j}(k-2j)^{2n+1}}{2^{k}i^{k}k}},}

Rules
n will be a non-negative integer such that the nth Euler number is within the representable range of integers for your language.
Test Cases
0 -> 1
1 -> 0
2 -> -1
3 -> 0
6 -> -61
10 -> -50521
20 -> 370371188237525

"""

from math import comb

def A000364(n):
    if n == 0:
        return 1

    v = 0
    for i in range(n):
        s = -1
        if i%2 == 0:
            s = 1
        v += s * A000364(i) * comb(2*n, 2*i)
    
    if n%2 == 0:
        v = -v

    return v

def euler_number(n):
    if n < 0 or n%2 != 0:
        return 0

    n = n // 2
    v = A000364(n)
    s = 1
    if n%2 != 0:
        s = -1
    return s * v

def main():
    assert(euler_number(0) == 1)
    assert(euler_number(1) == 0)
    assert(euler_number(2) == -1)
    assert(euler_number(3) == 0)
    assert(euler_number(6) == -61)
    assert(euler_number(10) == -50521)
    assert(euler_number(20) == 370371188237525)

main()
