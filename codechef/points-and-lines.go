/*

Given N points of the form (xi,yi) on a 2-D plane.

From each point, you draw 2 lines one horizontal and one vertical. Now some of the lines may overlap each other, therefore you are required to print the number of distinct lines you can see on the plane.

Note:

Two horizontal lines are distinct if they pass through different y coordinates.
Two vertical lines are distinct if they pass through different x coordinates.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a single integer N, the number of points.
The next N lines contain two space separated integers xi,yi, the coordinate of the ith point.

Output Format

For each testcase, output in a single line the number of distinct lines that can be seen on the plane.

Constraints
1≤T≤1000
1≤N≤10^5
0≤Xi,Yi≤10^9
Sum of N over all test cases is atmost 10^5.

*/

package main

func main() {
	assert(distinct([][2]int{
		{1, 1},
		{1, 0},
		{0, 1},
		{0, 0},
	}) == 4)

	assert(distinct([][2]int{
		{0, 0},
		{0, 1},
		{0, 2},
		{0, 3},
		{0, 4},
	}) == 6)

	assert(distinct([][2]int{
		{10, 10},
	}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func distinct(a [][2]int) int {
	x := make(map[int]bool)
	y := make(map[int]bool)
	for _, p := range a {
		x[p[0]] = true
		y[p[1]] = true
	}
	return len(x) + len(y)
}
