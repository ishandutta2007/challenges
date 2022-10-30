#!/usr/bin/env python

"""

The Torian, x!x, of a non-negative integer x

can be recursively defined as

x!0=xx!n=∏i=1xi!(n−1)=1!(n−1)×2!(n−1)×⋯×x!(n−1)

The Torian is then equal to x!x
for a given x. This sequence begins 0,1,2,24,331776,... for x=0,1,2,3,4,...

Alternatively, you can consider the binary function ! to be instead f(x,y).
We then have f(x,0)=x and f(x,y)=f(1,y−1)×f(2,y−1)×⋯×f(x,y−1). You should then calculate f(x,x).

You are to take a non-negative integer x and output x!x.
You may take input and output in any convenient method, and you don't have to worry about outputs exceeding your language's integer limit.

This is code-golf, so the shortest code in bytes wins

Test cases

x x!x
0  0
1  1
2  2
3  24
4  331776
5  2524286414780230533120
6  18356962141505758798331790171539976807981714702571497465907439808868887035904000000
7  5101262518548258728945891181868950955955001607224762539748030927274644810006571505387259191811206793959788670295182572066866010362135771367947051132012526915711202702574141007954099155897521232723988907041528666295915651551212054155426312621842773666145180823822511666294137239768053841920000000000000000000000000000

And here is a reference program that produces output for 0!0
to 11!11

"""

import math

def compute(z, x):
    if x <= 0:
        return z
    r = 1
    for i in range(1, z+1):
        r *= compute(i, x-1)
    return r

# https://googology.wikia.org/wiki/Torian
def torian(x):
    return compute(x, x)

def main():
    for i in range(1, 8):
        print(i, torian(i))

main()
