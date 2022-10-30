/*

Chef has a sequence A1,A2,…,AN. He needs to find the number of pairs (i,j) (1≤i<j≤N) such that Ai+Aj=Ai⋅Aj.
However, he is busy, so he asks for your help.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output

For each test case, print a single line containing one integer ― the desired number of pairs.

Constraints
1≤T≤20
1≤N≤40,000
0≤Ai≤10^9 for each valid i

*/

package main

func main() {
	assert(pairs([]int{2, 4, 2}) == 1)
	assert(pairs([]int{0, 2, 3}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pairs(a []int) int {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	x := (m[0] * (m[0] - 1)) / 2
	y := (m[2] * (m[2] - 1)) / 2
	return x + y
}
