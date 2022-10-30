/*

In order to establish dominance amongst his friends, Chef has decided that he will only walk in large steps of length exactly K feet.
However, this has presented many problems in Chef’s life because there are certain distances that he cannot traverse.
Eg. If his step length is 5 feet, he cannot travel a distance of 12 feet.
Chef has a strict travel plan that he follows on most days, but now he is worried that some of those distances may become impossible to travel.
Given N distances, tell Chef which ones he cannot travel.

Input:

The first line will contain a single integer T, the number of test cases.
The first line of each test case will contain two space separated integers - N, the number of distances, and K, Chef’s step length.
The second line of each test case will contain N space separated integers, the ith of which represents Di, the distance of the ith path.

Output:

For each testcase, output a string consisting of N characters. The ith character should be 1 if the distance is traversable, and 0 if not.

Constraints
1≤T≤1000
1≤N≤1000
1≤K≤10^9
1≤Di≤10^9

*/

package main

import "bytes"

func main() {
	assert(traverse([]int{12, 13, 18, 20, 27216}, 3) == "10101")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func traverse(a []int, k int) string {
	w := new(bytes.Buffer)
	for _, v := range a {
		if v%k == 0 {
			w.WriteRune('1')
		} else {
			w.WriteRune('0')
		}
	}
	return w.String()
}
