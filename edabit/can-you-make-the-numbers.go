/*

You are given an array representing the number of 0s, 1s, 2s, ..., 9s you have. The function will look like:

can_build([#0s, #1s, #2s, ..., #9s], [num1, num2, ...])

Write a function that returns true if you can build the following numbers using only the digits you have.
Examples

canBuild([0, 1, 2, 2, 3, 0, 0, 0, 1, 1], [123, 444, 92]) ➞ true

// You have: one 1, two 2s, two 3s, three 4s, one 8 and one 9
// Using only these digits, you can build 123, 444, and 92

canBuild([10, 2, 3, 8, 5, 8, 5, 5, 3, 1], [11, 2, 22, 49, 444, 998, 87, 44]) ➞ false

canBuild([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], []) ➞ true

canBuild([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [3]) ➞ false

Notes

N/A

*/

package main

func main() {
	assert(build([]uint{0, 1, 2, 2, 3, 0, 0, 0, 1, 1}, []uint{123, 444, 92}) == true)
	assert(build([]uint{10, 2, 3, 8, 5, 8, 5, 5, 3, 1}, []uint{11, 2, 22, 49, 444, 998, 87, 44}) == false)
	assert(build([]uint{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, []uint{}) == true)
	assert(build([]uint{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, []uint{3}) == false)
	assert(build([]uint{1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, []uint{1, 8}) == true)
	assert(build([]uint{1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, []uint{1, 80}) == true)
	assert(build([]uint{0, 1, 2, 2, 3, 0, 0, 0, 1, 1}, []uint{123, 444, 92}) == true)
	assert(build([]uint{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, []uint{10, 23, 45, 6789}) == true)
	assert(build([]uint{0, 2, 3, 0, 5, 0, 0, 0, 0, 1}, []uint{11, 2, 22, 49, 444, 4}) == true)
	assert(build([]uint{1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, []uint{1, 80, 0}) == false)
	assert(build([]uint{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, []uint{1}) == false)
	assert(build([]uint{0, 2, 3, 0, 5, 0, 0, 0, 0, 1}, []uint{11, 7, 2, 22, 49, 444, 4}) == false)
	assert(build([]uint{0, 2, 3, 0, 5, 0, 0, 0, 0, 1}, []uint{11, 2, 22, 49, 444, 44}) == false)
	assert(build([]uint{10, 2, 3, 8, 5, 8, 5, 5, 3, 1}, []uint{11, 2, 22, 49, 444, 998, 87, 44}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func build(x, y []uint) bool {
	for _, v := range y {
		for {
			n := v % 10
			if x[n] == 0 {
				return false
			}
			x[n]--

			if v /= 10; v == 0 {
				break
			}
		}
	}
	return true
}
