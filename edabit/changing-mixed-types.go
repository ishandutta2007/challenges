/*

Create a function that changes all the elements in an array as follows:

    Add 1 to all even integers, nothing to odd integers.
    Concatenates "!" to all strings and make the first letter of the word a capital letter.
    Changes all boolean values to its opposite.

Examples

changeTypes(["a", 12, true]) ➞ ["A!", 13, 0]

changeTypes([13, "13", "12", "twelve"]) ➞ [13, "13!", "12!", "Twelve!"]

changeTypes([false, "false", "true"]) ➞ [1, "False!", "True!"]

Notes

    There won't be any float values.
    You won't get strings with both numbers and letters in them.
    Although the task may be easy, try keeping your code as clean and as readable as possible!
    false becomes 1 and true becomes 0

*/

package main

import (
	"reflect"
	"unicode"
)

func main() {
	test([]interface{}{"a", 12, true}, []interface{}{"A!", 13, false})
	test([]interface{}{13, "13", "12", "twelve"}, []interface{}{13, "13!", "12!", "Twelve!"})
	test([]interface{}{false, "false", "true"}, []interface{}{true, "False!", "True!"})
}

func test(v, r []interface{}) {
	changetypes(v)
	assert(reflect.DeepEqual(v, r))
}

func changetypes(v []interface{}) {
	for i := range v {
		switch x := v[i].(type) {
		case string:
			r := []rune(x)
			if len(r) > 0 {
				r[0] = unicode.ToUpper(r[0])
			}
			v[i] = string(r) + "!"
		case int:
			if x&1 == 0 {
				x++
			}
			v[i] = x
		case bool:
			v[i] = !x
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
