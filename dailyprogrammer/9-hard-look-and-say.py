#!/usr/bin/env python

"""

The U.S government has commissioned you to catch the terrorists!

There is a mathematical pyramid with the following pattern:

1

11

21

1211

111221

312211

you must write a program to calculate up to the 40th line of this pyramid. If you don't, the terrorists win!

"""

def sign(n):
    if n > 0:
        return 1
    if n == 0:
        return 0
    return -1

def say(a):
    r = 0
    p = 0
    while a > 0:
        c = 3 - sign((a % 100) % 11) - sign((a % 1000) % 111)
        r += (10 * c + (a % 10)) * 10**(2*p)
        a //= 10**c
        p += 1
    return r

# https://oeis.org/A005150
def seq(n):
    r = 1
    for i in range(1, n):
        r = say(r)
    return r

def main():
    for i in range(1, 40):
        print(i, seq(i))

main()
