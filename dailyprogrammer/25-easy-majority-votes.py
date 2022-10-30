#!/usr/bin/env python

"""

In an election, the person with the majority of the votes is the winner. Sometimes due to similar number of votes, there are no winners.

Your challenge is to write a program that determines the winner of a vote, or shows that there are no winners due to a lack of majority.

"""

def majority(v):
    for e in set(v):
        if v.count(e) > len(v)//2:
            return e
    return None

def main():
    assert(majority([1, 1, 1, 1, 2, 3, 5]) == 1)
    assert(majority([1, 2, 3]) == None)
    assert(majority([1, 2, 3, 3]) == None)
    assert(majority([1, 2, 3, 3, 3]) == 3)
    assert(majority([1, 2, 3, 3, 5]) == None)
    assert(majority([4, 7, 4, 4, 3, 4, 6, 4]) == 4)
    assert(majority([4, 7, 0, 5, 3, 4, 6, 4]) == None)

main()
