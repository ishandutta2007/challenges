/*

Given a list of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.
For example, there are 7 socks with colors [1, 2, 1, 2, 1, 3, 2].
There is one pair of color 1 and one of color 2.
There are three odd socks left, one of each color. The number of pairs is 2.

Create a function that returns an integer representing the number of matching pairs of socks that are available.

Examples

sock_merchant([10, 20, 20, 10, 10, 30, 50, 10, 20]) ➞ 3

sock_merchant([50, 20, 30, 90, 30, 20, 50, 20, 90]) ➞ 4

sock_merchant([]) ➞ 0

Notes

N/A

*/

package main

func main() {
	assert(socks([]int{10, 20, 20, 10, 10, 30, 50, 10, 20}) == 3)
	assert(socks([]int{50, 20, 30, 90, 30, 20, 50, 20, 90}) == 4)
	assert(socks([]int{90, 20, 30, 40, 40, 20, 30, 20, 90}) == 4)
	assert(socks([]int{10, 40, 40, 40, 40, 20, 10, 10, 10}) == 4)
	assert(socks([]int{50, 40, 30, 10, 60, 60, 90, 80, 10}) == 2)
	assert(socks([]int{50, 40, 30, 100, 60, 65, 90, 80, 10}) == 0)
}

func socks(a []int) int {
	m := make(map[int]int)
	for i := range a {
		m[a[i]]++
	}

	s := 0
	for _, v := range m {
		s += v / 2
	}
	return s
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
