#!/usr/bin/env python

"""

Description:
Given a NxN size 2D array of numbers. Develop a way to rotate the data as if you rotated the data by 90 degrees clockwise.

Example:
N = 3

Data:

1 2 3
4 5 6
7 8 9
Rotate 90 degrees:

7 4 1
8 5 2
9 6 3
Rotate it again 90 degrees:

9 8 7
6 5 4
3 2 1

Challenge Input:
N = 10

1 2 3 4 5 6 7 8 9 0
0 9 8 7 6 5 4 3 2 1
1 3 5 7 9 2 4 6 8 0
0 8 6 4 2 9 7 5 3 1
0 1 2 3 4 5 4 3 2 1
9 8 7 6 5 6 7 8 9 0
1 1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2 2
9 8 7 6 7 8 9 8 7 6
0 0 0 0 0 0 0 0 0 0

Optional:
Show the 2D array at 90, 180, 270 degree clockwise from the original position.

"""

def dump(m):
    n = len(m)
    for i in range(0, n):
        for j in range(0, n):
            print(m[i][j], end=' ')
        print()
    print()

def rot90cw(m):
    n = len(m)
    for i in range(0, n//2):
        for j in range(i, n-i-1):
            t               = m[i][j]
            m[i][j]         = m[n-1-j][i]
            m[n-1-j][i]     = m[n-1-i][n-1-j]
            m[n-1-i][n-1-j] = m[j][n-1-i]
            m[j][n-1-i]     = t

def swirl(m):
    for i in range(4):
        dump(m)
        rot90cw(m)
    print("-"*20)

def main():
    swirl([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
    ])

    swirl([
        [1, 2, 3, 4, 5, 6, 7, 8, 9, 0],
        [0, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        [1, 3, 5, 7, 9, 2, 4, 6, 8, 0],
        [0, 8, 6, 4, 2, 9, 7, 5, 3, 1],
        [0, 1, 2, 3, 4, 5, 4, 3, 2, 1],
        [9, 8, 7, 6, 5, 6, 7, 8, 9, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [2, 2, 2, 2, 2, 2, 2, 2, 2, 2],
        [9, 8, 7, 6, 7, 8, 9, 8, 7, 6],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ])

main()
