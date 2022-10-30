/*

Create a function that takes an array and return the most frequently occuring element contained within it.
Examples

findFrequent([3, 7, 3]) ➞ 3

findFrequent([null, "hello", true, null]) ➞ null

findFrequent([false, "up", "down", "left", "right", true, false]) ➞ false

*/

package main

func main() {
	assert(frequent([]interface{}{3, 7, 3}) == 3)
	assert(frequent([]interface{}{nil, "hello", true, nil}) == nil)
	assert(frequent([]interface{}{false, "up", "down", "left", "right", true, false}) == false)
	assert(frequent([]interface{}{nil}) == nil)
	assert(frequent([]interface{}{1, 2, -3, true, false, nil, "yes", "yeah", "yup", 2}) == 2)
	assert(frequent([]interface{}{"Batman", "Superman", "Batman"}) == "Batman")
}

func frequent(a []interface{}) interface{} {
	m := make(map[interface{}]int)
	for i := range a {
		m[a[i]]++
	}

	var p interface{}
	var c int
	for k, v := range m {
		if c < v {
			p = k
			c = v
		}
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
