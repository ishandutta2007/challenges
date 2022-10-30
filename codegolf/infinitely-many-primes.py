#!/usr/bin/env python

"""

Since Euclid, we have known that there are infinitely many primes.
The argument is by contradiction: If there are only finitely many, let's say p1,p2,...,pn, then surely m:=p1⋅p2⋅...⋅p[n+1] is not divisible by any of these primes, so its prime factorization must yield a new prime that was not in the list.
So the assumption that only finitely primes exist is false.

Now let's assume that 2 is the only prime. The method from above yields 2+1=3 as a new (possible) prime.
Applying the method again yields 2⋅3+1=7, and then 2⋅3⋅7+1=43, then 2⋅3⋅7⋅43+1=13⋅139, so both 13 and 139 are new primes, etc.
In the case where we get a composite number, we just take the least new prime. This results in A000945.

Challenge
Given a prime p1 and an integer n calculate the n-th term pn of the sequence defined as follows:

pn:=min(primefactors(p1⋅p2⋅...⋅p[n-1]+1))

These sequences are known as Euclid-Mullin-sequences.

Examples
For p1=2:

1 2
2 3
3 7
4 43
5 13
6 53
7 5
8 6221671
9 38709183810571
For p1=5 (A051308):

1 5
2 2
3 11
4 3
5 331
6 19
7 199
8 53
9 21888927391
For p1=97 (A051330)

1 97
2 2
3 3
4 11
5 19
6 7
7 461
8 719
9 5

"""

from sympy import *

class EuclidMullin:
    def __init__(self, p1):
        self.lut = {
            1: p1,
        }
    
    def term(self, n):
        if n < 1:
            return 0
        
        v = self.lut.get(n)
        if v != None:
            return v
        
        v = 1
        for i in range(1, n):
            v *= self.term(i)
        
        self.lut[n] = min(primefactors(v + 1))
        return self.lut[n]
            
def test(r):
    if len(r) < 1:
        return

    em = EuclidMullin(r[0])
    for i in range(len(r)):
        assert(em.term(i+1) == r[i])
        print(r[i], end=' ')
    print()

def main():
    test([2, 3, 7, 43, 13, 53, 5, 6221671, 38709183810571])
    test([5, 2, 11, 3, 331, 19, 199, 53, 21888927391])
    test([97, 2, 3, 11, 19, 7, 461, 719, 5])

main()
