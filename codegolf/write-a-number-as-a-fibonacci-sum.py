#!/usr/bin/env python

"""

Let us define the Fibonacci sequence as

F(1) = 1

F(2) = 2

F(n) = F(n - 2) + F(n - 1)
So we have the infinite sequence 1,2,3,5,8,13,... It is well known that any positive integer can be written as a sum of some Fibonacci numbers.
The only caveat is that this summation might not be unique. There is always at least one way to write a number as a sum of Fibonacci numbers but there may be many many more.

Your challenge is to write a complete program which using stdin takes in a positive integer between one and one million inclusive, and then outputs using stdout all possible summations of Fibonacci numbers which sum up to the input.
In a summation, the Fibonacci numbers must not repeat and that includes the number 1. In any summation, if 1 is present, it must be present only once because in my definition of the sequence above 1 appears only once.
Summations with only term are valid so if the input number is a Fibonacci number itself, then the number itself is a valid summation and must be printed. If multiple sums, then between any two sums there must be a blank line to easily distinguished between them.

Here are some samples.

./myfib 1
1
There is only one such sum and it has only term so that's all that is printed.

./myfib 2
2
Note here that 1+1 is not a valid sum because 1 repeats.

./myfib 3
1+2

3
Two sums and they are both printed with a blank line in between.

./myfib 10
2+8

2+3+5

./myfib 100
3+8+89

1+2+8+89

3+8+34+55

1+2+3+5+89

1+2+8+34+55

3+8+13+21+55

1+2+3+5+34+55

1+2+8+13+21+55

1+2+3+5+13+21+55

True code-golf. The shortest code in any language wins. Please post your code with some test cases (besides the one I gave above).
In the case of ties, I pick the one with the highest upvotes after waiting at least for two weeks and probably longer.
So the community please feel free to upvote any solutions you like. The cleverness/beauty of the code matters much more than who posts first.

Happy coding!

"""

from itertools import *

def fib(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a+b
    return a

def dump(l):
    n = len(l)
    for i in range(0, n):
        print(l[i], end='')
        if i+1 < n:
            print('+', end='')
    print()

def fibp(n):
    print("n={}".format(n))
    
    if n < 0:
        return

    if n <= 1:
        dump([n])
        print()
        return

    m = 2
    while fib(m-2) < n:
        m += 1

    p = list(range(2, m))
    for i in range(1, len(p)):
        for c in combinations(p, i):
            r = 0
            l = []
            for x in c:
                v = fib(x)
                l.append(v)
                r += v
                if r > n:
                    break
            if r == n:
                dump(l)

    print()

def main():
    fibp(0)
    fibp(1)
    fibp(2)
    fibp(3)
    fibp(10)
    fibp(100)
    fibp(10000)

main()
