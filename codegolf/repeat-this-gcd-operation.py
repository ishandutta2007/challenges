#!/usr/bin/env python

"""

Problem A3 from the 2008 Putnam competition says:

Start with a finite sequence a1,a2,…,an of positive integers.
If possible, choose two indices j<k such that aj does not divide ak, and replace aj and ak by gcd(aj,ak) and lcm(aj,ak), respectively.
Prove that if this process is repeated, it must eventually stop and the final sequence does not depend on the choices made.

Your goal in this challenge is to take a finite sequence of positive integers as input, and output the result of repeating this process until no further progress is possible.
(That is, until every number in the resulting sequence divides all the numbers that come after it.) You don't need to solve the Putnam problem.

This is code-golf: the shortest solution in every programming language wins.

Test cases
[1, 2, 4, 8, 16, 32] => [1, 2, 4, 8, 16, 32]
[120, 24, 6, 2, 1, 1] => [1, 1, 2, 6, 24, 120]
[97, 41, 48, 12, 98, 68] => [1, 1, 2, 4, 12, 159016368]
[225, 36, 30, 1125, 36, 18, 180] => [3, 9, 18, 90, 180, 900, 4500]
[17, 17, 17, 17] => [17, 17, 17, 17]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] => [1, 1, 1, 1, 1, 2, 2, 6, 60, 2520]

"""

from math import *

"""

@Lynn
Write each integer a[i] as 2^α[i] * 3^β[i] * 5^γ[i]⋯ and note that the process simply bubble-sorts the lists α,β,γ,… in parallel

"""

def fixpoint(a):
    n = len(a)
    while True:
        f = False
        for i in range(0, n):
            for j in range(i+1, n):
                if a[i] != 0 and a[j]%a[i] != 0:
                    a[i], a[j], f = gcd(a[i], a[j]), lcm(a[i], a[j]), True
        if not f:
            break
    return a

def main():
    assert(fixpoint([1, 2, 4, 8, 16, 32]) == [1, 2, 4, 8, 16, 32])
    assert(fixpoint([120, 24, 6, 2, 1, 1]) == [1, 1, 2, 6, 24, 120])
    assert(fixpoint([97, 41, 48, 12, 98, 68]) == [1, 1, 2, 4, 12, 159016368])
    assert(fixpoint([225, 36, 30, 1125, 36, 18, 180]) == [3, 9, 18, 90, 180, 900, 4500])
    assert(fixpoint([17, 17, 17, 17]) == [17, 17, 17, 17])
    assert(fixpoint([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]) == [1, 1, 1, 1, 1, 2, 2, 6, 60, 2520])

main()
