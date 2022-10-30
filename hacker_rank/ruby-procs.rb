#!/usr/bin/env ruby

=begin
Passing blocks is one way to pass functions as arguments to other functions.

Blocks are one of the very few exceptions to the "everything is an object" rule in Ruby. Blocks are not objects, and they can't be saved to variables.

Proc objects are blocks of code that can be bound to a set of local variables. You can think of a proc object as a "saved" block.

Procs are a great way of keeping your code DRY. DRY stands for Do not Repeat Yourself.

The square_of_sum method computes the sum of the elements in an input array and returns the square of the summed elements. 
=end

def square_of_sum(array, proc_square, proc_sum)
	proc_square.call(proc_sum.call(array))
end

sum = proc { |a| a.reduce(0) { |r, n| r+n } }
square = proc { |x| x*x }
p square_of_sum([1, 2, 3], square, sum)
p square_of_sum([10, 20, 45], square, sum)
