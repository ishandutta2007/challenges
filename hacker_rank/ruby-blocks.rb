#!/usr/bin/env ruby

=begin
Higher order functions are one of the key components of functional programming.

A higher order function is a tool that takes other functions as parameters or returns them as a result.

Blocks are nameless methods that can be passed to another method as a parameter.
Passing a block to a method is a great way of data abstraction.

Blocks can either be defined with a keyword do ... end or curly braces { ... }.

Implement factorial using blocks
=end

def factorial
	yield
end

n = gets.to_i
factorial do
	puts (if n < 0 then 0 else (1..n).reduce(1) { |r, n| r * n } end)
end
