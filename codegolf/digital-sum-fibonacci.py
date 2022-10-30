#!/usr/bin/env python

"""

We are all familiar with the Fibonacci sequence:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765
However, instead of, f(n) = f(n-1) + f(n-2) we'll be taking digital sum of the previous 2 entries.

The sequence should still start with 0, 1, after that the differences are rapidly apparent. This list is 0-indexed, you may use 1-indexed as well, state which you used.

f(0)  = 0
f(1)  = 1
f(2)  = 1   # 0 + 1
f(3)  = 2   # 1 + 1
f(4)  = 3   # 1 + 2
f(5)  = 5   # 2 + 3
f(6)  = 8   # 3 + 5
f(7)  = 13  # 8 + 5
f(8)  = 12  # 8 + 1 + 3
f(9)  = 7   # 1 + 3 + 1 + 2
f(10) = 10  # 1 + 2 + 7
f(11) = 8   # 7 + 1 + 0
f(12) = 9   # 1 + 0 + 8
f(13) = 17  # 8 + 9
f(14) = 17  # 9 + 1 + 7
f(15) = 16  # 1 + 7 + 1 + 7
f(16) = 15  # 1 + 7 + 1 + 6
f(17) = 13  # 1 + 6 + 1 + 5
f(18) = 10  # 1 + 5 + 1 + 3
f(19) = 5   # 1 + 3 + 1 + 0
f(20) = 6   # 1 + 0 + 5
f(21) = 11  # 5 + 6
f(22) = 8   # 6 + 1 + 1
f(23) = 10  # 1 + 1 + 8
f(24) = 9   # 8 + 1 + 0
f(25) = 10  # 1 + 0 + 9
f(26) = 10  # 9 + 1 + 0
f(27) = 2   # 1 + 0 + 1 + 0
(After this point it repeats at the 3rd term, 0-indexed)
Note: I didn't notice the repetition until I posted the challenge itself, and here I was thinking it'd be impossible to write another novel Fibonacci challenge.

Your task is, given a number n, output the nth digit of this sequence.

First 3 digits: [0,1,1],

24-digit repeated pattern: [2,3,5,8,13,12,7,10,8,9,17,17,16,15,13,10,5,6,11,8,10,9,10,10]

Hint: You may be able to exploit this repetition to your advantage.

This is code-golf, lowest byte-count is the winner.

BONUS: If you use the repetition in your answer, I will award the lowest byte-count answer that takes advantage of the repetition in the sequence a bounty of 100 points.
This should be submitted as part of your original answer, after your original answer. See this post as an example of what I am talking about: https://codegolf.stackexchange.com/a/108972/59376

To qualify for this bonus your code must run in constant time (O(1)) with an explanation.

"""

class DF:
    def __init__(self):
        self.a = 0
        self.b = 1

    def next(self):
        r = self.a
        c = self.digitsum(self.a) + self.digitsum(self.b)
        self.a = self.b
        self.b = c
        return r

    @staticmethod
    def digitsum(n):
        r = 0
        while n > 0:
            r += n % 10
            n = n // 10
        return r

def main():
    tab = [0, 1, 1, 2, 3, 5, 8, 13, 12, 7, 10, 8, 9, 17, 17, 16, 15, 13, 10, 5, 6, 11, 8, 10, 9, 10, 10, 2]
    df = DF()
    for v in tab:
        assert(df.next() == v)

main()
