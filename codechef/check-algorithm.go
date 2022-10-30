/*

One day, Saeed was teaching a string compression algorithm.
This algorithm finds all maximal substrings which contains only one character repeated one or more times (a substring is maximal if it we cannot add one character to its left or right without breaking this property)
and replaces each such substring by the string "cK", where K is the length of the substring and c is the only character it contains.
For example, "aabaaa" is compressed to "a2b1a3".

Saeed wanted to check if the students understood the algorithm, so he wrote a string S on the board and asked the students if the algorithm is effective on S, i.e. if the string created by compressing S is strictly shorter than S.
Help them answer this question.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S.

Output

For each test case, print a single line containing the string "YES" if the algorithm is effective on S or "NO" if it is not.

Constraints
1≤T≤100
1≤|S|≤10^3
S may consist of only lowercase English letters.

*/

package main

import "fmt"

func main() {
	assert(effective("bbbbbbbbbbaa") == true)
	assert(effective("c") == false)
	assert(effective("aaaaaaaaaabcdefgh") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func effective(s string) bool {
	if len(s) == 0 {
		return false
	}

	r := []rune(s)
	p := []rune{r[0]}
	c := 1
	for i := 1; i < len(r); i++ {
		if r[i] != r[i-1] {
			p = append(p, []rune(fmt.Sprint(c))...)
			p = append(p, r[i])
			c = 1
		} else {
			c++
		}
	}
	p = append(p, []rune(fmt.Sprint(c))...)
	return len(p) < len(r)
}
