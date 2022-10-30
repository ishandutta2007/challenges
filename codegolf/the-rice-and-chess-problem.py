#!/usr/bin/env python

"""

An Indian legend tells the story of the alleged inventor of the chess game, who impressed the emperor of India with his game so much that he would get rewarded with anything asked.

The man said he wanted to be paid in rice. He wanted a grain of rice for the first square of the chessboard, two for the second, four for the third, eight for the fourth, and so on, until the 64th square.

The emperor was amazed that the man asked for such a small reward, but as his mathematicians started counting, he ended up losing one of his provinces.

Task
Given the length of the side of a hypothetical chessboard (which is 8 on a default chessboard) and the multiplier between squares (which is 2 in the legend), calculate the number of grains of rice the emperor must pay to the man.

Notes
The side length will always be a positive integer. The multiplier could instead be any kind of rational number.

If your language of choice can't display very large numbers, it's okay as long as your program can correctly process smaller inputs.

Also if your language of choice rounds larger values (with exponential notations), it's okay if those values are approximately correct.

Testcases
Input (side length, multiplier) => Output
8, 2                            => 18446744073709551615
3, 6                            => 2015539
7, 1.5                          => 850161998.2854
5, -3                           => 211822152361
256, 1                          => 65536
2, 2                            => 15
2, -2                           => -5
Please note that the explicit formula

result = (multiplier ^ (side ^ 2) - 1) / (multiplier - 1)
Performs wrong on multiplier = 1, as

1 ^ (side ^ 2) - 1 = 0
1 - 1 = 0
0 / 0 != side ^ 2 (as it should be)

"""

def rice(s, m):
    r = 0
    p = 1
    for i in range(0, s*s):
        r += p
        p *= m
    return r

def main():
    print(rice(8, 2))
    print(rice(3, 6))
    print(rice(7, 1.5))
    print(rice(5, -3))
    print(rice(256, 1))
    print(rice(2, 2))
    print(rice(2, -2))

main()
