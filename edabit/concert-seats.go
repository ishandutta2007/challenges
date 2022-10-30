/*

Create a function that determines whether each seat can "see" the front-stage. A number can "see" the front-stage if it is strictly greater than the number before it.

Everyone can see the front-stage in the example below:

# FRONT STAGE
[[1, 2, 3, 2, 1, 1],
[2, 4, 4, 3, 2, 2],
[5, 5, 5, 5, 4, 4],
[6, 6, 7, 6, 5, 5]]

# Starting from the left, the 6 > 5 > 2 > 1, so all numbers can see.
# 6 > 5 > 4 > 2 - so all numbers can see, etc.

Not everyone can see the front-stage in the example below:

# FRONT STAGE
[[1, 2, 3, 2, 1, 1],
[2, 4, 4, 3, 2, 2],
[5, 5, 5, 10, 4, 4],
[6, 6, 7, 6, 5, 5]]

# The 10 is directly in front of the 6 and blocking its view.

The function should return True if every number can see the front-stage, and False if even a single number cannot.
Examples

can_see_stage([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]) ➞ True

can_see_stage([
  [0, 0, 0],
  [1, 1, 1],
  [2, 2, 2]
]) ➞ True

can_see_stage([
  [2, 0, 0],
  [1, 1, 1],
  [2, 2, 2]
]) ➞ False

can_see_stage([
  [1, 0, 0],
  [1, 1, 1],
  [2, 2, 2]
]) ➞ False

# Number must be strictly smaller than
# the number directly behind it.

Notes

    Numbers must be strictly greater than the number in front of it.
    All numbers within the lists will be whole numbers greater than or equal to zero.

*/

package main

func main() {
	test([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}, true)

	test([][]int{
		{1, 1, 2},
		{5, 2, 3},
		{4, 4, 4},
	}, false)

	test([][]int{
		{1, 1, 2},
		{5, 2, 3},
		{6, 4, 4},
	}, true)

	test([][]int{
		{0, 0, 0},
		{1, 1, 1},
		{2, 2, 2},
	}, true)

	test([][]int{
		{2, 0, 0},
		{1, 1, 1},
		{2, 2, 2},
	}, false)

	test([][]int{
		{1, 0, 0},
		{1, 1, 1},
		{2, 2, 2},
	}, false)

	test([][]int{
		{1, 2, 3, 2, 1, 1},
		{2, 4, 4, 3, 2, 2},
		{5, 5, 5, 5, 4, 4},
		{6, 6, 7, 6, 5, 5},
	}, true)

	test([][]int{
		{1, 2, 3, 2, 1, 1},
		{2, 4, 4, 3, 2, 2},
		{5, 5, 5, 10, 4, 4},
		{6, 6, 7, 6, 5, 5},
	}, false)
}

func seestage(a [][]int) bool {
	for i := len(a) - 1; i > 0; i-- {
		for j := 0; j < len(a); j++ {
			if a[i][j] <= a[i-1][j] {
				return false
			}
		}
	}
	return true
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a [][]int, r bool) {
	assert(seestage(a) == r)
}
