#!/usr/bin/env lua

--[[

Using two characters: . (dot) and * (asterisk) print a chessboard-like pattern. The first character printed should be * (asterisk).

Input
You are given t < 100 - the number of test cases and for each of the test cases two positive integers: l - the number of lines and c - the number of columns in the pattern (l, c < 100).

Output
For each of the test cases output the requested pattern (please have a look at the example). Use one line break in between successive patterns.

Example
Input:
3
3 1
4 4
2 5

Output:
*
.
*

*.*.
.*.*
*.*.
.*.*

*.*.*
.*.*.

--]]

function chessboard(l, c)
	chars = {'*', '.'}
	for i=1,l do
		for j=1,c do
			k = (i + j) & 1;
			io.write(chars[k + 1]);
		end
		print()
	end
	print()
end

chessboard(3, 1)
chessboard(4, 4)
chessboard(2, 5)
