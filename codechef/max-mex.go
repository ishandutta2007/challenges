/*

You are given a multi-set S of N integers, and an integer K.
You want to find the maximum value of minimal excluded non-negative integer (MEX) of the multi-set given that you are allowed to add at most any K integers to the multi-set.
Find the maximum value of MEX that you can obtain.

Few examples of finding MEX of a multi-set are as follows. MEX of multi-set {0} is 1, {1} is 0, {0, 1, 3} is 2, {0, 1, 2, 3, 5, 6} is 4.

Input

The first line of the input contains an integer T denoting the number of testcases.

The first line of each test case contains two space seperated integers N and K denoting the size of the multi-set and the maximum number of extra integers that you can add in the multi-set respectively.

The second line contains N space separated integers denoting the multi-set S: S1, S2 ,.... SN.

Output

For each testcase, output the answer in a single line.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
0 ≤ K ≤ 10^5
0 ≤ Si ≤ 2 * 10^5

*/

package main

func main() {
	assert(mex([]int{1, 0, 2}, 0) == 3)
	assert(mex([]int{1, 0, 2}, 1) == 4)
	assert(mex([]int{2, 5, 4, 9}, 3) == 6)
	assert(mex([]int{3, 4}, 0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mex(a []int, k int) int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v] = true
	}

	r := 0
	for {
		if m[r] {
			r = r + 1
		} else if k > 0 {
			r, k = r+1, k-1
		} else {
			break
		}
	}
	return r
}
