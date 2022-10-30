#!/usr/bin/env python

"""

Given an array A of size N and an integer K , check if there exist any pair of index i,j such that Ai+Aj=K and i≠j

Input

The first line of the input contains a single integer T denoting the number of test cases.
The first line of each test case contains two space separated integer N and K respectively.
The second line of each test case contains N space separated integers Ai.

Output

For each test case, print a single line containing answer "Yes" or "No" (without quotes).

Constraints

1≤T≤100
2≤N≤10^4
1≤K≤10^9
1≤Ai≤10^9

"""

def main():
    assert(pairs([1, 2, 1, 3], 3) == True)
    assert(pairs([1, 2, 1, 3], 6) == False)
    assert(pairs([5, 4, 1, 2, 3], 1) == False)

def pairs(a, k):
    m = {}
    for i, v in enumerate(a):
        m[v] = i + 1
    
    for i, v in enumerate(a):
        j = k - v
        try:
            if m[j] != i + 1 and m[j] >= 1:
                return True
        except:
            pass
    
    return False

main()
