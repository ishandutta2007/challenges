#!/usr/bin/env python

"""

Ved is a salesman. He needs to earn at least W rupees in N days for his livelihood. However, on a given day i (1≤i≤N), he can only earn Ai rupees by working on that day.

Ved, being a lazy salesman, wants to take as many holidays as possible. It is known that on a holiday, Ved does not work and thus does not earn anything. Help maximize the number of days on which Ved can take a holiday.

It is guaranteed that Ved can always earn at least W rupees by working on all days.

Input Format

The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first line of each test case contains two integers N and W - the size of the array A and the money Ved has to earn in those N days.
The second line of each test case contains N space-separated integers A1,A2,…,AN denoting the money which Ved can earn on each day.

Output Format

For each test case, output the maximum number of holidays Ved can take.

Constraints
1≤T≤100
1≤W≤10000
1≤N≤100
1≤Ai≤100
It is guaranteed that Ved can always earn at least W rupees by working on all days.

"""

def holidays(a, w):
    sorted(a, reverse=True)
    r = 0
    i = 0
    n = len(a)
    while i < n:
        r += a[i]
        i += 1
        if r >= w:
            break
    return n - i

def main():
    assert(holidays([3, 2, 6, 1, 3], 10) == 2)
    assert(holidays([3, 2, 4, 6], 15) == 0)
    assert(holidays([9, 12, 6, 5, 2, 2], 8) == 5)

main()
