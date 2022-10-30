/*

In mathematics, interval is the difference between the largest number and the smallest number in a list.

To illustrate:

A = (3, 5, 7, 23, 11, 42, 80)

Interval of A = 80 - 3 = 77

Create a function that takes a list and returns ":)" if the interval of the list is equal to any other element; otherwise return ":(".
Examples

face_interval([1, 2, 5, 8, 3, 9]) ➞ ":)"
# List interval is equal to one of the other elements.

face_interval([5, 2, 8, 3, 11]) ➞ ":("
# List interval is not among the other elements.

face_interval("bruh") ➞ ":/"
# "bruh" is not a list. It's string.

Notes

    Lists won't contain any duplicate numbers.
    If you're not given a list, return ":/"

*/

package main

import "fmt"

func main() {
	test([]int{1, 2, 5, 8, 3, 9}, ":)")
	test([]int{5, 2, 6, 3, 11}, ":(")
	test([]int{20, 50, 13, 60, 79, 72, 99}, ":(")
	test([]int{11, 42, 83, 28, 47, 94}, ":)")
	test("bruh", ":/")
}

func test(a interface{}, r string) {
	p := face(a)
	fmt.Println(p)
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func face(a interface{}) string {
	p, ok := a.([]int)
	if !ok || len(p) == 0 {
		return ":/"
	}

	x, y := p[0], p[0]
	for i := 1; i < len(p); i++ {
		x = min(x, p[i])
		y = max(y, p[i])
	}

	l := y - x
	for i := range p {
		if p[i] == l {
			return ":)"
		}
	}

	return ":("
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
