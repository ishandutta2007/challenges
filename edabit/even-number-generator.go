/*

Using list comprehensions, create a function that finds all even numbers from 1 to the given number.

Examples

find_even_nums(8) ➞ [2, 4, 6, 8]

find_even_nums(4) ➞ [2, 4]

find_even_nums(2) ➞ [2]

Try to use list comprehensions in your solution. Here's an example:

vals = [expression
  for value in collection
    if condition]

This is equivalent to:

vals = []
for value in collection:
  if condition:
    vals.append(expression)

Notes

    Try to use list comprehensions instead of logic.
    If there are no even numbers, return an empty list.

*/

package main

import "reflect"

func main() {
	test(4, []int{2, 4})
	test(8, []int{2, 4, 6, 8})
	test(2, []int{2})
	test(1, []int{})
	test(9, []int{2, 4, 6, 8})
	test(11, []int{2, 4, 6, 8, 10})
}

func test(n int, r []int) {
	p := evens(n)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func evens(n int) []int {
	r := []int{}
	for i := 2; i <= n; i += 2 {
		r = append(r, i)
	}
	return r
}
