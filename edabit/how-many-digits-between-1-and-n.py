"""

Imagine you took all the numbers between 0 and n and concatenated them together into a long string.
How many digits are there between 0 and n? Write a function that can calculate this.

There are 0 digits between 0 and 1, there are 9 digits between 0 and 10 and there are 189 digits between 0 and 100.

Examples

digits(1) ➞ 0

digits(10) ➞ 9

digits(100) ➞ 189

digits(2020) ➞ 6969

Notes

The numbers are going to be rather big so creating that string won't be practical.

"""

from math import *

# https://oeis.org/A058183 
def digits(n):
    if n <= 1:
        return 0
    n = n - 1
    d = floor(log10(n) + 1)
    return (n+1)*d - (10**d-1)//9

def main():
    assert(digits(1) == 0)
    assert(digits(10) == 9)
    assert(digits(100) == 189)
    assert(digits(2020) == 6969)
    assert(digits(103496754) == 820359675)
    assert(digits(3248979384) == 31378682729)
    assert(digits(122398758003456) == 1724870258940729)
    assert(digits(58473029386609125789) == 1158349476621071404669)

main()
