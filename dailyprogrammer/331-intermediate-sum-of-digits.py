"""

Description

For some xn, find the sum of its digits. The solution to this problem is extremely simple. Say, I give you 34. You could calculate 3n and add the digits.

However things might get a bit complex for 5100. It's a 70-digit number. You could come up with a larger data type that could handle the product of that number and then you could add each number... but where's the fun in that?

This is today's challenge. Find the sum of the digits of some xn without directly calculating the number and adding the digits.

Some simple examples with values that you're familiar with:

25 = 32 = 3 + 2 = 5

53 = 125 = 1 + 2 + 5 = 8

27 = 1 + 2 + 8 = 11

Note that I have not summed the digits of 11.

We'll work with powers and bases greater than zero.
Input Description

    Base Power

means basepower

    2 ^ 1000

means 21000
Output Description

Display the sum of the digits of basepower.
Challenge Input

    2 1234

    11 4000

    50 3000

Challenge Output

    1636

    18313

    9208

If you have any challenges, please share it at r/dailyprogrammer_ideas!

Edit : If you're unable to come up with an idea, like the one is Project eulers 16, then feel free to solve it using your own data types (if required). Please consider it as the last option.

"""

def main():
    assert(sumdigits(2, 5) == 5)
    assert(sumdigits(2, 3) == 8)
    assert(sumdigits(2, 7) == 11)
    assert(sumdigits(2, 1234) == 1636)
    assert(sumdigits(11, 4000) == 18313)
    assert(sumdigits(50, 3000) == 9208)

def sum_digits(n, p):
    v = n**p
    r = 0
    while v != 0:
        r += v % 10
        v //= 10
    return r

