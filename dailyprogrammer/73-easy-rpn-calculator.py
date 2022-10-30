#!/usr/bin/env python

"""

During the 70s and 80s, some handheld calculators used a very different notation for arithmetic called Reverse Polish notation (RPN).
Instead of putting operators (+, *, -, etc.) between their operands (as in 3 + 4), they were placed behind them: to calculate 3 + 4, you first inputted the operands (3 4) and then added them together by pressing +.

Internally, this was implemented using a stack: whenever you enter a number, it's pushed onto the stack, and whenever you enter an operator, the top two elements are popped off for the calculation. Here's an example of a RPN calculator calculating 3 4 * 6 2 - +:

[3] --> 3
[4] --> 3 4
[*] --> 12      ( 3 * 4 = 12)
[6] --> 12 6
[2] --> 12 6 2
[-] --> 12 4    ( 6 - 2 =  4)
[+] --> 16      (12 + 4 = 16)

Your task is to implement a program that reads a string in Reverse Polish notation and prints the result of the calculation.
Your program should support positive and negative integers and the operators +, -, *. (For extra credit, you can implement extra functions, such as decimal numbers, division, exponentiation, etc.)

"""

def skipws(s, i):
    while i < len(s) and s[i].isspace():
        i += 1
    return i

def number(s, i):
    j = i + 1
    while j < len(s) and s[j].isdigit():
        j += 1
    return (int(s[i:j]), j)

def binop(op, p):
    n = len(p)
    if op == '+':
        p[n-2] = p[n-2] + p[n-1]
    elif op == '-':
        p[n-2] = p[n-2] - p[n-1]
    elif op == '*':
        p[n-2] = p[n-2] * p[n-1]
    elif op == '/':
        p[n-2] = p[n-2] / p[n-1]
    elif op == '^':
        p[n-2] = p[n-2] ** p[n-1]
    return p[:n-1]

def rpn(s):
    p = []
    i = 0
    while True:
        i = skipws(s, i)
        if i >= len(s):
            break

        if s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/' or s[i] == '^':
            p = binop(s[i], p)
            i += 1
        elif s[i].isdigit():
            (v, i) = number(s, i)
            p.append(v)
        else:
            raise Exception("invalid character in expression")
    if len(p) != 1:
        raise Exception("invalid expression")
    return p[0]

def main():
    assert(rpn("3 4 * 6 2 - +") == 16)
    assert(rpn("2 4 ^") == 16)

main()
