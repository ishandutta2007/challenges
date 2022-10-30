#!/usr/bin/env python

"""

Chef and Divyam are playing a game. They start with a rational number X, such that 0<X<1.

In each turn, Chef chooses a positive real number Y. Then Divyam either adds or subtracts Y to X. So X is replaced with either X+Y or X−Y. If this number becomes 0 or 1, then Chef wins. Otherwise, the game continues.

You are given X, and you have to determine whether Chef can win in a finite number of moves. More formally, does there exist a finite number N so that Chef has a strategy that is guaranteed to win in at most N moves?

Here, X will be given in the form AB, where A and B are positive integers, A<B and gcd(A,B)=1.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers A and B.

Output

For each test case, print a single line containing the string "Yes" if Chef can win the game in a finite number of moves and "No" otherwise (without quotes). You can print "Yes" or "No" in any case.

Constraints

1≤T≤10^6
1≤A<B≤10^18
gcd(A,B)=1

"""

def winnable(a, b):
    return b&(b-1) == 0

def main():
    assert(winnable(1, 2) == True)
    assert(winnable(2, 3) == False)

main()
