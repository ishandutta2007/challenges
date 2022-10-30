#!/usr/bin/env python

"""

Given two points A and B, find the angle from line AO to line BO about point O where O is the origin ((0,0)).
Additionally, the angle may be positive or negative depending on the positions of the points (see examples).
Input will be points A and B, and may be given in any convenient form. Output will be the angle in degrees (but it is positive if AO is rotated counter-clockwise about the origin to get BO and negative if it is rotated clockwise).
If the angle is 180 degrees you may return a negative or positive output. Similarly, the angle can be the positive or negative version of the same angle (90 deg is equal to -270 deg). Examples:

Input: A(5,5) B(5,-5) Output: -90 (AO is rotated -90 degrees to get BO).

Input: A(5,-5) B(5,5) Output: 90 (AO is rotated 90 degrees to get BO).

This is code-golf, so shortest code in bytes wins!

"""

import cmath
import math

def angle(x1, y1, x2, y2):
    a = complex(x1, y1)
    b = complex(x2, y2)
    p = cmath.phase(b - a)
    return math.degrees(p)

def main():
    print(angle(5, 5, 5, -5))
    print(angle(5, -5, 5, 5))
    print(angle(0, 1, 1, 0))

main()
