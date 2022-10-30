#!/usr/bin/env julia

#=

Challenge
Given two integers A and B as input, you must write a program which outputs if A>B, A==B or A<B.

The integers will be in any reasonable range supported by your language which includes at least 256 values.

Your program can be either a full program or a function, taking input via STDIN or function arguments.

Outputs

If A>B output
A is greater than B

If A==B output
A is equal to B

If A<B output
A is less than B

Where you replace A and B for their integer values.

=#

using Printf

function compare(a, b)
	if a > b
		return @sprintf("%d is greater than %d", a, b)
	elseif a == b
		return @sprintf("%d is equal to %d", a, b)
	else
		return @sprintf("%d is less than %d", a, b)
	end
end

@assert(compare(1, -1) == "1 is greater than -1")
@assert(compare(1, 1) == "1 is equal to 1")
@assert(compare(-1, 1) == "-1 is less than 1")
