#!/usr/bin/env python

"""

Finding primes is a programming rite of passage and very frequently the first serious program someone creates (usually with trial division).

But primes alone are already worn out. A next far more interesting thing is to get the prime gaps: the so-far-longest gaps between consecutive primes.
These are quite rare and "precious". A first few pairs and their differences are:

2 3 1
3 5 2
7 11 4
23 29 6
89 97 8
113 127 14
...
My father used to calculate these by hand for fun up to 10k. Let's see how short a code you can get.

Write a program which goes through primes and produces a line of output every time the difference between two consecutive primes is bigger than that of any two previous consecutive primes.

Your output can either be the two primes followed by their gap, or just the gap. If you choose the later add 10 to your overall score.

For instance, between 3 and 5, there is a gap 2 units wide. The gap between 5 and 7 is also 2, but that's old news, we don't care any more.
Only when you see a new biggest gap, you report it. This reflects how the primes are getting less and less frequent, as the gaps become wider and wider.

Rules:

no builtin functions for prime testing, prime generation or prime gaps
no retrieving http://oeis.org/A002386 or similar (I can smell you cheaters from far away :) )
no precomputed arrays
keep printing until your internal integer type fails on you
Answers are scored in characters, plus the potential 10 penalty. With lower scores being the goal.

You can also show off versions with builtin functions if they are interesting. Be creative.

EDIT: Most of the answers are brilliant and deserve more recognition. However, so far, a GolfScript entry with 48 characters is the shortest.

"""

import sympy

# http://oeis.org/A002386
def primegap(n):
    p = list(sympy.primerange(0, n))
    m = 0
    for i in range(1, len(p)):
        d = p[i] - p[i-1]
        if d > m:
            print(p[i-1], d)
            m = d

def main():
    primegap(10000000)

main()
