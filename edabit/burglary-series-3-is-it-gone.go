/*

Your spouse is not concerned with the loss of material possessions but rather with his/her favorite pet. Is it gone?!

Given an object of the stolen items and a string in lower cases representing the name of the pet (e.g. "rambo"), return:

    "Rambo is gone..." if the name is on the list.
    "Rambo is here!" if the name is not on the list.

Note that the first letter of the name in the return statement is capitalized.
Examples

const obj = {
  tv: 30,
  timmy: 20,
  stereo: 50,
} ➞ "Timmy is gone..."
// Timmy is in the object.


const obj = {
  tv: 30,
  stereo: 50,
} ➞ "Timmy is here!"
// Timmy is not in the stolen list object.


const obj = { } ➞ "Timmy is here!"
// Timmy is not in the object.

Notes

N/A

*/

package main

import (
	"fmt"
	"strings"
	"unicode"
	"unicode/utf8"
)

func main() {
	assert(gone(map[string]int{}, "rambo") == "Rambo is here!")
	assert(gone(map[string]int{}, "heman") == "Heman is here!")
	assert(gone(map[string]int{"tv": 30, "stereo": 50}, "rocky") == "Rocky is here!")
	assert(gone(map[string]int{"tv": 30, "stereo": 50}, "spiderman") == "Spiderman is here!")
	assert(gone(map[string]int{"tv": 30, "stereo": 50, "julius": 100}, "julius") == "Julius is gone...")
	assert(gone(map[string]int{"tv": 30, "stereo": 50, "batman": 200}, "batman") == "Batman is gone...")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gone(m map[string]int, o string) string {
	r, w := utf8.DecodeRuneInString(o)
	_, f := m[strings.ToLower(o)]
	if f {
		return fmt.Sprintf("%c%s is gone...", unicode.ToUpper(r), o[w:])
	}
	return fmt.Sprintf("%c%s is here!", unicode.ToUpper(r), o[w:])
}
