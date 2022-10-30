/*

The Physics teacher in Tanu's class is teaching concepts of a bouncing ball.
The rubber ball that she is using has the property that if the ball is dropped from height H then, it bounces back to maximum height H/F.
So after first bounce it rises up to maximum height H/F, after second bounce to maximum height H/F2, after third bounce to maximum height H/F3, and so on.

The class has N children, and the teacher wants to select two children such that when the taller child drops the ball from his height, ball reaches a maximum height equal to the height of the shorter child after some (possibly zero) number of bounces.
Note that zero bounces mean heights of the two children will be same.
Given the heights of the children in the class Height[i], can you tell how many ways are there for the teacher to select two children for the demonstration?
Note that when heights are same, the pair is only counted once (See first example for further clarification).

Input

First line contains T, number of testcases. Then 2*T lines follow, 2 per testcase.
First line of each testcase consists of two space-separated intergers N and F. Second line of each testcase contains N space-separated integers representing the array Height.

Output

For each testcase, print a single line containing the answer to the problem.

Constraints
For 40 points: 1 ≤ T ≤ 100, 1 ≤ N ≤ 10^3, 2 ≤ F ≤ 10^9, 1 ≤ Height[i] ≤ 10^9
For 60 points: 1 ≤ T ≤ 100, 1 ≤ N ≤ 10^4, 2 ≤ F ≤ 10^9, 1 ≤ Height[i] ≤ 10^9

*/

package main

import "sort"

func main() {
	assert(ways([]int{2, 2, 2}, 2) == 3)
	assert(ways([]int{2, 1, 4}, 2) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ways(a []int, f int) int {
	sort.Ints(a)

	m := make(map[int]int)
	r := 0
	for _, v := range a {
		r += m[v]
		for h := v; h > 0 && h%f == 0; h /= f {
			r += m[h/f]
		}
		m[v]++
	}
	return r
}
