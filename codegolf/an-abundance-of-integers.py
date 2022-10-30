#!/usr/bin/env python

"""

An Abundant number is any number where the sum of its proper divisors is greater than the original number. For example, the proper divisors of 12 are:

1, 2, 3, 4, 6
And summing these results in 16. Since 16 is larger than 12, 12 is abundant. Note that this does not include "Perfect numbers", e.g. numbers that are equal to the sum of its proper divisors, such as 6 and 28.

Your task for today is to write a program or function that determines if a number is abundant or not.
Your program should take a single integer as input, and output a truthy/falsy value depending on whether it is abundant or not.
You can assume that the input will always be valid and greater than 0, so for bad inputs, undefined behavior is fine.

You may take your input and output in any reasonable format, for example STDIN/STDOUT, files, or arguments/return values would all be acceptable.

For reference, here are the abundant numbers up to 100:

12,
18,
20,
24,
30,
36,
40,
42,
48,
54,
56,
60,
66,
70,
72,
78,
80,
84,
88,
90,
96,
100
And more can be found on A005101

Since this is code-golf, standard loopholes are denied, and try to write the shortest possible code you can in whichever language you happen to choose!

"""

from sympy import divisors

# http://oeis.org/A005101
def abundant(n):
    return sum(divisors(n)) > 2*n

def main():
    for i in range(101):
        if abundant(i):
            print(i)

main()
