#!/usr/bin/env julia

#=

You are to approximate the value of:

Integral[0, I] exp(x)/x^x dx

Where your input is I.

Rules
You may not use any built-in integral functions.
You may not use any built-in infinite summation functions.
Your code must execute in a reasonable amount of time ( < 20 seconds on my machine)
You may assume that input is greater than 0 but less than your language's upper limit.
It may be any form of standard return/output.
You can verify your results at Wolfram | Alpha (you can verify by concatenating your intended input to the linked query).

Examples
(let's call the function f)

f(1) -> 2.18273
f(50) -> 6.39981
f(10000) -> 6.39981
f(2.71828) -> 5.58040
f(3.14159) -> 5.92228
Your answer should be accurate to ±.0001.

=#

using QuadGK

function integral(I)
	f(x) = exp(x) / x^x
	return quadgk(f, 0, BigFloat(I))[1]
end

println(integral(1))
println(integral(50))
println(integral(10000))
println(integral(2.71828))
println(integral(3.14159))

