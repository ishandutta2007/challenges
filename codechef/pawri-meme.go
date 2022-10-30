/*

Lately, Chef has been inspired by the "pawri" meme. Therefore, he decided to take a string S and change each of its substrings that spells "party" to "pawri". Find the resulting string.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S.

Output

For each test case, print a single line containing the string after it is modified by Chef.

Constraints
1≤T≤10
1≤|S|≤10^5
S contains only lowercase English letters

*/

package main

import "strings"

func main() {
	assert(pawri("part") == "part")
	assert(pawri("partypartiparty") == "pawripartipawri")
	assert(pawri("yemaihuyemericarhaiauryahapartyhorahihai") == "yemaihuyemericarhaiauryahapawrihorahihai")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pawri(s string) string {
	return strings.Replace(s, "party", "pawri", -1)
}
