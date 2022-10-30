#!/usr/bin/env python

"""

In this challenge you will be given an array containing equations, with each equation written as a string. Here's an example:

["1+1=2", "2+2=3", "5*5=10", "3/3=1"]

If you do the math, you'll see that the equations "1+1=2" and "3/3=1" are actually true while "2+2=3" and "5*5=10" are false nonsense.

Write a function which, given an array of equations as above, returns only the true equations. For instance, for the example above the output should be:

["1+1=2", "3/3=1"]

Examples

trueEquations(["2*2=4"]) ➞ ["2*2=4"]

trueEquations(["1+1=3", "3-1=1"]) ➞ []

trueEquations(["1+1=2", "2+2=3", "5*5=10", "3/3=1"]) ➞ ["1+1=2", "3/3=1"]

Notes

    If all equations are false, return the empty array [], as in the second example.
    The equations will only involve the elementary operations: +, -, *, /

"""

def true_equations(a):
    r = []
    for s in a:
        t = s.replace("=", "==") 
        if eval(t):
            r.append(s)
    return r

def main():
    assert(true_equations(["2*2=4"]) == ["2*2=4"])
    assert(true_equations(["1+1=3", "3-1=1"]) == [])
    assert(true_equations(["1+1=2", "2+2=3", "5*5=10", "3/3=1"]) == ["1+1=2", "3/3=1"])
    assert(true_equations(["4/2=2", "8-4=2", "5*5=25", "3/3=14"]) == ["4/2=2", "5*5=25"])
    assert(true_equations(["1-1=0", "2/2=1", "13+9=22", "1*9=9"]) == ["1-1=0", "2/2=1", "13+9=22", "1*9=9"])
    assert(true_equations(["1/41=3", "2+19=14", "13*9=22", "1-9=9"]) == [])
    assert(true_equations(["82/41=2", "21-17=3", "3+99=2", "9*9=81", "7*6=42", "101+10=111", "2*3=5","143/11=13"]) == ["82/41=2", "9*9=81", "7*6=42", "101+10=111", "143/11=13"])

main()
