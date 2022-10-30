/*

Chef and Dhyey have become friends recently. Chef wants to test Dhyey's intelligence by giving him a puzzle to solve.

The puzzle contains an integer sequence A1,A2,…,AN. The answer to the puzzle is the maximum of Ai%Aj, taken over all valid i, j.

Help Dhyey solve this puzzle.

Input

The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output

For each test case, print a single line containing one integer — the answer to the puzzle.

Constraints
2≤N≤10^5
1≤Ai≤10^9 for each valid i

*/

package main

import "sort"

func main() {
	assert(solve([]int{1, 2, 3, 4, 5}) == 4)
	assert(solve([]int{5, 5, 5, 2, 3, 8}) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a []int) int {
	sort.Ints(a)

	n := len(a)
	for i := n - 2; i >= 0; i-- {
		if a[i] != a[n-1] {
			return a[i] % a[n-1]
		}
	}
	return 0
}
