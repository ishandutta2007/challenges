/*

There are N balloons floating in the air in a large room, lined up from left to right.
Young Perica likes to play with arrows and practice his hunting abilities.
He shoots an arrow from the left to the right side of the room from an arbitrary height he chooses.
The arrow moves from left to right, at a chosen height H until it finds a balloon.
The moment when an arrow touches a balloon, the balloon pops and disappears and the arrow continues its way from left to right at a height decreased by 1.
Therefore, if the arrow was moving at height H, after popping the balloon it travels on height H−1.

Our hero’s goal is to pop all the balloons using as little arrows as possible.

Input

The first line of input contains the integer N (1≤N≤1 000 000).
The second line of input contains an array of N integers Hi.
Each integer Hi (1≤Hi≤1 000 000) is the height at which the i-th balloon floats, respectively from left to right.

Output

The first and only line of output must contain the minimal number of times Pero needs to shoot an arrow so that all balloons are popped.

*/

package main

func main() {
	assert(arrows([]int{2, 1, 5, 4, 3}) == 2)
	assert(arrows([]int{1, 2, 3, 4, 5}) == 5)
	assert(arrows([]int{4, 5, 2, 1, 4}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func arrows(a []int) int {
	m := make(map[int]int)
	c := 0
	for _, v := range a {
		if m[v] != 0 {
			m[v]--
		} else {
			c++
		}
		m[v-1]++
	}
	return c
}
