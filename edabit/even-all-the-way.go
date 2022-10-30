/*

Given an array of numbers, return an array which contains all the even numbers in the orginal array, which also have even indices.
Examples

getOnlyEvens([1, 3, 2, 6, 4, 8]) ➞ [2, 4]

getOnlyEvens([0, 1, 2, 3, 4]) ➞ [0, 2, 4]

getOnlyEvens([1, 2, 3, 4, 5]) ➞ []

Notes

Arrays start at index 0.

*/

package main

func main() {
	eq(evens([]int{1, 3, 2, 6, 4, 8}), []int{2, 4})
	eq(evens([]int{0, 1, 2, 3, 4}), []int{0, 2, 4})
	eq(evens([]int{1, 2, 3, 4, 5}), []int{})
	eq(evens([]int{37, 26, 18, 42, 2, 30}), []int{18, 2})
	eq(evens([]int{49, 41, 30, 44, 26, 0, 5}), []int{30, 26})
	eq(evens([]int{47, 47, 12, 3, 48}), []int{12, 48})
	eq(evens([]int{30, 26, 0, 13, 20, 38, 50, 2}), []int{30, 0, 20, 50})
	eq(evens([]int{34, 21, 38, 28, 13, 8, 26, 29, 24, 5}), []int{34, 38, 26, 24})
	eq(evens([]int{47, 31, 24, 37, 29, 41, 31, 49, 4, 24}), []int{24, 4})
	eq(evens([]int{45, 47, 20, 49}), []int{20})
	eq(evens([]int{20, 14, 10, 32, 28, 6, 49, 5, 46}), []int{20, 10, 28, 46})
	eq(evens([]int{39, 45, 5}), []int{})
	eq(evens([]int{45, 3, 50, 15, 49}), []int{50})
	eq(evens([]int{45, 25, 10, 47, 24, 30, 28, 48}), []int{10, 24, 28})
	eq(evens([]int{10, 16, 9, 40, 28, 21, 37, 4, 45}), []int{10, 28})
	eq(evens([]int{31, 25, 19, 49, 50, 22}), []int{50})
	eq(evens([]int{38, 36, 8, 34, 8, 45, 4, 45, 2, 9}), []int{38, 8, 8, 4, 2})
	eq(evens([]int{38, 21, 50, 14}), []int{38, 50})
	eq(evens([]int{24, 16, 32, 14, 32, 42, 13, 33, 13, 39}), []int{24, 32, 32})
	eq(evens([]int{38, 24, 4, 49, 5, 33, 1, 10, 3}), []int{38, 4})
	eq(evens([]int{46}), []int{46})
	eq(evens([]int{13, 6, 12, 23, 31, 14, 2}), []int{12, 2})
	eq(evens([]int{7, 1, 34, 14, 26, 3, 7, 7}), []int{34, 26})
	eq(evens([]int{31, 11, 26, 19, 45, 12}), []int{26})
	eq(evens([]int{22}), []int{22})
	eq(evens([]int{29, 11}), []int{})
	eq(evens([]int{6, 6, 37, 10, 4}), []int{6, 4})
	eq(evens([]int{6, 46, 12, 47, 49, 26, 40, 28, 38}), []int{6, 12, 40, 38})
	eq(evens([]int{31}), []int{})
	eq(evens([]int{28, 44, 4, 31, 30, 46, 37}), []int{28, 4, 30})
	eq(evens([]int{24}), []int{24})
	eq(evens([]int{23, 41, 49, 5, 0, 46, 15, 15}), []int{0})
	eq(evens([]int{44, 39, 15}), []int{44})
}

func evens(a []int) []int {
	var p []int
	for i := 0; i < len(a); i += 2 {
		if a[i]&1 == 0 {
			p = append(p, a[i])
		}
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b []int) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}
