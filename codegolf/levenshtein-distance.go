/*

While there are many edit distance questions, such as this one, there isn't a simple question to write a program that calculates the Levenshtein distance.

Some Exposition

The Levenshtein edit distance between two strings is the minimum possible number of insertions, deletions, or substitutions to convert one word into another word. In this case, each insertion, deletion and substitution has a cost of 1.

For example, the distance between roll and rolling is 3, because deletions cost 1, and we need to delete 3 characterrs. The distance between toll and tall is 1, because substitutions cost 1.

Rules

    The input will be two strings. You may assume that the strings are lowercase, only contain letters, are non-empty and are a maximum of 100 characters in length.
    The output will be minimum Levenshtein edit distance of the two strings, as defined above.
    Your code must a program or a function. It does not need to be a named function, but it cannot be a built-in function that directly computes the Levenshtein distance. Other built-ins are allowed.
    This is code golf, so the shortest answer wins.

Some Examples

>>> lev("atoll", "bowl")
3
>>> lev("tar", "tarp")
1
>>> lev("turing", "tarpit")
4
>>> lev("antidisestablishmentarianism", "bulb")
27

As always, if the problem is unclear, please let me know. Good luck and good golfing!

*/

package main

func main() {
	assert(lev("atoll", "bowl") == 3)
	assert(lev("tar", "tarp") == 1)
	assert(lev("turing", "tarpit") == 4)
	assert(lev("antidisestablishmentarianism", "bulb") == 27)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lev(s, t string) int {
	a := []rune(s)
	b := []rune(t)

	m := len(a)
	n := len(b)

	d := make([][]int, m+1)
	p := make([]int, (m+1)*(n+1))
	for i := range d {
		d[i] = p[i*(n+1) : (i+1)*(n+1)]
	}

	for i := 1; i <= m; i++ {
		d[i][0] = i
	}
	for j := 1; j <= n; j++ {
		d[0][j] = j
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if a[i-1] == b[j-1] {
				d[i][j] = d[i-1][j-1]
			} else {
				d[i][j] = min(min(d[i][j-1]+1, d[i-1][j]+1), d[i-1][j-1]+1)
			}
		}
	}
	return d[m][n]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
