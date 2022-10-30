#!/usr/bin/env python

"""

In research, it is tough to determine how good of a researcher you are. One way that people determine how good you are is by looking at your H-Index.

Each paper has a certain number of citations. Your H-Index is the largest number H such that you have H papers with at least H citations. Given the number of citations on each paper you have written, what is your H-Index?

Input

The first line of input contains a single integer n (1≤n≤100000), which is the number of papers you have written.
The next n lines describe the papers. Each of these lines contains a single integer c (0≤c≤1000000000), which is the number of citations that this paper has.

Output

Display your H-Index.

"""

def hindex(a):
    a.sort(reverse=True)
    
    r = 0
    i = 0
    for v in a:
        if v >= i + 1:
            r = i + 1
        else:
            break
        i += 1
    return r

def main():
    assert(hindex([7, 1, 2, 1, 5]) == 2)
    assert(hindex([7, 1, 3, 1, 5]) == 3)
    assert(hindex([4, 2, 3]) == 2)

main()
