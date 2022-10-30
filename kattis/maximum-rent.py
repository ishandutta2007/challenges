#!/usr/bin/env python

"""

Yan and Fen have just accepted jobs in TechValley California allowing them to pursue their childhood dream of renting the most expensive apartment in the area.

Yan and Fen have decided that the rent of an apartment denoted R is a function of its square footage x and the number of smartbulbs y it has.
The cost of 1 square foot is given by a and the cost of 1 smartbulb is given by b and thus we have,

R=ax+by

Fortunately for the pair, TechValley California has no shortage of expensive apartments for rent. Unfortunately, there are some specific constraints on the apartment and the contents of the apartment that Yan and Fen must follow.
First the square footage of the apartment and the number of smart bulbs must both be greater than or equal to 1.

xy≥1≥1

Secondly, the square footage of the apartment plus the number of smartbulbs cannot exceed a specific m, you may assume that m will always be an even integer.

x+y≤m

Lastly, since both Yan and Fen need lots of outlets in their apartment to support all their electronics they will only look at apartments that have exactly 2
outlets for each square foot of the house in addition to one outlet for each smartbulb with minimum of σ outlets. You may assume that σ will always be an even integer.

2x+y≥σ

Find the maximum rent of an apartment R subject to these constraints

Input

The input consists of a single test case with two lines. The test case starts with two integers a and b (0≤a,b<100), the price per square foot and price per smart bulb respectively.

The next line consists of two integers m and σ (0<m,σ≤108 and m,σ are both even) the square footage and smartbulbs maximum and the minimum number of outlets respectively.

Output

Output a single line with the maximum value of R. Note that R is guaranteed to be an integer and the input will be supplied such that there will always be a solution.

"""

from pulp import *

def maximum_rent(a, b, m, s):
    x = LpVariable("x", cat=LpInteger)
    y = LpVariable("y", cat=LpInteger)
    p = LpProblem("Rent", LpMaximize)
    p += a*x + b*y
    p += x >= 1
    p += y >= 1
    p += x + y <= m
    p += 2*x + y >= s
    if p.solve(PULP_CBC_CMD(msg=0)) < 0:
        return -1
    R = a*x.varValue + b*y.varValue
    return int(R)

def main():
    assert(maximum_rent(3, 1, 12, 16) == 34)
    assert(maximum_rent(0, 3, 8, 12) == 12)

main()
