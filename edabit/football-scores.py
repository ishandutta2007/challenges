"""

Scoring plays in American football count as either 2, 3, 6, 7, or 8 points.
Write a function that has as it's argument a football score and returns the number of possible ways that score can be achieved.
Order is not important.

Examples

football(4) ➞ 1
// 2+2

football(6) ➞ 3
// 2+2+2 or 3+3 or 6

football(7) ➞ 2
// 2+2+3 or 7

football(9) ➞ 4
// 2+2+2+3 or 3+3+3 or 3+6 or 7+2

Notes

N/A

"""

from sympy import *

"""

http://gerin.perso.math.cnrs.fr/Enseignements/Symbolic2_Solutions.pdf
https://oeis.org/A069745

Express the sequence as a generating function and expand it to the nth coefficient

"""

def football(n):
    if n == 0:
        return 1

    x = var('x')
    f = 1/((1-x**2)*(1-x**3)*(1-x**6)*(1-x**7)*(1-x**8))
    g = f.series(x, 0, n+1)
    return g.coeff(x**n)

def main():
    assert(football(0) == 1)
    assert(football(1) == 0)
    assert(football(8) == 4)
    assert(football(19) == 18)
    assert(football(35) == 103)
    assert(football(66) == 804)

main()
