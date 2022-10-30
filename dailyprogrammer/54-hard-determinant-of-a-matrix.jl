#!/usr/bin/env julia

#=

For this challenge, make a program that finds the determinant of a square matrix.
You do not need to use any exceedingly complex methods, using expansion by cofactors is entirely sufficient (if you have no idea what that is, the always helpful Khan Academy here to help.
Wikipedia also has you covered.

What is the determinant of the following matrix?

 -5   0   1  -3   0  -4   2  -2   0   2
 -5  -1  -4   4  -2  -5   0  -4   3  -3
 -4   5   3   3   0   0  -2  -2   2   2
 -4  -1   5  -3  -3  -5  -2  -5   3  -1
  4   5   2  -5   2  -4   1  -1   0  -3
 -2  -4  -3  -1   4  -5  -4   2   1   4
  5   5   2  -5   1  -3  -2  -1  -5   5
  1   4  -2   4   3   2   1   0   3  -2
  3   0  -4  -3   0   1  -3   0   1   2
 -1  -4  -3  -1  -4   1   2  -5   2  -1

Note: the whole purpose of this challenge is to write the code for calculating the determinant yourself.
Therefore, you are not allowed to use library functions that are designed to calculate things like this.
The matrix should be represented by the native array construct of your language, not any special data type designed to operate on mathematical matrices.
That means no NumPy, no using fancy functions in Mathematica or Matlab! You are allowed to use these to test whether or not your function works, but that's it.

=#

using LinearAlgebra

println(det([-5 0 1 -3 0 -4 2 -2 0 2;
             -5 -1 -4 4 -2 -5 0 -4 3 -3;
             -4 5 3 3 0 0 -2 -2 2 2;
             -4 -1 5 -3 -3 -5 -2 -5 3 -1;
              4 5 2 -5 2 -4 1 -1 0 -3;
             -2 -4 -3 -1 4 -5 -4 2 1 4;
              5 5 2 -5 1 -3 -2 -1 -5 5;
              1 4 -2 4 3 2 1 0 3 -2;
              3 0 -4 -3 0 1 -3 0 1 2;
             -1 -4 -3 -1 -4 1 2 -5 2 -1]))

