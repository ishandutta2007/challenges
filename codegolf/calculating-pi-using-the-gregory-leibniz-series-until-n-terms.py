#!/usr/bin/env python

"""

Your task: given i, calculate π till i terms of the Gregory-Leibniz series.

The series:

π = 4/1 - 4/3 + 4/5 - 4/7 + 4/9 -...

Here, 4/1 is the first term, -4/3 is the second, 4/5 is the second and so on.

Note that for the nth term,

Sn = 4*(-1)**(n+1) / (2n-1)
πn = S1 + S2 + ... + Sn,
where πn is π approximated to n terms.
Test cases:

In - Out
1 - 4
2 - 2.66666667
3 - 3.46666667
4 - 2.8952381
Floating point issues are OK.

You may not calculate infinite terms of pi using this as we are calculating a number rather than terms of a series here.

This is code-golf, so shortest answer wins!

"""

def series(n):
    r = 0
    for i in range(1, n+1):
        r += (4*(-1)**(i+1)) / (2*i - 1)
    return r

def main():
    for i in range(1, 1001):
        print(i, series(i))

main()
