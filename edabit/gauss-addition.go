/*

Watch the video about Gauss's Addition in the Resources tab to see how you can use the formula for your function.

Gauss

Create a function that adds all the numbers together from 1 to n or, if two numbers are given: n to m. The input can be in any order.

Examples

gauss([100]) ➞ 5050 # From the video

gauss([5001, 7000]) ➞ 12001000 # Also ^^

gauss([1975, 165]) ➞ 1937770

Notes

    Try not to use a for or while loop.
    Try not to create a recursive function.
    Use the formula explained in the video.

*/

package main

func main() {
	assert(gauss([]int64{100}) == 5050)
	assert(gauss([]int64{1, 100}) == 5050)
	assert(gauss([]int64{5000}) == 12502500)
	assert(gauss([]int64{5001, 7000}) == 12001000)
	assert(gauss([]int64{3, 5}) == 12)
	assert(gauss([]int64{1800, 250}) == 1589775)
	assert(gauss([]int64{1, 5000}) == 12502500)
	assert(gauss([]int64{5, 500}) == 125240)
	assert(gauss([]int64{1975, 165}) == 1937770)
	assert(gauss([]int64{50000}) == 1250025000)
	assert(gauss([]int64{28, 123}) == 7248)
	assert(gauss([]int64{7000, 5001}) == 12001000)
	assert(gauss([]int64{0, 100}) == 5050)
	assert(gauss([]int64{5000, 1}) == 12502500)
	assert(gauss([]int64{100, 1}) == 5050)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gauss(a []int64) int64 {
	var n, m int64
	switch len(a) {
	case 1:
		m = a[0]
	case 2:
		n, m = a[0], a[1]
	}
	if n > m {
		n, m = m, n
	}
	if n > 0 {
		n--
	}

	x := n * (n + 1) / 2
	y := m * (m + 1) / 2
	return y - x
}
