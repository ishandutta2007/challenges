/*

You are given an array A of N elements. For any ordered triplet (i,j,k) such that i, j, and k are pairwise distinct and 1≤i,j,k≤N, the value of this triplet is (Ai−Aj)⋅Ak.
You need to find the maximum value among all possible ordered triplets.

Note: Two ordered triplets (a,b,c) and (d,e,f) are only equal when a=d and b=e and c=f. As an example, (1,2,3) and (2,3,1) are two different ordered triplets.

Input Format

The first line of the input contains a single integer T - the number of test cases. The test cases then follow.
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.

Output Format

For each test case, output the maximum value among all different ordered triplets.

Constraints
1≤T≤100
3≤N≤3⋅10^5
1≤Ai≤10^6
Sum of N over all testcases won't exceed 3⋅10^5

*/

package main

import "sort"

func main() {
	assert(triplet([]int{1, 1, 3}) == 2)
	assert(triplet([]int{3, 4, 4, 1, 2}) == 12)
	assert(triplet([]int{23, 17, 21, 18, 19}) == 126)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func triplet(a []int) int {
	n := len(a)
	if n < 3 {
		return 0
	}

	sort.Ints(a)

	return (a[n-1] - a[0]) * a[n-2]
}
