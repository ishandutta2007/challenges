#!/usr/bin/env perl

=begin comment

You are given two integers A,B. You have to choose an integer X in the range [minimum(A,B), maximum(A,B)] such that:

⌈B−X/2⌉+⌈X−A/2⌉ is maximum.

What is the maximum sum you can obtain if you choose X optimally?

Note: ⌈x⌉ : Returns the smallest integer that is greater than or equal to x (i.e rounds up to the nearest integer). For example, ⌈1.4⌉=2, ⌈5⌉=5, ⌈−1.5⌉=−1, ⌈−3⌉=−3 , ⌈0⌉=0.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, two integers A,B.

Output Format

For each testcase, output the maximum sum of ⌈B−X2⌉+⌈X−A2⌉.

Constraints
1≤T≤10^5
1≤A,B≤10^9

=end comment
=cut

use strict;

sub assert($) {
	die "Assertion failed: $_[1]\n" unless $_[0];
}

sub maximum_sum {
	use integer;
	
	my $a = shift;
	my $b = shift;
	if ($a == $b) {
		return 0;
	}
	if ($b > $a or ($a - $b) % 2 == 0) {
		return ($b - $a) / 2 + 1;
	}
	return ($b - $a) / 2;
}

assert(maximum_sum(2, 2) == 0);
assert(maximum_sum(1, 11) == 6);
assert(maximum_sum(13, 6) == -3);
