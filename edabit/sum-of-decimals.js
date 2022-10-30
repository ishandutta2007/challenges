/*

Captain Obvious is asked to implement a simple function that given two decimal numbers A and B returns their sum.

"Easy one!" he thinks, but soon he discovers that his function fails over the fifty percent of given test cases!
He suspects the test cases are wrong, but his calculator is saying they're correct! What's happening?

Can you help Captain Obvious to debug his function and solve the exercise?

Examples

floatSum(0.3, 0.7) ➞ 1

floatSum(0.35, 0.75) ➞ 1.1

floatSum(1.234, 5.6789) ➞ 6.9129

Notes

    Given numbers can be either integer or float with 1 up to 6 decimals.
    Don't round results!
    Bonus: Can you resolve it using a simple math expression instead of a built-in method?

*/

var assert = require('assert');

function floatsum(a, b, p) {
	return (a+b).toFixed(6);
}

function main() {
	assert.equal(floatsum(0.1, 0.2), 0.3);
	assert.equal(floatsum(0.2, 0.3), 0.5);
	assert.equal(floatsum(8.4, 8.8), 17.2);
	assert.equal(floatsum(5.7, 4.3), 10);
	assert.equal(floatsum(5, 0.81), 5.81);
	assert.equal(floatsum(0.81, 99), 99.81);
	assert.equal(floatsum(99.1, 0.109), 99.209);
	assert.equal(floatsum(50.1234, 11.5678), 61.6912);
	assert.equal(floatsum(3.4444, 3.5555), 6.9999);
	assert.equal(floatsum(2.12022, 1.110001), 3.230221);
}

main();
