/*

You will be given a collection of five cards (representing a player's hand in poker).
If your hand contains at least one pair, return an array of two elements: true and the card number of the highest pair (trivial if there only exists a single pair).
Else, return false.

Examples

highestPair(["A", "A", "Q", "Q", "6" ]) ➞ [true, "A"]

highestPair(["J", "6", "3", "10", "8"]) ➞ false

highestPair(["K", "7", "3", "9", "3"]) ➞ [true, "3"]

highestPair(["K", "9", "10", "J", "Q"]) ➞ false

highestPair(["3", "5", "5", "5", "5"]) ➞ [true, "5"]

Notes

Hands with three or more of the same card still count as containing a pair (see the last example).

*/

package main

import (
	"reflect"
)

func main() {
	test([]string{"A", "A", "Q", "Q", "6"}, []interface{}{true, "A"})
	test([]string{"J", "6", "3", "10", "8"}, false)
	test([]string{"K", "7", "3", "9", "3"}, []interface{}{true, "3"})
	test([]string{"K", "9", "10", "J", "Q"}, false)
	test([]string{"3", "5", "5", "5", "5"}, []interface{}{true, "5"})
	test([]string{"A", "A", "K", "K", "3"}, []interface{}{true, "A"})
	test([]string{"A", "K", "Q", "J", "10"}, false)
	test([]string{"A", "K", "K", "K", "Q"}, []interface{}{true, "K"})
	test([]string{"A", "3", "3", "4", "4"}, []interface{}{true, "4"})
	test([]string{"A", "K", "Q", "Q", "5"}, []interface{}{true, "Q"})
}

func test(a []string, r interface{}) {
	p := highest(a)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func highest(a []string) interface{} {
	m := make(map[string]int)
	for _, v := range a {
		m[v]++
	}

	var s string
	for k, v := range m {
		if v >= 2 && si(k) > si(s) {
			s = k
		}
	}

	if s == "" {
		return false
	}
	return []interface{}{true, s}
}

func si(s string) int {
	switch s {
	case "A":
		return 14
	case "K":
		return 13
	case "Q":
		return 12
	case "J":
		return 11
	case "10":
		return 10
	case "9", "8", "7", "6", "5", "4", "3", "2", "1":
		return int(s[0] - '0')
	default:
		return 0
	case "":
		return -1
	}
}
