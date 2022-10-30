#!/usr/bin/env julia

#=

We do seem to have a fastest square root challenge, but it's very restrictive. In this challenge, your program (or function) will be given an arbitrarily sized nonnegative integer, which is the square of an integer.

Input

You may take input in any normally allowed way, including (but not limited to) an arbitrary sized integer type, string in any base, or list of numbers representing digits.

Output

The allowed output methods are similar to the input ones, they just need to be in a way which can also represent a number of arbitrary size.

Requirements

Your program should theoretically work correctly given any number (which is the square of an integer), assuming the language is capable of this
All submissions should be in either:
A language with an online interpreter that can give (or be trivially modified to give) accurate times, and doesn't time out with your solution
A language with an interpreter/compiler available from the apt package manager, and is less than 1 GiB, in which case it will be run on my Chromebook's Linux VM
If it doesn't take under 20 minutes, I'll just give a good estimate based on the first test cases and time complexity
Built in square root functions are allowed (but boring :p)
Scoring

Your program's score will be the amount of time it takes to find the square root of:

All 4096 perfect squares up to (not including) 224
A random (but same for all programs) 2048 perfect squares up to 248
A random (but same for all programs) 1024 perfect squares up to 2144
A random (but same for all programs) 512 perfect squares up to 21440
A random (but same for all programs) 256 perfect squares up to 25760
A random (but same for all programs) 128 perfect squares up to 214400
A random (but same for all programs) 64 perfect squares up to 286400
UPDATE: The numbers have been made bigger. This is a total of 8128 numbers as inputs, specifically these. Remember that fitting the test cases specifically is a standard loophole. The only part that counts toward the time is the math. I/O and setup can be ignored.

=#

x = BigInt(0)
y = BigInt(2e300)
for i in x:y
	println(sqrt(i*i))
end
