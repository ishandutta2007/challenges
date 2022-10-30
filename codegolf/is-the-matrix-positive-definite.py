#!/usr/bin/env python

"""

Introduction

Today we're gonna take care of the bane of first-year linear algebra students: matrix definiteness! Apparently this doesn't yet have a challenge so here we go:
Input

    A n×n

symmetric Matrix A
in any convenient format (you may also of course only take the upper or the lower part of the matrix)
Optionally: the size of the matrix n

What to do?

The challenge is simple: Given a real-valued matrix n×n

Matrix decide whether it is positive definite by outputting a truthy value if so and a falsey value if not.

You may assume your built-ins to actually work precisely and thus don't have to account for numerical issues which could lead to the wrong behaviour if the strategy / code "provably" should yield the correct result.
Who wins?

This is code-golf, so the shortest code in bytes (per-language) wins!
What is a positive-definite Matrix anyways?

There are apparently 6 equivalent formulations of when a symmetric matrix is positive-definite. I shall reproduce the three easier ones and reference you to Wikipedia for the more complex ones.

    If ∀v∈Rn∖{0}:vTAv>0

then A is positive-definite.
This can be re-formulated as:
If for every non-zero vector v the (standard) dot product of v and Av is positive then A
is positive-definite.
Let λii∈{1,…,n}
be the eigenvalues of A, if now ∀i∈{1,…,n}:λi>0 (that is all eigenvalues are positive) then A
is positive-definite.
If you don't know what eigenvalues are I suggest you use your favourite search engine to find out, because the explanation (and the needed computation strategies) is too long to be contained in this post.
If the Cholesky-Decomposition of A
exists, i.e. there exists a lower-triangular matrix L such that LLT=A then A

    is positive-definite. Note that this is equivalent to early-returning "false" if at any point the computation of the root during the algorithm fails due to a negative argument.

Examples
For truthy output

⎛⎝⎜100010001⎞⎠⎟

⎛⎝⎜⎜⎜1000020000300004⎞⎠⎟⎟⎟

⎛⎝⎜52−121−1−1−13⎞⎠⎟

⎛⎝⎜1−22−2502030⎞⎠⎟

(7.152.452.459.37)

For falsey output

(at least one eigenvalue is 0 / positive semi-definite)
⎛⎝⎜3−22−240202⎞⎠⎟

(eigenvalues have different signs / indefinite)
⎛⎝⎜1000−10001⎞⎠⎟

(all eigenvalues smaller than 0 / negative definite)
⎛⎝⎜−1000−1000−1⎞⎠⎟

(all eigenvalues smaller than 0 / negative definite)
⎛⎝⎜−2303−5000−1⎞⎠⎟

(all eigenvalues smaller than 0 / negative definite)
(−7.15−2.45−2.45−9.37)

(three positive, one negative eigenvalue / indefinite)
⎛⎝⎜⎜⎜7.152.451.233.52.459.372.713.141.232.7106.23.53.146.20.56⎞⎠⎟⎟

"""

import numpy as np

def positive_definite(m):
    try:
        np.linalg.cholesky(m)
    except:
        return False
    return True

def main():
    m1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    m2 = [[1, 0, 0, 0], [0, 2, 0, 0], [0, 0, 3, 0], [0, 0, 0, 4]]
    m3 = [[5, 2, -1], [2, 1, -1], [-1, -1, 3]]
    m4 = [[1, -2, 2], [-2, 5, 0], [2, 0, 30]]
    m5 = [[7.15, 2.45], [2.45, 9.37]]

    m6 = [[3, -2, 2], [-2, 4, 0], [2, 0, 2]]
    m7 = [[1, 0, 0], [0, -1, 0], [0, 0, 1]]
    m8 = [[-1, 0, 0], [0, -1, 0], [0, 0, -1]]
    m9 = [[-2, 3, 0], [3, -5, 0], [0, 0, -1]]
    m10 = [[-7.15, -2.45], [-2.45, -9.37]]
    m11 = [[7.15, 2.45, 1.23, 3.5], [2.45, 9.37, 2.71, 3.14], [1.23, 2.71, 0, 6.2], [3.5, 3.14, 6.2, 0.56]]

    assert(positive_definite(m1) == True)
    assert(positive_definite(m2) == True)
    assert(positive_definite(m3) == True)
    assert(positive_definite(m4) == True)
    assert(positive_definite(m5) == True)

    assert(positive_definite(m6) == False)
    assert(positive_definite(m7) == False)
    assert(positive_definite(m8) == False)
    assert(positive_definite(m9) == False)
    assert(positive_definite(m10) == False)
    assert(positive_definite(m11) == False)

main()
