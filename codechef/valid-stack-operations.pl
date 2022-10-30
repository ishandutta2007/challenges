#!/usr/bin/perl -w

=begin comment

You have a stack which is initially empty. You receive instructions of the form 1 or 0.
1 denotes that you have to push in an element, and 0 denotes that you have to pop out an element.
But of course you can pop something out only if it exists in the stack.
So your job is to look at the instructions and see if they are valid (ie. you never have to pop from an empty stack), or not.

Input

The first line of the input contains a single integers T, which denotes the number of testcases.
The first line of each testcase contains a single integer n, which denotes the number of instructions.
The second line contains n space separated integers, which are all 0 or 1.

Output

For each testcase output either "Valid" or "Invalid", in a new line.

Constraints

1≤T≤10
1≤n≤10^5
All instructions are either 0 or 1.

=end comment
=cut

use strict;
use warnings;

sub assert($) {
	die "Assertion failed: $_[1]\n" unless $_[0];
}

sub validate {
	my $c = 0;
	foreach (@_) {
		if ($_ == 1) {
			$c++;
		} elsif ($_ == 0 && $c > 0) {
			$c--;
		} else {
			return "Invalid";
		}
	}
	return "Valid";
}

assert(validate((1, 1, 0, 0, 1)) eq "Valid");
assert(validate((1, 0, 0, 1, 1)) eq "Invalid");
