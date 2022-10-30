#!/usr/bin/env python

"""

Input: Either one or two strings consisting of '0's and '1's. If there are 2, they are separated by a space. All strings are of length at least 1.

Output:

    If a single input was given as input, 2 are output.
    If 2 were input, 1 is output.

The output strings can be whatever you like, but if running your program with input A gives you B, then running it with B must give A (if inputting 111 11 gives 00000, then inputting 00000 must give 111 11).

That means if you pipe your program to itself, you should get back whatever you input. If your program is called foo, you can test that like this:

>echo 101 101|foo|foo
101 101

To prevent the use of brute force techniques, your code should be able to run with 1000 digit strings in under 10 seconds. My Python solution for this takes less than 1 second on 10000 digit strings so this shouldn't be a problem.

Shortest code wins.

"""

from math import *

# https://en.wikipedia.org/wiki/Pairing_function
def pair(x, y):
    return (x+y+1)*(x+y)/2 + y

def unpair(z):
    w = floor((sqrt(8*z + 1) - 1) / 2)
    t = (w**2 + w) / 2
    y = z - t
    x = w - y
    return (int(x), int(y))

def lzb(x, y):
    return '{0}{1}'.format('0'*x, bin(y)[2:])

def unlzb(s):
    l = len(s)
    for i in range(l):
        if s[i] != '0':
            return (i, int(s[i:], 2))
    return (l-1, 0)

def meld(s, t):
    (a, b) = unlzb(s)
    (c, d) = unlzb(t)
    x = int(pair(a, b))
    y = int(pair(c, d))
    return lzb(x, y)

def unmeld(s):
    (x, y) = unlzb(s)
    (a, b) = unpair(x)
    (c, d) = unpair(y)
    return '{0} {1}'.format(lzb(a, b), lzb(c, d))

"""

There is a well known bijection from a binary string to the pair of natural numbers (x, y)
x: length of leading zeroes of the binary string
y: the integer value of that binary string

Coupled this with the cantor pairing function to allow the bijection we want.

Given a single binary string, we decode it to (x, y) using the encoding above.
Then we generate 2 more coordinates by
x -> (a, b)
y -> (c, d)
Using the cantor pairing functions, this allows us to have two numbers which we can output as the encoded binary string.

The reverse process of the above allows us to make two numbers from one number.

"""
def cantor(s):
    t = s.split(' ')
    if len(t) == 1:
        return unmeld(t[0])
    elif len(t) == 2:
        return meld(t[0], t[1])
    else:
        raise ValueError("invalid input")

def main():
    print(cantor(cantor('101')))
    print(cantor(cantor('101 101')))
    print(cantor(cantor('1000')))
    print(cantor(cantor('001')))
    print(cantor(cantor('001 01010')))
    print(cantor(cantor('1000')))
    print(cantor(cantor('11111111')))
    print(cantor(cantor('10111010')))
    print(cantor(cantor('00000000')))
    print(cantor(cantor('10001 1001')))
    print(cantor(cantor('010')))
    print(cantor(cantor('1')))

main()
