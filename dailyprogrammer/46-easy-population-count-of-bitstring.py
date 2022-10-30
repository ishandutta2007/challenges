#!/usr/bin/python

"""

The population count of a bitstring is the number of set bits (1-bits) in the string.
For instance, the population count of the number 23, which is represented in binary as 10111 is 4.

Your task is to write a function that determines the population count of a number representing a bitstring

"""

def popcnt(x):
    return bin(x).count("1")

def main():
    assert(popcnt(23) == 4)
    assert(popcnt(0xffffffff) == 32)

main()
