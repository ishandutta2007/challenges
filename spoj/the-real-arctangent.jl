#!/usr/bin/env julia

#=

Compute 101 significant figures of the arctangent of a real number.

Input
The first line of the input contains the number of test cases. In each of the following lines, a single real number 0 ≤ x ≤ 10 is given, in the usual decimal notation. The number of decimal digits of x is not more than 101.

Output
Each line of the output should be the sequence consisting of the first 101 significant decimal digits of the arctangent of x. All trailing and leading zeroes, as well as the decimal point (if any) should be removed.

Example
Input:
3
0
1
2.718281828459045235360287

Output:
0
78539816339744830961566084581987572104929234984377645524373614807695410157155224965700870633552926699
12182829050172776217604617127291832691014807688333489455796019635447595534415986839011077205055833227

=#

setprecision(BigFloat, 10000)
println(atan(BigFloat(0)))
println(atan(BigFloat(1)))
println(atan(BigFloat(2.718281828459045235360287)))
