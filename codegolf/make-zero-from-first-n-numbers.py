#!/usr/bin/env python

"""

Challenge
The challenge is to write a code that takes a positive integer 'n' as an input and displays all the possible ways in which the numbers from 1 - n can be written, with either positive or negative sign in between, such that their sum is equal to zero. Please remember that you may only use addition or subtraction.

For example, if the input is 3, then there are 2 ways to make the sum 0:

 1+2-3=0
-1-2+3=0
Note that, the numbers are in order, starting from 1 till n (which is 3 in this case). As it is evident from the example, the sign of the first number can also be negative, so be careful.

Now, 3 was pretty much simple. Let us list all the ways when we consider the number 7.

 1+2-3+4-5-6+7=0
 1+2-3-4+5+6-7=0
 1-2+3+4-5+6-7=0
 1-2-3-4-5+6+7=0
-1+2+3+4+5-6-7=0
-1+2-3-4+5-6+7=0
-1-2+3+4-5-6+7=0
-1-2+3-4+5+6-7=0
So here, we have got a total of 8 possible ways.

Input And Output
As stated before, the input would be a positive integer. Your output should contain all the possible ways in which the numbers give a sum of zero. In case there is no possible way to do the same, you can output anything you like.

Also, you can print the output in any format you like. But, it should be understandable. For example, you may print it as in the above example. Or, you may just print the signs of the numbers in order. Otherwise, you can also print '0's and '1's in order, where '0' would display negative sign and '1' would display positive sign (or vice versa).

For example, you can represent 1+2-3=0 using:

1+2-3=0
1+2-3
[1,2,-3]
++-
110
001
However, I would recommend using any of the first three formats for simplicity. You can assume all the inputs to be valid.

Examples
7 ->

 1+2-3+4-5-6+7=0
 1+2-3-4+5+6-7=0
 1-2+3+4-5+6-7=0
 1-2-3-4-5+6+7=0
-1+2+3+4+5-6-7=0
-1+2-3-4+5-6+7=0
-1-2+3+4-5-6+7=0
-1-2+3-4+5+6-7=0

4 ->

 1-2-3+4=0
-1+2+3-4=0

2 -> -

8 ->

 1+2+3+4-5-6-7+8=0
 1+2+3-4+5-6+7-8=0
 1+2-3+4+5+6-7-8=0
 1+2-3-4-5-6+7+8=0
 1-2+3-4-5+6-7+8=0
 1-2-3+4+5-6-7+8=0
 1-2-3+4-5+6+7-8=0
-1+2+3-4+5-6-7+8=0
-1+2+3-4-5+6+7-8=0
-1+2-3+4+5-6+7-8=0
-1-2+3+4+5+6-7-8=0
-1-2+3-4-5-6+7+8=0
-1-2-3+4-5+6-7+8=0
-1-2-3-4+5+6+7-8=0

"""

def gen(n):
    for i in range(0, 1<<n):
        s = ""
        for j in range(0, n):
            if i&(1<<j) != 0:
                if j == 0:
                    s += " "
                else:
                    s += "+"
            else:
                s += "-"
            s += str(j + 1)
        if eval(s) == 0:
            print(s + "=0")
    print()

def main():
    gen(2)
    gen(3)
    gen(7)
    gen(8)
    gen(11)

main()
