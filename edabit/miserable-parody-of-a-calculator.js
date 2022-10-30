/*

Create a function that will handle simple math expressions.
The input is an expression in the form of a string.

Examples

Calculator("23+4") ➞ 27

Calculator("45-15") ➞ 30

Calculator("13+2-5*2") ➞ 5

Calculator("49/7*2-3") ➞ 11

Notes

    There will be no brackets in the input line.
    No need to calculate mathematical functions (sin, cos, ln...).
    There are no gaps in the expression.

*/

var assert = require('assert');

function calculator(s) {
	return eval(s);
}

function main() {
	assert(calculator("23+4") == 27);
	assert(calculator("45-15") == 30);
	assert(calculator("13+2-5*2") == 5);
	assert(calculator("49/7*2-3") == 11);
	assert(calculator("2+2*2") == 6);
	assert(calculator("5/2") == 2.5);
	assert(calculator("-34/4") == -8.5);
	assert(calculator("0+43-0+56*0") == 43);
	assert(calculator("-14*2-37-0") == -65);
	assert(calculator("0*0") == 0);
	assert(calculator("4+2+3-5*2-8/4-12-0+3-14") == -26);
	assert(calculator("9/2+9/4") == 6.75);
	assert(calculator("56*27*18*12/2*0") == 0);
	assert(calculator("34/4*0*45*7") == 0);
}

main();
