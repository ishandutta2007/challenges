/*

Create a function which converts an ordered number array into a array of ranges (represented as strings). Note how some arrays have some numbers missing.

Examples

numbersToRanges([1, 2, 3, 4, 5]) ➞ ["1-5"]

numbersToRanges([3, 4, 5, 10, 11, 12]) ➞ ["3-5", "10-12"]

numbersToRanges([1, 2, 3, 4, 99, 100]) ➞ ["1-4", "99-100"]

numbersToRanges([1, 3, 4, 5, 6, 7, 8]) ➞ ["1", "3-8"]

Notes

    If there are no numbers consecutive to a number in the array, represent it as only the string version of that number (see example #4).
    Return an empty array if the given array is empty.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2, 3, 4, 5}, []string{"1-5"})
	test([]int{6, 7, 8, 10, 11, 12}, []string{"6-8", "10-12"})
	test([]int{1, 2, 3, 6, 7, 8}, []string{"1-3", "6-8"})
	test([]int{1}, []string{"1"})
	test([]int{3, 4, 5, 10, 11, 12}, []string{"3-5", "10-12"})
	test([]int{1, 2, 3, 4, 99, 100}, []string{"1-4", "99-100"})
	test([]int{}, []string{})
}

func test(a []int, r []string) {
	p := ranges(a)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ranges(a []int) []string {
	var p []string
	for i := 0; i < len(a); {
		j := i + 1
		for j < len(a) && a[j]-a[j-1] == 1 {
			j++
		}
		if i == j-1 {
			p = append(p, fmt.Sprint(a[i]))
		} else {
			p = append(p, fmt.Sprintf("%d-%d", a[i], a[j-1]))
		}
		i = j
	}
	return p
}
