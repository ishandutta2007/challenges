#!/usr/bin/env julia

#==

Background
We define the prime-counting function, π(x), as the number of prime numbers less than or equal to x. You can read about it here.

For example, π(2)=1 and π(6)=3.

It can be shown, using dark magic, that

lim[x→∞] π(x) / (x/log(x)) = 1

which means we can approximate π(x) by x/log(x).

Your task
Your purpose is to write a function/program that takes x as input and outputs the approximation of π(x) as given by the ratio of the input and the logarithm of the input, with exactly π(x) decimal places. Either rounding works fine.

Test cases
f(4) = 2.89
f(10) = 4.3429
f(19.3) = 6.52003877
f(60) = 14.6543602005583370
f(173) = 33.570776430488395580723956088340374417691
f(499) = 80.3205598921264941447922062868184315657020413225943243128931714242910058741601601524983152243502
f(1024) = 147.73197218702985291365628733459375487248854570526575965547001926974558404415335218027792618429504967649254587490842053177273361276604002741459580500208428403451262667619517

Scoring

This is code-golf so shortest solution wins... With a twist! If the code you wrote gives the right answer for results with up to p decimal places and your code has b bytes, then your score is

(e^(-p/64)+ 1/3) * b

which essentially means you get a better score if the precision is really high, as the factor multiplying by b decays rapidly as the precision increases until flattening at 13.

If you can't tell for sure the precision up to which your code works, you can take p to be the number of decimal places of the last test case your code can handle exactly.

For this challenge, the minimum score is 1/3, which would be attainable by a 1-byte long submission with arbitrary precision.

Admissible solution
To wrap up, your code is a valid solution if and only if it computes the approximation of π(x) as given by the formula and, when it gives the output, the output has exactly π(x) decimal places.
The p for the scoring will be how many decimal places you can get right.

Notice the distinction. The code linked outputs square root of 2 with 1000 decimal places BUT python only gets some of the decimal places right.

Standard loopholes are forbidden

==#

using Printf
using Primes

fmtsprint(fmt, args...) = @eval @sprintf($fmt, $(args...))

function primecount(x)
	p = primes(trunc(Int64, x))
	n = length(p)
	setprecision(BigFloat, 10*n)
	v = BigFloat(x) / log(BigFloat(x))
	f = @sprintf("%%.%df", n)
	r = fmtsprint(f, v)
	return r
end

println(primecount(4))
println(primecount(10))
println(primecount(19.3))
println(primecount(60))
println(primecount(173))
println(primecount(499))
println(primecount(1024))
