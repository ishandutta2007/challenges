/*

Given an array A1,A2,...,AN, count the number of subarrays of array A which are non-decreasing.

A subarray A[i,j], where 1≤i≤j≤N is a sequence of integers Ai,Ai+1,...,Aj.

A subarray A[i,j] is non-decreasing if Ai≤Ai+1≤Ai+2≤...≤Aj. You have to count the total number of such subarrays.

Input

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the size of array.

The second line contains N space-separated integers A1, A2, …, AN denoting the elements of the array.

Output

For each test case, output in a single line the required answer.

Constraints
1≤T≤5
1≤N≤10^5
1≤Ai≤10^9

*/

package main

func main() {
	assert(subarrays([]int{1, 4, 2, 3}) == 6)
	assert(subarrays([]int{5}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func subarrays(a []int) int {
	n := len(a)

	p := make([]int, n)
	for i := range p {
		p[i] = 1
	}

	r := 1
	for i := 1; i < n; i++ {
		if a[i-1] <= a[i] {
			p[i] += p[i-1]
		}
		r += p[i]
	}
	return r
}
