#!/usr/bin/env python

"""

A pandigital number is an integer which contains every digit from 0 to 9 at least once. 1234567890, 1902837465000000, and 9023289761326634265 are all pandigital.
For the purposes of this challenge, numbers such as 123456789 are not pandigital, since they do not contain a 0, even though 123456789 = 0123456789.

A diverse pair of integers is a pair of integers (a,b) such that ab is pandigital. b is called the diversifying exponent.

Challenge: Given an integer a, find the smallest corresponding diversifying exponent b. This is a code-golf, so the shortest program in bytes wins.

(You may assume that there exists such an exponent, that is, your program will not be given invalid input, such as a power of 10.)

Your solution must be able to handle at the minimum the given test cases, but it should theoretically handle all valid inputs.

This is A090493 on OEIS.

Test cases
2 -> 68
3 -> 39
4 -> 34
5 -> 19
6 -> 20
7 -> 18
8 -> 28
9 -> 24
11 -> 23
12 -> 22
13 -> 22
14 -> 21
15 -> 12
16 -> 17
17 -> 14
18 -> 21
19 -> 17
20 -> 51
21 -> 17
22 -> 18
23 -> 14
24 -> 19
25 -> 11
26 -> 18
27 -> 13
28 -> 11
29 -> 12
30 -> 39
31 -> 11
32 -> 14
33 -> 16
34 -> 14
35 -> 19
36 -> 10
1234567890 -> 1

"""

# http://oeis.org/A090493
def diverse(n):
    if n < 1:
        return 0

    s = str(n)
    if n == 1 or (s.count('0') == len(s)-1 and s.startswith('1')):
        return 0

    k = 1
    c = 0
    while c != 10:
        c = 0
        for i in range(10):
            if str(n**k).count(str(i)) == 0:
                c += 1
                break

        if c != 0:
            k += 1
        else:
            return k
    
    return -1

def main():
    tab = [0, 68, 39, 34, 19, 20, 18, 28, 24, 0, 23, 22, 22, 21, 12, 17, 14, 21, 17, 51, 17, 18, 14, 19, 11, 18, 13, 11, 12, 39, 11, 14, 16, 14, 19, 10, 13, 14, 17, 34, 11, 17, 13, 16, 15, 11, 12, 12, 9, 18, 16, 11, 13, 10, 12, 7, 13, 11, 11, 20, 14, 18, 13, 14, 10, 13, 10, 9, 11, 18, 15]

    for i in range(len(tab)):
        assert(diverse(i+1) == tab[i])

main()
