/*

Create a function (named fifth) that takes some arguments and returns the type of the fifth argument.
In case the arguments were less than 5, return "Not enough arguments".

Examples

fifth(1, 2, 3, 4, 5) ➞ int

fifth("a", 2, 3, [1, 2, 3], "five") ➞ str

fifth() ➞ "Not enough arguments"

Notes

    Don't get confused between zero-indexing and one-indexing.
    If you get stuck check the Resources tab.

*/

package main

import (
	"reflect"
)

func main() {
	assert(fifth([]interface{}{'a', 2, 3, 4, []int{5}}) == "slice")
	assert(fifth([]interface{}{"zero", "one", "two", "three", "four", "five"}) == "string")
	assert(fifth([]interface{}{1, 2, 3, 4, "5"}) == "string")
	assert(fifth([]interface{}{1, 2, 3, 4, 5}) == "int")
	assert(fifth([]interface{}{1, 2, 3}) == "Not enough arguments")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fifth(a []interface{}) string {
	if len(a) < 5 {
		return "Not enough arguments"
	}
	rv := reflect.ValueOf(a[4])
	return rv.Kind().String()
}
