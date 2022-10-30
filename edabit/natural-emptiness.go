/*

In abstract set theory, a construction due to von Neumann represents the natural numbers by sets, as follows:

    0 = [ ] is the empty set
    1 = 0 ∪ [ 0 ] = [ 0 ] = [ [ ] ]
    2 = 1 ∪ [ 1 ] = [ 0, 1 ] = [ [ ], [ [ ] ] ]
    n = n−1 ∪ [ n−1 ] = ...

Write a function that receives an integer n and produces the representing set.

Examples

repSet(0) ➞ []

repSet(1) ➞ [[]]

repSet(2) ➞ [[], [[]]]

repSet(3) ➞ [[], [[]], [[], [[ ]]]]

Notes

    Make sure to use array brackets [,].
    A neat feature of this representation is that n < m precisely if the set representing n is contained in the set representing m.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	test(0, "[]")
	test(1, "[[]]")
	test(2, "[[], [[]]]")
	test(3, "[[], [[]], [[], [[]]]]")
	test(5, "[[], [[]], [[], [[]]], [[], [[]], [[], [[]]]], [[], [[]], [[], [[]]], [[], [[]], [[], [[]]]]]]")
	test(7, "[[], [[]], [[], [[]]], [[], [[]], [[], [[]]]], [[], [[]], [[], [[]]], [[], [[]], [[], [[]]]]], [[], [[]], [[], [[]]], [[], [[]], [[], [[]]]], [[], [[]], [[], [[]]], [[], [[]], [[], [[]]]]]], [[], [[]], [[], [[]]], [[], [[]], [[], [[]]]], [[], [[]], [[], [[]]], [[], [[]], [[], [[]]]]], [[], [[]], [[], [[]]], [[], [[]], [[], [[]]]], [[], [[]], [[], [[]]], [[], [[]], [[], [[]]]]]]]]")
}

func test(n uint, r string) {
	fmt.Printf("%v\n%v\n\n", n, r)
	assert(stringify(set(n)) == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = map[uint]interface{}{
	0: []interface{}{},
}

func set(n uint) interface{} {
	if r, ok := cache[n]; ok {
		return r
	}

	r := make([]interface{}, n)
	for i := uint(0); i < n; i++ {
		r[i] = set(i)
	}

	cache[n] = r
	return r
}

func stringify(v interface{}) string {
	w := new(bytes.Buffer)
	switch p := v.(type) {
	case []interface{}:
		fmt.Fprintf(w, "[")
		for i := range p {
			fmt.Fprintf(w, "%v", stringify(p[i]))
			if i+1 < len(p) {
				fmt.Fprintf(w, ", ")
			}
		}
		fmt.Fprintf(w, "]")
	}
	return w.String()
}
