/*

Chef has gone shopping with his 5-year old son. They have bought N items so far. The items are numbered from 1 to N, and the item i weighs Wi grams.

Chef's son insists on helping his father in carrying the items. He wants his dad to give him a few items.
Chef does not want to burden his son. But he won't stop bothering him unless he is given a few items to carry.
So Chef decides to give him some items. Obviously, Chef wants to give the kid less weight to carry.

However, his son is a smart kid. To avoid being given the bare minimum weight to carry, he suggests that the items are split into two groups, and one group contains exactly K items.
Then Chef will carry the heavier group, and his son will carry the other group.

Help the Chef in deciding which items should the son take.
Your task will be simple.
Tell the Chef the maximum possible difference between the weight carried by him and the weight carried by the kid.

Input:

The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. The first line of each test contains two space-separated integers N and K. The next line contains N space-separated integers W1, W2, ..., WN.

Output:

For each test case, output the maximum possible difference between the weights carried by both in grams.

Constraints:
1 ≤ T ≤ 100
1 ≤ K < N ≤ 100
1 ≤ Wi ≤ 100000 (10^5)

*/

package main

import "sort"

func main() {
	assert(maxdiff([]int{8, 4, 5, 2, 10}, 2) == 17)
	assert(maxdiff([]int{1, 1, 1, 1, 1, 1, 1, 1}, 3) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxdiff(a []int, k int) int {
	sort.Ints(a)

	n := len(a)
	i := n - k
	if k <= n/2 {
		i = k
	}
	return abs(sum(a[:i]) - sum(a[i:]))
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func sum(a []int) int {
	r := 0
	for _, v := range a {
		r += v
	}
	return r
}
