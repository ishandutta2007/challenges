/*

Create a function to check whether the given parameter is an Object or not.
Examples

isObject(function add(x,y) {return x + y;}) ➞ true

isObject(new Regex("^[a-zA-Z0-9]+$)","g")) ➞ true

isObject(null) ➞ false

isObject("") ➞ false

Notes

Inputs may be null, primitive wrapper types, dates.

*/

var assert = require('assert');

function isobject(obj) {
	return obj instanceof Object;
}

function main() {
	assert(isobject(function add(x,y) {return x + y;}) == true);
	assert(isobject(new RegExp("^[a-zA-Z0-9]+$","g")) == true);
	assert(isobject(null) == false);
	assert(isobject("") == false);
	assert(isobject(new Date()) == true);
	assert(isobject("12/12/2011") == false);
	assert(isobject([1,2,3]) == true);
	assert(isobject({}) == true);
}

main();
