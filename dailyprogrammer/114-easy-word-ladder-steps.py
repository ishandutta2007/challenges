#!/usr/bin/env python

"""

A word ladder is a sequence of words made by changing one letter at a time. For example:

cold → cord → card → ward → warm
Given a word, list all the words that can appear next to it in a word ladder, using this list of 3,807 four-letter words. Sample input:

puma
Sample output:

duma
pima
puja
pula
pump
puna
pupa
How many words from the list can appear next to the word best in a word ladder?

Bonus 1: One word in the list has 33 other words that can appear next to it. What is this word?

Bonus 2: How many different words can be reached, starting from best, in 3 or fewer steps?

Thanks to Thomas1122 for suggesting this challenge on r/dailyprogrammer_ideas!

"""

def load(name):
    db = {}
    f = open(name)
    for l in f:
        l = l.rstrip()
        db[l] = True
    f.close()
    return db

def query(db, s):
    n = 0
    for i in range(len(s)):
        for c in range(0, 26):
            t = s[:i] + chr(ord('a') + c) + s[i+1:]
            if t != s and t in db:
                n += 1
                print(t)
    print("Found {} matches for word '{}'".format(n, s))
    print()

def main():
    db = load("114-easy-word-ladder-steps.txt")
    query(db, "cold")
    query(db, "puma")
    query(db, "best")

main()
