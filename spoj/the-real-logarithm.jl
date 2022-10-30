#!/usr/bin/env julia

#=

Compute 101 significant figures of the logarithm of a positive real number.

Input
The first line of the input contains the number of test cases. In each of the following lines, a single real number 1 ≤ x ≤ 100 is given, in the usual decimal notation. The number of decimal digits of x is not more than 101.

Output
Each line of the output should be the sequence consisting of the first 101 significant decimal digits of the logarithm of x. All trailing and leading zeroes, as well as the decimal point (if any) should be removed.

=#

setprecision(BigFloat, 10000)
println(log(BigFloat(1)))
println(log(BigFloat(3.1415926535897932384626433832)))
