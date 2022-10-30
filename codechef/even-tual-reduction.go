/*

You are given a string S with length N. You may perform the following operation any number of times:
choose a non-empty substring of S (possibly the whole string S) such that each character occurs an even number of times in this substring and erase this substring from S.
(The parts of S before and after the erased substring are concatenated and the next operation is performed on this shorter string.)

For example, from the string "acabbad", we can erase the highlighted substring "abba", since each character occurs an even number of times in this substring.
After this operation, the remaining string is "acd".

Is it possible to erase the whole string using one or more operations?

Note: A string B is a substring of a string A if B can be obtained from A by deleting several (possibly none or all) characters from the beginning and several (possibly none or all) characters from the end.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains a single string S with length N.

Output

For each test case, print a single line containing the string "YES" if it is possible to erase the whole string or "NO" otherwise (without quotes).

Constraints

1≤T≤200
1≤N≤1,000
S contains only lowercase English letters

*/

package main

func main() {
	assert(erasable("cabbac") == true)
	assert(erasable("acabbad") == false)
	assert(erasable("fbedfcbdaebaaceeba") == true)
	assert(erasable("yourcrushlovesyouback") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func erasable(s string) bool {
	m := make(map[rune]int)
	for _, r := range s {
		m[r]++
	}

	for _, v := range m {
		if v&1 != 0 {
			return false
		}
	}
	return true
}
