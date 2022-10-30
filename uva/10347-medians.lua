#!/usr/bin/env lua

--[[

Given the length of three medians of a triangle you will have to find out the area of the triangle.
Unless you are weak in geometry you should know that median of a triangle is formed by connecting any vertex of a triangle and the mid-point of its opposite edge.
So a triangle has three medians.

Input

The input file contains 1000 lines of input. Each line contains three numbers which denote the length of the medians of a triangle.
All the values in the input will be less than 100. Input is terminated by end of file.

Output
For each line of input you should produce one line of output. This line should contain the area of the triangle for the corresponding input.
If it is not possible to form a triangle with the given medians, the area of the triangle should be set as ‘-1.
The areas should be rounded up to three digits after the decimal point.
Consider that a triangle must have a STRICTLY positive area.

Sample Input

3 3 3
3 3 3

Sample Output

5.196
5.196

--]]

function area(a, b, c)
	local d = (a + b + c) / 2
	local s = d*(d-a)*(d-b)*(d-c)
	if s <= 0 then
		return -1
	end
	return 4.0/3.0 * math.sqrt(s)
end

print(area(3, 3, 3))
