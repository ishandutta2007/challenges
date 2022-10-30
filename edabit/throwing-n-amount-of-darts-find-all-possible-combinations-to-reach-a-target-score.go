/*

You're given a dartboard divided into sections, each section has a unique score. That means there won't be two sections with the same score.

Throwing a certain amount of valid darts, find how many solutions there are to reach the target score. Your function will be passed three parameters...

    Sections: An array of values for the sections (e.g. [3, 6, 8, 11, 15, 19, 22], the array is already sorted).

    Darts: The amount of darts to throw.

    Target: The target score.

Return an empty array if no solution is found, otherwise an array of non-duplicate strings for each solution (e.g. ["3-11-18", "7-7-18", "7-11-14"]).


Examples

If there are duplicate values, keep only the one sorted from smallest to biggest.

"8-19-8"

"8-8-19" <-- This is the one you would keep.

"19-8-8"

Multiple solutions should be sorted before returning them.

["3-11-18", "7-7-18", "7-11-14"] is ok.

["7-11-14", "7-7-18", "3-11-18"] is not ok.

Notes

    Multiple darts can land in the same section.

    A dart must land in a valid section (it can't miss).

*/
package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(darts([]int{3, 6, 8, 11, 15, 19, 22}, 3, 35))
	fmt.Println(darts([]int{2, 4, 7, 10, 13, 18, 24}, 3, 29))
	fmt.Println(darts([]int{3, 7, 11, 14, 18, 20, 25}, 3, 40))
	fmt.Println(darts([]int{3, 7, 11, 14, 18, 20, 25}, 3, 8))
	fmt.Println(darts([]int{3, 7, 11, 14, 18, 20, 25}, 3, 32))
	fmt.Println(darts([]int{3, 7, 11, 14, 18, 20, 25, 29, 34}, 3, 67))
	fmt.Println(darts([]int{3, 7, 11, 14, 18, 20, 25}, 4, 23))
}

func darts(s []int, n, t int) []string {
	var r, p []string
	dartsrec(s, n, t, 0, "", &r)

	m := make(map[string]bool)
	for _, r := range r {
		w := sortword(r)
		if !m[w] {
			p = append(p, r)
		}
		m[w] = true
	}
	return p
}

func dartsrec(s []int, n, t, v int, p string, r *[]string) {
	if n == 0 {
		if v == t {
			*r = append(*r, p)
		}
		return
	}

	for i := range s {
		var q string
		if p == "" {
			q = fmt.Sprint(s[i])
		} else {
			q = fmt.Sprintf("%s-%d", p, s[i])
		}

		dartsrec(s, n-1, t, v+s[i], q, r)
	}
}

func sortword(w string) string {
	r := []rune(w)
	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})
	return string(r)
}
