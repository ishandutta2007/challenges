#!/usr/bin/perl

=begin comment

The goal is to write a program that returns number of 1 bits in a given number.
Examples

5      ->  2
1254   ->  6
56465  ->  8

Winner

The winning submission is the code which runs in the minimum time. You can assume that normal int value in your language can handle any number (no matter how large) and computes all the valid operators defined for integer in O(1).

If two pieces of code run in the same time the winner is the one implemented in fewer bytes.

Please provide some explanation how your code is computing the result.

=end comment
=cut

use strict;
use warnings;

sub assert($) {
    die "Assertion failed: $_[1]\n" unless $_[0];
}

sub ones {
	my $n = $_[0];
	my $c = 0;
	while ($n) {
		$n = $n & ($n - 1);
		$c += 1;
	}
	return $c;
}

assert(ones(5) == 2);
assert(ones(1254) == 6);
assert(ones(56465) == 8);
