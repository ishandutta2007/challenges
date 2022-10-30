#!/usr/bin/env/python

"""
You have a non-empty set s, and you have to execute N commands given in N lines.

The commands will be pop, remove and discard.
"""

from functools import reduce

def run(lines, wset):
    for line in lines.split('\n'):
        if line == "":
            continue
        toks = line.split(' ')
        try:
            if toks[0] == "pop":
                wset.pop()
            elif toks[0] == "remove" and len(toks) > 1:
                wset.remove(int(toks[1]))
            elif toks[0] == "discard":
                wset.discard(int(toks[1]))
        except:
            pass

    print(reduce(lambda x, y: x+y, wset))

lines = """
pop
remove 9
discard 9
discard 8
remove 7
pop
discard 6
remove 5
pop
discard 5
"""
wset = set([1, 2, 3, 4, 5, 6, 7, 8, 9])
run(lines, wset)
