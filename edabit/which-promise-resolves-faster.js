/*

Given two promises, create a function to determine whether the second promise is faster than the first. If it is, return true. Otherwise, return false.

Examples

speedTest(promise1, promise2) ➞ true
// promise2 resolves faster

speedTest(promise1, promise2) ➞ false
// promise1 resolves faster

Notes

	Make sure you await both promises when executing them.
	Check the Resources tab for a hint.

*/

var assert = require('assert');

function sleeper(id, ms) {
	return new Promise(resolve => {
		setTimeout(() => {
			resolve(id);
		}, ms);
	});
}

async function speedtest(pa, pb) {
	var r;
	await Promise.race([pa, pb]).then((id) => {
		r = id;
	});
	return r == 2;
}

async function test(pa, pb, r) {
	var p = await speedtest(pa, pb);
	assert(p == r);
}

function main() {
	test(sleeper(1, 6000), sleeper(2, 3000), true);
	test(sleeper(1, 1000), sleeper(2, 5000), false);
	test(sleeper(1, 8000), sleeper(2, 6000), true);
	test(sleeper(1, 3000), sleeper(2, 1000), true);
}

main();
