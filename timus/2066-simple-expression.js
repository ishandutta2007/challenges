/*

You probably know that Alex is a very serious mathematician and he likes to solve serious problems. This is another problem from Alex.
You are given three nonnegative integers a, b, c. You have to arrange them in some order and put +, − or × signs between them to minimize the outcome of the resulting expression.
You are not allowed to use unary minus and parentheses in the expression. There must be exactly one sign between every pair of neighbouring numbers.
You should use standard order for performing operations (multiplication first, addition and subtraction then).

Input

There are three lines with one integer in each line. The numbers are arranged in non-decreasing order (0 ≤ a ≤ b ≤ c ≤ 100).

Output

Print one number — the minimal outcome.

*/

var assert = require('assert');

function minimize(a, b, c) {
	var ops = ['+', '-', '*'];
	
	var r = Number.MAX_VALUE;
	for (var i = 0; i < ops.length; i++) {
		for (var j = 0; j < ops.length; j++) {
			var v = eval(`${a} ${ops[i]} ${b} ${ops[j]} ${c}`);
			r = Math.min(r, v);
		}
	}
	return r;
}

assert(minimize(1, 2, 3) == -5);
