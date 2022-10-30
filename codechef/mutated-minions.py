#!/usr/bin/env python

"""

Gru has not been in the limelight for a long time and is, therefore, planning something particularly nefarious.
Frustrated by his minions' incapability which has kept him away from the limelight, he has built a transmogrifier — a machine which mutates minions.

Each minion has an intrinsic characteristic value (similar to our DNA), which is an integer. The transmogrifier adds an integer K to each of the minions' characteristic value.

Gru knows that if the new characteristic value of a minion is divisible by 7, then it will have Wolverine-like mutations.

Given the initial characteristic integers of N minions, all of which are then transmogrified, find out how many of them become Wolverine-like.

Input Format:

The first line contains one integer, T, which is the number of test cases. Each test case is then described in two lines.

The first line contains two integers N and K, as described in the statement.

The next line contains N integers, which denote the initial characteristic values for the minions.

Output Format:

For each testcase, output one integer in a new line, which is the number of Wolverine-like minions after the transmogrification.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ K ≤ 100
All initial characteristic values lie between 1 and 10^5, both inclusive.

"""

def transminion(a, k):
    c = 0
    for v in a:
        v += k
        if v%7 == 0:
            c += 1
    return c

def main():
    assert(transminion([2, 4, 1, 35, 1], 10) == 1)

main()
