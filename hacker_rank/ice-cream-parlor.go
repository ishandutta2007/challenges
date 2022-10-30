/*

Sunny and Johnny like to pool their money and go to the ice cream parlor. Johnny never buys the same flavor that Sunny does.
The only other rule they have is that they spend all of their money.

Given a list of prices for the flavors of ice cream, select the two that will cost all of the money they have.

There will always be a unique solution.

Output Format

For each test case, print two space-separated integers denoting the indices of the two flavors purchased, in ascending order.

*/
package main

import "fmt"

func main() {
	fmt.Println(flavor([]int{1, 3, 4, 5, 6}, 6))
	fmt.Println(flavor([]int{1, 4, 5, 3, 2}, 4))
	fmt.Println(flavor([]int{2, 2, 4, 3}, 4))
}

func flavor(a []int, m int) (int, int) {
	p := make(map[int]int)
	for i, x := range a {
		y := m - x
		j, f := p[y]
		if f {
			return j + 1, i + 1
		}
		p[x] = i
	}
	return 0, 0
}
