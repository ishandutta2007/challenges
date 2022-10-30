/*

There are n chocolates, and you are given an array of n numbers where the i-th number Ai is the flavour type of the i-th chocolate.
Sebrina wants to eat as many different types of chocolates as possible, but she also has to save at least x number of chocolates for her little brother.

Find the maximum possible number of distinct flavour types Sebrina can have.

Input:

The first line contains an integer T --- the number of test cases.

The first line of each test case consists of two integers n, x - The number of chocolates Sabrina has and the number of chocolates she has to save for her brother, respectively.

The second line contains n integers A1,…,An, where the i-th chocolate has type Ai.

Output:

For each test case, output a single integer denoting the maximum possible number of distinct chocolate flavours Sabrina can eat.

Constraints

1≤T≤10
1≤x≤n≤2⋅10^5

1≤Ai≤10^9
Sum of n over all test cases do not exceed 2⋅10^5

*/

package main

func main() {
	assert(distinct([]int{1, 2}, 1) == 1)
	assert(distinct([]int{1, 1, 1, 1}, 2) == 1)
	assert(distinct([]int{50, 50, 50, 100, 100}, 3) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func distinct(a []int, x int) int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v] = true
	}
	return min(len(a)-x, len(m))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
