#!/usr/bin/env ruby

def sum(n)
	(0..n).reduce(0) { |r, n| r + n*n+1 }
end

0.upto(100) do |i|
	print i, ": ", sum(i), "\n"
end
