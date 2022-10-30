/*

Write a function that sorts a given array in an alternative fashion. The result should be a array sorted in ascending order (number then letter).
Array will contain equal amounts of integer numbers and single characters.

Examples

alternateSort(["a", "b", "c", 1, 2, 3]) ➞ [1, "a", 2, "b", 3, "c"]

alternateSort([-2, "f", "A", 0, 100, "z"]) ➞ [-2, "A", 0, "f", 100, "z"]

alternateSort(["X", 15, 12, 18, "Y", "Z"]) ➞ [12, "X", 15, "Y", 18, "Z"]

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	eq(altsort([]interface{}{13}), []interface{}{13})
	eq(altsort([]interface{}{"x", 13}), []interface{}{13, "x"})
	eq(altsort([]interface{}{5, 1, "a", "c", 2, 1, 3, "c", "b", "e"}), []interface{}{1, "a", 1, "b", 2, "c", 3, "c", 5, "e"})
	eq(altsort([]interface{}{-2, "f", "A", 0, 100, "z"}), []interface{}{-2, "A", 0, "f", 100, "z"})
	eq(altsort([]interface{}{"a", "b", "c", 1, 2, 3}), []interface{}{1, "a", 2, "b", 3, "c"})
	eq(altsort([]interface{}{"e", "d", "a", "b", "i", "t", 1, 10, 100, 2, 20, 200}), []interface{}{1, "a", 2, "b", 10, "d", 20, "e", 100, "i", 200, "t"})
	eq(altsort([]interface{}{"X", 15, 12, 18, "Y", "Z"}), []interface{}{12, "X", 15, "Y", 18, "Z"})
	eq(altsort([]interface{}{"e", "d", "a", "b", "i", "u", "t", 1, 10, 100, 2, 20, 200, 400}), []interface{}{1, "a", 2, "b", 10, "d", 20, "e", 100, "i", 200, "t", 400, "u"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b []interface{}) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

func nssort(p []interface{}) {
	sort.Slice(p, func(i, j int) bool {
		x, n := p[i].(int)
		y, m := p[j].(int)

		z, s := p[i].(string)
		w, t := p[j].(string)
		switch {
		case n && m:
			return x < y
		case s && t:
			return z < w
		}
		return !n && m
	})
}

func altsort(p []interface{}) []interface{} {
	for i, l := 0, len(p)/2; l > 0; l /= 2 {
		if i == 0 || l&1 != 0 {
			nssort(p[i:])
		}
		for j := 0; j < l+(l&1); j++ {
			k := index(j) + l
			p[i+j], p[i+k] = p[i+k], p[i+j]
		}
		i += l + (l & 1)
	}

	return p
}

// https://oeis.org/A025480
func index(n int) int {
	if n <= 0 {
		return 0
	}
	for n&1 != 0 {
		n /= 2
	}
	return n / 2
}

// want altsort to be in place for no good reason
// the hard part is figuring out the swaps
// so use brute force to find a pattern
func findpat(n int) (s []int) {
	if n <= 0 {
		return nil
	}

	p := make([]int, n*2)
	for i := range p {
		p[i] = i
	}

	t := make([]int, n*2)
	for i := 0; i < len(t); i += 2 {
		t[i] = i / 2
		t[i+1] = (len(t) + i) / 2
	}

	for i := 0; !cmpi(p, t); i++ {
		for j := i; j < len(p); j++ {
			if p[j] == t[i] {
				p[i], p[j] = p[j], p[i]
				s = append(s, j)
				break
			}
		}
	}

	// almost matches https://oeis.org/A025480 up to a point then diverges
	// but this gives us enough info to figure out the indexing scheme
	for i := 1; i < len(s); i++ {
		s[i] -= n
	}
	fmt.Println(s)

	return
}

func cmpi(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
