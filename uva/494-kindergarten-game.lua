#!/usr/bin/env lua

--[[

Everybody sit down in a circle. Ok. Listen to me carefully.
“Woooooo, you scwewy wabbit!”
Now, could someone tell me how many words I just said?

Input

Input to your program will consist of a series of lines, each line containing multiple words (at least one).
A “word” is defined as a consecutive sequence of letters (upper and/or lower case).

Output

Your program should output a word count for each line of input. Each word count should be printed
on a separate line.

Sample Input

Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...

Sample Output

2
7
10
9

--]]

function isletter(c)
	return ('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z')
end

function count(s)
	local r = 0
	local f = 0
	for i=1,#s do
		local c = s:sub(i, i)
		if f == 0 and isletter(c) then
			r = r + 1
			f = 1
		elseif not isletter(c) then
			f = 0
		end
	end

	return r
end

assert(count("Meep Meep!") == 2)
assert(count("I tot I taw a putty tat.") == 7)
assert(count("I did! I did! I did taw a putty tat.") == 10)
assert(count("Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...") == 9)
