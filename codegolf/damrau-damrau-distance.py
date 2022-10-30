#!/usr/bin/env python

"""

Given a list of the integers from 1 to some n, give the minimum number of adjacent swaps required to put the list in ascending order.

You will receive a list as input and should output a non-negative integer. You may if you wish choose to expect a list of the integers from 0 to n instead.

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test cases
[3,2,1] -> 3
[1,2,3,4] -> 0
[2,1,3,4] -> 1
[2,1,4,3] -> 2
[2,4,1,3] -> 3
[4,2,3,1] -> 5
[4,3,2,1] -> 6

"""

def damrau(a):
    c = 0
    n = len(a)
    for i in range(0, n):
        for j in range(i+1, n):
            if a[i] > a[j]:
                a[i], a[j] = a[j], a[i]
                c += 1
    return c

def main():
    assert(damrau([3, 2, 1]) == 3)
    assert(damrau([1, 2, 3, 4]) == 0)
    assert(damrau([2, 1, 3, 4]) == 1)
    assert(damrau([2, 1, 4, 3]) == 2)
    assert(damrau([2, 4, 1, 3]) == 3)
    assert(damrau([4, 2, 3, 1]) == 5)
    assert(damrau([4, 3, 2, 1]) == 6)

main()
