#!/usr/bin/env python

"""

Today's intermediate challenge comes from user nagasgura

Calculate the day of the week on any date in history

You could use the Doomsday rule to program it. It should take in a day, month, and year as input, and return the day of the week for that date.

"""

from datetime import *

def weekday(y, m, d):
    p = date(y, m, d)
    return p.strftime("%A")

def main():
    print(weekday(2002, 12, 4))
    print(weekday(1999, 12, 31))
    print(weekday(2001, 9, 11))

main()
