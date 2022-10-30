#!/usr/bin/env python

import numpy.linalg as linalg

m=[[1.1, 1.1], [1.1, 1.1]]
# determinant
print(linalg.det(m))
# eigenvalues/eigenvectors
print(linalg.eig(m))
# inverse
try:
    print(linalg.inv(m))
except:
    pass
