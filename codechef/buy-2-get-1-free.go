/*

There is a sale going on in Chefland. For every 2 items Chef pays for, he gets the third item for free (see sample explanations for more clarity).

It is given that the cost of 1 item is X rupees. Find the minimum money required by Chef to buy at least N items.

Input Format
First line will contain T, number of test cases. Then the test cases follow.
Each test case contains of a single line of input, two integers N and X.

Output Format
For each test case, output the minimum money required by Chef to buy at least N items.

Constraints
1≤T≤1000
1≤N,X≤1000

*/

package main

func main() {
	assert(cost(3, 4) == 8)
	assert(cost(4, 2) == 6)
	assert(cost(5, 3) == 12)
	assert(cost(6, 1) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cost(n, x int) int {
	return 2*(n/3)*x + (n%3)*x
}
