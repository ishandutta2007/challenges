#!/usr/bin/env julia

#=

Calculate
R := B^P mod M
for large values of B, P, and M using an efficient algorithm. (That’s right, this problem has a time dependency !!!.)

Input

The input will contain several test cases, each of them as described below.
Consecutive test cases are separated by a single blank line.
Three integer values (in the order B, P, M) will be read one number per line. B and P are integers in the range 0 to 2147483647 inclusive.
M is an integer in the range 1 to 46340 inclusive.

Output

For each test, the result of the computation. A single integer on a line by itself.

Sample Input

3
18132
17

17
1765
3

2374859
3029382
36123

Sample Output

13
2
13195

=#

function modexp(b, p, m)
	return (big(b) ^ big(p)) % big(m)
end

@assert(modexp(3, 18132, 17) == 13)
@assert(modexp(17, 1765, 3) == 2)
@assert(modexp(2374859, 3029382, 36123) == 13195)
