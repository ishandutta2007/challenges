/*

Create a function that given an array of dates returns the average date in string form.

Examples

averageDate([]) ➞ null

averageDate([
  new Date(Date.UTC(1970, 0, 1))
]) ➞ "1970-01-01T00:00:00.000Z"

averageDate([
  new Date(Date.UTC(1970, 0, 1)),
  new Date(Date.UTC(1971, 0, 1))
]) ➞ "1970-07-02T12:00:00.000Z"

Notes

    For the return value you can use the .toISOString() method.
    If dates is an empty array return null.

*/

var assert = require('assert');

function average(a) {
	if (a.length == 0) {
		return null;
	}

	var t = 0;
	for (const v of a) {
		t += v.getTime();
	}
	t /= a.length;

	var p = new Date();
	p.setTime(t);
	return p.toISOString();
}

function equals(a, b) {
	console.log(a);
	console.log(b);
	console.log();
	assert(a == b);
}

function main() {
	equals(average([]), null);

	equals(
  		average([new Date(Date.UTC(1970, 0, 1))]),
  		'1970-01-01T00:00:00.000Z'
	);

	equals(
  		average([new Date(Date.UTC(1970, 0, 1)), new Date(Date.UTC(1971, 0, 1))]),
  		'1970-07-02T12:00:00.000Z'
	);

	equals(
		average([new Date(Date.UTC(1970, 0, 1)), new Date(Date.UTC(1970, 0, 1))]),
		'1970-01-01T00:00:00.000Z'
	);

	equals(
		average([
			new Date(Date.UTC(1970, 0, 1)),
			new Date(Date.UTC(1971, 0, 1)),
			new Date(Date.UTC(1972, 0, 1)),
		]),
		'1971-01-01T00:00:00.000Z'
	);

	equals(
		average([
			new Date(Date.UTC(2010, 12, 30)),
			new Date(Date.UTC(2006, 12, 1)),
			new Date(Date.UTC(2006, 11, 4)),
			new Date(Date.UTC(2003, 4, 21)),
		]),
		'2007-02-05T06:00:00.000Z'
	);

	equals(
		average([
			new Date(Date.UTC(2018, 10, 2)),
			new Date(Date.UTC(2006, 8, 24)),
			new Date(Date.UTC(2005, 1, 31)),
			new Date(Date.UTC(2007, 11, 7)),
			new Date(Date.UTC(2009, 6, 19)),
			new Date(Date.UTC(2005, 6, 1)),
			new Date(Date.UTC(2013, 3, 8)),
			new Date(Date.UTC(2005, 7, 1)),
			new Date(Date.UTC(2012, 7, 8)),
			new Date(Date.UTC(2013, 6, 29)),
		]),
		'2009-11-15T09:36:00.000Z'
	);
}

main();
