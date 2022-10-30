#!/usr/bin/env julia

#=

our task is simple: output the letter x a random number of times. Every possible length of xs must have a non-zero probability of being output.

Of course, there must be some lengths whose probabilities tend to 0, in order for the total probabilities to sum to 1, but all must still be theoretically possible.

You may choose whether to include the empty string as a possible output
You may have any consistent separator between the xs, and you may output the separator more than once. The separator may not contain the unary character
You may use any other consistent single character instead of x
Per standard rules, your program must always halt in finite time. (Terminating "with probability 1" is allowed, though)
You can assume your language's random number generator is perfectly random. If it is supposedly continuous, you may assume it has infinite precision.
This is code-golf, so the shortest code wins.

=#

function xs(limit)
	n = rand(1:limit)
	for i in 0:n
		m = rand(1:limit)
		s = repeat("x", m)
		println(s)
	end
end

xs(100)
