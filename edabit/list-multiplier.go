/*

Create a function that takes a list as an argument and returns a new nested list for each element in the original list.
The nested list must be filled with the corresponding element (string or number) in the original list and each nested list has the same amount of elements as the original list.

Examples

multiply([4, 5]) ➞ [[4, 4], [5, 5]]

multiply(["*", "%", "$"]) ➞ [["*", "*", "*"], ["%", "%", "%"], ["$", "$", "$"]]

multiply(["A", "B", "C", "D", "E"]) ➞ [["A", "A", "A", "A", "A"], ["B", "B", "B", "B", "B"], ["C", "C", "C", "C", "C"], ["D", "D", "D", "D", "D"], ["E", "E", "E", "E", "E"]]

Notes

The given list contains numbers or strings.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]interface{}{"*", "%", "$"}, [][]interface{}{{"*", "*", "*"}, {"%", "%", "%"}, {"$", "$", "$"}})
	test([]interface{}{4, 5}, [][]interface{}{{4, 4}, {5, 5}})
	test([]interface{}{"A", "B", "C", "D", "E"}, [][]interface{}{{"A", "A", "A", "A", "A"}, {"B", "B", "B", "B", "B"}, {"C", "C", "C", "C", "C"}, {"D", "D", "D", "D", "D"}, {"E", "E", "E", "E", "E"}})
	test([]interface{}{1}, [][]interface{}{{1}})
}

func test(a []interface{}, r [][]interface{}) {
	p := multiply(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func multiply(a []interface{}) [][]interface{} {
	n := len(a)
	r := make([][]interface{}, n)
	for i := range a {
		for j := 0; j < n; j++ {
			r[i] = append(r[i], a[i])
		}
	}
	return r
}
