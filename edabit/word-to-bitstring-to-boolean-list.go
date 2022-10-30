/*

Create a function that converts a word to a bitstring and then to a boolean list based on the following criteria:

    Locate the position of the letter in the English alphabet (from 1 to 26).
    Odd positions will be represented as 1 and 0 otherwise.
    Convert the represented positions to boolean values, 1 for True and 0 for False.
    Store the conversions into an array.

Examples

to_boolean_list("deep") ➞ [False, True, True, False]
# deep converts to 0110
# d is the 4th alphabet - 0
# e is the 5th alphabet - 1
# e is the 5th alphabet - 1
# p is the 16th alphabet - 0

to_boolean_list("loves") ➞ [False, True, False, True, True]

to_boolean_list("tesh") ➞ [False, True, True, False]

Notes

    The letter A is at position 1 and Z at 26.
    All input strings are in lowercase letters of the English alphabet.

*/

package main

import "reflect"

func main() {
	test("charming", []bool{true, false, true, false, true, true, false, true})
	test("exquisite", []bool{true, false, true, true, true, true, true, false, true})
	test("admire", []bool{true, false, true, true, false, true})
	test("deep", []bool{false, true, true, false})
	test("loves", []bool{false, true, false, true, true})
	test("tesh", []bool{false, true, true, false})
	test("xavier", []bool{false, true, false, true, true, false})
	test("adores", []bool{true, false, true, false, true, true})
	test("tesha", []bool{false, true, true, false, true})
	test("esquire", []bool{true, true, true, true, true, false, true})
	test("randomize", []bool{false, true, false, false, true, true, true, false, true})
	test("exotic", []bool{true, false, true, false, true, true})
}

func test(s string, r []bool) {
	assert(reflect.DeepEqual(blist(s), r))
}

func blist(s string) []bool {
	var p []bool
	for _, r := range s {
		if 'a' <= r && r <= 'z' {
			r -= 'a' + 1
		} else if 'A' <= r && r <= 'Z' {
			r -= 'A' + 1
		}
		p = append(p, r&1 != 0)
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
