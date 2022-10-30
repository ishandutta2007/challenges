/*

Chef built a binary string S that has exactly N hills and M valleys.

A hill is any index 1<i<|S| such that both its neighbors are strictly smaller than it, i.e, Si−1<Si and Si+1<Si.

A valley is any index 1<i<|S| such that both its neighbors are strictly larger than it, i.e, Si−1>Si and Si+1>Si.

Chef thinks that his string S is the shortest among all binary strings with N hills and M valleys.
You don't quite trust his words, so to verify his claim you would like to find the shortest binary string with exactly N hills and M valleys.

If there are multiple possible binary strings of the least length satisfying the given condition, you may print any of them.

Input Format

The first line of input will contain a single integer T, denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers N and M, the required number of hills and valleys respectively.

Output Format

For each test case, output two lines.

The first line contains the length of the binary string you constructed to satisfy the given conditions.
The second line contains the string itself.

Constraints

1≤T≤2500
1≤N≤500
1≤M≤500
The sum of lengths of the answer strings across all test cases does not exceed 2⋅10^5

*/

package main

import "strings"

func main() {
	assert(binstr(3, 2) == "0101010")
	assert(binstr(2, 3) == "1010101")
	assert(binstr(3, 3) == "01010101")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func binstr(n, m int) string {
	var s string
	switch {
	case n == m:
		s = strings.Repeat("01", n+1)
	case n < m:
		s = strings.Repeat("10", n+1)
		s += strings.Repeat("110", m-n-1)
		s += "1"
	default:
		s = strings.Repeat("01", m+1)
		s += strings.Repeat("001", n-m-1)
		s += "0"
	}
	return s
}
