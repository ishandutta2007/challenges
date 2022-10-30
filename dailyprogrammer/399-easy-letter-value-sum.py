#!/usr/bin/env python

"""

Challenge

Assign every lowercase letter a value, from 1 for a to 26 for z. Given a string of lowercase letters, find the sum of the values of the letters in the string.

lettersum("") => 0
lettersum("a") => 1
lettersum("z") => 26
lettersum("cab") => 6
lettersum("excellent") => 100
lettersum("microspectrophotometries") => 317

Optional bonus challenges

Use the enable1 word list for the optional bonus challenges.

    microspectrophotometries is the only word with a letter sum of 317. Find the only word with a letter sum of 319.

    How many words have an odd letter sum?

    There are 1921 words with a letter sum of 100, making it the second most common letter sum. What letter sum is most common, and how many words have it?

    zyzzyva and biodegradabilities have the same letter sum as each other (151), and their lengths differ by 11 letters. Find the other pair of words with the same letter sum whose lengths differ by 11 letters.

    cytotoxicity and unreservedness have the same letter sum as each other (188), and they have no letters in common. Find a pair of words that have no letters in common, and that have the same letter sum, which is larger than 188. (There are two such pairs, and one word appears in both pairs.)

    The list of word { geographically, eavesdropper, woodworker, oxymorons } contains 4 words. Each word in the list has both a different number of letters, and a different letter sum. The list is sorted both in descending order of word length, and ascending order of letter sum. What's the longest such list you can find?

(This challenge is a repost of Challenge #52 [easy], originally posted by u/rya11111 in May 2012.)

It's been fun getting a little activity going in here these last 13 weeks. However, this will be my last post to this subreddit for the time being. Here's hoping another moderator will post some challenges soon!

"""

def lettersum(s):
    r = 0
    for c in s:
        v = ord(c)
        if 'a' <= c and c <= 'z':
            v = ord(c) - ord('a') + 1
        elif 'A' <= c and c <= 'Z':
            v = ord(c) - ord('A') + 1
        r += v
    return r

def main():
    assert(lettersum("") == 0)
    assert(lettersum("a") == 1)
    assert(lettersum("z") == 26)
    assert(lettersum("cab") == 6)
    assert(lettersum("excellent") == 100)
    assert(lettersum("microspectrophotometries") == 317)
    assert(lettersum("biodegradabilities") == 151)

main()
