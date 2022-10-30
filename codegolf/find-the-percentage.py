#!/usr/bin/env python

"""

Given a list of integers each greater than 0 and an index as input, output the percentage of the item at the given index of the total sum of the list.

Output should be whatever the natural representation for floats/integers is in your language (unary, decimal, Church numerals etc.).
If you choose to round the output in any way, it must have at minimum 2 decimal places (when reasonable. 1.2 doesn't need to be rounded, but 1.20 is also perfectly acceptable).

Indexes can be either 1-indexed or 0-indexed, and will always be within the bounds of the array.

This is code-golf, so the shortest code in bytes wins!

Examples
Using 1-indexed and rounded to 2 d.p

list, index                    =>         output
[1, 2, 3, 4, 5], 5             => 5 / 15    => 33.33
[7, 3, 19], 1                  => 7 / 29    => 24.14
[1, 1, 1, 1, 1, 1, 1, 1, 1], 6 => 1 / 9     => 11.11
[20, 176, 194, 2017, 3], 1     => 20 / 2410 => 0.83
[712], 1                       => 712 / 712 => 100
Or, as three lists:

[[1, 2, 3, 4, 5], [7, 3, 19], [1, 1, 1, 1, 1, 1, 1, 1, 1], [20, 176, 194, 2017, 3], [712]]
[5, 1, 6, 1, 1]
[33.33, 24.14, 11.11, 0.83, 100]

"""

def percentage(a, i):
    return a[i-1]/sum(a) * 100

def main():
    print(percentage([1, 2, 3, 4, 5], 5))
    print(percentage([7, 3, 19], 1))
    print(percentage([1, 1, 1, 1, 1, 1, 1, 1, 1], 6))
    print(percentage([20, 176, 194, 2017, 3], 1))
    print(percentage([712], 1))

main()
