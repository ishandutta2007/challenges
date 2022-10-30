#!/usr/bin/env julia

#=

Challenge
Given an integer Q in the range −2100≤Q≤2100, output the number of digits in that number (in base 10).

Rules
Yes, you may take the number as a string and find its length.

All mathematical functions are allowed.

You may take input in any base, but the output must be the length of the number in base 10.

Do not count the minus sign for negative numbers. The number will never have a decimal point.

Zero can either have one or zero digits.

Assume the input will always be a valid integer.

Examples
Input > Output

-45 > 2
12548026 > 8
33107638153846291829 > 20
-20000 > 5
0 > 1 or 0

Winning
Shortest code in bytes wins.

=#

using Printf

function count(x)
	return length(@sprintf("%d", abs(x)))
end

@assert(count(-45) == 2)
@assert(count(12548026) == 8)
@assert(count(33107638153846291829) == 20)
@assert(count(-20000) == 5)
@assert(count(0) == 1)
