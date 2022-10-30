/*

Quantifiers indicate numbers of characters or expressions to match.

x* matches the preceding item "x" 0 or more times.

"A ghost booooed".match(/bo+/) ➞ "boooo"

x+ matches the preceding item "x" 1 or more times. Equivalent to {1,}.

"caaaaaaandy".match(/a+/) ➞ "aaaaaa"

x? matches the preceding item "x" 0 or 1 times. If used immediately after any of the quantifiers *, +, ?, or {}, makes the quantifier non-greedy (matching the minimum number of times), as opposed to the default, which is greedy (matching the maximum number of times).

"angle.".match(/e?le?/) ➞ "le"
"angel.".match(/e?le?/) ➞ "el"

    Write the regex to match only the street.
    Use a quantifier in your expression.

Example

let address = "Harry Potter, 4 Privet Drive, Little Whinging, Surrey"
address.match(REGEXP) ➞ "4 Privet Drive"

Notes

Check the Resources tab if you get stuck.

*/

var assert = require('assert');

function match(address) {
	const REGEXP = ",+ *([^,]+),+";
	group = address.match(REGEXP);
	if (group.length != 2)
		return null;
	return group[1];
}

function main() {
	const address1 = "Harry Potter, 4 Privet Drive, Little Whinging, Surrey";
	const address2 = "Sherlock Holmes, 221B Baker St, Marylebone London NW1 6XE, UK";
	const address3 = "The White House, 1600 Pennsylvania Avenue, Washington, DC";

	assert(match(address1) == "4 Privet Drive");
	assert(match(address2) == "221B Baker St");
	assert(match(address3) == "1600 Pennsylvania Avenue");
}

main();
