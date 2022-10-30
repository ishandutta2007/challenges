#!/usr/bin/python

"""

Related: Iterated phi(n) function.

Your challenge is to compute the iterated phi function:

f(n) = number of iterations of φ for n to reach 1.
Where φ is Euler's totient function.

Related OEIS.

Here's the graph of it:

enter image description here

Rules:
Your goal is to output f(n) from n=2 to n=100.

This is code-golf, so shortest code wins.

Here's the values you can check against:

1, 2, 2, 3, 2, 3, 3, 3, 3, 4, 3, 4, 3, 4, 4, 5, 3, 4, 4, 4, 4, 5, 4, 5, 4, 4, 4, 5, 4, 5, 5, 5, 5, 5, 4, 5, 4, 5, 5, 6, 4, 5, 5, 5, 5, 6, 5, 5, 5, 6, 5, 6, 4, 6, 5, 5, 5, 6, 5, 6, 5, 5, 6, 6, 5, 6, 6, 6, 5, 6, 5, 6, 5, 6, 5, 6, 5, 6, 6, 5, 6, 7, 5, 7, 5, 6, 6, 7, 5, 6, 6, 6, 6, 6, 6, 7, 5, 6, 6

"""

from sympy.ntheory.factor_ import totient

def iterated_phi(n):
    if n <= 1:
        return 0

    c = 0
    while n > 1:
        n = totient(n)
        c += 1
    return c

def main():
    inputs = "1, 2, 2, 3, 2, 3, 3, 3, 3, 4, 3, 4, 3, 4, 4, 5, 3, 4, 4, 4, 4, 5, 4, 5, 4, 4, 4, 5, 4, 5, 5, 5, 5, 5, 4, 5, 4, 5, 5, 6, 4, 5, 5, 5, 5, 6, 5, 5, 5, 6, 5, 6, 4, 6, 5, 5, 5, 6, 5, 6, 5, 5, 6, 6, 5, 6, 6, 6, 5, 6, 5, 6, 5, 6, 5, 6, 5, 6, 6, 5, 6, 7, 5, 7, 5, 6, 6, 7, 5, 6, 6, 6, 6, 6, 6, 7, 5, 6, 6"
    seq = inputs.split(",")
    for i in range(0, len(seq)):
        assert(iterated_phi(i + 2) == int(seq[i]))

main()

