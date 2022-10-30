"""

For this challenge, when given a list of (x,y) points your submission needs to output a polynomial function that goes through all of them.

For example, if your points were [(0,0), (2,5)], you could return y = 2.5*x or y = x + 1/4x^2.

    All points passed in will consist only of integers
    Two points will never have the same y value
    Your function be of the form y = a*x^n + ... b*x^m. Reducing of terms is allowed.
    Constants (the exponent and coefficient) can either be in decimal or fractional form. Decimals should be accurate to at least 3 decimal places
    You should be able to handle an arbitrary number of points
    Output must be a string starting with "y=". Whitespace anywhere in the string is fine.

Test cases

Note, the given output is not the only valid output, just one of the possibilities.

(1,4)                                                    -> y=x+3
(0,0), (1,8)                                             -> y=8x
(0,6), (-1,90)                                           -> y=-84x+6
(6,4), (70,4), (-1,-6)                                   -> y=−10/497x^2+760/497x−316/71
(4,5), (5,6), (6,7)                                      -> y=x+1
(20,1), (-20,1), (0,5), (10, 4), (11,12), (17,4), (2,4)  -> y=488137/10424165400x^6−643187/473825700x^5−87561839/10424165400x^4+550999039/1042416540x^3−21590713027/5212082700x^2+300110420/52120827x+5

This is a code-golf, so make your answers as short as possible in your favorite language!

"""

from sympy import *

def basis(x, xc, j, k):
    r = 1
    for m in range(k):
        if m != j:
            r *= (x - xc[m]) / (xc[j] - xc[m])
    return r

# https://en.wikipedia.org/wiki/Lagrange_polynomial
def interpolate(*args):
    x = Symbol('x')
    xc = []
    yc = []
    for p in args:
        xc.append(p[0])
        yc.append(p[1])
    
    k = len(xc)
    r = 0
    for j in range(k):
        r += yc[j]*basis(x, xc, j, k)
    return simplify(expand(r))

def main():
    print(interpolate((1, 4)))
    print(interpolate((0, 0), (1, 8)))
    print(interpolate((0, 6), (-1, 90)))
    print(interpolate((6, 4), (70, 4), (-1, -6)))
    print(interpolate((4, 5), (5, 6), (6, 7)))
    print(interpolate((20, 1), (-20, 1), (0, 5), (10, 4), (11, 12), (17, 4), (2, 4)))

main()
