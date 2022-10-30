#!/usr/bin/env/python

"""
You are given four points A, B, C and D in a 3-dimensional Cartesian coordinate system. You are required to print the angle 
between the plane made by the points A, B, C and B, C, D in degrees(not radians). Let the angle be PHI.

cos(phi) = x.y/|x||y|
where x = abxbc and y=bcxcd

"""

import numpy as np
import numpy.linalg as ln
from math import *

def torsion_angle(a, b, c, d):
    ab = np.subtract(b, a)
    bc = np.subtract(c, b)
    cd = np.subtract(d, c)
    x = np.cross(ab, bc)
    y = np.cross(bc, cd)
    d = acos(np.dot(x, y) / (ln.norm(x) * ln.norm(y)))
    return degrees(d)

a = np.array([0, 4, 5])
b = np.array([1, 7, 6])
c = np.array([0, 5, 9])
d = np.array([1, 7, 2])
print("%.2f" % (torsion_angle(a, b, c, d)))
