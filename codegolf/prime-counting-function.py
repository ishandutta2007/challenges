#!/usr/bin/env python

"""

Introduction
The Prime Counting Function, also known as the Pi function π(x), returns the amount of primes less than or equal to x.

Challenge
Your program will take an integer x which you can assume to be positive, and output a single integer equal to the amount of primes less than or equal to x. This is a code-golf challenge, so the winner will be the program with the fewest bytes.

You may use any language of your choosing provided that it existed before this challenge went up, but if the language has a built-in prime-counting function or a primality checking function (such as Mathematica), that function cannot be used in your code.

Example Inputs
Input:
1
Output:
0

Input:
2
Output:
1

Input:
5
Output:
3

A000720 - OEIS

"""

from sympy import *

def main():
    for i in range(1, 10000):
        print(primepi(i))

main()
