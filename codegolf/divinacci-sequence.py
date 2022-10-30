#!/usr/bin/env python

"""

Perform the Fibonacci sequence but instead of using:

f(n) = f(n-1)+f(n-2)
Use:

f(n) = sum(divisors(f(n-1))) + sum(divisors(f(n-2)))
For an input of n, output the nth term, your program should only have 1 input.

First 14 terms (0-indexed, you may 1-index; state which you used):

0  | 0     # Initial               | []
1  | 1     # Initial               | [1] => 1
2  | 1     # [] + [1]              | [1] => 1
3  | 2     # [1] + [1]             | [1,2] => 3
4  | 4     # [1] + [1,2]           | [1,2,4] => 7
5  | 10    # [1,2] + [1,2,4]       | [1,2,5,10] => 18
6  | 25    # [1,2,4] + [1,2,5,10]  | [1,5,25] => 31
7  | 49    # [1,2,5,10] + [1,5,25] | [1,7,49] => 57
8  | 88    # [1,5,25] + [1,7,49]   | [1, 2, 4, 8, 11, 22, 44, 88] => 180
9  | 237   # [1,7,49] + [180]      | [1, 3, 79, 237] => 320
10 | 500   # [180] + [320]         | [1, 2, 4, 5, 10, 20, 25, 50, 100, 125, 250, 500] => 1092
11 | 1412  # [320] + [1092]        | [1, 2, 4, 353, 706, 1412] => 2478
12 | 3570  # [1092] + [2478]       | [1, 2, 3, 5, 6, 7, 10, 14, 15, 17, 21, 30, 34, 35, 42, 51, 70, 85, 102, 105, 119, 170, 210, 238, 255, 357, 510, 595, 714, 1190, 1785, 3570] => 10368
13 | 12846 # [2478] + [10368]      | [1, 2, 3, 6, 2141, 4282, 6423, 12846] => 25704
Etc...
You may choose whether or not to include the leading 0. For those who do: the divisors of 0 are [] for the purpose of this challenge.

It's code-golf lowest byte-count wins...

"""

from sympy import *
import functools

# https://oeis.org/A000458
@functools.cache
def f(n):
    if n < 1:
        return 0
    if n < 3:
        return 1
    return sum(divisors(f(n-1))) + sum(divisors(f(n-2)))

def main():
    tab = [1, 1, 2, 4, 10, 25, 49, 88, 237, 500, 1412, 3570, 12846, 36072, 126504, 493920, 2358720, 12292224, 49984224, 171237888, 642804078, 1980490350, 6380883000, 27032104440, 117961599600, 555861355920, 2623445776224]
    for i in range(len(tab)):
        assert(f(i+1) == tab[i])

main()
