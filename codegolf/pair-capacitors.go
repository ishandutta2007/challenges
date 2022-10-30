/*

Capacitors are notorious for being manufactured with high tolerances. This is acceptable in many cases, but some times a capacity with tight tolerances is required.
A common strategy to get a capacity with the exact value you need is to use two carefully measured capacitors in parallel such that their capacities add up to something in the range you need.

The goal in this challenge is, given a (multi) set of capacities, to pair the capacitors such that the total capacity of each pair is in a given range.
You also need to find the best set of pairings, that is, the set of pairings such that as many pairs as possible are found.

Constraints

Input comprises in a format of choice
an unordered list of capacities representing the (multi) set of capacitors you have
a pair of capacities representing the lower and upper bound of the target range (inclusive)
all capacities in the input are positive integers smaller than 230, the unit is pF (not that that matters).
In addition to the list of capacities in the input, the set of capacitors you have also contains an infinite amount of capacitors with a value of 0 pF.
Output comprises in a format of choice a list of pairs of capacities such that the sum of each pair is in the target range specified. Neither the order of pairs nor the order of capacities within a pair is specified.
No capacity in the output may appear more often than it appears in the set of capacitors you have. In other words: The pairs you output must not overlap.
There shall be no possible output satisfying conditions 4 and 5 that contains more pairs of capacities than the output your program produces.
Your program shall terminate in O(n!) time where n is the length of the list representing the set of capacitors you have
Loopholes shall not be abused
The target range shall not be empty

Scoring

Your score is the length of your solution in octets. If your solution manages to solve this problem in polynomial time O(nk) for some k, divide your score by 10. I do not know if this is actually possible.

Sample input
range 100 to 100, input array 100 100 100, valid output:

0 100
0 100
0 100
range 100 to 120, input array 20 80 100, valid output:

0 100
20 80
the output 20 100 is not valid

range 90 to 100, input array 50 20 40 90 80 30 60 70 40, valid output:

0 90
20 80
30 70
40 60
40 50
range 90 to 90, input array 20 30 40 40 50 60 70 80 90, valid output:

0 90
20 70
30 60
40 50
range 90 to 110, input array 40 60 50, valid output:

40 60

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(100, 100, []int{100, 100, 100}, [][2]int{{0, 100}, {0, 100}, {0, 100}})
	test(100, 120, []int{20, 80, 100}, [][2]int{{0, 100}, {20, 80}})
	test(90, 100, []int{50, 20, 40, 90, 80, 30, 60, 70, 40}, [][2]int{{0, 90}, {20, 80}, {30, 70}, {40, 60}, {40, 50}})
	test(90, 90, []int{20, 30, 40, 40, 50, 60, 70, 80, 90}, [][2]int{{0, 90}, {20, 70}, {30, 60}, {40, 50}})
	test(90, 110, []int{40, 60, 50}, [][2]int{{40, 60}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b int, c []int, r [][2]int) {
	p := pairs(a, b, c)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func pairs(a, b int, c []int) [][2]int {
	sort.Ints(c)
	c = append(make([]int, len(c)), c...)

	p := [][2]int{}
	for {
		n := len(c)
		if n < 2 {
			break
		}

		v := c[0] + c[n-1]
		if a <= v && v <= b {
			p = append(p, [2]int{c[0], c[n-1]})
		}

		i, j := 0, 0
		if v <= b {
			i = 1
		}
		if a <= v {
			j = 1
		}
		c = c[i : n-j]
	}

	return p
}
