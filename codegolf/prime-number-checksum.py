#!/usr/bin/env python

"""

Given a message, append checksum digits using prime numbers as weights.

A checksum digit is used as an error-detection method.
Take, for instance, the error-detection method of the EAN-13 code:
The checksum digit is generated by:

Multiplying each digit in the message alternating by 1 and 3 (the weights)
Summing it up
Calculating the difference between the nearest multiple of 10 (Maximum possible value) and the sum
E.g:

1214563 -> 1*1 + 2*3 + 1*1 + 4*3 + 5*1 + 6*3 + 3*1 = 46
50 - 46 = 4
Although the EAN-13 code can detect transposition errors (i.e. when two adjacent bits are switched, the checksum will be different) it can't detect an error when two bits with the same weight are swapped.
E.g.: 163 -> checksum digit 8, 361 -> checkdum digit 8

Using a prime checksum, with the first weight being the first prime number, the second weight being the second prime number, etc., errors can be detected when any two bits are swapped.
Because the primes act as weights, you have an extra factor, the length of the message l:

Multiply each digit in the message by the nth prime (First digit times the first prime, second digit times the second prime, etc.)
Sum it up
Calculate the sum of each prime up to the lth prime multiplied by 9 plus 1 (Maximum possible value)
Subtract the second sum by the first sum
E.g.:

1214563 -> 1*2 + 2*3 + 1*5 + 4*7 + 5*11 + 6*13 + 3*17 = 225
9*(2+3+5+7+11+13+17) + 1 -> 523
523 - 225 = 298
Rules
Take a decimal string, leading zeros are prohibited
Output the checksum digits
Standard Loopholes apply
This is code-golf, the shortest answer wins!
Examples
[In]:  213
[Out]: 69

[In]:  89561
[Out]: 132

[In]:  999999
[Out]: 1

[In]:  532608352
[Out]: 534

"""

import sympy

def digits(n):
    d = []
    while True:
        d.append(n % 10)
        n //= 10
        if n <= 0:
            break
    d.reverse()
    return d

def primes(n):
    p = []
    for i in range(n):
        p.append(sympy.prime(i+1))
    return p

def prime_checksum(n):
    d = digits(n)
    p = primes(len(d))
    r = 0
    for i in range(len(d)):
        r += d[i]*p[i]
    return (9*sum(p) + 1) - r

def main():
    assert(prime_checksum(1214563) == 298)
    assert(prime_checksum(89561) == 132)
    assert(prime_checksum(999999) == 1)
    assert(prime_checksum(532608352) == 534)

main()
