#!/usr/bin/env python

"""

{n, k} or S(n,k) is a way of referring to the Stirling numbers of the second kind, the number of ways to partition a set of n items into k non-empty subsets. For example, to partition {1,2,3,4} into 2

non-empty subsets, we have

{{1},{2,3,4}}{{1,2},{3,4}}{{2},{1,3,4}}{{1,3},{2,4}}{{3},{1,2,4}}{{1,4},{2,3}}{{4},{1,2,3}}

So {42}=S(4,2)=7

Here, we'll only be considering the sequence {n3}=S(n,3), or the ways to partition n items into 3 non-empty subsets. This is A000392. There is also the related sequence which ignores the three leading zeros (so is 1,6,25,90,301,...)∗.

This is a standard sequence challenge, where you can choose which of the two related sequences to handle (leading zeros or not). Regardless of which sequence you choose, you should do one of the following:

    Take an integer n

and output the nth element of the sequence. This can be 0 or 1 indexed, your choice, and n's minimum value will reflect this.

Take a positive integer and output the first n elements of the sequence
Take no input and infinitely output the sequence

This is code-golf so the shortest code in bytes wins.

I'm allowing either sequence, as handling the leading zeros can "fail" for some algorithms that have to compute empty sums

Test cases

If you ignore the leading zeros, the first 20 elements are

1, 6, 25, 90, 301, 966, 3025, 9330, 28501, 86526, 261625, 788970, 2375101, 7141686, 21457825, 64439010, 193448101, 580606446, 1742343625, 5228079450

Otherwise, the first 20 elements are

0, 0, 0, 1, 6, 25, 90, 301, 966, 3025, 9330, 28501, 86526, 261625, 788970, 2375101, 7141686, 21457825, 64439010, 193448101

"""

import math

def stirling(n, k):
    r = 0
    s = 1
    for i in range(k+1):
        r += s * math.comb(k, i) * (k - i)**n
        s = -s
    return r // math.factorial(k)

def main():
    for i in range(32):
        print(stirling(i, 3))

main()
