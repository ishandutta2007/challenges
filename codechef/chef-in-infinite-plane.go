/*

Chef has an integer sequence A1,A2,…,AN. For each index i (1≤i≤N), Chef needs to divide Ai into two positive integers x and y such that x+y=Ai, then place this as a point (x,y) in the infinite 2-dimensional coordinate plane.
Help Chef to find the maximum number of distinct points that can be put in the plane, if he optimally splits the values Ai.
Note that Chef can only perform one split for each index.

Note: Please use fast input/output methods for this problem.

Input Format

The first line contains a single integer T - the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N integers A1,A2,…,AN.

Output Format

For each test case, print a single line containing one integer — the maximum number of distinct points there can be in the infinite plane.

Constraints
1≤T≤10
1≤N≤2⋅10^5
2≤Ai≤10^5

*/

package main

func main() {
	assert(points([]int{2, 2, 4, 4, 2, 6}) == 4)
	assert(points([]int{16, 8}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func points(a []int) int {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	r := 0
	for k, v := range m {
		r += min(k-1, v)
	}
	return r
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
