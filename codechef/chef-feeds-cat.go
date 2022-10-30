/*

Chef owns N cats (numbered 1 through N) and he wants to feed them.
There are M identical cans of cat food; each can must be used to feed exactly one cat and Chef can only feed one cat at a time.
Chef wrote down the order in which he wants to feed the cats: a sequence A1,A2,…,AM.

An order of feeding cats is fair if there is no moment where Chef feeds a cat that has already been fed strictly more times than some other cat.
Help Chef — tell him if the order in which he wants to feed the cats is fair.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M.
The second line contains M space-separated integers A1,A2,…,AM.

Output

For each test case, print a single line containing the string "YES" if the order is fair or "NO" if it is unfair.

Constraints
1≤T≤100
2≤N≤100
1≤M≤10^3

*/

package main

import "math"

func main() {
	assert(fair(3, []int{1, 2, 3, 1, 2, 3, 1, 2, 3}) == true)
	assert(fair(3, []int{1, 2, 3, 3, 2, 1, 1, 2, 3}) == true)
	assert(fair(3, []int{2, 3, 1, 1, 2}) == true)
	assert(fair(3, []int{2, 1, 1, 3, 2, 3}) == false)
	assert(fair(2, []int{1, 2, 1, 2, 1, 2, 1, 1}) == false)
	assert(fair(5, []int{5, 3, 1}) == true)
	assert(fair(4, []int{1, 2, 3, 1, 4}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fair(n int, a []int) bool {
	p := make([]int, n)
	for _, v := range a {
		i := v - 1
		if i < 0 || i >= n {
			return false
		}
		p[i]++

		if x, y := minmax(p); y-x >= 2 {
			return false
		}
	}
	return true
}

func minmax(a []int) (x, y int) {
	x = math.MaxInt
	y = math.MinInt
	for _, v := range a {
		x = min(x, v)
		y = max(y, v)
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
