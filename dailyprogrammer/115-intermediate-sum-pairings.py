#!/usr/bin/env python

"""

Let the term "sum-pair" be a pair of integers A and B such that the sum of A and B equals a given number C. As an example, let C be 10. Thus, the pairs (5, 5), (1, 9), (2, 8), etc. are all sum-pairs of 10.

Your goal is to write a program that, given an array through standard input (console), you echo out all sum-pairs of a given integer C.

Formal Inputs & Outputs
Input Description:
On the console, you will be first given an integer N. This is the number of following integers that are part of the array. After the N integers, you will be given an integer C which represents the sum-pair you are attempting to match.

Output Description
Your program must print all unique pair of integers in the given list, where the sum of the pair is equal to integer C.

Sample Inputs & Outputs
Input (Through Console)
4
1 -3 4 10
5
Output (Through Console)
1, 4
Note that there is only one pair printed to the console since there is only one unique pair (1, 4) that has the sum of C (5).

Challenge Input
We will show the solution of this problem data-set in 7-days after the original submission.

14
10 -8 2 1 4 -9 6 1 9 -10 -5 2 3 7
7
Note
(Awesome points awarded to /u/drigz for getting some important information into my thick-skull: there are linear-time solutions!)

This is a common interviewing problem for programming jobs, so treat it as such!
There is a very trivial solution, but the trivial solution will run in O(N^2) time.
There are a few other known solutions: one that runs in O(N Log(N)) time (hint: takes advantage of sorting), and another in linear time (hint: dictionary).

"""

def sum_pairs(a, t):
    m = {}
    for v in a:
        if v not in m:
            m[v] = 0
        m[v] += 1

    r = []
    for v in a:
        u = t - v
        if u not in m:
            continue
        
        m[u] -= 1
        m[v] -= 1
        if m[u] >= 0 and m[v] >= 0:
            r.append([min(u, v), max(u, v)])
        m[u], m[v] = 0, 0
    
    return r

def main():
    assert(sum_pairs([1, -3, 4, 10], 5) == [[1, 4]])
    assert(sum_pairs([10, -8, 2, 1, 4, -9, 6, 1, 9, -10, -5, 2, 3, 7], 7) == [[1, 6], [3, 4]])
    assert(sum_pairs([2], 4) == [])
    assert(sum_pairs([2, 2], 4) == [[2, 2]])
    assert(sum_pairs([1, 2, 5, 22, 4, 6, -1, -5, -7, 6, 18, 16, -9, 2, 5, -8, 6, 9, 3, -7], 15) == [[-7, 22], [6, 9], [-1, 16]])
    assert(sum_pairs([1, 2, 5, 8, 4, 6, -1, -5, -7, 6, 11, 15, -9, 2, 5, -8, 6, 9, 3, -7], 15) == [[4, 11], [6, 9]])

main()
