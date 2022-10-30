#!/usr/bin/env python

"""

In this challenge, you will be given a square matrix A, a vector v, and a scalar λ. You will be required to determine if (λ, v) is an eigenpair corresponding to A; that is, whether or not Av = λv.

Dot Product
The dot product of two vectors is the sum of element-wise multiplication. For example, the dot product of the following two vectors is:

(1, 2, 3) * (4, 5, 6) = 1*4 + 2*5 + 3*6 = 32
Note that the dot product is only defined between two vectors of the same length.

Matrix-Vector Multiplication
A matrix is a 2D grid of values. An m x n matrix has m rows and n columns. We can imagine an m x n matrix as m vectors of length n (if we take the rows).

Matrix-Vector multiplication is defined between an m x n matrix and a size-n vector. If we multiply an m x n matrix and a size-n vector, we obtain a size-m vector.
The i-th value in the result vector is the dot product of the i-th row of the matrix and the original vector.

Example
        1 2 3 4 5
Let A = 3 4 5 6 7
        5 6 7 8 9

        1
        3
Let v = 5
        7
        9

If we multiply the matrix and the vector Av = x, we get the following:

x1 = AT1 * v /* AT1 means the first row of A; A1 would be the first column */ = (1,2,3,4,5) * (1,3,5,7,9) = 1*1 + 2*3 + 3*5 + 4*7 + 5*9 = 1+6+15+28+45 = 95

x2 = AT2 * v = (3,4,5,6,7) * (1,3,5,7,9) = 3*1 + 4*3 + 5*5 + 6*7 + 7*9 = 3+12+25+42+63 = 145

x3 = AT3 * v = (5,6,7,8,9) * (1,3,5,7,9) = 5*1 + 6*3 + 7*5 + 8*7 + 9*9 = 5+18+35+56+81 = 195

So, we get Av = x = (95, 145, 195).

Scalar Multiplication
Multiplication of a scalar (a single number) and a vector is simply element-wise multiplication. For example, 3 * (1, 2, 3) = (3, 6, 9). It's fairly straightforward.

Eigenvalues and Eigenvectors
Given the matrix A, we say that λ is an eigenvalue corresponding to v and v is an eigenvector corresponding to λ if and only if Av = λv. (Where Av is matrix-vector multiplication and λv is scalar multiplication).

(λ, v) is an eigenpair.

Challenge Specifications
Input
Input will consist of a matrix, a vector, and a scalar. These can be taken in any order in any reasonable format.

Output
Output will be a truthy/falsy value; truthy if and only if the scalar and the vector are an eigenpair with the matrix specified.

Rules
Standard loopholes apply
If a built-in for verifying an eigenpair exists in your language, you may not use it.
You may assume that all numbers are integers

Test Cases
 MATRIX  VECTOR  EIGENVALUE
 2 -3 -1    3
 1 -2 -1    1    1    ->    TRUE
 1 -3  0    0

 2 -3 -1    1
 1 -2 -1    1    -2   ->    TRUE
 1 -3  0    1

 1  6  3    1
 0 -2  0    0    4    ->    TRUE
 3  6  1    1

 1  0 -1    2
-1  1  1    1    7    ->    FALSE
 1  0  0    0

-4 3    1    
 2 1    2    2    ->    TRUE

2    1    2    ->    TRUE

"""

import numpy as np

def eigenpair(M, v, e):
    return np.allclose(np.dot(M, v), np.multiply(e, v))

def main():
    assert(eigenpair([[2, -3, -1], [1, -2, -1], [1, -3, 0]], [3, 1, 0], 1) == True)
    assert(eigenpair([[2, -3, -1], [1, -2, -1], [1, -3, 0]], [1, 1, 1], -2) == True)
    assert(eigenpair([[1, 6, 3], [0, -2, 0], [3, 6, 1]], [1, 0, 1], 4) == True)
    assert(eigenpair([[1, 0, -1], [-1, 1, 1], [1, 0, 0]], [2, 1, 0], 7) == False)
    assert(eigenpair([[-4, 3], [2, 1]], [1, 2], 2) == True)
    assert(eigenpair([[2]], [1], 2) == True)

main()
