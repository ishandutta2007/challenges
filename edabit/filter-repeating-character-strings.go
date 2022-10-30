/*

Create a function that keeps only strings with repeating identical characters (in other words, it has a set size of 1).
Examples

identicalFilter(["aaaaaa", "bc", "d", "eeee", "xyz"])
➞ ["aaaaaa", "d", "eeee"]

identicalFilter(["88", "999", "22", "545", "133"])
➞ ["88", "999", "22"]

identicalFilter(["xxxxo", "oxo", "xox", "ooxxoo", "oxo"])
➞ []

Notes

    A string with a single character is trivially counted as a string with repeating identical characters.
    If there are no strings with repeating identical characters, return an empty array (see example #3).

*/

package main

func main() {
	eq(filter([]string{"aaaaaa", "bc", "d", "eeee", "xyz"}), []string{"aaaaaa", "d", "eeee"})
	eq(filter([]string{"88", "999", "22", "545", "133"}), []string{"88", "999", "22"})
	eq(filter([]string{"xxxxo", "oxo", "xox", "ooxxoo", "oxo"}), []string{})
	eq(filter([]string{"aaaaaa", "bc", "d", "eeee", "xyz"}), []string{"aaaaaa", "d", "eeee"})
	eq(filter([]string{"1", "2", "3"}), []string{"1", "2", "3"})
}

func filter(s []string) []string {
	var p []string
	for i := range s {
		if isrepeat(s[i]) {
			p = append(p, s[i])
		}
	}
	return p
}

func isrepeat(s string) bool {
	var lr rune
	for i, r := range s {
		if i == 0 {
			lr = r
		}
		if lr != r {
			return false
		}
	}
	return true
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(s, t []string) {
	assert(len(s) == len(t))
	for i := range s {
		assert(s[i] == t[i])
	}
}
