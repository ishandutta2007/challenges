/*

You have one job and one job only, to ruin the day of any unsuspecting victim using the toString function.
Hook the String prototype toString to instead return a string that is in reverse.
Examples

("Hello World!").toString() ➞ "!dlroW olleH"

("My hooking function! :3").toString() ➞ "3: !noitcnuf gnikooh yM"

("RaceCar")toString() ➞ "raCecaR"

Notes

Remember that this is an object!

*/

var assert = require('assert');

String.prototype.toString = function () {
	var s = "";
	for (var i = 0; i < this.length; i++)
		s += this[this.length - 1 - i];
	return s;
};

assert(("Hello World!").toString() == "!dlroW olleH");
assert(("My hooking function! :3").toString() == "3: !noitcnuf gnikooh yM");
assert(("RaceCar").toString() == "raCecaR");
assert(("Level").toString() == "leveL");
assert(("live").toString() == "evil");
assert(("penut butter").toString() == "rettub tunep");
