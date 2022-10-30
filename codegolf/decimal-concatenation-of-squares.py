#!/usr/bin/env python

"""

Premise

One night, I was just contemplating on numbers. I found out about something unique about numbers like 7, 10, 12, 13, and more.
They are squares of squares! Meaning, that when squared, are comprised of squares themselves.
The OEIS calls them Squares which are a decimal concatenation of two or more squares.

Examples of such numbers include 7 (49 has 22 and 32) 13 (169 has 42 and 32) and 20 (400 has 22 and 02).
Other examples include 37, as 1369 is a term as it can be partitioned as 1, 36 and 9. 1444 (382) is a term as it can be partitioned as 1, 4, 4, 4.
I asked about this on Math.SE, and it was named after me!

Challenge

Design a program that prints TanMath numbers. Given the number n (starting at 1), print the nth TanMath number, T(n).

As a code example:

>> 1
>> 7
or

>> 4
>> 13
Reference Python implementation(thanks @MartinBüttner and @Sp3000!):

from math import sqrt

n = input()

def r(digits, depth):
    z = len(digits)
    if z < 1:
        return (depth > 1)
    else:
        for i in range(1, z+1):
            t = int(digits[:i])
            if sqrt(t).is_integer() and r(digits[i:], depth+1):
                return True
        return False


i=0
t=0
while t < n:
    i += 1

    if r(str(i**2), 0):
        t += 1

print i
Here is a list of the first 100 numbers:

7 10 12 13 19 20 21 30 35 37 38 40 41 44 50 57 60 65 70 80 90 95 97 100 102 105 107 108 110 112 119 120 121 125 129 130 138 140 150 160 170 180 190 191 200 201 204 205 209 210 212 220 223 230 240 250 253 260 270 280 285 290 300 305 306 310 315 320 325 330 340 342 343 345 348 350 360 369 370 375 379 380 390 397 400 402 405 408 410 413 420 430 440 441 450 460 470 475 480 487

This is a code golf, so the shortest code wins!

Good luck!

"""

from math import *

def r(digits, depth):
    z = len(digits)
    if z < 1:
        return depth > 1
    
    for i in range(1, z+1):
        t = int(digits[:i])
        if sqrt(t).is_integer() and r(digits[i:], depth+1):
            return True
    return False

def T(n):
    i = 0
    t = 0
    while t < n:
        i += 1
        if r(str(i**2), 0):
            t += 1
    return i

def main():
    tab = [7, 10, 12, 13, 19, 20, 21, 30, 35, 37, 38, 40, 41, 44, 50, 57, 60, 65, 70, 80, 90, 95, 97, 100, 102, 105, 107, 108, 110, 112, 119, 120, 121, 125, 129, 130, 138, 140, 150, 160, 170, 180, 190, 191, 200, 201, 204, 205, 209, 210, 212, 220, 223, 230, 240, 250, 253, 260, 270, 280, 285, 290, 300, 305, 306, 310, 315, 320, 325, 330, 340, 342, 343, 345, 348, 350, 360, 369, 370, 375, 379, 380, 390, 397, 400, 402, 405, 408, 410, 413, 420, 430, 440, 441, 450, 460, 470, 475, 480, 487]
    
    for i in range(len(tab)):
        assert(T(i+1) == tab[i])

main()
