#!/usr/bin/env python

"""

An orthogonal matrix is a square matrix with real entries whose columns and rows are orthogonal unit vectors (i.e., orthonormal vectors).

This means that M^T M = I, where I is the identity matrix and ^T signifies matrix transposition.

Note that this is orthogonal not "special orthogonal" so the determinant of M can be 1 or -1.

The aim of this challenge is not machine precision so if M^T M = I to within 4 decimal places that will be fine.

The task is to write code that takes a positive integer n > 1 and outputs a random orthogonal n by n matrix.
The matrix should be randomly and uniformly chosen from all n by n orthogonal matrices.
In this context, "uniform" is defined in terms of the Haar measure, which essentially requires that the distribution does not change if multiplied by any freely chosen orthogonal matrix.
This means the values of the matrix will be floating point values in the range -1 to 1.

The input and output can be any form you find convenient.

Please show an explicit example of your code running.

You may not use any existing library function which creates orthogonal matrices. This rule is a little subtle so I will explain more.
This rule bans the use of any existing function which takes in some (or no) input and outputs a matrix of size at least n by n which is guaranteed to be orthogonal.
As an extreme example, if you want the n by n identity matrix, you will have to create it yourself.

You can use any standard random number generator library for choosing random numbers of your choosing.

Your code should complete within at most a few seconds for n < 50.

"""

from scipy.stats import ortho_group

for i in range(2, 51):
    print(i)
    print(ortho_group.rvs(dim=i))
    print()
