#!/usr/bin/env julia

#=

Challenge

Given nine numbers, a, b, c, d, e, f, g, h, i, as input which correspond to the square matrix:

M=[a b c]
  [d e f]
  [g h i]

Find the inverse of the matrix, M^-1 and output its components.

Inverse Matrix
The inverse of a matrix 3 by 3 obeys the following equation:

M*M^-1 = I
And can be calculated as:

M^-1 = 1/det(M) * tr(C) Where C is the matrix of cofactors:

C = [ei-fh fg-di dh-eg]
    [ch-bi ai-cg bg-ah]
    [bf-ce cd-af ae-bd]

And CT is the transpose of C:

C^T = [ei-fh ch-bi bf-ce]
      [fg-di ai-cg cd-af]
      [dh-eg bg-ah ae-bd]

And det(M) is the determinant of M:

det(M)=a(ei−fh)−b(di−fg)+c(dh−eg)

Rules

The given matrix will always have an inverse (i.e. non-singular). The matrix may be self-inverse

The given matrix will always be a 3 by 3 matrix with 9 integers

The numbers in the input will always be integers in the range −1000≤n≤1000
Non-integer components of the matrix may be given as a decimal or a fraction

Examples

Input > Output
1, 0, 0, 0, 1, 0, 0, 0, 1 > 1, 0, 0, 0, 1, 0, 0, 0, 1
0, -3, -2, 1, -4, -2, -3, 4, 1 > 4, -5, -2, 5, -6, -2, -8, 9, 3
1, 2, 3, 3, 1, 2, 2, 1, 3 > -1/6, 1/2, -1/6, 5/6, 1/2, -7/6, -1/6, -1/2, 5/6
7, 9, 4, 2, 7, 9, 3, 4, 5 > -1/94, -29/94, 53/94, 17/94, 23/94, -55/94, -13/94, -1/94, 31/94

Winning

The shortest code in bytes wins.

=#

M1 = [1 0 0
      0 1 0
      0 0 1]

M2 = [0 -3 -2
      1 -4 -2
     -3 4 1]

M3 = [1 2 3
      3 1 2
      2 1 3]

M4 = [7 9 4
      2 7 9
      3 4 5]

println(inv(M1))
println(inv(M2))
println(inv(M3))
println(inv(M4))
