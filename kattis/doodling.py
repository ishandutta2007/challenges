#!/usr/bin/env python

"""

When thinking about a hard problem a lot of people like to doodle, to create “an unfocused drawing that can help the memory and improve abstract thinking”.
The most basic form of doodle is a repetitive pattern covering the whole page.
One way to create such a pattern is to take a graphing paper and start in the top-left corner (0,0) and fill out the square,
then move down and right one square (1,1), fill it out, and so on. Every time you hit the edge of the paper you reverse direction, until you are back at the starting point.
This will create a very soothing pattern.

However, to ensure you don’t spend the whole competition doodling you need to figure out how how many squares you will have to
fill in the paper to complete the doodle before you even start doodling.

Input

    First line of input contains an integer 1≤n≤4000, the number of test cases.

    Each test case consists of a line containing two integers 2≤xy≤20000, the height and width (in squares) of the graphing paper.

Output

    The number of unique squares you will have filled in before you are done with your doodle.

"""

from math import *

def unique_squares(x, y):
    x -= 1
    y -= 1
    l = lcm(x, y)
    return l + 1 - ((l//x - 1) * (l//y - 1) / 2)

def main():
    assert(unique_squares(11, 3) == 11)
    assert(unique_squares(5, 7) == 12)
    assert(unique_squares(5, 8) == 20)

main()
