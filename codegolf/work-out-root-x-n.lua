#!/usr/bin/env lua

--[[

Given integers 0<x<10^10^6 and 0<n<10^6, work out x(1/n) under 15 seconds(TIO or your computer), 1GB memory. You can assume the result is integer smaller than 50000.

Shortest code in bytes in each language win.

Sample:

x     n     result
121   2     11
123   1     123
1024  10    2

--]]

function root(x, n)
	return x^(1/n)
end

assert(root(121, 2) == 11)
assert(root(123, 1) == 123)
assert(root(1024, 10) == 2)
