/*

You can think of character classes as characters with special meaning. They are recognized as special when you place the \ before the character.

Here are a list of the characters classes in JavaScript:

., \cX, \d, \D, \f, \n, \r, \s, \S, \t, \v, \w, \W, \0, \xhh, \uhhhh, \uhhhhh, [\b]

We have the \t and \v character classes that match any tabs in a string. But more specifically \t is used to match horizontal tabs while \v matches vertical tabs.
Vertical tabs were once a thing but are rarely used anymore. We generally use horizontal tabs which are produced by the tab key on our keyboards.

Find how many tabs with one literal whitespace immediately following the tab are in a string.
Notes

    Not all whitespaces are the same, however, \s will match any whitespace.
    See Resources for help.

*/

var assert = require('assert');

function match(address) {
	const REGEXP = "\t+ ";
	group = address.match(REGEXP);
	return group.length;
}

function main() {
	const str = `What\tabout\tme?\t `;
	assert(match(str) == 1);
}

main();
