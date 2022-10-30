#!/usr/bin/env julia

#=

Input: A positive integer n=p^q where p and q are prime.

Output: Output the result of q^p

Test cases (in, out):

4, 4
8, 9
25, 32
27, 27
49, 128
121, 2048
125, 243
343, 2187
1331, 177147
3125, 3125,
16807, 78125,
823543, 823543
161051, 48828125
19487171, 1977326743

=#

using Primes

function prime_switch(n)
	p = collect(factor(Vector, n))
	n = length(p)
	u = unique!(p)
	if length(u) != 1
		return -1
	end
	return n^u[1]
end

@assert(prime_switch(4) == 4)
@assert(prime_switch(8) == 9)
@assert(prime_switch(25) == 32)
@assert(prime_switch(27) == 27)
@assert(prime_switch(49) == 128)
@assert(prime_switch(121) == 2048)
@assert(prime_switch(125) == 243)
@assert(prime_switch(343) == 2187)
@assert(prime_switch(1331) == 177147)
@assert(prime_switch(3125) == 3125)
@assert(prime_switch(16807) == 78125)
@assert(prime_switch(823543) == 823543)
@assert(prime_switch(161051) == 48828125)
@assert(prime_switch(19487171) == 1977326743)
