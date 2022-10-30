#!/usr/bin/env python

"""

BABA taught properties of right angled triangle and asked a questions

"Can you find a right angled triangle whose length of hypotenuse is H and its area is A?"

INDIAN students can answer quickly.

Input
The first line of the input contains a single integer T  (where 1≤T≤10^5)  denoting the number of test-cases. T test cases follow.

For each test case, there will be a single line containing two space separated integer H and A (where 1 ≤ H ≤ 10^6  and 1 ≤ A ≤ 10^12 ).

Output
Output the answer for each test-case in a single line. If it is not possible to find such a triangle, output -1.

Otherwise print 3 real numbers corresponding to the lengths of the sides of the triangle sorted in non-decreasing order.

NOTE:- Answer values upto 10^-6 decimal places.

"""

from math import sqrt

def triangle(H, A):
    if H*H < 4*A:
        return -1

    x = sqrt(H*H + 4*A)
    y = sqrt(H*H - 4*A)
    a = (x + y) / 2
    b = (x - y) / 2
    return [min(a, b), max(a, b), H]

def main():
    print(triangle(24252, 56578987908))
    print(triangle(1, 1))
    print(triangle(2, 2))
    print(triangle(10, 10))

main()
