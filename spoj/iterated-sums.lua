#!/usr/bin/env lua

--[[

Please compute the sum of squares for the given numbers: a, a+1, ..., b-1, b.

Input
Two numbers: a and b separated by space, where 1 <= a <= b <=100.

Output
Computed sum: a*a + (a+1)*(a+1) + ... + (b-1)*(b-1) + b*b

Example
Input:
1 4

Output:
30

Example 2
Input:
5 6

Output:
61

--]]

function sos(a, b)
	r = 0
	for i=a,b do
		r = r + i*i
	end
	return r
end

assert(sos(1, 4) == 30)
assert(sos(5, 6) == 61)
