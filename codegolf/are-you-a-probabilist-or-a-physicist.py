"""

Hermite polynomials refer to two sequences of polynomials:

    The "probabilist's Hermite polynomials", given by

    Hen(x)=(−1)nex22dndxne−x22

where dndxnf(x)
refers to the nth derivative of f(x)

The "physicist's Hermite polynomials", given by

Hn(x)=(−1)nex2dndxne−x2

The first few terms are
n
	Hen(x)
	Hn(x)
0
	1
	1
1
	x
	2x
2
	x2−1
	4x2−2
3
	x3−3x
	8x3−12x
4
	x4−6x2+3
	16x4−48x2+12
5
	x5−10x3+15x
	32x5−160x3+120x

Both sequences can be expressed via recurrence relations:

Hen+1(x)=xHen(x)−nHen−1(x)Hn+1(x)=2xHn(x)−2nHn−1(x)

with the base cases

He0(x)=1,He1(x)=xH0(x)=1,H1(x)=2x

You should write a polyglot program that works in at least 2 languages. In one language, it should take a non-negative integer n
as input and output the polynomial Hn(x), and in the second, it should take a non-negative integer n and output the polynomial Hen(x).

Your programs should be true polyglots, so are the same bytes, rather than the same characters. For example, if your program is g)ʠẹṁ in the Jelly code page, the bytes are 67 29 A5 D6 EF, and the same program in the 05AB1E code page would be g)¥Öï.

You may output the polynomial in any reasonable format, such as a list of coefficients (little- or big-endian) (e.g. x4−6x2+3) as [1,0,-6,0,3]), a list of pairs of coefficients and powers (e.g. [[1,4], [-6,2], [3,0]]), or a string such as x^4-6x^2+3.

Different versions of languages (e.g. Python 2 and 3) are considered the same language. As a general rule, if 2 languages are considered to be versions of each other (e.g. Seriously and Actually), they may not both be used.
Additionally, using command line flags, in this case, does not count as different languages.

This is code-golf, so the shortest code in bytes wins.
Test cases

The polynomials here are represented in little-endian format

n -> He(x)                                 H(x)
0 -> [1]                                   [1]                                  
1 -> [0, 1]                                [0, 2]                               
2 -> [-1, 0, 1]                            [-2, 0, 4]                           
3 -> [0, -3, 0, 1]                         [0, -12, 0, 8]                       
4 -> [3, 0, -6, 0, 1]                      [12, 0, -48, 0, 16]                  
5 -> [0, 15, 0, -10, 0, 1]                 [0, 120, 0, -160, 0, 32]             
6 -> [-15, 0, 45, 0, -15, 0, 1]            [-120, 0, 720, 0, -480, 0, 64]       
7 -> [0, -105, 0, 105, 0, -21, 0, 1]       [0, -1680, 0, 3360, 0, -1344, 0, 128]

"""

from sympy import *
from sympy.abc import *

def He(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if n == 1:
        return x
    return x*He(n-1) - (n-1)*He(n-2)

def H(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if n == 1:
        return 2*x
    return 2*x*H(n-1) - 2*(n-1)*H(n-2)

def table(n):
    print("Probabilist Hermite Polynomial")
    for i in range(n+1):
        print(pretty(expand(He(i))))

    print()
    print("Physicist Hermite Polynomial")
    for i in range(n+1):
        print(pretty(expand(H(i))))

def main():
    table(7)

main()
