/*

As a crude form of hashing function, Lars wants to sum the digits of a number.
Then he wants to sum the digits of the result, and repeat until he have only one digit left.
He learnt that this is called the digital root of a number, but the Wikipedia article is just confusing him.

Can you help him implement this problem in your favourite programming language?

It is possible to treat the number as a string and work with each character at a time. This is pretty slow on big numbers, though, so Lars wants you to at least try solving it with only integer calculations (the modulo operator may prove to be useful!).

Author: TinyLebowski

Formal Inputs & Outputs
Input Description
A positive integer, possibly 0.

Output Description
An integer between 0 and 9, the digital root of the input number.

Sample Inputs & Outputs
Sample Input
31337

Sample Output
8, because 3+1+3+3+7=17 and 1+7=8

Challenge Input
1073741824

Challenge Input Solution
?

Note
None

*/

var assert = require('assert');

// https://en.wikipedia.org/wiki/Digital_root
// https://oeis.org/A010888
function digitalroot(n) {
	var b = 10;
	if (n == 0) {
		return 0;
	}
	return 1 + ((n - 1) % (b - 1));
}

function digitalrootbf(n) {
	while (n >= 10) {
		var r = 0;
		var x = n;
		while (x > 0) {
			r += x % 10;
			x = Math.floor(x / 10);
		}
		n = r;
	}
	return n;
}

function main() {
	assert(digitalroot(31337) == 8);
	assert(digitalroot(1073741824) == 1);
	for (var i = 0; i < 10000000; i++) {
		assert(digitalroot(i) == digitalrootbf(i));
	}
}

main();
