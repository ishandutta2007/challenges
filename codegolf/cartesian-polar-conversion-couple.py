#!/usr/bin/env python

"""

We don't have a challenge for conversion between Cartesian and polar coordinates, so ...

The challenge
Write two programs (or functions) in the same language:

one that converts from polar to Cartesian coordinates, and
the other from Cartesian to polar coodrinates.
The score is the sum of the two program lengths in bytes. Shortest wins.

For reference, the following figure (from the Wikipedia entry linked above) illustrates the relationship between Cartesian coordinates (x,y) and polar coordinates (r,φ):

                         enter image description here

Additional rules
Input and output are flexible as usual, except that they cannot be in the form of complex numbers (which would trivialize the problem).
Of course, the program can use complex numbers internally, just not as input or output. Input and output methods can be different for the two programs.

You can choose to input and output the angle φ either in radians or in degrees; and to limit its values to any 2π-radian or 360º-degree interval.

Builtins for coordinate conversion are allowed. If you use them, you may want to include another solution without the builtins.

Floating-point number limitations (accuracy, allowed range of values) are acceptable.

Programs or functions are allowed. Standard loopholes are forbidden.

Test cases
Values are shown rounded to 5 decimals. Angles are in radians in the interval [0,2π).

Cartesian: x, y       <-->      Polar: r, ϕ
------------------              ------------------

2.5, -3.42                       4.23632, -0.93957
3000, -4000                      5000, -0.92730
0, 0                             0, <any>
-2.08073, 4.54649                5, 2
0.07071, 0.07071                 0.1, 0.78540

"""

from math import *

def cartesian_to_polar(x, y):
    r = sqrt(x*x + y*y)
    p = atan2(y, x)
    return (r, p)

def polar_to_cartesian(r, p):
    x = r*cos(p)
    y = r*sin(p)
    return (x, y)

def test(x, y, r, p):
    (R, P) = cartesian_to_polar(x, y)
    (X, Y) = polar_to_cartesian(r, p)
    eps = 1e-1
    print(X, Y, R, P)
    assert(abs(x - X) < eps)
    assert(abs(y - Y) < eps)
    assert(abs(r - R) < eps)
    assert(abs(p - P) < eps)

def main():
    test(2.5, -3.42, 4.23632, -0.93957)
    test(3000, -4000, 5000, -0.92730)
    test(0, 0, 0, 0)
    test(-2.08073, 4.54649, 5, 2)
    test(0.07071, 0.07071, 0.1, 0.78540)

main()
