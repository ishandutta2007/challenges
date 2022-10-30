--[[

The following text was taken from a book of mathematics:
“The antidifference of a function f(x) is the function g(x) such that f(x) = g(x + 1) − g(x).
So, if we have a summation of f(x), it can be simplified by the use of its antidifference in the following way:
f(k) + f(k + 1) + f(k + 2) + . . . + f(k + n) = = g(k + 1) − g(k) + g(k + 2) − g(k + 1) + g(k + 3) − g(k + 2)+ . . . + g(k + n + 1) − g(k + n) = = g(k + n + 1) − g(k)
A factorial polynomial is expressed as k{n} meaning the following expression: k ∗ (k − 1) ∗ (k − 2) ∗ . . . ∗ (k − (n − 1))
The antidifference of a factorial polynomial k{n} is k {n+1}/(n + 1).”
So, if you want to calculate Sn = p(1) +p(2) +p(3) +. . .+p(n), where p(i) is a polynomial of degree k, we can express p(i) as a sum of various factorial polynomials and then, find out the antidifference P(i).
So, we have Sn = P(n + 1) − P(1).

Example:

S = 2∗3+ 3∗5+ 4∗7+ 5∗9+ 6∗11+. . .+ (n+ 1)∗(2n+ 1) = p(1)+p(2)+p(3)+p(4)+p(5)+...+p(n), where p(i) = (i + 1)(2i + 1).

Expressing p(i) as a factorial polynomial, we have:
p(i) = 2i
{2} + 5i + 1.
and then
P(i) = (2/3)i
{3} + (5/2)i
{2} + i.

Calculating P(n + 1) − P(1) we have
S = (n/6) ∗ (4n^2 + 15n + 17)

Given a number 1 ≤ x ≤ 50, 000, one per line of input, calculate the following summation:
1 + 8 + 27 + ... + x^3

Input
Input file contains several lines of input. Each line contain a single number which denotes the value of x.
Input is terminated by end of file.

Output
For each line of input produce one line of output which is the desired summation value.

--]]

function summation(x)
	return x*x*(x+1)*(x+1)//4
end

assert(summation(1) == 1)
assert(summation(2) == 9)
assert(summation(3) == 36)
