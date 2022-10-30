#!/usr/bin/env python

# You are given a space separated list of integers.
# If all the integers are positive, then you need to check if any integer is a palindromic integer.
def check(l):
    return all(map(lambda x: x > 0, l)) and any(map(lambda x: str(x) == str(x)[::-1], l))

print(check([12, 9, 61, 5, 14]))
print(check([12, 9, -1, 5, 14]))
print(check([12, 90, 19, 24, 14]))
print(check([12, 90, 19, 24, 414]))
