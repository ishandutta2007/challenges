/*

Mubashir needs your help to compare two arrays.

First array arr1 contains some numbers and second array arr2 contains squared values of numbers given in the first array.

Create a function which takes these two arrays and returns true if all square values are available, false otherwise.

arr1 = [121, 144, 19, 161, 19, 144, 19, 11]
arr2 = [121, 14641, 20736, 361, 25921, 361, 20736, 361]

Returns true because 121 is square of 11, 14641 is square of 121, 20736 is square of 144, 361 is square of 19, 25921 the square of 161, and so on...

arr1 = [121, 144, 19, 161, 19, 144, 19, 11]
arr2 = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]

Examples

simpleComp([121, 144, 19, 161, 19, 144, 19, 11], [121, 14641, 20736, 361, 25921, 361, 20736, 361]) ➞ true

simpleComp([4, 4], [1, 31]) ➞ false

simpleComp([2, 2, 3], [4, 4, 9]) ➞ true

Notes

Numbers can be in any order.

*/

package main

func main() {
	a1 := []int{121, 144, 19, 161, 19, 144, 19, 11}
	b1 := []int{11 * 11, 121 * 121, 144 * 144, 19 * 19, 161 * 161, 19 * 19, 144 * 144, 19 * 19}

	a2 := []int{4, 4}
	b2 := []int{1, 31}

	a3 := []int{121, 144, 19, 161, 19, 144, 19, 11}
	b3 := []int{11 * 21, 121 * 121, 144 * 144, 19 * 19, 161 * 161, 19 * 19, 144 * 144, 19 * 19}

	a4 := []int{121, 144, 19, 161, 19, 144, 19, 11}
	b4 := []int{11 * 11, 121 * 121, 144 * 144, 190 * 190, 161 * 161, 19 * 19, 144 * 144, 19 * 19}

	a5 := []int{}
	b5 := []int{}

	a6 := []int{}
	b6 := []int(nil)

	a7 := []int{121, 144, 19, 161, 19, 144, 19, 11, 1008}
	b7 := []int{11 * 11, 121 * 121, 144 * 144, 190 * 190, 161 * 161, 19 * 19, 144 * 144, 19 * 19}

	a8 := []int{10000000, 100000000}
	b8 := []int{10000000 * 10000000, 100000000 * 100000000}

	a9 := []int{10000001, 100000000}
	b9 := []int{10000000 * 10000000, 100000000 * 100000000}

	a10 := []int{2, 2, 3}
	b10 := []int{4, 9, 9}

	a11 := []int(nil)
	b11 := []int{}

	a12 := []int{}
	b12 := []int{1}

	a13 := []int{-121, -144, 19, -161, 19, -144, 19, -11}
	b13 := []int{11 * 11, 121 * 121, 144 * 144, 19 * 19, 161 * 161, 19 * 19, 144 * 144, 19 * 19}

	a14 := []int{42}
	b14 := []int{42}

	assert(simple(a1, b1) == true)
	assert(simple(a2, b2) == false)
	assert(simple(a3, b3) == false)
	assert(simple(a4, b4) == false)
	assert(simple(a5, b5) == true)
	assert(simple(a6, b6) == false)
	assert(simple(a7, b7) == false)
	assert(simple(a8, b8) == true)
	assert(simple(a9, b9) == false)
	assert(simple(a10, b10) == false)
	assert(simple(a11, b11) == false)
	assert(simple(a12, b12) == false)
	assert(simple(a13, b13) == true)
	assert(simple(a14, b14) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func simple(a, b []int) bool {
	if a == nil && b != nil || a != nil && b == nil {
		return false
	}

	m := make(map[int]int)
	for _, v := range a {
		m[v*v]++
	}
	for _, v := range b {
		if m[v] == 0 {
			return false
		}
		m[v]--
	}
	return true
}
