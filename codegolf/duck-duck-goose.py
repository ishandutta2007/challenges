#!/usr/bin/env python

"""

Remember the kids game, 'Duck, Duck, Goose'? No? Me neither.

The challenge
Print the word 'duck' on individual lines an indeterminate amount of times.
Print the word 'goose'.
Your program ends.
The rules
Attempt to play the game in the fewest bytes.
There must be at least one duck.
There must be exactly one goose, at the end of the list.
There must be exactly one bird on each line. No empty lines.
The case of the outputted strings is irrelevant.
White-space within a line is fine.
Your program must finish.
Your program must not consistently produce the same number of ducks.
Have fun!

Please note: This question is not a duplicate of Shortest code to produce non-deterministic output

Reasons include:

The association to a childrens' game
The defined start and end requirements of the result string. There is no specified output in the other challenge.
Answers For the other, non-duplicate challenge are in a single-digit number of bytes. The average for this one is around 30, or there about.
By the amount of overlap between this challenge and that one, any code-golf question including the 'random' tag is a duplicate. Should we delete them all?
The code answers for this challenge would match the other challenge (in a ridiculously bloated way), but the answers to that challenge would not match this one.

"""

import random

def ddg(n):
    for i in range(random.randint(1, n)):
        print("duck")
    print("goose")

def main():
    ddg(1e6)

main()
