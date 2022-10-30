/*

Last month Alice nonchalantly entered her name in a draw for a Tapmaster 4000.
Upon checking her mail today, she found a letter that read:
“Congratulations, Alice! You have won a Tapmaster 4000. To claim your prize, you must answer the following skill testing question.”
Alice’s initial feelings of surprised joy turned quickly to those of dismay.
Her lifetime record for skill testing questions is an abysmal 3 right and 42 wrong.
Mad Skills, the leading skill testing question development company, was hired to provide skill testing questions for this particular Tapmaster 4000 draw.
They decided to create a different skill testing question to each winner so that the winners could not collaborate to answer the question.
Can you help Alice win the Tapmaster 4000 by solving the skill testing question?

Input

The input begins with t (1 ≤ t ≤ 100), the number of test cases. Each test case contains an integer n (−1000 ≤ n ≤ 1000) on a line by itself.
This n should be substituted into the skill testing question below.

Output
For each test case, output the answer to the following skill testing question on a line by itself:
“Multiply n by 567, then divide the result by 9, then add 7492, then multiply by 235, then divide by 47, then subtract 498.
What is the digit in the tens column?”

Sample Input

2
637
-120

Sample Output

1
3

*/

package main

func main() {
	assert(answer(637) == 1)
	assert(answer(-120) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func answer(n int) int {
	n = (n*567/9+7492)*235/47 - 498
	return (abs(n) / 10) % 10
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
