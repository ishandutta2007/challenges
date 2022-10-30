#!/usr/bin/env lua

--[[

Take a list of 2-digit hexadecimal numbers as input, and output the binary value, replacing each 1 with an 'X', and each 0 with a space.

For example

Input = FF, 81, 47, 99.

FF = 11111111 in binary, so print XXXXXXXX
81 = 10000001 in binary, so print X      X
47 = 01000111 in binary, so print  X   XXX
99 = 10011001 in binary, so print X  XX  X
Full output:

XXXXXXXX
X      X
 X   XXX
X  XX  X
Clarifications

The hexadecimal numbers will always be 2-digits.
There can be any number of hexadecimal numbers.
You can choose to input in whatever format you want (separated by a space, comma, newline, etc.)
The character to output for a 1 is X, and for 0 it is a  . This will not change.
Also, apparently I wasn't clear enough: the input is in Hexadecimal (Base 16) not denary (Base 10)

This is code-golf, so the shortest answer in bytes wins!

--]]

function hexart(b)
	for i=7,0,-1 do
		if b&(1<<i) ~= 0 then
			io.write('X')
		else
			io.write(' ')
		end
	end
	io.write('\n')
end

hexart(0xff)
hexart(0x81)
hexart(0x47)
hexart(0x99)
