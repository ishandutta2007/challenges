#!/usr/bin/env julia

#=

Chef has two positive integers X and Y. Now Chef wants to perform some number of operations (possibly zero) on them.
In each operation, Chef can choose either X or Y and increment it by 1.
Find the minimum number of operations Chef needs to perform so that there is a positive integer strictly greater than 1 which divides both X and Y
(In other words, the greatest common divisor of X and Y should be greater than 1).

Input Format

The first line contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two integers X and Y.

Output Format

For each test case, print a single line containing one integer — the minimum number of operations Chef needs to perform.

Constraints
1≤T≤10^5
1≤X,Y≤10^9

=#

function operations(x, y)
	if gcd(x, y) > 1
		return 0
	elseif gcd(x+1, y) > 1 || gcd(x, y+1) > 1
		return 1
	else
		return 2
	end
end

@assert(operations(4, 16) == 0)
@assert(operations(4, 55) == 1)
