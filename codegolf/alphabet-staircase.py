#!/usr/bin/env python

"""

The Challenge

Your task is to create a program or function that outputs the following with no input:

a
bb
ccc
dddd
eeeee
ffffff
ggggggg
hhhhhhhh
iiiiiiiii
jjjjjjjjjj
kkkkkkkkkkk
llllllllllll
mmmmmmmmmmmmm
nnnnnnnnnnnnnn
ooooooooooooooo
pppppppppppppppp
qqqqqqqqqqqqqqqqq
rrrrrrrrrrrrrrrrrr
sssssssssssssssssss
tttttttttttttttttttt
uuuuuuuuuuuuuuuuuuuuu
vvvvvvvvvvvvvvvvvvvvvv
wwwwwwwwwwwwwwwwwwwwwww
xxxxxxxxxxxxxxxxxxxxxxxx
yyyyyyyyyyyyyyyyyyyyyyyyy
zzzzzzzzzzzzzzzzzzzzzzzzzz

You may use the uppercase alphabet instead of lowercase if you prefer. Trailing/leading newlines or spaces are allowed.

Scoring

This is code-golf, so the shortest answer in each language wins.

"""

def staircase():
    for i in range(26):
        print(chr(97 + i) * (i + 1))

def main():
    staircase()

main()
