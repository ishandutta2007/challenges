#!/usr/bin/env python

"""

Challenge
You must choose one number x (y = x + 9) and create ten unique programs which each print out one of the numbers in the range x to y inclusive. However, there are three twists:

Each program's score is the difference between length of your program in bytes and n (where n is the number that the program outputs). i.e. If a program is 12 bytes long and it outputs the number 15, its score is 3 (|15-12| = 3).
You must not use comments to achieve this byte count.
Your program must not contain any number which is contained within the number which the program outputs. i.e. If a program outputs 1659, the program cannot contain 1, 6, 5 or 9
Your program must not contain any of the characters which are the first letters of the number which the program outpts. i.e. If the program outputs 1659, the program cannot contain o, s, f or n (one, six, five and nine)
Rules
If any number is impossible, this is counted as a DNP. You should declare all DNPs in your range.

The following is a list of numbers and their spellings. The disallowed characters for each are highlighted in bold:

0: Zero
1: One
2: Two
3: Three
4: Four
5: Five
6: Six
7: Seven
8: Eight
9: Nine
Scoring
Your overall score is the sum of all your programs' scores.

Winning
The person with the lowest score with the fewest DNPs wins.

In the event of a tie, the person whose last edit was earliest wins.

"""

def gen(x):
    r = []
    y = x + 9
    while x <= y:
        r.append("print({})".format(x))
        x += 1
    return r

def main():
    for s in gen(1):
        eval(s)

main()
