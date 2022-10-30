#!/usr/bin/env python

"""

Aristotle's number puzzle is the challenge of populating each of 19 cells in a hexagonal grid with a unique integer between 1 and 19 such that the total along every axis is 38.

You can picture the game board looking like this:

    https://i.stack.imgur.com/20sBh.png

And the puzzle, in essence, is the solution to the following set of fifteen equations:

((a + b + c) == 38 && (d + e + f + g) == 38 && (h + i + j + k + l) ==
   38 && (m + n + o + p) == 38 && (q + r + s) == 38 && (a + d + h) ==
   38 && (b + e + i + m) == 38 && (c + f + j + n + q) ==
   38 && (g + k + o + r) == 38 && (l + p + s) == 38 && (c + g + l) ==
   38 && (b + f + k + p) == 38 && (a + e + j + o + s) ==
   38 && (d + i + n + r) == 38 && (h + m + q) == 38)
Where each variable is a unique number in the set {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}.

There are multiple possible solutions, and are 19! possible combinations of integers, so naive brute force will be impractical.

Rules:

No hardcoding the answer or looking up the answer elsewhere; your code needs to find it on its own
Speed doesn't matter, but you do have to show your results, so code that takes 1000 years to run won't help you
Find all the answers
Treat answers that are identical under rotation as identical
Deduct 5% of your total byte count if you output the results in an attractive honeycomb
Fewest bytes wins

"""

from pulp import *

def ci(c):
    return ord(c) - ord('a')

def con(s, t):
    r = "p += ("
    for i in range(len(s)):
        r += "x[%d]" % (ci(s[i]))
        if i+1 < len(s):
            r += "+"
    r += ")==%d" % (t)
    return r

"""

This problem can be set up as a mixed-integer programming problem.
To express the constraint that each variable has to be a different value, we can use the following:

https://stackoverflow.com/questions/50428510/how-to-express-the-not-equals-relation-in-linear-programming
http://yetanothermathprogrammingconsultant.blogspot.com/2016/05/all-different-and-mixed-integer.html

@Erwin Kalvelagen

The all-different constraint can be written pairwise as x[i] ≠ x[j] for all i < j (we don't want to check i and j twice). This inequality can be restated as: x[i] ≤ x[j]-1 OR x[i] ≥ x[j]+1. The OR condition can be implemented in a MIP model as:

 x[i] ≤ x[j]-1 + M δ[i,j]        ∀ i < j
 x[i] ≥ x[j]+1 - M (1-δ[i,j])    ∀ i < j
 δ[i,j] ∈ {0,1}
where M=n+1. We added extra binary variables δ[i,j].

This is the most direct formulation of a "not-equal" construct. It also has relatively few binary variables: about n^2/2. Other formulations are also possible.

"""

def solve():
    CONSTRAINTS = ["abc", "defg", "hijkl", "mnop", "qrs", "adh", "beim", "cfjnq", "gkor", "lps", "cgl", "bfkp", "aejos", "dinr", "hmq"]
    TARGET = 38

    n = 19
    x = []
    o = []
    
    for i in range(n):
        x.append(LpVariable("x_%d" % (i), 1, n, cat=LpInteger))

    for i in range(n):
        v = []
        for j in range(n):
            v.append(LpVariable("o_%d_%d" % (i, j), 0, 1, cat=LpBinary))
        o.append(v)

    p = LpProblem("Aristotles", LpMaximize)
    p += lpSum(x for x in x), "Objective"

    # constraint: each variable has to be a different value
    M = n + 1
    for i in range(n):
        for j in range(i+1, n):
            p += x[i] <= x[j]-1 + M*o[i][j]
            p += x[i] >= x[j]+1 - M*(1-o[i][j])

    # constraint: the following set of variables has to add up to the target value
    for c in CONSTRAINTS:
        exec(con(c, TARGET))

    r = []
    if p.solve(PULP_CBC_CMD(msg=0)) < 0:
        return r
    for v in x:
        r.append(int(v.varValue))

    # verify the solution works
    for s in CONSTRAINTS:
        v = 0
        for c in s:
            v += x[ci(c)]
        assert(v == TARGET)

    return r

def main():
    print(solve())

main()
