/*

Given a word, create an object that stores the indexes of each letter in an array.

    Make sure the letters are the keys.
    Make sure the letters are symbols.
    Make sure the indexes are stored in an array and those arrays are values.

Examples

mapLetters("dodo") ➞ { d: [0, 2], o: [1, 3] }

mapLetters("froggy") ➞ { f: [0], r: [1], o: [2], g: [3, 4], y: [5] }

mapLetters("grapes") ➞ { g: [0], r: [1], a: [2], p: [3], e: [4], s: [5] }

Notes

All strings given will be lowercase.

*/

package main

func main() {
	eqm(mapletters("dodo"), map[rune][]int{'d': []int{0, 2}, 'o': []int{1, 3}})
	eqm(mapletters("froggy"), map[rune][]int{'f': []int{0}, 'r': []int{1}, 'o': []int{2}, 'g': []int{3, 4}, 'y': []int{5}})
	eqm(mapletters("grapes"), map[rune][]int{'g': []int{0}, 'r': []int{1}, 'a': []int{2}, 'p': []int{3}, 'e': []int{4}, 's': []int{5}})
	eqm(mapletters(""), map[rune][]int{})
	eqm(mapletters("a"), map[rune][]int{'a': []int{0}})
	eqm(mapletters("abcdefg"), map[rune][]int{'a': []int{0}, 'b': []int{1}, 'c': []int{2}, 'd': []int{3}, 'e': []int{4}, 'f': []int{5}, 'g': []int{6}})
	eqm(mapletters("balloon"), map[rune][]int{'b': []int{0}, 'a': []int{1}, 'l': []int{2, 3}, 'o': []int{4, 5}, 'n': []int{6}})
	eqm(mapletters("imagining"), map[rune][]int{'i': []int{0, 4, 6}, 'm': []int{1}, 'a': []int{2}, 'g': []int{3, 8}, 'n': []int{5, 7}})
	eqm(mapletters("mummy"), map[rune][]int{'m': []int{0, 2, 3}, 'u': []int{1}, 'y': []int{4}})
	eqm(mapletters("aaaaaaabaaabaaabbb"), map[rune][]int{'a': []int{0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 13, 14}, 'b': []int{7, 11, 15, 16, 17}})
}

func mapletters(s string) map[rune][]int {
	m := make(map[rune][]int)
	i := 0
	for _, r := range s {
		m[r], i = append(m[r], i), i+1
	}
	return m
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eqs(a, b []int) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

func eqm(a, b map[rune][]int) {
	for k, v := range a {
		eqs(b[k], v)
	}
	for k, v := range b {
		eqs(b[k], v)
	}
}
