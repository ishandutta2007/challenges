/*

There are N hills in a row numbered 1 through N from left to right. Each hill has a height; for each valid i, the height of the i-th hill is Hi.
Chef is initially on the leftmost hill (hill number 1).
He can make an arbitrary number of jumps (including zero) as long as the following conditions are satisfied:

Chef can only jump from each hill to the next hill, i.e. from the i-th hill, he can jump to the i+1-th hill (if it exists).
It's always possible to jump to a hill with the same height as the current hill.
It's possible to jump to a taller hill if it's higher than the current hill by no more than U.
It's possible to jump to a lower hill if it's lower than the current hill by no more than D.
Chef can use a parachute and jump to a lower hill regardless of its height (as long as it's lower than the current hill). This jump can only be performed at most once.
Chef would like to move as far right as possible. Determine the index of the rightmost hill Chef can reach.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, U and D.
The second line contains N space-separated integers H1, H2, ..., HN.

Output

For each test case, print a single line containing one integer — the index of the rightmost reachable hill.

Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ U, D ≤ 1,000,000
1 ≤ Hi ≤ 1,000,000 for each valid i

*/

package main

func main() {
	assert(hill([]int{2, 5, 2, 6, 3}, 3, 2) == 3)
	assert(hill([]int{4, 4, 4, 4, 4}, 2, 3) == 5)
	assert(hill([]int{1, 4, 3, 2, 1}, 2, 7) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hill(a []int, u, d int) int {
	h, p := 1, 1
loop:
	for i := 1; i < len(a); i++ {
		switch {
		case a[i] > a[i-1]:
			if a[i]-a[i-1] <= u {
				h++
			} else {
				break loop
			}

		case a[i] < a[i-1]:
			if a[i-1]-a[i] <= d {
				h++
			} else if p == 1 {
				h, p = h+1, p-1
			} else {
				break loop
			}

		default:
			h++
		}
	}
	return h
}
