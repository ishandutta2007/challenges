#!/usr/bin/env python

"""

The weather report of Chefland is Good if the number of sunny days in a week is strictly greater than the number of rainy days.

Given 7 integers A1,A2,A3,A4,A5,A6,A7 where Ai=1 denotes that the ith day of week in Chefland is a sunny day, Ai=0 denotes that the ith day in Chefland is a rainy day. Determine if the weather report of Chefland is Good or not.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, 7 space separated integers A1,A2,A3,A4,A5,A6,A7.

Output Format

For each testcase, print "YES" if the weather report of Chefland is Good, otherwise print "NO". Print the output without quotes.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤20
0≤Ai≤1

"""

def good(a):
    s, r = 0, 0
    for v in a:
        if v != 0:
            s += 1
        else:
            r += 1
    return s > r

def main():
    assert(good([1, 0, 1, 0, 1, 1, 1]) == True)
    assert(good([0, 1, 0, 0, 0, 0, 1]) == False)
    assert(good([1, 1, 1, 1, 1, 1, 1]) == True)
    assert(good([0, 0, 0, 1, 0, 0, 0]) == False)

main()
