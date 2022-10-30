/*

I was wondering how one might go and produce a program that takes input from some kind of random source and uses it to produce constant output.
An obvious way is, for example, to take an integer x and output x/x for 1, but that isn't too clever, is it? Therefore, the task is to write a program that outputs the same thing, no matter which input is given to it.

Specifications

The program may assume that the input is either a number or a one line string (that is, valid characters are [a-z][A-z][0-9] and spaces). If you adopt one of those restrictions, specify which in your answer.
The program must use the entered input in some way. To put it more formally, the contents of the variable that takes the input must be used afterwards in some calculation that affects the final variable to be printed.
The winner will be the most upvoted solution.

*/

const readline = require("readline");

function main() {
	const rl = readline.createInterface({
		input: process.stdin,
		output: process.stdout,
	});

	rl.question("Enter something: ", function (answer) {
		console.log(`1`);
		process.exit(0);
	});
}

main();
