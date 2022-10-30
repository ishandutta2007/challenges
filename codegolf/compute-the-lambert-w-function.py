#!/usr/bin/env python

"""

Your challenge is to compute the Lambert W function. W(x) is defined to be the real value(s) y

such that

y=W(x) if x=yey

where e=2.718281828... is Euler's number.

Sometimes, y may not be real.

Examples

W(-1) = non-real
W(-0.1) = -0.11183, -3.57715
W(1) = 0.56714
W(2) = 0.85261

Here's a quick graph of what this function looks like.

enter image description here
Rules

Your goal is to take an input and output either nothing, 1 solution, or 2 solutions, out to 5 significant figs. You should expect float inputs within the reasonable range of -100..100.

This is code-golf, so shortest code wins.

"""

import numpy as np
from scipy.special import lambertw

def W(x):
    l = []
    for i in range(-1, 1):
        v = lambertw(x, i)
        if not np.iscomplex(v):
            l.append(np.real(v))
    return l

def main():
    print(W(-1))
    print(W(-0.1))
    print(W(1))
    print(W(2))

main()
