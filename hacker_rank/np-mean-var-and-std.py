#!/usr/bin/env python

"""
You are given a 2-D array of size NxM.
Your task is to find:

The mean along axis 1
The var along axis 0
The std along axis None
"""

import numpy as np

m = np.array([[1, 2], [3, 4]])
print(np.mean(m, axis=1))
print(np.var(m, axis=0))
print(np.std(m, axis=None))
