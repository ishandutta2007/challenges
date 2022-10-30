/*

I was browsing Stack Overflow when I saw this post in Puzzling in the hot network questions and decided to make a challenge out of it (all credit goes to the creator of the challenge).

Overview
A Chess Number is a number that, when converted to base 18, results in a valid chess coordinate pair, where the first character is a-h and the second character is 1-8 (inclusive).
Your job is to generate the full list of them, ordered. Output may be an array/list, printed individually, as a matrix/grid, or in a string. The numbers must be in decimal, not base 18.

Examples

Here is a Python program to generate the full list:

def baseN(num, b, numerals = "0123456789abcdefghijklmnopqrstuvwxyz"):
    return ((num == 0) and numerals[0]) or (baseN(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b])

for i in range(0, 10000):
    s = baseN(i, 18)
    if len(s) == 2 and s[0].isalpha() and s[1].isdigit() and 0 < int(s[1]) < 9:
        print(i, s)
Try it online!

The complete list is:

181, 182, 183, 184, 185, 186, 187, 188, 199, 200, 201, 202, 203, 204, 205, 206, 217, 218, 219, 220, 221, 222, 223, 224, 235, 236, 237, 238, 239, 240, 241, 242, 253, 254, 255, 256, 257, 258, 259, 260, 271, 272, 273, 274, 275, 276, 277, 278, 289, 290, 291, 292, 293, 294, 295, 296, 307, 308, 309, 310, 311, 312, 313, 314

*/

package main

import (
	"reflect"
	"strconv"
)

func main() {
	m := []int{181, 182, 183, 184, 185, 186, 187, 188, 199, 200, 201, 202, 203, 204, 205, 206, 217, 218, 219, 220, 221, 222, 223, 224, 235, 236, 237, 238, 239, 240, 241, 242, 253, 254, 255, 256, 257, 258, 259, 260, 271, 272, 273, 274, 275, 276, 277, 278, 289, 290, 291, 292, 293, 294, 295, 296, 307, 308, 309, 310, 311, 312, 313, 314}
	assert(reflect.DeepEqual(m, gen()))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen() []int {
	var r []int
	for i := 0; i < 10000; i++ {
		s := strconv.FormatInt(int64(i), 18)
		if ismove(s) {
			r = append(r, i)
		}
	}
	return r
}

func ismove(s string) bool {
	if len(s) != 2 {
		return false
	}
	if !('a' <= s[0] && s[0] <= 'h') {
		return false
	}
	if !('1' <= s[1] && s[1] <= '8') {
		return false
	}
	return true
}
