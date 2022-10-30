#!/usr/bin/env python

"""

Source: Math is Fun - Pascal's triangle

Your job is to prove this property in Lean theorem prover (Lean 3 + mathlib). Shortest code in bytes wins.

import data.nat.choose.basic
import data.nat.fib
import data.list.defs
import data.list.nat_antidiagonal

theorem X (n : ℕ) :
  ((list.nat.antidiagonal n).map (function.uncurry nat.choose)).sum
  = n.succ.fib :=
sorry -- replace this with actual proof
Since the statement itself depends on the current version of mathlib, it is encouraged to use Lean web editor (as opposed to TIO) to demonstrate that your answer is correct.

Some primer on the built-ins used:

nat or ℕ is the set/type of natural numbers including zero.
list.nat.antidiagonal n creates a list of all pairs that sum to n, namely [(0,n), (1,n-1), ..., (n,0)].
nat.choose n k or n.choose k is equal to nCk.
nat.fib n or n.fib is the Fibonacci sequence defined with the initial terms of f0=0,f1=1.
In mathematics notation, the equation to prove is

∀n∈N,∑i=[0,n] C(i, n-i) = fib(n+1)

Rules
Your code should provide a named theorem or lemma X having the exact type as shown above. Any kind of sidestepping is not allowed.

The score of your submission is the length of your entire source code in bytes (including the four imports given and any extra imports you need).

"""

import math

def pascal(n):
    r = 0
    for i in range(n+1):
        r += math.comb(i, n-i)
    return r

def fib(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a+b
    return a

def main():
    for i in range(0, 1000):
        assert(pascal(i) == fib(i+1))

main()
