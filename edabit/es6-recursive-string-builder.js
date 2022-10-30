/*

Write a getStringBuilder() function that returns an object.
Any arbitrary property of that object will also be an object as will the properties of that object. Recursively.
Invoking any of the child objects should return a string generated from the entire property chain.

Examples

getStringBuilder().Hello.there() ➞ "Hello there"

getStringBuilder().one.two.three.four() ➞ "one two three four"

getStringBuilder().we.live.in.a.society() ➞ "we live in a society"

Notes

N/A

*/

var assert = require('assert');

function builder() {
	var list = [];
	const handler = {
		apply: function(target, that, args) {
			return list.join(" ");
		},

		get: function(target, property) {
			list.push(property);
			return new Proxy(target, handler);
		}
	};
	return new Proxy(function(){}, handler);
}

function main() {
	assert(builder().hello.how.are.you.today() == 'hello how are you today');
	assert(builder().Hello.there() == 'Hello there');
	assert(builder().one.two.three.four() == 'one two three four');
	assert(builder().we.live.in.a.society() == 'we live in a society');
	assert(builder().today.is.the.greatest.day.I.have.ever.known() == 'today is the greatest day I have ever known');
	assert(builder().there.are.only.two.hard.things.in.Computer.Science.cache.invalidation.and.naming.things() == 'there are only two hard things in Computer Science cache invalidation and naming things');
}

main();
