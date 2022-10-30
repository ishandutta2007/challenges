#!/usr/bin/env julia

#=

Pi times e (or Pie if you like ambiguous notation) to 100 decimal places is:

8.5397342226735670654635508695465744950348885357651149618796011301792286111573308075725638697104739439...
(OIES A019609) (argument for possible irrationality)

Your task is to write a program that takes in a positive integer N, and outputs Pi*e truncated to N decimal places. e.g. if N = 2, then the output should be 8.53.

This is an optimization problem, so the submission that can give the correct output for the highest value of N will win.

To ensure all submissions are judged using the same computing power, your code must be run on ideone, using any language they support.
According to the ideone faq, there is a 5 second run time limit for not logged in users.
This 5 second limit is the one you must use, not the 15 second limit for logged in users. (See faq for other limits like memory, code size, etc.)

Specifically, anyone not logged into ideone should be able to run your program on ideone for all values of N from 1 to some maximum Nmax, and see correct output nearly all of the time. without any Time limit exceeded or Memory limit exceeded, etc. errors.
The submission with the largest Nmax wins.

(Whether the actual time taken is a smidge over 5 seconds doesn't matter as long as ideone doesn't give errors. "Nearly all of the time" is defined as more than 95% of the time for any particular N.)

Details
You may use any mathematical method you like to calculate Pi*e, but you may not hardcode the output beyond the first dozen digits of Pi, e or Pi*e.
Your program should be able to work for any N, given unlimited resources.
You may use built in Pi or e constants if your language happens to have them.
You may not access websites or resources external to your code (if ideone even allows this).
Beyond hardcoding and accessing external resources, anything that ideone allows is almost certainly fine.
Your input and output must (obviously) work with whatever ideone provides for i/o (stdin/stdout only it seems). It's fine if you need quotes around the input N or the output is something like ans = ..., etc.
Please include a link to an ideone snippet of your code with your Nmax as input.
If there happens to be a tie (only likely if multiple submissions hit the 64kB output character limit) the highest votes answer wins.

=#

function pie(n)
	setprecision(BigFloat, n*10)
	r = BigFloat(ℯ) * BigFloat(π)
	return first(string(r), n+2)
end

println(pie(100))
println(pie(1000))
