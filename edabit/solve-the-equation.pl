use strict;

assert(equation("1+1"), 2);
assert(equation("7*4-2"), 26);
assert(equation("1+1+1+1+1"), 5);

sub equation {
	return eval($_[0]);
}

sub assert {
	if ($_[0] != $_[1]) {
		print("assertion failed: $_[0] != $_[1]\n");
		exit 1;
	}
}
