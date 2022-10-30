"""

Create a function that takes an integer parameter, n, and returns the sum of all the digits in each integer in the range 0 to 10^n - 1 inclusive.

    If n is 1, the range is 0 to 9.
    if n is 2, the range is 0 to 99.
    if n is 12, the range is 0 to 999999999999.

n will always be >= 1.

Because of JavaScript's representation of numbers, n will be limited to 125
Examples

sumDigitsInRange(1) ➞ 45

sumDigitsInRange(2) ➞ 900

sumDigitsInRange(3) ➞ 13500

sumDigitsInRange(8) ➞ 3600000000

sumDigitsInRange(13) ➞ 585000000000000

Notes

The function should run quickly.

"""

# https://oeis.org/A034967
def sum(n):
    return 45*n*10**(n-1)

assert(sum(1) == 45)
assert(sum(2) == 900)
assert(sum(3) == 13500)
assert(sum(7) == 315000000)
assert(sum(8) == 3600000000)
assert(sum(13) == 585000000000000)
assert(sum(14) == 6300000000000000)
assert(sum(125) == 56250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000)
