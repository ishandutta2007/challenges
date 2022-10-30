#!/usr/bin/env python

"""

The Binary Sierpinski Triangle sequence is the sequence of numbers whose binary representations give the rows of the Binary Sierpinski Triangle, which is given by starting with a 1 in an infinite row of zeroes,
then repeatedly replacing every pair of bits with the xor of those bits, like so:

f(0)=      1                    =1
f(1)=     1 1                   =3
f(2)=    1 0 1                  =5
f(3)=   1 1 1 1                 =15
f(4)=  1 0 0 0 1                =17
More digits are given at OEIS: https://oeis.org/A001317

Input: A non-negative integer n in any format you like. (Must work for all n up to 30.)

Output: The nth term (0-indexed) of the sequence as a decimal number.

This is code-golf so try give the shortest answer in bytes of which your language is capable. No answer will be accepted.
Standard loopholes apply (e.g. no hard-coding the sequence), except that you may use a language created/modified after this challenge was posted.
(Do avoid posting another solution in a language that has already been used unless your solution is shorter.)

"""

from sympy import binomial

# https://oeis.org/A001317
def binary_sierpinski(n):
    r = 0
    for i in range(n+1):
        a = binomial(n, i) & 1
        b = 1 << i
        r += a * b
    return r

def main():
    tab = [1, 3, 5, 15, 17, 51, 85, 255, 257, 771, 1285, 3855, 4369, 13107, 21845, 65535, 65537, 196611, 327685, 983055, 1114129, 3342387, 5570645, 16711935, 16843009, 50529027, 84215045, 252645135, 286331153, 858993459, 1431655765, 4294967295, 4294967297, 12884901891, 21474836485, 64424509455, 73014444049, 219043332147, 365072220245, 1095216660735, 1103806595329, 3311419785987]
    for i in range(len(tab)):
        assert(binary_sierpinski(i) == tab[i])

main()
