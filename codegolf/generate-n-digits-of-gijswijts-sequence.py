#!/usr/bin/env python

"""

Introduction
Gijswijt's sequence (A090822) is famously really, REALLY slow. To illustrate:

The first 3 appears in the 9th term (alright).
The first 4 appears in the 220th term (a long way away, but feasible).
The first 5 appears at (approximately) the 10^(10^23)th term (just no).
No one really even knows where the first 6 is... it's suspected it's at the...
2^(2^(3^(4^5)))th term.
You can assume that you won't have to deal with a two-digit number.

The sequence is generated like so:

The first term is 1.
Each term after that is the amount of repeating "blocks" previous to it (if there are multiple repeating "blocks", the largest amount of repeating blocks is used).
To clarify, here are the first few terms.

1 -> 1, 1 (one repeating block (1), so the digit recorded is 1)

1, 1 -> 1, 1, 2 (two repeating blocks (1), so the digit recorded is 2)

1, 1, 2 -> 1, 1, 2, 1 (one repeating block (2 or 1, 1, 2), so the digit recorded is 1)

1, 1, 2, 1 -> 1, 1, 2, 1, 1 (you get the idea)

1, 1, 2, 1, 1 -> 1, 1, 2, 1, 1, 2

1, 1, 2, 1, 1, 2 -> 1, 1, 2, 1, 1, 2, 2 (two repeating blocks (1, 1, 2), so the digit recorded is 2)

Task
Your task is, as stated in the question, to generate n digits of the Gijswijt sequence.

Instructions
The input will be an integer n.
Your code can output the digits in any form (a list, multiple outputs, etc.).
This is code golf, so shortest code in bytes wins.

"""

def gen(s):
    maxk = 1
    for m in range(1, len(s)+1):
        i, y, k = 1, s[-m:], len(s)//m
        if k <= maxk:
            break
        
        while s[-(i+1)*m:-i*m] == y:
            i += 1
        maxk = max(maxk, i)
    
    return maxk

# https://oeis.org/A090822
def gijswijt(n):
    r = [1]
    for i in range(2, n+1):
        r.append(gen(r))
    return r

def main():
    tab = [1, 1, 2, 1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2, 2, 2, 3, 2, 1, 1, 2, 1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2, 2, 2, 3, 2, 2, 2, 3, 2, 2, 2, 3, 3, 2, 1, 1, 2, 1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2, 2, 2, 3, 2, 1, 1, 2, 1, 1, 2, 2, 2, 3, 1, 1, 2, 1, 1, 2, 2, 2, 3, 2, 2, 2, 3, 2, 2, 2, 3, 3, 2, 2, 2, 3, 2, 1]
    
    assert(tab == gijswijt(len(tab)))

main()
