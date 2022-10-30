/*

Create a function that returns the frequency distribution of an array.
This function should return an object, where the keys are the unique
elements and the values are the frequency in which those elements occur.

Examples

getFrequencies(["A", "B", "A", "A", "A"]) ➞ { A: 4, B: 1 }

getFrequencies([1, 2, 3, 3, 2]) ➞ { "1": 1, "2": 2, "3": 2 }

getFrequencies([true, false, true, false, false]) ➞ { true: 2, false: 3 }

getFrequencies([]) ➞ {}

Notes

    If given an empty array, return an empty object (see example #4).
    The object should be in the same order as in the input array.

*/

package main

import "fmt"

func main() {
	fmt.Println(getfreq([]interface{}{"A", "A"}))
	fmt.Println(getfreq([]interface{}{"A", "B", "A", "A", "A"}))
	fmt.Println(getfreq([]interface{}{"A", "B", "C", "A", "A"}))
	fmt.Println(getfreq([]interface{}{true, false, true, false, false}))
	fmt.Println(getfreq([]interface{}{1, 2, 3, 3, 2}))
}

func getfreq(v []interface{}) map[interface{}]int {
	m := make(map[interface{}]int)
	for i := range v {
		m[v[i]]++
	}
	return m
}
