#!/usr/bin/env julia

#=

Write a program that outputs the highest number that is lower or equal than the square root of the given number, with the given number of decimal fraction digits.

Use this technique, (do not use your language's built in square root function): https://medium.com/i-math/how-to-find-square-roots-by-hand-f3f7cadf94bb

input format: 2 numbers: precision-digits Number

sample input

0 7720.17
1 7720.17
2 7720.17

sample output

87
87.8
87.86

challenge inputs

0 12345
8 123456
1 12345678901234567890123456789

=#

using Printf

@printf("%.0f\n", sqrt(7720.17))
@printf("%.1f\n", sqrt(7720.17))
@printf("%.2f\n", sqrt(7720.17))

@printf("%.0f\n", sqrt(12345))
@printf("%.8f\n", sqrt(123456))
@printf("%.1f\n", sqrt(BigFloat(12345678901234567890123456789)))
