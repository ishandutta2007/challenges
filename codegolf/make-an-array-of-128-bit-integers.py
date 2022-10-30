#!/usr/bin/env python

"""

Given an input value n, construct an array of n

random 128 bit (unsigned) integers. The integers should be uniformly random.

Your code can use any in built random number generation function it has or you can implement your own. Clearly this challenge is harder (and more fun) in lower level languages.

"""

import random

def gen(n):
    return [random.randint(0, 2**128) for i in range(n)]

def main():
    print(gen(10))

main()
