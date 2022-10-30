"""

In linear algebra, the determinant is a scalar value that can be computed from the elements of a square matrix and encodes certain properties of the linear transformation described by the matrix.

Create a function that takes a square 2D array as an argument and returns a number (determinant).
Examples

getDet([
  [ 0, 1],
  [ 1, 1]
]) ➞ -1

getDet([
  [69, 0],
  [1, 1]
]) ➞ 69

getDet([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]) ➞ 0

Notes

N/A

"""

from numpy.linalg import *

def test(m, r):
    d = det(m)
    assert(abs(d-r) < 1e-8)

def main():
    test([[0, 1], [1, 0]], -1)
    test([[69, 0], [1, 1]], 69)
    test([[7, 420, 8], [5, 7, 0], [1, 1, 7]], -14373)
    test([[5, 1], [1, 6]], 29)
    test([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 0)
    test([[-1, 1, -1], [-1, -55, 1], [1, -1, -1]], -112)
    test([[2, 7, 6], [9, 5, 1], [4, 3, 8]], -360)

main()
