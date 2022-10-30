/*

Create a function that takes an array, finds the most repeated element(s) within it and returns it/them in an array (order not important). The function should work for both integers and strings mixed together within the input array (e.g. [1, 1, "a"]).

Notes

    If there is a tie for highest occurrence, return both (see second example above).
    Don't let integers become strings and/or string become integers in the result.
    NaN counts as a number.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(highest([]interface{}{"a"}))
	fmt.Println(highest([]interface{}{"a", "a"}))
	fmt.Println(highest([]interface{}{"a", "a", "b"}))
	fmt.Println(highest([]interface{}{"a", "a", "b", "b"}))
	fmt.Println(highest([]interface{}{2, 3, 2, 5, 6, 7, 2}))
	fmt.Println(highest([]interface{}{1, 2, 3, 3, "a", "b", "b", "c"}))
	fmt.Println(highest([]interface{}{"it", "keeps", "coding", "on", "or", "it", "gets", "the", "hose"}))
	fmt.Println(highest([]interface{}{1, "a", "b", "b"}))
	fmt.Println(highest([]interface{}{math.NaN(), "a", "b", "b"}))
	fmt.Println(highest([]interface{}{1, 2, 2, 3, 3, 3, 4, 4, 4, 4}))
	fmt.Println(highest([]interface{}{"ab", "ab", "b"}))
	fmt.Println(highest([]interface{}{"ab", "ab", "b", "bb", "b"}))
	fmt.Println(highest([]interface{}{"3a", "2a", "3a"}))
	fmt.Println(highest([]interface{}{3, 3, 3, 4, 4, 4, 4, 2, 3, 6, 7, 6, 7, 6, 7, 6, "a", "a", "a", "a"}))
	fmt.Println(highest([]interface{}{"ab", "ab", "b", "bb", "b"}))
	fmt.Println(highest([]interface{}{0, 1}))
	fmt.Println(highest([]interface{}{"hearts", "diamonds", "diamonds", "spades", "spades", "clubs"}))
	fmt.Println(highest([]interface{}{"1", "2", "2"}))
	fmt.Println(highest([]interface{}{2, 2, "2", "2", 4, 4}))
}

func highest(a []interface{}) []interface{} {
	var p []interface{}

	n := 0
	m := make(map[interface{}]int)
	for _, v := range a {
		m[v]++
		if n < m[v] {
			n = m[v]
		}
	}

	for k, v := range m {
		if n == v {
			p = append(p, k)
		}
	}
	return p
}
