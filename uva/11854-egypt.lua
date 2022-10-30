#!/usr/bin/env lua

--[[

A long time ago, the Egyptians figured out that a triangle with sides of length 3, 4, and 5 had a right angle as its largest angle.
You must determine if other triangles have a similar property.

Input

Input represents several test cases, followed by a line containing ‘0 0 0’. Each test case has three positive integers, less than 30,000, denoting the lengths of the sides of a triangle.

Output
For each test case, a line containing ‘right’ if the triangle is a right triangle, and a line containing ‘wrong’ if the triangle is not a right triangle.

Sample Input
6 8 10
25 52 60
5 12 13
0 0 0

Sample Output
right
wrong
right

--]]

function right(a, b, c)
	if a > b then
		a, b = b, a
	end
	
	if a > c then
		a, c = c, a
	end
	
	if b > c then
		b, c = c, b
	end
	
	return a > 0 and a*a + b*b == c*c
end

assert(right(6, 8, 10) == true)
assert(right(25, 52, 60) == false)
assert(right(5, 12, 13) == true)
