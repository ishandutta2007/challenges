#!/usr/bin/env python
"""

You're given three numbers: A, B, and C, and all you have to do is to find the number Fn where
F_0 = A
F_1 = B
F_i = F_i-1 + F_i-2 for i >= 2

As the number can be very large, output it modulo 10**9 + 7

Consider the following link: http://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form

"""

import numpy as np
import numpy.linalg as ln

def F(a, b, n):
    p = 10**9 + 7
    
    A = [[1, 1], [1, 0]]
    B = ln.eig(A)
    
    v = B[0]
    S = B[1]
    M = [[v[0], 0], [0, v[1]]]
    Si = ln.inv(S)

    M = ln.matrix_power(M, n)
    M = S.dot(M.dot(Si))
    v = [[b], [a]]
    v = M.dot(v)
    return int(round(v[1][0])) % p

print(F(2, 3, 1))
print(F(9, 1, 7))
print(F(9, 8, 3))
print(F(2, 4, 9))
print(F(1, 7, 2))
print(F(1, 8, 1))
print(F(4, 3, 1))
print(F(3, 7, 5))

print("\n")
for i in range(1, 32):
    print(F(0, 1, i))
