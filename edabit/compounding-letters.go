/*

Create a function that takes a string and returns a new string with each new character accumulating by +1. Separate each set with a dash.
Examples

accum("abcd") ➞ "A-Bb-Ccc-Dddd"

accum("RqaEzty") ➞ "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"

accum("cwAt") ➞ "C-Ww-Aaa-Tttt"

Notes

    Capitalize the first letter of each set.
    All tests contain valid strings with alphabetic characters (a-z, A-Z).

*/

package main

import (
	"strings"
	"unicode"
)

func main() {
	assert(accum("abcd") == "A-Bb-Ccc-Dddd")
	assert(accum("RqaEzty") == "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy")
	assert(accum("cwAt") == "C-Ww-Aaa-Tttt")
	assert(accum("VgyCdnQa") == "V-Gg-Yyy-Cccc-Ddddd-Nnnnnn-Qqqqqqq-Aaaaaaaa")
	assert(accum("nRBSdNOsMl") == "N-Rr-Bbb-Ssss-Ddddd-Nnnnnn-Ooooooo-Ssssssss-Mmmmmmmmm-Llllllllll")
	assert(accum("nuE") == "N-Uu-Eee")
	assert(accum("RlDrhZuQaqsoHEfziByObtMxkFCJVe") == "R-Ll-Ddd-Rrrr-Hhhhh-Zzzzzz-Uuuuuuu-Qqqqqqqq-Aaaaaaaaa-Qqqqqqqqqq-Sssssssssss-Oooooooooooo-Hhhhhhhhhhhhh-Eeeeeeeeeeeeee-Fffffffffffffff-Zzzzzzzzzzzzzzzz-Iiiiiiiiiiiiiiiii-Bbbbbbbbbbbbbbbbbb-Yyyyyyyyyyyyyyyyyyy-Oooooooooooooooooooo-Bbbbbbbbbbbbbbbbbbbbb-Tttttttttttttttttttttt-Mmmmmmmmmmmmmmmmmmmmmmm-Xxxxxxxxxxxxxxxxxxxxxxxx-Kkkkkkkkkkkkkkkkkkkkkkkkk-Ffffffffffffffffffffffffff-Ccccccccccccccccccccccccccc-Jjjjjjjjjjjjjjjjjjjjjjjjjjjj-Vvvvvvvvvvvvvvvvvvvvvvvvvvvvv-Eeeeeeeeeeeeeeeeeeeeeeeeeeeeee")
	assert(accum("EXpzPFx") == "E-Xx-Ppp-Zzzz-Ppppp-Ffffff-Xxxxxxx")
	assert(accum("NU") == "N-Uu")
	assert(accum("g") == "G")
}

func accum(s string) string {
	p := new(strings.Builder)
	n := 1
	for _, r := range s {
		if n > 1 {
			p.WriteRune('-')
		}
		p.WriteRune(unicode.ToUpper(r))
		r = unicode.ToLower(r)
		for i := 1; i < n; i++ {
			p.WriteRune(r)
		}
		n++
	}
	return p.String()
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
