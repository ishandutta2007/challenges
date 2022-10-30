#!/usr/bin/env python

"""

Preface
In the well known carol, The Twelve Days of Christmas, the narrator is presented with several gifts each day.
The song is cumulative - in each verse, a new gift is added, with a quantity one higher than the gift before it.
One Partridge, Two Turtle Doves, Three French Hens, and so on.

At any given verse, N, we can calculate the cumulative sum of presents so far in the song by finding the Nth tetrahedral number, which gives the results:

Verse 1: 1
Verse 2: 4
Verse 3: 10
Verse 4: 20
Verse 5: 35
Verse 6: 56
Verse 7: 84
Verse 8: 120
Verse 9: 165
Verse 10: 220
Verse 11: 286
Verse 12: 364
For example, after verse 4, we've had 4*(1 partridge), 3*(2 turtle doves), 2*(3 French hens) and 1*(4 calling birds). By summing these, we get 4(1) + 3(2) + 2(3) + 1(4) = 20.

The Challenge
Your task is to write a program or function which, given a positive integer representing the number of presents 364 ≥ p ≥ 1, determines which day (verse) of Christmas it is.

For example, if p = 286, we are on the 11th day of Christmas. However, if p = 287, then the next load of presents has begun, meaning it is the 12th day.

Mathematically, this is finding the next tetrahedral number, and returning its position in the whole sequence of tetrahedral numbers.

Rules:

This is code-golf, so the shortest solution (in bytes) wins.
Standard golfing loopholes apply.
When it comes to days, your program must be 1-indexed.
Your submission must be a full program or a function - but not a snippet.
Test Cases
1   ->  1
5   ->  3
75  ->  7
100 ->  8
220 ->  10
221 ->  11
364 ->  12

"""

from sympy import *
from sympy.solvers import *

def verse(n):
    x = Symbol('x')
    r = solve(x*(x+1)*(x+2)/6-n, x)
    if len(r) == 0:
        return -1
    return int(r[0])

def main():
    values = [1, 4, 10, 20, 35, 56, 84, 120, 165, 220, 286, 364]
    for i in range(len(values)):
        assert(verse(values[i]) == i+1)

main()
