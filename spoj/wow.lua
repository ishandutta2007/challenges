#!/usr/bin/env lua

--[[

Input
Given a positive integer 0 < x < 50.

Output
Print one word: Wo...ow (letter o must be repeated x times).

Example 1
Input:
1

Output:
Wow

Example 2
Input:
7

Output:
Wooooooow

--]]

function wow(x)
	s = 'W'
	for i=1,x do
		s = s.."o"
	end
	s = s..'w'
	return s
end

assert(wow(1) == "Wow")
assert(wow(7) == "Wooooooow")
