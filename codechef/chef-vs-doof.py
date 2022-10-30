#!/usr/bin/env python

"""

Chef got into a fight with the evil Dr Doof. Dr Doof has decided to destroy all even numbers from the universe using his Evil-Destroy-inator.
Chef has N integers with him. To stop Doof, Chef has to find an odd number which is an integer multiple of all N numbers that he has with him.
Find if it is possible for Chef to prevent Dr Doof from destroying the even numbers.

Formally, given N positive integers, find if there exists an odd number which is an integer multiple of all the given N numbers.
If yes, print "YES", otherwise "NO". You can print any letter in any case.

Input

First line contains T, number of testcases. Each testcase consists of 2 lines.

The first line of each test case consists of a positive integer N, denoting the number of positive integers Chef has.
The second line of each test case contains N space separated integers Ai each denoting an integer that Chef has with him.

Output

For every test case, if there exists such an odd number, print "YES" on a separate line, otherwise "NO". The judge is case insensitive.
That means, your code can print any letter in any case ( "Yes", "yes" or "YES" are all accepted).

Constraints

1≤T≤10^3
1≤N≤10^3
1≤Ai≤10^3

"""

import math

def odd_multiple(a):
    if len(a) == 0:
        return False

    v = a[0]
    for i in range(1, len(a)):
        v = math.lcm(v, a[i])
    return v%2 != 0

def main():
    assert(odd_multiple([1, 2, 5, 4, 3]) == False)
    assert(odd_multiple([7]) == True)

main()
