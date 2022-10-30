#!/usr/bin/env julia

#=

Chef has his lunch only between 1 pm and 4 pm (both inclusive).

Given that the current time is X pm, find out whether it is lunchtime for Chef.

Input Format

The first line of input will contain a single integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, containing one integer X.

Output Format

For each test case, print in a single line YES if it is lunchtime for Chef. Otherwise, print NO.

You may print each character of the string in either uppercase or lowercase (for example, the strings YeS, yEs, yes and YES will all be treated as identical).

Constraints
1≤T≤12
1≤X≤12

=#

function lunchtime(x)
	return 1 <= x && x <= 4
end

@assert(lunchtime(1) == true)
@assert(lunchtime(7) == false)
@assert(lunchtime(3) == true)
