/*

Tenpin bowling scores can range from 0 (all gutter balls) to 300 (a perfect game). If you are unfamiliar with scorekeeping, please see the Resource for a quick description.

A complete record of a 10 frame bowling game can be given as an array of the number of pins knocked down by each ball in sequence from beginning to the end of the game.

Create a function whose argument is such an array. The function should return the final score.
Examples

bowling([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]) ➞ 300

bowling([4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4]) ➞ 80

bowling([5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5]) ➞ 150

bowling([10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10]) ➞ 200

Notes

The number of balls thrown for a complete game can vary from 11 to 21 depending on the number of strikes thrown.

*/

package main

func main() {
	assert(bowl([]int{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) == 300)
	assert(bowl([]int{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}) == 80)
	assert(bowl([]int{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}) == 150)
	assert(bowl([]int{10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10}) == 200)
	assert(bowl([]int{10, 0, 10, 7, 2, 10, 10, 10, 8, 2, 9, 1, 7, 2, 10, 10, 5}) == 194)
	assert(bowl([]int{8, 0, 8, 2, 10, 10, 7, 3, 9, 1, 7, 2, 10, 10, 9, 0}) == 177)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://codereview.stackexchange.com/questions/124019/bowling-scoring-kata
func bowl(a []int) (s int) {
	defer func() {
		if err := recover(); err != nil {
			s = -1
		}
	}()

	for i, j := 0, 0; i < 10; i++ {
		switch {
		case a[j] == 10:
			s += 10 + a[j+1] + a[j+2]
			j += 1
		case a[j]+a[j+1] == 10:
			s += 10 + a[j+2]
			j += 2
		default:
			s += a[j] + a[j+1]
			j += 2
		}
	}
	return
}
