#!/usr/bin/env python

"""

The factorial of 10 is 3628800. The last non-zero digit of that factorial is 8.

Similarly, the last non-zero digit of the factorial of 10^3 is 2.

Compute the last non-zero digit of the factorial of 10^9.

Bonus: Compute the last non-zero digit of the factorial of 10^100 .

Thanks to ashashwat for suggesting this problem at r/dailyprogrammer_ideas! If you have a problem that you think would be good for us, why not head over there and suggest it?

"""

# https://oeis.org/A008904
def lnzdf(n):
    tab = [1, 1, 2, 6, 4, 4, 4, 8, 4, 6]
    if n <= 1:
        return 1
    return (6*tab[n%10] * 3**(n//5%4) * lnzdf(n//5)) % 10

def main():
    tab = [1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 8, 8, 6, 8, 2, 8, 8, 6, 8, 2, 4, 4, 8, 4, 6, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2, 2, 2, 4, 2, 8, 2, 2, 4, 2, 8, 6, 6, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 6, 6, 2, 6, 4, 6, 6, 2, 6, 4, 8, 8, 6, 8, 2, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2, 2, 2, 4, 2, 8, 2, 2, 4, 2, 8, 6, 6, 2, 6]
    assert(lnzdf(10) == 8)
    assert(lnzdf(10**3) == 2)
    assert(lnzdf(10**9) == 4)
    assert(lnzdf(10**100) == 6)
    for i in range(len(tab)):
        assert(lnzdf(i) == tab[i])

main()
