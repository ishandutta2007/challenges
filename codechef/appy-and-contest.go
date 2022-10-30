/*

Appy and Chef are participating in a contest. There are N problems in this contest; each problem has a unique problem code between 1 and N inclusive.
Appy and Chef decided to split the problems to solve between them ― Appy should solve the problems whose problem codes are divisible by A but not divisible by B,
and Chef should solve the problems whose problem codes are divisible by B but not divisible by A (they decided to not solve the problems whose codes are divisible by both A and B).

To win, it is necessary to solve at least K problems. You have to tell Appy whether they are going to win or lose.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers N, A, B and K.

Output
For each test case, print a single line containing the string "Win" if they can solve at least K problems or "Lose" otherwise (without quotes).

Constraints
1≤T≤15
1≤K≤N≤10^18
1≤A,B≤10^9

*/

package main

func main() {
	assert(outcome(6, 2, 3, 3) == "Win")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func outcome(n, a, b, k int) string {
	l := lcm(a, b)
	x := n/a - n/l
	y := n/b - n/l
	if x+y >= k {
		return "Win"
	}
	return "Lose"
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return abs(a*b) / gcd(a, b)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
