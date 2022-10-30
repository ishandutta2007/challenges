#!/usr/bin/env python

# https://www.quora.com/How-would-you-explain-an-algorithm-that-generates-permutations-using-lexicographic-ordering
def lexicographic(a):
    while True:
        print(a)

        x, y, n = -1, -1, len(a)
        for i in range(0, n-1):
            if a[i] < a[i+1]:
                x = i

        if x < 0:
            break
        
        for i in range(0, n):
            if a[x] < a[i]:
                y = i
        
        a[x], a[y] = a[y], a[x]
        a[x+1:n] = reversed(a[x+1:n])

def main():
    lexicographic([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])

main()
