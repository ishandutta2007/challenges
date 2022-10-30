#!/usr/bin/env python

"""

Write a program or function which will provably print all integers exactly once given infinite time and memory.

Possible outputs could be:

0, 1, -1, 2, -2, 3, -3, 4, -4, …

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -2, -3, -4, -5, -6, -7, -8, -9, 10, 11, …
This is not a valid output, as this would never enumerate negative numbers:

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, …
The output must be in decimal, unless your language does not support decimal integer (in that case use the natural representation of integers your language uses).

Your program has to work up to the numbers with the biggest magnitude of the standard integer type of your language.

Each integer must be separated from the next using any separator (a space, a comma, a linebreak, etc.) that is not a digit nor the negative sign of your language.

The separator must not change at any point.

The separator can consist of multiple characters, as long as none of them is a digit nor the negative sign (e.g. ,  is as valid as just ,).

Any supported integer must eventually be printed after a finite amount of time.

"""

def sequence():
    n = 1
    i = 0
    print(0)
    while True:
        if i == 0:
            print(n)
        elif i == 1:
            print(-n)
            n += 1
        i = (i + 1) & 1

def main():
    sequence()

main()
