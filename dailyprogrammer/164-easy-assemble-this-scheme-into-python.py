#!/usr/bin/env python

"""

Description
You have just been hired by the company 'Super-Corp 5000' and they require you to be up to speed on a new programming language you haven't yet tried.

It is your task to familiarise yourself with this language following this criteria:

The language must be one you've shown interest for in the past

You must not have had past experience with the language

In order to Impress HR and convince the manager to hire you, you must complete 5 small tasks. You will definitely be hired if you complete the bonus task.

Input & Output
These 5 tasks are:

Output 'Hello World' to the console.

Return an array of the first 100 numbers that are divisible by 3 and 5.

Create a program that verifies if a word is an anagram of another word.

Create a program that removes a specificed letter from a word.

Sum all the elements of an array

All output will be the expected output of these processes which can be verified in your normal programming language.

Bonus
Implement a bubble-sort.

Note
Don't use a language you've had contact with before, otherwise this will be very easy. The idea is to learn a new language that you've been curious about.

"""

from collections import Counter

def hello_world():
    print("Hello World")

def div_3_5():
    r = []
    i = 0
    while len(r) < 100:
        if i%3 == 0 and i%5 == 0:
            r.append(i)
        i += 1
    return r

def anagram(a, b):
    return Counter(a) == Counter(b)

def remove_char(s, c):
    return s.replace(c, '')

def main():
    hello_world()
    print(div_3_5())
    print(anagram("listen", "silent"))
    print(remove_char("hello", "l"))
    print(sum([1, 2, 3, 4, 5]))

main()
