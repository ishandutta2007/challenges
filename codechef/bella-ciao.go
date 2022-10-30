/*

Chef is planning a heist in the reserve bank of Chefland. They are planning to hijack the bank for D days and print the money.
The initial rate of printing the currency is P dollars per day and they increase the production by Q dollars after every interval of d days.
For example, after d days the rate is P+Q dollars per day, and after 2d days the rate is P+2Q dollars per day, and so on.
Output the amount of money they will be able to print in the given period.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, four integers D,d,P,Q.

Output

For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤10^5
1≤d≤D≤10^6
1≤P,Q≤10^6

*/

package main

func main() {
	assert(amount(2, 1, 1, 1) == 3)
	assert(amount(3, 2, 1, 1) == 4)
	assert(amount(5, 2, 1, 2) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func amount(D, d, P, Q int) int {
	a := P
	n := D / d
	l := Q
	r := D % d
	x := d * ((n * (2*a + (n-1)*l)) / 2)
	y := r * (a + n*l)
	return x + y
}
