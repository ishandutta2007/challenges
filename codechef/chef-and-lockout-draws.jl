#!/usr/bin/env julia

#=

Bob and Alice are having a lockout match between them. There are three problems in the contest worth A, B, and C points respectively.
Only the first player to solve a problem gets points for that problem. It is impossible for Bob and Alice to solve a problem at the same time.
Chef wants to know if there is any chance of a draw if Bob and Alice manage to solve all 3 problems. A draw occurs when both players end with equal number of points.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, three space separated integers A, B, and C.

Output Format

For each testcase, output YES if the match can end in a draw, and NO otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤1000
1≤A,B,C≤10^6

=#

function drawable(a, b, c)
	p = sort([a, b, c])
	return p[1] + p[2] == p[3]
end

@assert(drawable(2, 5, 2) == false)
@assert(drawable(4, 2, 2) == true)
@assert(drawable(3, 5, 5) == false)

