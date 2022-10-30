#!/usr/bin/env python

"""

Introduction:

Two resistors, R1 and R2, in parallel (denoted R1 || R2) have a combined resistance Rp given as:

R_P2=(R1⋅R2)/(R1+R2)
or as suggested in comments:

R_P2=1/(1/R1+1/R2)

Three resistors, R1, R2 and R3 in parallel (R1 || R2 || R3) have a combined resistance (R1 || R2) || R3 = Rp || R3 :

RP3=((R1⋅R2/R1+R2)⋅R3)/((R1⋅R2/R1+R2)+R3)

or, again as suggested in comments:

RP3=1/(1/R1+1/R2+1/R3)

These formulas can of course be extended to an indefinite number of resistors.

Challenge:
Take a list of positive resistor values as input, and output the combined resistance if they were placed in parallel in an electric circuit. You may not assume a maximum number of resistors (except that your computer can handle it of course).

Test cases:
1, 1
0.5

1, 1, 1
0.3333333

4, 6, 3
1.3333333

20, 14, 18, 8, 2, 12
1.1295

10, 10, 20, 30, 40, 50, 60, 70, 80, 90
2.6117

"""

def parallel(a):
    r = 0
    for v in a:
        r += 1/v
    return 1/r

def main():
    print(parallel([1, 1]))
    print(parallel([1, 1, 1]))
    print(parallel([4, 6, 3]))
    print(parallel([20, 14, 18, 8, 2, 12]))
    print(parallel([10, 10, 20, 30, 40, 50, 60, 70, 80, 90]))

main()
