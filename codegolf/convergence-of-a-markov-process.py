#!/usr/bin/env python

"""

Given a left- or right-stochastic matrix where the limit as x approaches infinity of the matrix to the power of x approaches a matrix with all finite values, return the matrix to which the matrix converges.
Basically, you want to keep multiplying the matrix by itself until the result no longer changes.

Test Cases

[[7/10, 4/10], [3/10, 6/10]] -> [[4/7, 4/7], [3/7, 3/7]]
[[2/5, 4/5], [3/5, 1/5]] -> [[4/7, 4/7], [3/7, 3/7]]
[[1/2, 1/2], [1/2, 1/2]] -> [[1/2, 1/2], [1/2, 1/2]]
[[1/3, 2/3], [2/3, 1/3]] -> [[1/2, 1/2], [1/2, 1/2]]
[[1/10, 2/10, 3/10], [4/10, 5/10, 6/10], [5/10, 3/10, 1/10]] -> [[27/130, 27/130, 27/130], [66/130, 66/130, 66/130], [37/130, 37/130, 37/130]]
[[1/7, 2/7, 4/7], [2/7, 4/7, 1/7], [4/7, 1/7, 2/7]] -> [[1/3, 1/3, 1/3], [1/3, 1/3, 1/3], [1/3, 1/3, 1/3]]

Rules

Standard Loopholes Apply
You may choose whether you want a right- or a left-stochastic matrix
You may use any reasonable number type, such as floats, rationals, infinite precision decimals, etc
This is code-golf, so the shortest submission in bytes for each language is declared the winner for its language. No answer will be accepted

"""

import numpy as np

def stationary(m):
    while True:
        n = np.dot(m, m)
        if np.allclose(n, m):
            break
        m = n
    return m

def test(m, r):
    p = stationary(m)
    print(p)
    assert(np.allclose(p, r))

def main():
    test([[7/10, 4/10], [3/10, 6/10]], [[4/7, 4/7], [3/7, 3/7]])
    test([[2/5, 4/5], [3/5, 1/5]], [[4/7, 4/7], [3/7, 3/7]])
    test([[1/2, 1/2], [1/2, 1/2]], [[1/2, 1/2], [1/2, 1/2]])
    test([[1/3, 2/3], [2/3, 1/3]], [[1/2, 1/2], [1/2, 1/2]])
    test([[1/10, 2/10, 3/10], [4/10, 5/10, 6/10], [5/10, 3/10, 1/10]], [[27/130, 27/130, 27/130], [66/130, 66/130, 66/130], [37/130, 37/130, 37/130]])
    test([[1/7, 2/7, 4/7], [2/7, 4/7, 1/7], [4/7, 1/7, 2/7]], [[1/3, 1/3, 1/3], [1/3, 1/3, 1/3], [1/3, 1/3, 1/3]])

main()
