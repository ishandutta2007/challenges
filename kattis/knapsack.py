#!/usr/bin/env python

"""

Implement a solution to the classic knapsack problem. You are given a knapsack that can hold up to a certain weight (its capacity), and several items you may choose to put in the knapsack.
Each item has a weight and a value. Choose a subset of the items (which could be all of them, or none of them) having the greatest value that fit into the knapsack
(i.e. the sum of the weights of the items you choose must be less than or equal to the knapsack capacity).

Input

The input consists of between 1 and 30 test cases. Each test case begins with an integer 1≤C≤2000, giving the capacity of the knapsack, and an integer 1≤n≤2000, giving the number of objects.
Then follow n lines, each giving the value and weight of the n objects. Both values and weights are integers between 1 and 10000.

Output

For each test case, output a line containing the number of items chosen, followed by a line containing the indices of the chosen items (the first item has index 0, the second index 1, and so on).
The indices can be given in any order.

"""

from pulp import *

def knapsack(w, b):
    n = len(b)
    x = LpVariable.dicts("x", indexs=range(n), lowBound=0, upBound=1, cat="Integer")
    p = LpProblem("Knapsack", LpMaximize)
    p += lpSum(x[i]*b[i][0] for i in range(n))
    p += lpSum(x[i]*b[i][1] for i in range(n)) <= w
    if p.solve(PULP_CBC_CMD(msg=0)) < 0:
        return []

    l = []
    for v in p.variables():
        if v.varValue != 0:
            l.append(int(v.name[2:]))
    return l

def main():
    assert(knapsack(5, [[1, 5], [10, 5], [100, 5]]) == [2])
    assert(knapsack(6, [[5, 4], [4, 3], [3, 2], [2, 1]]) == [1, 2, 3])

main()
