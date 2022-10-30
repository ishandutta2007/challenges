#!/usr/bin/env python

"""

Mubashir needs your help to construct a building which will be a pile of n cubes. The cube at the bottom will have a volume of n^3, the cube above will have volume of (n-1)^3 and so on until the top which will have a volume of 1^3.

Given the total volume m of the building, can you find the number of cubes n required for the building?

In other words, you have to return an integer n such that:

n^3 + (n-1)^3 + ... + 1^3 == m

Return None if there is no such number.
Examples

pile_of_cubes(1071225) ➞ 45

pile_of_cubes(4183059834009) ➞ 2022

pile_of_cubes(16) ➞ None

Notes

N/A

"""


from math import *

def sum(n):
    return n*n*(n+1)*(n+1)//4

def cubes(n):
    if n <= 0:
        return 0

    lo = 0
    hi = int(sqrt(n))
    while hi-lo != 1:
        mid = lo + (hi - lo) // 2
        if sum(mid) < n:
            lo = mid
        else:
            hi = mid

    if sum(hi) != n:
        return None
    return hi

def main():
    assert(cubes(1) == 1)
    assert(cubes(1071225) == 45)
    assert(cubes(4183059834009) == 2022)
    assert(cubes(16) == None)
    assert(cubes(24723578342962) == None)
    assert(cubes(135440716410000) == 4824)
    assert(cubes(40539911473216) == 3568)
    assert(cubes(26825883955641) == 3218)
    assert(cubes(41364076483082) == None)
    assert(cubes(9541025211025) == 2485)
    assert(cubes(112668204662785) == None)
    assert(cubes(79172108332642) == None)
    assert(cubes(1788719004901) == None)
    assert(cubes(131443152397956) == 4788)
    assert(cubes(1801879360282) == None)
    assert(cubes(18262169777476) == 2923)
    assert(cubes(11988186060816) == 2631)
    assert(cubes(826691919076) ==  1348)
    assert(cubes(36099801072722) ==  None)
    assert(cubes(171814395026) ==  None)
    assert(cubes(637148782657) ==  None)
    assert(cubes(6759306226) ==  None)
    assert(cubes(33506766981009) ==  3402)
    assert(cubes(108806345136785) ==  None)
    assert(cubes(14601798712901) ==  None)
    assert(cubes(56454575667876) ==  3876)
    assert(cubes(603544088161) ==  1246)
    assert(cubes(21494785321) ==  541)
    assert(cubes(4) ==  None)
    assert(cubes(16) ==  None)
    assert(cubes(1025292944081385001) ==  45001)
    assert(cubes(0) ==  0)

main()
