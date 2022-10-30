/*

Create a RegExp myRegExp to test if a string is a valid pin or not.

A valid pin has:

    Exactly 4 or 6 characters.
    Only numerical characters (0-9).
    No whitespace.

Examples

myRegExp.test("1234") ➞ true

myRegExp.test("45135") ➞ false

myRegExp.test("89abc1") ➞ false

myRegExp.test("900876") ➞ true

myRegExp.test(" 4983") ➞ false

Notes

    Empty strings should return false when tested.
    If you need help, look in the Resources tab.

*/

package main

func main() {
	assert(validate("1234") == true)
	assert(validate("45135") == false)
	assert(validate("89abc1") == false)
	assert(validate("900876") == true)
	assert(validate(" 4983") == false)
	assert(validate("123456") == true)
	assert(validate("4512a5") == false)
	assert(validate("") == false)
	assert(validate("21904") == false)
	assert(validate("9451") == true)
	assert(validate("213132") == true)
	assert(validate(" 4520") == false)
	assert(validate("15632") == false)
	assert(validate("000000") == true)
}

func validate(s string) bool {
	if len(s) != 4 && len(s) != 6 {
		return false
	}
	for _, r := range s {
		if !('0' <= r && r <= '9') {
			return false
		}
	}
	return true
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
