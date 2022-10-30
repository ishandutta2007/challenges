#!/usr/bin/env python

"""

"Fly straight, dammit" (OEIS A133058) is a sequence of integers, which has these rules:

a[0] = a[1] = 1
a[n] = a[n-1] + n + 1 if gcd(a[n-1], n) = 1
Otherwise, a[n] = a[n-1] / gcd(a[n-1], n)

In pseudocode:

a[0] = a[1] = 1
if gcd(a[n-1], n) == 1 then
    a[n] = a[n-1] + n + 1
else
    a[n] = a[n-1] / gcd(a[n-1], n)
(GCD stands for "Greatest Common Divisor". For example, GCD(8, 12) = 4.)

The graph for this function looks like this:

Graph

After n=638, it goes into three straight lines.

'Whenever I look at this sequence I am reminded of the great "Fly straight, dammit" scene in the movie "Avatar".' - N. J. A. Sloane

Your task
You have to:

accept an input, n, from the user (it will be a positive integer)
calculate an and output (this is sequence so any output is fine)
This is code-golf so shortest answer in bytes wins!

"""

from math import *

# https://oeis.org/A133058
def a(n):
    if n < 0:
        return 0
    if n <= 1:
        return 1

    x = a(n - 1)
    y = gcd(x, n)
    if y == 1:
        return x + n + 1
    return x // y

def main():
    tab = [1, 1, 4, 8, 2, 8, 4, 12, 3, 1, 12, 24, 2, 16, 8, 24, 3, 21, 7, 27, 48, 16, 8, 32, 4, 30, 15, 5, 34, 64, 32, 64, 2, 36, 18, 54, 3, 41, 80, 120, 3, 45, 15, 59, 104, 150, 75, 123, 41, 91, 142, 194, 97, 151, 206, 262, 131, 189, 248, 308, 77, 139, 202, 266, 133, 199, 266, 334, 167]
    for i in range(len(tab)):
        assert(a(i) == tab[i])

main()
