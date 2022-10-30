/*

Create a function that takes an array of strings and returns an array with only the strings that have numbers in them. If there are no strings containing numbers, return an empty array.

Examples

numInStr(["1a", "a", "2b", "b"]) ➞ ["1a", "2b"]

numInStr(["abc", "abc10"]) ➞ ["abc10"]

numInStr(["abc", "ab10c", "a10bc", "bcd"]) ➞ ["ab10c", "a10bc"]

numInStr(["this is a test", "test1"]) ➞ ["test1"]

Notes

    The strings can contain white spaces or any type of characters.
    Bonus: Try solving this without regex.

*/

package main

import (
	"reflect"
	"unicode"
)

func main() {
	test([]string{"abc", "abc10"}, []string{"abc10"})
	test([]string{"abc", "ab10c", "a10bc", "bcd"}, []string{"ab10c", "a10bc"})
	test([]string{"1", "a", " ", "b"}, []string{"1"})
	test([]string{"rct", "ABC", "Test", "xYz"}, []string{})
	test([]string{"this IS", "10xYZ", "xy2K77", "Z1K2W0", "xYz"}, []string{"10xYZ", "xy2K77", "Z1K2W0"})
	test([]string{"-/>", "10bc", "abc "}, []string{"10bc"})
}

func test(s, r []string) {
	p := numinstr(s)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func numinstr(s []string) []string {
	var v []string
loop:
	for _, p := range s {
		for _, r := range p {
			if unicode.IsDigit(r) {
				v = append(v, p)
				continue loop
			}
		}
	}
	return v
}
