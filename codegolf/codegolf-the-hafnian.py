#!/usr/bin/env python

"""

The challenge is to write codegolf for the Hafnian of a matrix. The Hafnian of an 2n-by-2n symmetric matrix A is defined as:

Here S_2n represents the set of all permutations of the integers from 1 to 2n, that is [1, 2n].

The wikipedia link talks about adjacency matrices but your code should work for any real valued symmetric input matrices.

For those interested in applications of the Hafnian, the mathoverflow link discusses some more.

Your code can take input however it wishes and give output in any sensible format but please include in your answer a full worked example including clear instructions for how to supply input to your code.

The input matrix is always square and will be at most 16 by 16. There is no need to be able to handle the empty matrix or matrices of odd dimension.
Reference implementation

Here is some example python code from Mr. Xcoder.

from itertools import permutations
from math import factorial

def hafnian(matrix):
    my_sum = 0
    n = len(matrix) // 2
    for sigma in permutations(range(n*2)):
        prod = 1
        for j in range(n):
            prod *= matrix[sigma[2*j]][sigma[2*j+1]]
        my_sum += prod
    return my_sum / (factorial(n) * 2 ** n)


print(hafnian([[0, 4.5], [4.5, 0]]))
4.5
print(hafnian([[0, 4.7, 4.6, 4.5], [4.7, 0, 2.1, 0.4], [4.6, 2.1, 0, 1.2], [4.5, 0.4, 1.2, 0]])
16.93
print(hafnian([[1.3, 4.1, 1.2, 0.0, 0.9, 4.4], [4.1, 4.2, 2.7, 1.2, 0.4, 1.7], [1.2, 2.7, 4.9, 4.7, 4.0, 3.7], [0.0, 1.2, 4.7, 2.2, 3.3, 1.8], [0.9, 0.4, 4.0, 3.3, 0.5, 4.4], [4.4, 1.7, 3.7, 1.8, 4.4, 3.2]])
262.458

The wiki page has now (March 2 2018) been updated by ShreevatsaR to include a different way of calculating the Hafnian. It would be very interesting to see this golfed.

"""

from itertools import permutations
from math import factorial

def hafnian(m):
    r = 0
    n = len(m) // 2
    for s in permutations(range(n*2)):
        p = 1
        for j in range(n):
            p *= m[s[2*j]][s[2*j + 1]]
        r += p
    return r / (factorial(n) * 2**n)

def main():
    print(hafnian([[0, 4.5], [4.5, 0]]))
    print(hafnian([[0, 4.7, 4.6, 4.5], [4.7, 0, 2.1, 0.4], [4.6, 2.1, 0, 1.2], [4.5, 0.4, 1.2, 0]]))
    print(hafnian([[1.3, 4.1, 1.2, 0.0, 0.9, 4.4], [4.1, 4.2, 2.7, 1.2, 0.4, 1.7], [1.2, 2.7, 4.9, 4.7, 4.0, 3.7], [0.0, 1.2, 4.7, 2.2, 3.3, 1.8], [0.9, 0.4, 4.0, 3.3, 0.5, 4.4], [4.4, 1.7, 3.7, 1.8, 4.4, 3.2]]))

main()
