/*

Write a function that takes an array of strings of arbitrary dimensionality ([], [][], [][][], etc.) and returns the sum of every separate number in each string in the array.

Examples

sum(["1", "five", "2wenty", "thr33"]) ➞ 36

sum([["1X2", "t3n"],["1024", "5", "64"]]) ➞ 1099

sum([[["1"], "10v3"], ["738h"], [["s0"], ["1mu4ch3"],"-1s0"]]) ➞ 759

Notes

    Numbers in strings can be negative, but will all be base-10 integers.
    Negative numbers may directly follow another number.
    The hyphen or minus character ("-") does not only occur in numbers.
    Arrays may be ragged or empty.

*/

package main

import (
	"strconv"
)

func main() {
	assert(sum(any{"1", "five", "2wenty", "thr33"}) == 36)
	assert(sum(any{any{"1X2", "t3n"}, any{"1024", "5", "64"}}) == 1099)
	assert(sum(any{any{any{"1"}, "10v3"}, any{"738"}, any{any{"s0"}, any{"1mu4ch3"}, "-1s0"}}) == 759)
	assert(sum(any{any{any{"0", "0x2", "z3r1"}, any{"1", "55a46"}}, any{any{"1", "0b2", "4"}, any{"0x5fp-2", "nine", "09"}, any{"4", "4", "4"}}, any{any{"03"}}, any{}}) == 142)
	assert(sum(any{any{any{any{any{any{any{any{any{any{any{any{any{any{any{any{"-1", "1"}, any{"3"}, any{""}, any{}}}}}}}}}}}}}}}}) == 3)
	assert(sum(any{any{any{any{any{any{any{any{any{any{any{any{any{any{any{any{}}}}}}}}}}}}}}}}) == 0)
	assert(sum(any{any{any{any{any{any{"-32-64", "a-zA-Z"}, any{"01-1"}}}}}}) == -96)
	assert(sum(any{"---"}) == 0)
	assert(sum(any{"4---54"}) == -50)
	assert(sum(any{"-4--+5"}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type any []interface{}

func sum(a any) int {
	r := 0
	for _, v := range a {
		switch v := v.(type) {
		case any:
			r += sum(v)
		case string:
			r += count(v)
		}
	}
	return r
}

func count(s string) int {
	r := 0
	n := len(s)
	for i := 0; i < n; i++ {
		j := i
		if s[i] == '-' {
			j++
		}
		for j < n && isdigit(s[j]) {
			j++
		}
		if i != j {
			v, _ := strconv.Atoi(s[i:j])
			r = r + v
			i = j - 1
		}
	}
	return r
}

func isdigit(b byte) bool {
	return '0' <= b && b <= '9'
}
