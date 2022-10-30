#!/usr/bin/env python

"""

A semester in Chef's University has 120 working days. The University's requirement is that a student should be present for at least 75% of the working days in the semester.
If not, the student is failed.

Chef has been taking a lot of holidays, and is now concerned whether he can pass the attendance requirement or not.
N working days have already passed, and you are given N bits - B1, B2, …, BN. Bi = 0 denotes that Chef was absent on the ith day, and Bi = 1 denotes that Chef was present on that day.

Can Chef hope to pass the requirement by the end of the semester?

Input:

First line will contain T, the number of testcases. Then the testcases follow.
Each testcase contains two lines of input.
The first line of each testcase contains a single integer, N, the number of days till now.
The second line of each testcase contains a string B of length N where Bi represents the status of the ith day.

Output:

For each testcase, output the answer in a single line - "YES" if Chef can pass the attendance requirement and "NO" if not.

Constraints
1≤T≤10
1≤N≤120
0≤Bi≤1

"""

def attendance(s):
    r = 0
    for c in s:
        if c == '0':
            r += 1
    if r > 30:
        return "NO"
    return "YES"

def main():
    assert(attendance("00000000000000000000000000000000000000000000000000") == "NO")
    assert(attendance("01010101010101010101010101010101010101010101010101") == "YES")
    assert(attendance("01") == "YES")

main()
