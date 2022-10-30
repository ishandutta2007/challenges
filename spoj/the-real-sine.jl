#!/usr/bin/env julia

#=

Compute 101 significant figures of the sine of a real number.

Input
The first line of the input contains the number of test cases. In each of the following lines, a single real number 0 ≤ x < π is given, in the usual decimal notation. The number of decimal digits of x is not more than 101.

Output
Each line of the output should be the sequence consisting of the first 101 significant decimal digits of the sine of x. All trailing and leading zeroes, as well as the decimal point (if any) should be removed.

Score
For each test case, let K be the first position of the digit where the first difference to the reference solution occured.
Then the score awarded to the test case will be K–1 divided by the number of digits M ≤ 101 in the reference solution.
If all digits match, K = M+1 is understood. For example, let us say a particular output has the first 50 digits of sin(1) correct, and the 51-st digit is different from that of the reference solution.
Then this particular test case would receive the score of 50/101 ≈ 0.5 (50%). The final score of the problem is the sum of the scores over all test cases, normalized so that the maximum possible score is 10.

Example
Input:
2
0
1.5707963267948966

Output:
0
99999999999999999999999999999999981507813299633318447401631655066443910339246693874482714867916134939

=#

setprecision(BigFloat, 10000)
println(sin(BigFloat(0)))
println(sin(BigFloat(1.5707963267948966)))
