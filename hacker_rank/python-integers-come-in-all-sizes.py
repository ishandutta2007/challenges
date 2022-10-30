#!/usr/bin/python

"""
Integers in Python can be as big as the bytes in your machine's memory. There is no limit in size as there is: (c++ int) or (C++ long long int).

As we know, the result of a^b grows really fast with increasing b.

Let's do some calculations on very large integers.

Read four numbers a, b, c, d and print result of a^b + c^d
"""

a, b, c, d = 9, 29, 7, 27
print(a**b + c**d)
