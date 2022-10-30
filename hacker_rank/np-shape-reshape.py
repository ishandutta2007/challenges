#!/usr/bin/env python

"""
You are given a space separated list of nine integers.
Your task is to convert this list into a 3x3 NumPy array.
"""

import numpy as np

l = [1, 2, 3, 4, 5, 6, 7, 8, 9]
m = np.reshape(l, (3, 3))
print(m)
