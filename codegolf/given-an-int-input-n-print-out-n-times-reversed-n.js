/*

Given an integer n, print out n * reversed(n)

reversed(n) is the number you get when you reverse the digits of n.

reverse(512) = 215

reverse(1) = 1

reverse(101) = 101

>>>>>>>>
func(5) = 5*5 = 25

func(12) = 12*21 = 252

func(11) = 11*11 = 121

func(659) = 659*956 = 630004
Shortest code wins!

*/

var assert = require('assert');

function reverse(n) {
	var s = 1;
	if (n < 0) {
		n = Math.abs(n);
		s = -1;
	}

	var r = 0;
	while (n > 0) {
		r = (r * 10) + (n % 10);
		n = Math.floor(n / 10);
	}
	return r * s;
}

function mul(n) {
	return n * reverse(n);
}

function main() {
	assert(mul(5) == 25);
	assert(mul(12) == 252);
	assert(mul(11) == 121);
	assert(mul(659) == 630004);
}

main();
