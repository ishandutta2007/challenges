#!/usr/bin/env python

"""

This challenge is a simple ASCII-art challenge inspired by the solar eclipse that happened on August 21, 2017. Given an input 0 <= n <= 4, output the corresponding stage of the eclipse described below:

n=0:
   *****
 **     **
*         *
*         *
**       **
  *******

n=1:
   *****
 **  *****
*   *******
*   *******
**   ******
  *******

n=2:
   *****
 *********
***********
***********
***********
  *******

n=3:
   *****
 *****  **
*******   *
*******   *
******   **
  *******

n=4:
   *****
 **     **
*         *
*         *
**       **
  *******
Rules
You can 0 or 1 index, state what you chose.
The chars used are space and *, you may use any printable char for * (other than space).
Trailing spaces are optional (you may or may not have them).
This is code-golf, lowest byte-count is the winner.

"""

PHASE0 = """
   *****
 **     **
*         *
*         *
**       **
  *******

"""

PHASE1 = """

   *****
 **  *****
*   *******
*   *******
**   ******
  *******

"""

PHASE2 = """
   *****
 *********
***********
***********
***********
  *******
"""

PHASE3 = """
   *****
 *****  **
*******   *
*******   *
******   **
  *******
"""

def eclipse(n):
    phases = [PHASE0, PHASE1, PHASE2, PHASE3]
    return phases[n & 3]

def main():
    for i in range(0, 5):
        print("n={}".format(i))
        print(eclipse(i))

main()

