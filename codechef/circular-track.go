/*

There is a circular track of length M consisting of M checkpoints and M bidirectional roads such that each road has a length of 1 unit.

Chef is currently at checkpoint A and wants to reach checkpoint B. Find the minimum length of the road he needs to travel.

Input Format

First line will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, three integers A,B, and M - the initial checkpoint, the final checkpoint, and the total number of checkpoints respectively.

Output Format

For each test case, output the minimum length Chef needs to travel.

Constraints

1≤T≤1000
2≤M≤10^9
1≤A,B≤M
A≠B

Sample Input 1
4
1 3 100
1 98 100
40 30 50
2 1 2

Sample Output 1
2
3
10
1

*/

package main

func main() {
	assert(length(1, 3, 100) == 2)
	assert(length(1, 98, 100) == 3)
	assert(length(40, 30, 50) == 10)
	assert(length(2, 1, 2) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func length(a, b, m int) int {
	if a > b {
		a, b = b, a
	}
	return min(b-a, m-b+a)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
