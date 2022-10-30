#!/usr/bin/env python

"""

For this challenge a "binary tree" is a rooted tree where each node has 0 children (leaf) or 2.
The children of a node are unordered, meaning that while you might draw the tree with left and right children there isn't a distinction between them and mirroring the tree or a sub-tree does not produce a new tree.

In this challenge you will be given an integer n and you will be asked to determine the number of binary trees with each node labeled from 1 to 2n+1 such that no child node is less than its parent.

For example the following tree with 7 nodes is valid:

     1
 2    7
3  4
  5 6
but the following tree is not:

     1
 2    7
6  4
  5 3
Since 3 is a child of 4.

Task
Given n calculate the number of binary trees labeled from 1 to 2n+1 such that no child node is less than its parent.

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test cases
I've calculated the first 11 solutions on my own:

1, 1, 4, 34, 496, 11056, 349504, 14873104, 819786496, 56814228736, 4835447317504
and the OEIS has more terms at: A002105

"""

from sympy import *

# https://oeis.org/A002105 
def trees(n):
    if n < 1:
        return 0
    return 2**n * (2**(2*n) - 1) * abs(bernoulli(2*n)) // n

def main():
    tab = [1, 1, 4, 34, 496, 11056, 349504, 14873104, 819786496, 56814228736, 4835447317504]
    for i in range(len(tab)):
        assert(trees(i+1) == tab[i])

main()
