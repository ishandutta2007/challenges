#!/usr/bin/env python

"""

You are given one positive integer N. Calculate
integral[0, inf] exp(2*pi*x - 1)/exp(2*pi*x + 1) * (1/x - x/(N^2 + x^2)) dx
It is possible to prove that its value can be written as a fraction a/b, where a and b are positive integers and b is coprime with 998,244,353.
You need to find a⋅b^-1 modulo 998,244,353, where b−1 denotes the multiplicative inverse of b modulo 998,244,353.

Input

The first and only line of the input contains a single integer N.

Output

Print a single line containing one integer a⋅b−1 modulo 998,244,353.

Constraints
1≤N≤10^6

"""

def integral(n):
    m = 998244353
    r = 0
    for i in range(1, 2*n, 2):
        r += pow(i, m-2, m)
    r *= 2
    r %= m
    return r

def main():
    assert(integral(1) == 2)

    for i in range(1, 11):
        print(i, integral(i))

main()
