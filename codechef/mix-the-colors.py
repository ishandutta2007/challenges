#!/usr/bin/env python

"""

Chef likes to mix colors a lot. Recently, she was gifted N colors A1, A2, ..., AN by her friend.

Chef wants to make the values of all her colors pairwise distinct, as they will then look stunningly beautiful. In order to achieve that, she can perform the following mixing operation zero or more times:

Choose any two colors. Let's denote their values by x and y.
Mix the color with value x into the color with value y. After the mixing, the value of the first color remains x, but the value of the second color changes to x + y.
Find the minimum number of mixing operations Chef needs to perform to make her colors beautiful.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of colors.
The second line contains N space-separated integers A1, A2, ..., AN denoting Chef's initial colors.

Output

For each test case, print a single line containing one integer — the minimum number of required mixing operations.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
1 ≤ Ai ≤ 10^9 for each valid i

"""

def mixing(a):
    m = {}
    for v in a:
        m[v] = True
    return len(a) - len(m)

def main():
    assert(mixing([1, 2, 3]) == 0)
    assert(mixing([2, 1, 2]) == 1)

main()
