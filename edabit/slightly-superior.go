/*

You will be given two extremely similar arrays, but exactly one of the items in an array will be valued slightly higher than its counterpart (which means that evaluating the value > the other value will return true).

Create a function that returns whether the first array is slightly superior to that of the second.
Examples

isFirstSuperior([1, 2, 4], [1, 2, 3]) ➞ true
// The pair of items at each index are compared in turn.
// 1 from the first array is the same as 1 from the second array.
// 2 is the same as 2.
// However, 4 is greater than 3, so first array is superior.

isFirstSuperior(["a", "d", "c"], ["a", "b", "c"]) ➞ true

isFirstSuperior(["zebra", "ostrich", "whale"], ["ant", "ostrich", "whale"]) ➞ true

isFirstSuperior([1, 2, 3, 4], [1, 2, 4, 4]) ➞ false

isFirstSuperior([true, 10, "zebra"], [true, 10, "zebra"]) ➞ false

Notes

    Both arrays will be the same length.
    All values and their counterparts will always be of the same data type.
    If the two arrays are the same, return false.

*/

package main

import "reflect"

func main() {
	assert(superior([]interface{}{1, 2, 3, 4}, []interface{}{1, 2, 3, 3}) == true)
	assert(superior([]interface{}{"a", "b", "c"}, []interface{}{"a", "d", "c"}) == false)
	assert(superior([]interface{}{true, 10, "zebra"}, []interface{}{true, 10, "zebra"}) == false)
	assert(superior([]interface{}{true, 10, "zebra"}, []interface{}{true, 10, "ant"}) == true)
	assert(superior([]interface{}{true, true, false, true}, []interface{}{true, true, true, true}) == false)
	assert(superior([]interface{}{9.1, 8.1, 7.1, 6.1}, []interface{}{9.1, 8.1, 7.1, 5.1}) == true)
	assert(superior([]interface{}{"llama", "buffalo"}, []interface{}{"llama", "buffalo"}) == false)
	assert(superior([]interface{}{"zebra", "ostrich", "whale"}, []interface{}{"ant", "ostrich", "whale"}) == true)
	assert(superior([]interface{}{1, 2, 3, 4}, []interface{}{1, 2, 4, 4}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func superior(a, b []interface{}) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return cmp(a[i], b[i])
		}
	}
	return false
}

func cmp(a, b interface{}) bool {
	ra := reflect.ValueOf(a)
	rb := reflect.ValueOf(b)
	if ra.Kind() != rb.Kind() {
		return false
	}
	switch ra.Kind() {
	case reflect.Int8, reflect.Int16, reflect.Int32, reflect.Int64, reflect.Int:
		return ra.Int() > rb.Int()
	case reflect.Uint8, reflect.Uint16, reflect.Uint32, reflect.Uint64, reflect.Uint:
		return ra.Uint() > rb.Uint()
	case reflect.Float32, reflect.Float64:
		return ra.Float() > rb.Float()
	case reflect.String:
		return ra.String() > rb.String()
	}
	return false
}
