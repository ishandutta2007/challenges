#!/usr/bin/env python

"""

Write a program or function where a matrix A (maximum value of dimensions of the matrix is 100) is transformed to a new matrix B.
Each element of the new matrix B is the sum of the positive neighbors of the corresponding element of the matrix A.

Only neighbors in the four orthogonal directions are considered, and the edges do not wrap around.

Example input:

 1  2  3
 4 -1 -2
-3 -4 10
 1  2 10
Output:

 6  4  2
 1  6 13
 5 12 10
 2 11 12
Rules:

As input use integers.
This is a code-golf, so the shortest code in bytes wins.

"""

def at(m, r, c, i, j):
    if i < 0 or j < 0 or i >= r or j >= c or m[i][j] < 0:
        return 0
    return m[i][j]

def transform(m):
    if len(m) == 0 or len(m[0]) == 0:
        return
    
    p = []
    r = len(m)
    c = len(m[0])
    for i in range(r):
        q = []
        for j in range(c):
            v = at(m, r, c, i-1, j)
            v += at(m, r, c, i+1, j)
            v += at(m, r, c, i, j-1)
            v += at(m, r, c, i, j+1)
            q.append(v)
        p.append(q)
    return p

def test(m, r):
    p = transform(m)
    print(p)
    assert(p == r)

def main():
    test([[1, 2, 3], [4, -1, -2], [-3, -4, 10], [1, 2, 10]],
         [[6, 4, 2], [1, 6, 13], [5, 12, 10], [2, 11, 12]])

main()
