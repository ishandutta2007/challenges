/*

Write a function that returns true if all subsets in a list belong to a given set.

Examples

validateSubsets([[1, 2], [2, 3], [1, 3]], [1, 2, 3]) ➞ true

validateSubsets([[1, 2, 3], [2], [3], []], [1, 2, 3]) ➞ true

validateSubsets([[1, 2], [2, 3], [1, 4]], [1, 2, 3]) ➞ false

validateSubsets([[1, 2, 3, 4]], [1, 2, 3]) ➞ false

Notes

    The empty set and the set itself are both valid subsets of a set (we are not talking about proper subsets here).
    The set and the subset will each have unique elements.

*/

package main

func main() {
	assert(validate([][]int{{1, 2}, {2, 3}, {1, 3}}, []int{1, 2, 3}) == true)
	assert(validate([][]int{{1, 2, 3}, {2}, {3}, {}}, []int{1, 2, 3}) == true)
	assert(validate([][]int{{1, 2}, {2, 3}, {1, 4}}, []int{1, 2, 3}) == false)
	assert(validate([][]int{{1, 2, 3, 4}}, []int{1, 2, 3}) == false)
	assert(validate([][]int{{'a', 'b'}, {'b', 'c'}, {'a', 'c'}}, []int{'a', 'b', 'c'}) == true)
	assert(validate([][]int{{'a', 'b', 'c'}, {'b'}, {'c'}, {}}, []int{'a', 'b', 'c'}) == true)
	assert(validate([][]int{{'a', 'b'}, {'b', 'c'}, {'a', 'd'}}, []int{'a', 'b', 'c'}) == false)
	assert(validate([][]int{{'a', 'b', 'c', 'd'}}, []int{'a', 'b', 'c'}) == false)
	assert(validate([][]int{{1, 0}, {1}}, []int{1, 0}) == true)
	assert(validate([][]int{{1}, {0}, {}}, []int{1, 0}) == true)
	assert(validate([][]int{{1}, {1, 0}}, []int{1}) == false)
	assert(validate([][]int{{0}}, []int{1}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func validate(a [][]int, s []int) bool {
	m := make(map[int]bool)
	for _, v := range s {
		m[v] = true
	}
	for _, p := range a {
		for _, v := range p {
			if !m[v] {
				return false
			}
		}
	}
	return true
}
