#!/usr/bin/env python

"""

Description
This challenge is based off the British tv game show "Countdown". The rules are pretty simple: Given a set of numbers X1-X5, calculate using mathematical operations to solve for Y. You can use addition, subtraction, multiplication, or division.

Unlike "real math", the standard order of operations (PEMDAS) is not applied here. Instead, the order is determined left to right.

Example Input
The user should input any 6 whole numbers and the target number. E.g.

1 3 7 6 8 3 250
Example Output
The output should be the order of numbers and operations that will compute the target number. E.g.

3+8*7+6*3+1=250
Note that if follow PEMDAS you get:

3+8*7+6*3+1 = 78
But remember our rule - go left to right and operate. So the solution is found by:

(((((3+8)*7)+6)*3)+1) = 250
If you're into functional progamming, this is essentially a fold to the right using the varied operators.

Challenge Input
25 100 9 7 3 7 881

6 75 3 25 50 100 952
Challenge Output
7 * 3 + 100 * 7 + 25 + 9 = 881

100 + 6 * 3 * 75 - 50 / 25 = 952
Notes about Countdown
Since Countdown's debut in 1982, there have been over 6,500 televised games and 75 complete series. There have also been fourteen Champion of Champions tournaments, with the most recent starting in January 2016.

On 5 September 2014, Countdown received a Guinness World Record at the end of its 6,000th show for the longest-running television programme of its kind during the course of its 71st series.

Credit
This challenge was suggested by user /u/MoistedArnoldPalmer, many thanks. Furthermore, /u/JakDrako highlighted the difference in the order of operations that clarifies this problem significantly.
Thanks to both of them. If you have a challenge idea, please share it in r/dailyprogrammer_ideas and there's a good chance we'll use it.

"""

from itertools import *

def operation(v, n):
    l = []
    ops = ['+', '-', '*', '//']
    for i in range(n):
        l.append(ops[v % 4])
        v //= 4
    return l

def equation(a, p, q):
    s = ""
    n = len(a)
    if n < 2:
        return s

    for i in range(n-1):
        if i == 0:
            s = "{0}".format(a[p[i]])
        else:
            s = "({0} {1} {2})".format(s, q[i-1], a[p[i]])
    return s

def countdown(a):
    n = len(a)
    if n < 2:
        return ""

    x = list(range(0, n-1))
    y = 4**(n-2)
    for p in permutations(x):
        for j in range(y):
            q = operation(j, n-2)
            s = equation(a, p, q)
            try:
                if eval(s) == a[n-1]:
                    s = s.replace('//', '/')
                    s = "{0} = {1}".format(s, a[n-1])
                    return s
            except:
                pass
    return ""

def main():
    print(countdown([1, 3, 7, 6, 8, 3, 250]))
    print(countdown([25, 100, 9, 7, 3, 7, 881]))
    print(countdown([6, 75, 3, 25, 50, 100, 952]))

main()
