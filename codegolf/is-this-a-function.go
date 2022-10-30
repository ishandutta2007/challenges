/*

Given a list of (key, value) pairs, determine whether it represents a function, meaning that each key maps to a consistent value. In other words, whenever two entries have equal keys, they must also have equal values. Repeated entries are OK.

For example:

# Not a function: 3 maps to both 1 and 6
[(3,1), (2,5), (3,6)]

# Function: It's OK that (3,5) is listed twice, and that both 6 and 4 both map to 4
[(3,5), (3,5), (6,4), (4,4)]
Input: An ordered sequence of (key, value) pairs using digits 1 to 9. You may not require a particular ordering. You may alternatively take the key list and value list as separate inputs.

Output: A consistent value for functions, and a different consistent value for non-functions.

Test cases: The first 5 inputs are functions, the last 5 are not.

[(3, 5), (3, 5), (6, 4), (4, 4)]
[(9, 4), (1, 4), (2, 4)]
[]
[(1, 1)]
[(1, 2), (2, 1)]

[(3, 1), (2, 5), (3, 6)]
[(1, 2), (2, 1), (5, 2), (1, 2), (2, 5)]
[(8, 8), (8, 8), (8, 9), (8, 9)]
[(1, 2), (1, 3), (1, 4)]
[(1, 2), (1, 3), (2, 3), (2, 4)]

Here they are as two lists of inputs:

[[(3, 5), (3, 5), (6, 4), (4, 4)], [(9, 4), (1, 4), (2, 4)], [], [(1, 1)], [(1, 2), (2, 1)]]
[[(3, 1), (2, 5), (3, 6)], [(1, 2), (2, 1), (5, 2), (1, 2), (2, 5)], [(8, 8), (8, 8), (8, 9), (8, 9)], [(1, 2), (1, 3), (1, 4)], [(1, 2), (1, 3), (2, 3), (2, 4)]]

*/

package main

func main() {
	assert(function([][2]int{
		{3, 5},
		{3, 5},
		{6, 4},
		{4, 4},
	}) == true)

	assert(function([][2]int{
		{9, 4},
		{1, 4},
		{2, 4},
	}) == true)

	assert(function([][2]int{}) == true)
	assert(function([][2]int{{1, 1}}) == true)
	assert(function([][2]int{{1, 2}, {2, 1}}) == true)

	assert(function([][2]int{
		{3, 1},
		{2, 5},
		{3, 6},
	}) == false)

	assert(function([][2]int{
		{1, 2},
		{2, 1},
		{5, 2},
		{1, 2},
		{2, 5},
	}) == false)

	assert(function([][2]int{
		{8, 8},
		{8, 8},
		{8, 9},
		{8, 9},
	}) == false)

	assert(function([][2]int{
		{1, 2},
		{1, 3},
		{1, 4},
	}) == false)

	assert(function([][2]int{
		{1, 2},
		{1, 3},
		{2, 3},
		{2, 4},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func function(a [][2]int) bool {
	m := make(map[int]int)
	for _, v := range a {
		x, y := v[0], v[1]
		if _, f := m[x]; !f {
			m[x] = y
		} else if m[x] != y {
			return false
		}
	}
	return true
}
