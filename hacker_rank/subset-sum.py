#!/usr/bin/env python

"""

You are given a list of N positive integers, A = {a[1], a[2], ..., a[N]} and another integer S. You have to find whether there exists a non-empty subset of A whose sum is greater than or equal to S.

You have to print the size of minimal subset whose sum is greater than or equal to S. If there exists no such subset then print -1 instead.

Input

First line will contain an integer, N, which is the size of list A. Second line contains N space separated integers, representing the elements of list A.
In third line there is an integer, T, which represent the number of test cases to follow. Then follows T lines. Each one of them contains an single integer, S.

Output

For each test case, print the size of minimal subset whose sum is greater than or equal to S. If there's no such subset then print -1.

Constraints
1 ≤ N ≤ 105
1 ≤ a[i] ≤ 109
1 ≤ T ≤ 105
1 ≤ S ≤ 1015

Note
Two subsets are different if there's an element a[i] which exists in one of them and not in other. That is, for set A = {4, 4} there are four possible subsets {}, {a[1]}, {a[2]} and {a[1], a[2]}.

Sample Input

4
4 8 10 12
4
4
13
30
100

Sample Output

1
2
3
-1

Explanation
Sample Case #00: For S = 4, we can select any one element of set A as each of them is greater than or equal to 4.
Sample Case #01: There are many possible subsets of size 2 whose sum is not less than 13. They are {4, 10}, {4, 12}, {8, 10}, {8, 12} and {10, 12}.
Sample Case #02: Subset {8, 10, 12}, with sum 30, is the only subset of size 3 whose sum is not less than S = 30.
Sample Case #03: Even after selecting all the elements of A, we can't exceed S = 100.

"""

from pulp import *

def subset_sum(a, s):
    n = len(a)
    x = LpVariable.dicts("x", indexs=range(n), lowBound=0, upBound=1, cat="Integer")
    p = LpProblem("Subset-Sum", LpMinimize)
    p += lpSum(x[i]*a[i] for i in range(n))
    p += lpSum(x[i]*a[i] for i in range(n)) >= s
    if p.solve(PULP_CBC_CMD(msg=0)) < 0:
        return -1

    c = 0
    for v in p.variables():
        if v.varValue != 0:
            c += 1
    return c

def main():
    a1 = [4, 8, 10, 12]
    assert(subset_sum(a1, 4) == 1)
    assert(subset_sum(a1, 13) == 2)
    assert(subset_sum(a1, 30) == 3)
    assert(subset_sum(a1, 100) == -1)

main()
