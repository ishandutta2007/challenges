#!/usr/bin/env python

"""

Introduction
You are probably familiar with the "puts on sunglasses" emoticon-meme:

(•_•)
( •_•)>⌐■-■
(⌐■_■)
In this challenge, your task is to take the first line as input, and output the last one, effectively putting sunglasses on that little button-eyed person. To make the task a bit more difficult, the characters have been scaled up and converted to (ugly) ASCII art.

Input
Your input is exactly this multi-line string, with an optional trailing newline:

   r                       t
  /                         \
 :                           :
 /    ,##.           ,##.    \
|     q##p           q##p     |
|      **             **      |
 \                           /
 :                           :
  \                         /
   L      ##########       j
Output
Your output is exactly this multi-line string, again with an optional trailing newline:

   r                                         t
  /                                           \
 :               ______             ______     :
 /              |######|           |######|    \
|     _______   |######|           |######|     |
|     #""""""   |######|           |######|     |
 \    #         |######|           |######|    /
 :    "          """"""             """"""     :
  \                                           /
   L                    ##########           j
Note that there are no trailing spaces in the input and output.

Rules and scoring
You can write a full program or a function. The lowest byte count wins, and standard loopholes are disallowed.

"""

tit = """
   r                       t
  /                         \\
 :                           :
 /    ,##.           ,##.    \\
|     q##p           q##p     |
|      **             **      |
 \                           /
 :                           :
  \                         /
   L      ##########       j
"""

tat = """

   r                                         t
  /                                           \\
 :               ______             ______     :
 /              |######|           |######|    \\
|     _______   |######|           |######|     |
|     #""""""   |######|           |######|     |
 \    #         |######|           |######|    /
 :    "          """"""             """"""     :
  \                                           /
   L                    ##########           j


"""

def sunglasses(text):
    assert(text == tit)
    return tat

def main():
    print(sunglasses(tit))

main()
