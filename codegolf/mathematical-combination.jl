#!/usr/bin/env julia

#=

Write a program that takes an input such as:

n,k
which then computes:

(nk)=n!k!(n−k)!

and then prints the result.

A numerical example:

Input:

5,2
Internal computation:

5!3!×2!

Printed Output:

10
I'd like to see an answer that beats my python solution of 65 characters, but all languages are obviously welcome.

Here's my solution:

n,k=input();f=lambda x:+(x<2)or x*f(x-1);print f(n)/(f(k)*f(n-k))
Edit:

I admit that this question is from the codegolf website mathematical combination puzzle. I know that my answer may look like not much progress can be made on it, but the leaders of this puzzle have solved it in nearly half as many characters.

=#

@assert(binomial(5, 2) == 10)
@assert(binomial(40, 3) == 9880)
