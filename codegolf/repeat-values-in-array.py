#!/usr/bin/env python

"""

Given two arrays of non-negative integers A=[A1,A2,…,An] and R=[R1,R2,…,Rn] which are equal in length, return an array which has the element A1 repeated R1 times, then element A2 repeated R2 times, all the way up to An.

Standard loopholes are forbidden. As this is code-golf, the shortest program wins.

Test Cases
A	R	Output
[1,2,3]	[1,2,3]	[1,2,2,3,3,3]
[6,0,0,6]	[5,1,1,0]	[6,6,6,6,6,0,0]
[100,100]	[0,0]	[]

"""

def repeat(a, r):
    p = []
    for i in range(len(a)):
        p += [a[i]]*r[i]
    return p

def main():
    assert(repeat([1, 2, 3], [1, 2, 3]) == [1, 2, 2, 3, 3, 3])
    assert(repeat([6, 0, 0, 6], [5, 1, 1, 0]) == [6, 6, 6, 6, 6, 0, 0])
    assert(repeat([100, 100], [0, 0]) == [])

main()
