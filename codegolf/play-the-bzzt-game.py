#!/usr/bin/env python

"""

The "Bzzt" game is a game where you must count to a number (in this case 500). However, if the number has a 3 in it, or is divisible by 3, you don't say the number. Instead, you say "Bzzt".

Rules:

You can't hard-code the numbers.
The number only has to satisfy at least 1 of the following requirements
Divisible by 3
Number contains a 3
Some type of separator is mandatory (12bzzt14 doesn't count)
Score is measured in bytes.
You must count exactly to 500, starting at 1 or 0 (you chose).
The numbers must be output, but it doesn't matter how (e.g., stdout, writing to a text file, etc.).
0 can be divisible by 3 or not divisible. You can choose.
You can output the numbers one at a time (ex, output 1, then 2, then bzzt, then 4, etc) or all at once (e.g., output 1 2 bzzt 4 5).
You must replace the letter 3 with the word "bzzt". This is not case sensitive (bZzt, Bzzt, bzzt are all okay).

"""

def count(n):
    for i in range(0, n+1):
        if i%3 == 0 or str(i).find('3') >= 0:
            print("bzzt")
        else:
            print(i)

def main():
    count(500)

main()
