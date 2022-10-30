#!/usr/bin/env lua

--[[

You are given a sorted sequence of n integers S = s1, s2, ..., sn and a sorted sequence of m integers Q = q1, q2, ..., qm. Please, print in the ascending order all such si that belongs to Q.

Input data specification
In the first line you are given one integer 2<=n<=100, and in the following line n integers:
-100 <= si <= 100, si <= si+1.

In the third line you are given one integer 2<=m<=100, and in the following line m integers:
-100 <= qi <= 100, qi <= qi+1.

Output data specification
The sequence of requested integers separated by spaces.

Example

Input:
5
-2 -1 0 1 4
6
-3 -2 -1 1 2 3

Output:
-2 -1 1

--]]

function equal(a, b)
	for i, v in pairs(a) do
		if v ~= b[i] then
			return false
		end
	end
	return true
end

function intersect(s, q)
	m = {}
	r = {}
	for _, v in ipairs(q) do
		if m[v] == nil then
			m[v] = 1
		else
			m[v] = m[v] + 1
		end
	end

	for _, v in ipairs(s) do
		if m[v] == nil then
			goto continue
		end

		for i=1,m[v] do
			r[#r + 1] = v
			m[v] = m[v] - 1
		end

		::continue::
	end

	return r
end

assert(equal(intersect({-2, -1, 0, 1, 4}, {-3, -2, -1, 1, 2, 3}), {-2, -1, 1}))
assert(equal(intersect({-2, -2, 3}, {-2, -2, 4}), {-2, -2}))
assert(equal(intersect({1, 1, 1, 2, 2, 2, 3, 3, 3}, {1, 1, 1, 2, 2, 2, 3, 3, 3}), {1, 1, 1, 2, 2, 2, 3, 3, 3}))
