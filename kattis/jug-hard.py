#!/usr/bin/env python

"""

You have two empty jugs and tap that may be used to fill a jug. When filling a jug from the tap, you can only fill it completely (i.e., you cannot partially fill it to a desired level, since there are no volume measurements on the jug).

You may empty either jug at any point.

You may transfer water between the jugs: if transferring water from a larger jug to a smaller jug, the smaller jug will be full and there will be water left behind in the larger jug.

Given the volumes of the two jugs, is it possible to have one jug with some specific volume of water?

Input

The first line contains T, the number of test cases (1≤T≤100000).
Each test case is composed of three integers: a, b, and d, where a and b (1≤a,b≤10000000) are the volumes of the two jugs, and d is the desired volume of water to be generated.
You can assume that d≤max(a,b).

Output

For each of the T test cases, output either Yes or No, depending on whether the specific volume of water can be placed in one of the two jugs.

"""

from math import *

def enclosable(a, b, d):
    if (d % gcd(a, b)) == 0:
        return "Yes"
    return "No"

def main():
    assert(enclosable(8, 1, 5) == "Yes")
    assert(enclosable(4, 4, 3) == "No")
    assert(enclosable(5, 3, 4) == "Yes")

main()
