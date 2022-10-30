/*

One day, Chef's friend gave him a wrong number W containing N+1 digits and said that the actual number A is the largest possible number that can be obtained from deleting exactly one digit of W. Chef was able to find A but forgot W.

Given A, find the smallest possible number W of length N+1 without leading 0's that is consistent with the story above. We can show that there is always at least one such W consistent with the story.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, an integer A.

Output

For each testcase, output in a single line string representing the answer to the problem.

Constraints
1≤T≤100
0≤Ai≤9 for all valid i, where Ai denotes the i-th digit of A
A1≠0 (no leading zero)
10≤|A|≤5000, where |A| denotes the number of digits of  A

*/

package main

import "strings"

func main() {
	assert(number("9876543211") == "19876543211")
	assert(number("12345678999") == "102345678999")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func number(s string) string {
	r := s
	if strings.HasPrefix(s, "1") {
		r = "0" + r[1:]
	}
	return "1" + r
}
