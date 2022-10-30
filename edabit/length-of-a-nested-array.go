/*

The .length property on an array will return the number of elements in the array. For example, the array below contains 2 elements:

[1, [2, 3]]
// 2 elements, number 1 and array [2, 3]

Suppose we instead wanted to know the total number of non-nested items in the nested array. In the above case, [1, [2, 3]] contains 3 non-nested items, 1, 2 and 3.

Write a function that returns the total number of non-nested items in a nested array.
Examples

getLength([1, [2, 3]]) ➞ 3

getLength([1, [2, [3, 4]]]) ➞ 4

getLength([1, [2, [3, [4, [5, 6]]]]]) ➞ 6

getLength([1, [2], 1, [2], 1]) ➞ 5

Notes

An empty array should return 0.

*/

package main

type any []interface{}

func main() {
	assert(length(any{1, any{2, 3}}) == 3)
	assert(length(any{1, any{2, any{3, 4}}}) == 4)
	assert(length(any{1, any{2, any{3, any{4, any{5, 6}}}}}) == 6)
	assert(length(any{1, any{2}, 1, any{2}, 1}) == 5)
	assert(length(any{1, 7, 8}) == 3)
	assert(length(any{2}) == 1)
	assert(length(any{2, any{3}, 4, any{7}}) == 4)
	assert(length(any{2, any{3, any{5, any{7}}}, 4, any{9}}) == 6)
	assert(length(any{2, any{3, any{4, any{5}}}, any{9}}) == 5)
	assert(length(any{}) == 0)
}

func length(a any) int {
	n := 0
	for _, p := range a {
		switch x := p.(type) {
		case any:
			n += length(x)
		case int:
			n++
		default:
			panic("unreachable")
		}
	}
	return n
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
