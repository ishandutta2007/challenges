#!/usr/bin/env python

"""

Chef's daily routine is very simple. He starts his day with cooking food, then he eats the food and finally proceeds for sleeping thus ending his day.
Chef carries a robot as his personal assistant whose job is to log the activities of Chef at various instants during the day.
Today it recorded activities that Chef was doing at N different instants. These instances are recorded in chronological order (in increasing order of time).
This log is provided to you in form of a string s of length N, consisting of characters 'C', 'E' and 'S'. If s[i] = 'C', then it means that at the i-th instant Chef was cooking, 'E' denoting he was eating and 'S' means he was sleeping.

You have to tell whether the record log made by the robot could possibly be correct or not.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The only line of each test case contains string s.

Output

For each test case, output a single line containing "yes" or "no" (without quotes) accordingly.

Constraints
1 ≤ T ≤ 20
1 ≤ N ≤ 10^5

"""

def correct(s):
    for i in range(1, len(s)):
        if s[i] < s[i-1]:
            return False
    return True

def main():
    assert(correct("CES") == True)
    assert(correct("CS") == True)
    assert(correct("CCC") == True)
    assert(correct("SC") == False)
    assert(correct("ECCC") == False)

main()
