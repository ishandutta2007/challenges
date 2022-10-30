#!/usr/bin/env lua

--[[

Bob has X rupees and goes to a market. The cost of apples is Rs. A per kg and the cost of oranges is Rs. B per kg.

Determine whether he can buy at least 1 kg each of apples and oranges.

Input Format

The first line of input will contain an integer X, the amount of money Bob has.
The second line of input contains two space-separated integers A and B, the cost per kg of apples and oranges respectively.

Output Format

Print a single line containing Yes if Bob can buy the fruits and No otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings yes, Yes, yEs, and YES will all be treated as identical).

Constraints
1≤X,A,B≤10^5

--]]

function buyable(x, a, b)
	return x >= a + b
end

assert(buyable(14, 2, 2) == true)
assert(buyable(1, 1, 1) == false)
assert(buyable(5, 3, 2) == true)
assert(buyable(10000, 5000, 6000) == false)
