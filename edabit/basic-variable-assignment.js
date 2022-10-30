/*

A student learning JavaScript was trying to make a function.
His code should concatenate a passed string name with string "Edabit" and store it in a variable called result.
He needs your help to fix this code.

Examples

nameString("Mubashir") ➞ "MubashirEdabit"

nameString("Matt") ➞ "MattEdabit"

nameString("javaScript") ➞ "javaScriptEdabit"

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

var assert = require('assert');

function name(s) {
	return s + "Edabit";
}

function main() {
	assert(name("Mubashir") == "MubashirEdabit");
	assert(name("Matt") == "MattEdabit");
	assert(name("javascript") == "javascriptEdabit");
	assert(name("Airforce") == "AirforceEdabit");
}

main();
