/*

Given the time control of a chess match as a+b, determine which format of chess out of the given 4 it belongs to.

1) Bullet if a+b<3
2) Blitz if 3≤a+b≤10
3) Rapid if 11≤a+b≤60
4) Classical if 60<a+b

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a single line of input, two integers a,b.

Output Format
For each testcase, output in a single line, answer 1 for bullet, 2 for blitz, 3 for rapid, and 4 for classical format.

Constraints
1≤T≤1100
1≤a≤100
0≤b≤10

*/

package main

func main() {
	assert(classify(1, 0) == 1)
	assert(classify(4, 1) == 2)
	assert(classify(100, 0) == 4)
	assert(classify(20, 5) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func classify(a, b int) int {
	switch v := a + b; {
	case v < 3:
		return 1
	case v <= 10:
		return 2
	case v <= 60:
		return 3
	}
	return 4
}
