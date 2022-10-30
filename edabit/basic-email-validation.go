/*

Create a function that accepts a string, checks if it's a valid email address and returns either true or false, depending on the evaluation.

    The string must contain an @ character.
    The string must contain a . character.
    The @ must have at least one character in front of it.
        e.g. "e@edabit.com" is valid while "@edabit.com" is invalid.
    The . and the @ must be in the appropriate places.
        e.g. "hello.email@com" is invalid while "john.smith@email.com" is valid.

If the string passes these tests, it's considered a valid email address.
Examples

validateEmail("@gmail.com") ➞ false

validateEmail("hello.gmail@com") ➞ false

validateEmail("gmail") ➞ false

validateEmail("hello@gmail") ➞ false

validateEmail("hello@edabit.com") ➞ true

Notes

    Check the Tests tab to see exactly what's being evaluated.
    You can solve this challenge with RegEx, but it's intended to be solved with logic.
    Solutions using RegEx will be accepted but frowned upon :(

*/

package main

import "regexp"

func main() {
	assert(validate("@gmail.com") == false)
	assert(validate("hello.gmail@com") == false)
	assert(validate("gmail") == false)
	assert(validate("hello@gmail") == false)
	assert(validate("hello@edabit.com") == true)
	assert(validate("@edabit.com") == false)
	assert(validate("@edabit") == false)
	assert(validate("matt@edabit.com") == true)
	assert(validate("") == false)
	assert(validate("hello.gmail@com") == false)
	assert(validate("matt@edabit.com") == true)
	assert(validate("bill.gates@microsoft.com") == true)
	assert(validate("hello@email") == false)
	assert(validate("%^%$#%^%") == false)
	assert(validate("www.email.com") == false)
	assert(validate("email") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://stackoverflow.com/questions/201323/how-to-validate-an-email-address-using-a-regular-expression
func validate(s string) bool {
	const pattern = "(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|\"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*\")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\\[(?:(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9]))\\.){3}(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\\])"
	m, _ := regexp.MatchString(pattern, s)
	return m
}
