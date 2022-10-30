#!/usr/bin/env julia

#=

Write a program to factorize a semi-prime number in the shortest amount of time.

For testing purposes, use this: 38!+1 (523022617466601111760007224100074291200000001)

It is equal to: 14029308060317546154181×37280713718589679646221

=#

using Primes

println(factor(factorial(big(38)) + 1))
