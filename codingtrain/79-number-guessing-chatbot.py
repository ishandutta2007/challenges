#!/usr/bin/env python

from random import randrange

def chat(l):
    n = randrange(l)
    while True:
        print("Guess a number between 0 and {}: ".format(l), end='')
        s = input()
        try:
            v = int(s)
        except:
            print("Invalid input, try again!")
            continue

        if v < n:
            print("Pick a higher number")
        elif v > n:
            print("Pick a lower number")
        else:
            print("You got it!")
            break

def main():
    chat(100)

main()
