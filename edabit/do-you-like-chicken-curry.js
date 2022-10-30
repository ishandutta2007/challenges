/*

Create a function that takes three collections of arguments and returns the sum of the product of numbers.
Examples

product(1,2)(1,1)(2,3) ➞ 8
// 1 * 1 * 2 + 2 * 1 * 3

product(10,2)(5,0)(2,3) ➞ 100
// 10 * 5 * 2 + 2 * 0 * 3

product(1,2)(2,3)(3,4) ➞ 30
// 1 * 2 * 3 + 2 * 3 * 4

product(1,2)(0,3)(3,0) ➞ 0
// 1 * 0 * 3 + 2 * 3 * 0

Notes

All test input is valid.

*/

var assert = require('assert');

function product(a, b) {
	return function(c, d) {
		return function(e, f) {
			return a*c*e + b*d*f; 
		}
	}
}

function main() {
	assert(product(1, 2)(1, 1)(2, 3) == 8);
	assert(product(10, 2)(5, 0)(2, 3) == 100);
	assert(product(1, 2)(2, 3)(3, 4) == 30);
	assert(product(1, 2)(0, 3)(3, 0) == 0);
}

main();
