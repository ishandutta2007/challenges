#!/usr/bin/env python

"""

A TicTacToe game can be represented by a string denoting the sequence of positions as the players make their move.

0 1 2
3 4 5
6 7 8
Assume X always plays first.

So a string of "012345678" denotes the game

X O X
O X O
X O X
Notice, the game is already won when Player X marks 6, at that point the game ends, granting a win to X. (ie, ignore the remaining moves once a player wins)

Your challenge (code) is to print all the games (sorted order) and its results.

The Format

<movesequence>:<result>\n
eg:

012345678:X
012345687:X
012345768:X
...
Denote X for the 1st player winning, O for the second player, and D for Draws.

There will be 9! (362880) games.

Here is some data to verify your results.

'X' Wins: 212256
'O' Wins: 104544
Draws : 46080
This is a codegolf, and runtime should be within a minute. Have Fun!

EDIT: Removed excess details, and just print it on stdout. No need to create a file.

"""

from itertools import *

def won(b, p):
    d1, d2 = 0, 0
    for i in range(3):
        if b[i][i] == p:
            d1 += 1
        if b[i][2-i] == p:
            d2 += 1

        r, c = 0, 0
        for j in range(3):
            if b[i][j] == p:
                r += 1
            if b[j][i] == p:
                c += 1
        if r == 3 or c == 3:
            return True
    return d1 == 3 or d2 == 3

def outcome(s):
    b = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    for n in range(len(s)):
        i = s[n] // 3
        j = s[n] % 3
        if n%2 == 0:
            b[i][j] = 'X'
        else:
            b[i][j] = 'O'
        
        if won(b, 'X'):
            return 'X'
        elif won(b, 'O'):
            return 'O'
    return 'D'

def main():
    x, o, d = 0, 0, 0
    m = [0, 1, 2, 3, 4, 5, 6, 7, 8]
    p = permutations(m)
    for s in list(p):
        a = ''.join(str(i) for i in s)
        r = outcome(s)
        print(a, r)
        
        if r == 'X':
            x += 1
        elif r == 'O':
            o += 1
        else:
            d += 1
    
    print("'X' Wins:", x)
    print("'O' Wins:", o)
    print("Draws:", d)

main()
