#!/usr/bin/env python

"""

Groups are a widely used structure in Mathematics, and have applications in Computer Science.
This code challenge is about the fewest # of characters to create a group table for the additive group Zn.

How the table is constructed: For Zn, the elements are {0, 1, 2, ..., n-1}.
The table will have n rows and n columns. For the ij-th entry of the table, the value is i+j mod n.
For example, in Z3, the 1-2nd entry (2nd row, 3rd column if you count the starting row/column as 1) is (1+2)%3 = 0 (see sample output).

Input: a positive integer, n

Output: a table that is a textual presentation of Zn, constructed as described above, and displayed as shown below in the sample outputs. Spaces are optional

Sample input: 3

Sample output:

0 1 2
1 2 0
2 0 1

Sample input: 5

Sample output:

0 1 2 3 4
1 2 3 4 0
2 3 4 0 1
3 4 0 1 2
4 0 1 2 3

"""

def table(n):
    for i in range(n):
        for j in range(n):
            print("{} ".format((i + j) % n), end='')
        print()
    print()

table(3)
table(5)
