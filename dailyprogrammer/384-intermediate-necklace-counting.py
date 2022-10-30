#!/usr/bin/env python

"""

For the purpose of this challenge, a k-ary necklace of length n is a sequence of n letters chosen from k options, e.g. ABBEACEEA is a 5-ary necklace of length 9.
Note that not every letter needs to appear in the necklace.
Two necklaces are equal if you can move some letters from the beginning to the end to make the other one, otherwise maintaining the order.
For instance, ABCDE is equal to DEABC. For more detail, see challenge #383 Easy: Necklace matching.

Today's challenge is, given k and n, find the number of distinct k-ary necklaces of length n.
That is, the size of the largest set of k-ary necklaces of length n such that no two of them are equal to each other.
You do not need to actually generate the necklaces, just count them.

For example, there are 24 distinct 3-ary necklaces of length 4, so necklaces(3, 4) is 24. Here they are:

AAAA  BBBB  CCCC
AAAB  BBBC  CCCA
AAAC  BBBA  CCCB
AABB  BBCC  CCAA
ABAB  BCBC  CACA
AABC  BBCA  CCAB
AACB  BBAC  CCBA
ABAC  BCBA  CACB
You only need to handle inputs such that kn < 10,000.

necklaces(2, 12) => 352
necklaces(3, 7) => 315
necklaces(9, 4) => 1665
necklaces(21, 3) => 3101
necklaces(99, 2) => 4950
The most straightforward way to count necklaces is to generate all kn patterns, and deduplicate them (potentially using your code from Easy #383).
This is an acceptable approach for this challenge, as long as you can actually run your program through to completion for the above examples.

Optional optimization
A more efficient way is with the formula:

necklaces(k, n) = 1/n * Sum of (phi(a) k^b)
    for all positive integers a,b such that a*b = n.
For example, the ways to factor 10 into two positive integers are 1x10, 2x5, 5x2, and 10x1, so:

necklaces(3, 10)
    = 1/10 (phi(1) 3^10 + phi(2) 3^5 + phi(5) 3^2 + phi(10) 3^1)
    = 1/10 (1 * 59049 + 1 * 243 + 4 * 9 + 4 * 3)
    = 5934
phi(a) is Euler's totient function, which is the number of positive integers x less than or equal to a such that the greatest common divisor of x and a is 1. For instance, phi(12) = 4, because 1, 5, 7, and 11 are coprime with 12.

An efficient way to compute phi is with the formula:

phi(a) = a * Product of (p-1) / Product of (p)
    for all distinct prime p that divide evenly into a.
For example, for a = 12, the primes that divide a are 2 and 3. So:

phi(12) = 12 * ((2-1)*(3-1)) / (2*3) = 12 * 2 / 6 = 4
If you decide to go this route, you can test much bigger examples.

necklaces(3, 90) => 96977372978752360287715019917722911297222
necklaces(123, 18) => 2306850769218800390268044415272597042
necklaces(1234567, 6) => 590115108867910855092196771880677924
necklaces(12345678910, 3) => 627225458787209496560873442940
If your language doesn't easily let you handle such big numbers, that's okay. But your program should run much faster than O(kn).

"""

from sympy import *

# https://handwiki.org/wiki/Necklace_(combinatorics)
def necklaces(k, n):
    r = 0
    for a in range(1, n+1):
        if n%a == 0:
            b = n//a
            r += totient(a) * k**b
    return r//n

def main():
    assert(necklaces(2, 12) == 352)
    assert(necklaces(3, 7) == 315)
    assert(necklaces(9, 4) == 1665)
    assert(necklaces(21, 3) == 3101)
    assert(necklaces(99, 2) == 4950)
    assert(necklaces(3, 10) == 5934)
    assert(necklaces(3, 90) == 96977372978752360287715019917722911297222)
    assert(necklaces(123, 18) == 2306850769218800390268044415272597042)
    assert(necklaces(1234567, 6) == 590115108867910855092196771880677924)
    assert(necklaces(12345678910, 3) == 627225458787209496560873442940)

main()
