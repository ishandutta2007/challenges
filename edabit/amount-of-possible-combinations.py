#!/usr/bin/env python

"""
Write a function that returns the amount of possible combinations when drawing the given amount of cards from a deck of cards.

The function must take two inputs: k is the amount of cards to draw. n the total amount of cards in the deck.

For example, a poker hand can be described as a 5-combination (k = 5) of cards from a 52 card deck (n = 52). The 5 cards of the hand are all distinct, and the order of cards in the hand does not matter. There are 2,598,960 such combinations.

The amount of combinations should be returned as an integer.

Notes

    Try solving this natively without any imports.
    Remember to return result as integer.
"""

def fact(n):
    if n < 0:
        return 0
    if n <= 1:
        return 1

    v = 1
    for i in range(2, n+1):
        v *= i

    return v

def combinations(k, n):
    return fact(n) / (fact(k)*fact(n-k))

def main():
    assert(combinations(6, 52) == 20358520)
    assert(combinations(5, 52) == 2598960)
    assert(combinations(10, 52) == 15820024220)
    assert(combinations(18, 52) == 42671977361650)
    assert(combinations(52, 52) == 1)
    assert(combinations(7, 64) == 621216192)

main()
