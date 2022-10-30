#!/usr/bin/env python

"""

Your task
Write a program or function that takes the input, which contains 3 pairs of x- and y-coordinates and calculates the area of the triangle formed inside them.
For those who can't remember how to calculate it, you can find it here.

Example:
1,2,4,2,3,7       # input as x1,y1,x2,y2,x3,y3
7.5               # output
See it at Wolfram Alpha

Some considerations:

The input will be six base 10 positive integers.
You may assume the input is in any reasonable format.
The points will always form a valid triangle.
You can assume the input is already stored in a variable such as t.
The shortest code in bytes wins!
Edit: To avoid any confusion I've simplificated how the input should be dealt without jeopardizing any of the current codes.

Remember that the your program/function must output a valid area, so it can't give a negative number as output

"""

import numpy as np
from numpy.linalg import *

def area(x1, y1, x2, y2, x3, y3):
    return 0.5 * det(np.array([[x1, y1, 1], [x2, y2, 1], [x3, y3, 1]]))

def test(x1, y1, x2, y2, x3, y3, r):
    a = area(x1, y1, x2, y2, x3, y3)
    print(a)
    assert(abs(a-r) < 1e-6)

def main():
    test(1, 2, 4, 2, 3, 7, 7.5)

main()
