#!/usr/bin/env python

"""

Your program must print out this exact sequence:

1
2
4
10
24
54
116
242
496
1006
2028
4074
8168
16358
32740
65506
131040
262110
NOPE!
As usual, shortest program wins. Standard code golf rules apply.

"""

def seq(n):
    tab = [1, 2, 4, 10, 24, 54, 116, 242, 496, 1006, 2028, 4074, 8168, 16358, 32740, 65506, 131040, 262110]
    if n < 0 or n >= len(tab):
        return "NOPE!"
    return tab[n]

def main():
    i = 0
    while True:
        v = seq(i)
        print(v)
        
        if v == "NOPE!":
            break
        i += 1

main()
