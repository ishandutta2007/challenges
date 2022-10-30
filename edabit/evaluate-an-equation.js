/*

Create a function that evaluates an equation.
Examples

eq("1+2") ➞ 3

eq("6/(9-7)") ➞ 3

eq("3+2-4") ➞ 1

Notes

    Don't print, return a value.
    Return the value, not the equation.
    The method used to solve this challenge should not be used in practice. However, it's important to be aware of how this functionality works and why it should not be used. Check the Resources for more information.

*/

var assert = require('assert');

function eq(str) {
	return eval(str);
}

function main() {
	assert(eq("1+2") == 3);
	assert(eq("6/(9-7)") == 3);
	assert(eq("3+2-4") == 1);
	assert(eq("3*4+1") == 13);
	assert(eq("5*8-4*9") == 4);
	assert(eq("3**7") == 2187);
	assert(eq("(6**3)+3") == 219);
}

main();
