#!/usr/bin/env python

"""

Your task: given a nonzero positive number i, calculate pi using the Nilakantha series unto i terms.

The Nilakantha series is as follows:

3 + 4/(2∗3∗4) - 4/(4∗5∗6) + 4/(6∗7∗8) - ...

3 is the first term, 4/(2*3*4) is the second, -4/(4*5*6) is the third, and so on.

Notice that for the nth term:

S_1 = 3
S_n = 4*(-1)**n / (2n∗(2n−1)∗(2n−2))

The approximation of pi by summing up these terms is
S1+S2+…+Sn

Test cases:

In = Out

1 = 3
2 = 3.16666666667
3 = 3.13333333333
4 = 3.1452381
Notice the pattern of the numbers approximating towards pi.

Floating point issues are OK.

This is code-golf so shortest answer wins!

EDIT: by default this is 1-indexed, but if you want 0-indexed no problem, just mention it. And even infinitely printing the approximations with no input is Okay.

"""

def seq(n):
    if n < 1:
        return 0
    if n == 1:
        return 3
    return 4*(-1)**n / (2*n * (2*n - 1) * (2*n - 2))

def nilakantha(n):
    r = 0
    for i in range(1, n+1):
        r += seq(i)
    return r

def main():
    for i in range(1, 20):
        print(i, nilakantha(i))

main()
