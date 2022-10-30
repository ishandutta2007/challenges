/*

Your spouse tells you that one of the items on the list wasn't stolen, it is in your castle in Transilvania.
Given an object of the stolen items and an item name, return a copy without that item on the list.

Examples

{ piano: 300, tv: 100, skate:50 } ➞ { piano: 300, tv: 100 }

{ mirror: 500, painting: 1 } ➞ { painting: 1 }

Notes

    The object will contain at least two items.
    Preferably, mutate the copy, not the original.

*/

package main

import (
	"math/rand"
	"reflect"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	m1 := map[string]int{"piano": rand.Int(), "tv": 100}
	r1 := map[string]int{"piano": m1["piano"]}

	m2 := map[string]int{"piano": rand.Int(), "tv": 100, "skate": 50}
	r2 := map[string]int{"piano": m2["piano"], "skate": m2["skate"]}

	test(m1, "tv", r1)
	test(m2, "tv", r2)
}

func test(m map[string]int, o string, r map[string]int) {
	p := remove(m, o)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func remove(m map[string]int, o string) map[string]int {
	p := make(map[string]int)
	for k, v := range m {
		p[k] = v
	}
	delete(p, o)
	return p
}
