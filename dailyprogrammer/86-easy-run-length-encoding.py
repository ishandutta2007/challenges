#!/usr/bin/env python

"""

Run-Length encoding is a simple form of compression that detects 'runs' of repeated instances of a symbol in a string and compresses them to a list of pairs of 'symbol' 'length'. For example, the string

"Heeeeelllllooooo nurse!"
Could be compressed using run-length encoding to the list of pairs [(1,'H'),(5,'e'),(5,'l'),(5,'o'),(1,'n'),(1,'u'),(1,'r'),(1,'s'),(1,'e')]

Which seems to not be compressed, but if you represent it as an array of 18bytes (each pair is 2 bytes), then we save 5 bytes of space compressing this string.

Write a function that takes in a string and returns a run-length-encoding of that string. (either as a list of pairs or as a 2-byte-per pair array)

BONUS: Write a decompression function that takes in the RLE representation and returns the original string

"""

def rleenc(s):
    l = []
    p = chr(0)
    for c in s:
        if c == p:
            n += 1
        else:
            if p.isalpha():
                l.append((n + 1, p))
            n = 0
        p = c

    if n != 0 or (n == 0 and p.isalpha()):
        l.append((n + 1, p))

    return l

def main():
    print(rleenc("Heeeeelllllooooo nurse!"))
    print(rleenc("!@$"))
    print(rleenc("!@$xx"))
    print(rleenc("abbccddd"))
    print(rleenc("aaaa"))
    print(rleenc("bc"))
    print(rleenc("b"))

main()
