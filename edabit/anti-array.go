/*

Given two arrays, return whether the two arrays are opposites of each other.
That means both arrays are comprised only from elements a and b and the occurrences of these elements are swapped between the two arrays.

Examples

isAntiArray(["1", "0", "0", "1"], ["0", "1", "1", "0"]) ➞ true

isAntiArray(["apples", "bananas", "bananas"], ["bananas", "apples", "apples"]) ➞ true

isAntiArray([3.14, True, 3.14], [3.14, False, 3.14]) ➞ false

Notes

All tests will include only two different elements.

*/

package main

func main() {
	assert(antiarray([]interface{}{"1", "0", "0", "1"}, []interface{}{"0", "1", "1", "0"}) == true)
	assert(antiarray([]interface{}{"apples", "bananas", "bananas"}, []interface{}{"bananas", "apples", "apples"}) == true)
	assert(antiarray([]interface{}{3.14, true, 3.14}, []interface{}{3.14, false, 3.14}) == false)
	assert(antiarray([]interface{}{6.28, true, 6.28}, []interface{}{true, false, true}) == false)
	assert(antiarray([]interface{}{"int", "str"}, []interface{}{"str", "int"}) == true)
	assert(antiarray([]interface{}{3.14, true, 3.14}, []interface{}{3.14, true, 3.14}) == false)
	assert(antiarray([]interface{}{121, "float", "float", "float", 121, "float"}, []interface{}{"float", 121, 121, 121, "float", 121}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func antiarray(a, b []interface{}) bool {
	m := make(map[interface{}]bool)
	if len(a) != len(b) {
		return false
	}
	for i := 0; i < len(a); i++ {
		if a[i] == b[i] || len(m) > 2 {
			return false
		}
		m[a[i]] = true
		m[b[i]] = true
	}
	return len(m) == 2
}
