/*

Create a function that takes an array of strings and return an array, sorted from shortest to longest.

Examples

sortByLength(["Google", "Apple", "Microsoft"])
➞ ["Apple", "Google", "Microsoft"]

sortByLength(["Leonardo", "Michelangelo", "Raphael", "Donatello"])
➞ ["Raphael", "Leonardo", "Donatello", "Michelangelo"]

sortByLength(["Turing", "Einstein", "Jung"])
➞ ["Jung", "Turing", "Einstein"]

Notes

All test cases contain arrays with strings of different lengths, so you won't have to deal with multiple strings of the same length.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]string{"Google", "Apple", "Microsoft"}, []string{"Apple", "Google", "Microsoft"})
	test([]string{"Leonardo", "Michelangelo", "Raphael", "Donatello"}, []string{"Raphael", "Leonardo", "Donatello", "Michelangelo"})
	test([]string{"Turing", "Einstein", "Jung"}, []string{"Jung", "Turing", "Einstein"})
	test([]string{"Tatooine", "Hoth", "Yavin", "Dantooine"}, []string{"Hoth", "Yavin", "Tatooine", "Dantooine"})
	test([]string{"Mario", "Bowser", "Link"}, []string{"Link", "Mario", "Bowser"})
}

func test(s, r []string) {
	p := lensort(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lensort(s []string) []string {
	p := append([]string{}, s...)
	sort.SliceStable(p, func(i, j int) bool {
		return len(p[i]) < len(p[j])
	})
	return p
}
