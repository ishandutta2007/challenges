#!/usr/bin/env python

"""

Graham's number G is defined in this way:

u(3,n,1) = 3^n
u(3,1,m) = 3
u(3,n,m) = u(3,u(3,n-1,m),m-1)
[Knuth's up-arrow notation]
[Conway chained arrow notation]

THEN

g1 = u(3,3,4)
g2 = u(3,3,g1)
g3 = u(3,3,g2)
...
G = u(3,3,g63)
You are given that u(3,3,2)=7625597484987 to check your code.

Your task is to write a program/function that will output the value of G deterministically, given enough integer size and enough time.

References
Graham's number
Knuth's up-arrow notation
Conway chained arrow notation

"""

def u(p, n, m):
    if m == 1:
        return p**n
    if n == 1:
        return p
    return u(p, u(p, n-1, m), m-1)

def graham():
    g = 4
    for i in range(63):
        g = u(3, 3, g)
    return g

def main():
    assert(u(3, 3, 2) == 7625597484987)

    try:
        print(graham())
    except:
        print("Graham's Number is TOO BIG")

main()
