/*

You are given a strictly convex polygon with N vertices (numbered 1 through N).
For each valid i, the coordinates of the i-th vertex are (Xi,Yi).
You may perform the following operation any number of times (including zero):

Consider a parent polygon. Initially, this is the polygon you are given.
Draw one of its child polygons ― a simple non-degenerate polygon such that each of its sides is a chord of the parent polygon (it cannot be a side of the parent polygon).
The operation cannot be performed if the parent polygon does not have any child polygons.
The child polygon which you drew becomes the new parent polygon.
Your goal is to draw as many sides of polygons in total as possible (including the polygon given at the start).
Find this maximum total number of sides.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Xi and Yi.

Output

Print a single line containing one integer ― the maximum possible number of sides of polygons.

Constraints

1≤T≤1,000
3≤N≤10^5
|Xi|,|Yi|≤10^9 for each valid i
the sum of N over all test cases does not exceed 2⋅10^6

*/

package main

func main() {
	assert(sides([][2]int{
		{-100, 1},
		{0, 2},
		{0, 0},
		{100, 1},
	}) == 4)

	assert(sides([][2]int{
		{-4, 0},
		{-3, -2},
		{-3, 2},
		{0, -4},
		{2, -3},
		{2, 3},
		{3, 2},
	}) == 10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sides(a [][2]int) int {
	n := len(a)
	p := make([]int, n+10)
	for i := 3; i <= 5; i++ {
		p[i] = i
	}
	for i := 6; i <= n; i++ {
		p[i] += i + p[i/2]
	}
	return p[n]
}
