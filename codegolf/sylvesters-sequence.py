#!/usr/bin/env python

"""

Sylvester's sequence, OEIS A000058, is an integer sequence defined as follows:

Each member is the product of all previous members plus one. The first member of the sequence is 2.

Task
Create a program to calculate the nth term of Sylvester's Sequence. Standard input, output and loopholes apply.

Standard sequence rules apply.

This is code-golf, so the goal is to minimize the size of your source code as measured in bytes.

Test Cases
You may use either zero or one indexing. (Here I use zero indexing)

>>0
2
>>1
3
>>2
7
>>3
43
>>4
1807

"""

# http://oeis.org/A000058
def sylvester(n):
    a = 2
    for i in range(n):
        a = a*a - a + 1
    return a

def main():
    tab = [2, 3, 7, 43, 1807, 3263443, 10650056950807, 113423713055421844361000443, 12864938683278671740537145998360961546653259485195807]
    for i in range(len(tab)):
        assert(sylvester(i) == tab[i])

main()
