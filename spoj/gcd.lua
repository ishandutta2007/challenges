#!/usr/bin/env lua

--[[

In this problem you need to find the G.C.D of some numbers.

Since G.C.D between two numbers is too mainstream you need to find the G.C.D of all the given numbers.

Input
In the first line, there will be an integer, N (1 ≤ N ≤ 105).

In the next line there will be N integers. All the given integers will be less than 105.

Output
You have to print the G.C.D of all the given numbers.

Example

Input:
5
2 4 6 8 2
Output:
2

--]]

function gcd(a, b)
	while (b ~= 0) do
		a, b = b, a % b
	end
end

function gcdv(a)
	if #a < 1 then
		return 0
	end

	r = a[1]
	for _, v in ipairs(a) do
		v = gcd(r, v)
	end
	
	return r
end

assert(gcdv({2, 4, 6, 8, 2}) == 2)
