#!/usr/bin/env python

"""

As all of us who have read "Harry Potter and the Chamber of Secrets" knows, the reason He-Who-Must-Not-Be-Named chose his creepy moniker is that "I Am Lord Voldemort" is an anagram for his birthname, "Tom Marvolo Riddle".

I've never been good at these kinds of word-games (like anagrams), I always find it hard to figure out that stuff manually.
I find it much more enjoyable to write computer programs to solve these problems for me. In the spirit of that, today's problem is to find simple one-word anagrams for other words.

Write a program that given a word will find all one-word anagrams for that word. So, for instance, if you put in "LEPROUS", it should return "PELORUS" and "SPORULE".
As a dictionary, use this file, which is a 1.8 mb text-file with one word listed on each line, each word listed in upper-case.
In this problem description, I've used upper-case for all words and their anagrams, but that is entirely optional, it's perfectly all right to use upper-case if you want to.

Using your program, find all the one-word anagrams for "TRIANGLE".

(by the way, in case anyone is curious: a "PELORUS" is "a sighting device on a ship for taking the relative bearings of a distant object", which I imagine basically is a telescope bolted onto a compass, and a "SPORULE" is "a small spore")

Bonus: if you looked up the anagrams for "PAGERS", you'd find that there was actually quite a few of them: "GAPERS", "GASPER", "GRAPES", "PARGES" and "SPARGE". Those five words plus "PAGERS" make a six-word "anagram family".

Here's another example of an anagram family, this time with five words: "AMBLERS", "BLAMERS", "LAMBERS", "MARBLES" and "RAMBLES".

What is the largest anagram family in the dictionary I supplied? What is the second largest?

"""

def wordkey(w):
    return ''.join(sorted(w))

def makedict(name):
    m = {}
    f = open(name)
    for w in f:
        w = w.strip('\n')
        w = w.upper()
        k = wordkey(w)
        if k not in m:
            m[k] = [w]
        else:
            m[k].append(w)
    
    for k in m:
        sorted(m[k])

    f.close()
    return m

def anagrams(m, w):
    w = w.upper()
    print("{} -> {}".format(w, m.get(wordkey(w))))

def longest2(m):
    l1, l2 = 0, 0
    k1, k2 = "", ""
    for k in m:
        l = len(m[k])
        if l1 < l:
            l2, k2 = l1, k1
            l1, k1 = l, k
        elif l2 < l:
            l2, k2 = l, k

    return ((l1, m.get(k1)), (l2, m.get(k2)))

def main():
    m = makedict("enable1.txt")

    anagrams(m, "TRIANGLE")
    anagrams(m, "LEPROUS")
    anagrams(m, "PAGERS")
    anagrams(m, "AMBLERS")

    print(longest2(m))

main()
