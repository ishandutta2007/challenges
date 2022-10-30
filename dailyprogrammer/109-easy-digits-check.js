/*

Description:

Write a function, where given a string, return true if it only contains the digits from 0 (zero) to 9 (nine). Else, return false.

Formal Inputs & Outputs:

Input Description:

string data - a given string that may or may not contains digits; will never be empty

Output Description:

Return True or False - true if the given string only contains digits, false otherwise

Sample Inputs & Outputs:

"123" should return true. "123.123" should return a false. "abc" should return a false.

Notes:

This is a trivial programming exercise, but a real challenge would be to optimize this function for your language and/or environment.
As a recommended reading, look into how fast string-searching works.

*/

var assert = require('assert');

function digits(str) {
	for (var i = 0; i < str.length; i++) {
		if (!('0' <= str[i] && str[i] <= '9')) {
			return false;
		}
	}
	return true;
}

function main() {
	assert(digits("abc123") == false);
	assert(digits("abc") == false);
	assert(digits("123") == true);
	assert(digits("123.123") == false);
}

main();
