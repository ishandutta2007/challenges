/*

Consider a currency system in which there are notes of six denominations, namely, Rs. 1, Rs. 2, Rs. 5, Rs. 10, Rs. 50, Rs. 100.
If the sum of Rs. N is input, write a program to computer smallest number of notes that will combine to give Rs. N.

Input

The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output

For each test case, display the smallest number of notes that will combine to give N, in a new line.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000

*/

package main

func main() {
	assert(smallest(1200) == 12)
	assert(smallest(500) == 5)
	assert(smallest(242) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func smallest(n int) int {
	tab := []int{100, 50, 10, 5, 2, 1}

	r := 0
	for _, d := range tab {
		r += n / d
		n -= d * (n / d)
	}
	return r
}
