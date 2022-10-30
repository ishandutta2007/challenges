/*

We say that a binary string (a string containing only characters '0' and '1') is pure if it does not contain either of the strings "0101" or "1010" as a subsequence.

Recall that string T is a subsequence of string S if we can delete some of the letters of S (possibly none) such that the resulting string will become T.

You are given a binary string S with length N. We want to make this string pure by deleting some (possibly zero) characters from it. What is the minimum number of characters we have to delete?

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S with length N.

Output

For each test case, print a single line containing one integer — the minimum number of characters we have to delete from S.

Constraints
1≤T≤40
1≤N≤1,000
S contains only characters '0' and '1'

*/

package main

func main() {
	assert(deletions("010111101") == 2)
	assert(deletions("1011100001011101") == 3)
	assert(deletions("0110") == 0)
	assert(deletions("111111") == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func deletions(s string) int {
	n := len(s)
	p := make([][2]int, n+1)
	for i := 1; i <= n; i++ {
		p[i] = p[i-1]
		switch c := s[i-1]; c {
		case '0', '1':
			p[i][c-'0']++
		}
	}

	r := n
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			r = min(r, (p[j][1]-p[i-1][1])+p[i-1][0]+(p[n][0]-p[j][0]))
			r = min(r, (p[j][0]-p[i-1][0])+p[i-1][1]+(p[n][1]-p[j][1]))
		}
	}
	return r
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
