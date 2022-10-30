/*

Groups and ranges indicate groups and ranges of expression characters. Negated character sets match any characters that are NOT inside of brackets [ ]. You differentiate a negated character set from a regular character set by inserting a ^ inside of the [ ].

"1234cba5678".match(/[^abc]/g)
// "12345678", matches any character that are not a, b, or c.

You can also negate ranges, but like with regular character sets, if the hyphen is at the beginning or ending of a range then it will be considered a literal hyphen.

"excludenumbers123".match(/[^1-3]/g)
// "excludenumbers", matches any character that are not the numbers 1, 2 or 3.

Create a REGEXP that matches any characters except letters, digits and spaces. You must use a negated character set in your expression.

 "alice15@gmail.com".match(/REGEXP/gi) ➞ ["@", "."]

Notes

Check the Resources tab if you get stuck.

*/

var assert = require('assert');

function match(address) {
	const REGEXP = "([^\\w\\d\\s])";
	return Array.from(address.matchAll(REGEXP), m => m[0]);
}

function main() {
	assert(JSON.stringify(match("alice15@gmail.com")) == JSON.stringify(['@', '.']))
}

main();
