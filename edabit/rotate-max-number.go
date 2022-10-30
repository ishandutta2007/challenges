/*

Create a function which takes a number and returns the maximum value by rearranging its digits.
Examples

rotateMaxNumber(123) ➞ 321

rotateMaxNumber("001") ➞ 100

rotateMaxNumber(999) ➞ 999

Notes

The input number can be a digit or a string.

*/

package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {
	assert(rmn(123) == 321)
	assert(rmn(1546) == 6541)
	assert(rmn("001") == 100)
	assert(rmn(999) == 999)
	assert(rmn("12345") == 54321)
	assert(rmn("00009") == 90000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rmn(v interface{}) int {
	b := itob(v)
	sort.Slice(b, func(i, j int) bool {
		return b[i] > b[j]
	})
	n, _ := strconv.Atoi(string(b))
	return n
}

func itob(v interface{}) []byte {
	switch v := v.(type) {
	case int:
		return []byte(fmt.Sprint(v))
	case string:
		return []byte(v)
	}
	return []byte{}
}
