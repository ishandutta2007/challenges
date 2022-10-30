/*

Jack and Jill have decided to sell some of their Compact Discs, while they still have some value.
They have decided to sell one of each of the CD titles that they both own. How many CDs can Jack and Jill sell?

Neither Jack nor Jill owns more than one copy of each CD.

Input

The input consists of a sequence of test cases. The first line of each test case contains two positive integers N and M, each at most one million,
specifying the number of CDs owned by Jack and by Jill, respectively.
This line is followed by N lines listing the catalog numbers of the CDs owned by Jack in increasing order,
and M more lines listing the catalog numbers of the CDs owned by Jill in increasing order.
Each catalog number is a positive integer no greater than one billion. The input is terminated by a line containing two zeros.
This last line is not a test case and should not be processed.

Output

For each test case, output a line containing one integer, the number of CDs that Jack and Jill both own.

*/

package main

func main() {
	assert(cds([]int{1, 2, 3}, []int{1, 2, 4}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cds(a, b []int) int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v] = true
	}

	c := 0
	for _, v := range b {
		if m[v] {
			c++
		}
	}

	return c
}
