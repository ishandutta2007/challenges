/*

A bee larva living in a hexagonal cell of a large honeycomb decides to creep for a walk.
In each “step” the larva may move into any of the six adjacent cells and after n steps, it is to end up in its original cell.

Your program has to compute, for a given n, the number of different such larva walks.

Input

The first line contains an integer giving the number of test cases to follow. Each case consists of one line containing an integer n, where 1≤n≤14.

Output

For each test case, output one line containing the number of walks. Under the assumption 1≤n≤14, the answer will be less than 2^31.

*/

package main

import "fmt"

func main() {
	assert(walks(2) == 6)
	assert(walks(4) == 90)
	for i := int64(0); i < 22; i++ {
		fmt.Println(walks(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A002898
func walks(n int64) int64 {
	if n < 0 {
		return 0
	}
	if n == 0 {
		return 1
	}
	if n == 1 {
		return 0
	}
	if n == 2 {
		return 6
	}

	a := (n - 1) * n * walks(n-1)
	b := 24 * (n - 1) * (n - 1) * walks(n-2)
	c := 36 * (n - 1) * (n - 2) * walks(n-3)
	return (a + b + c) / (n * n)
}
