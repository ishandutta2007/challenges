/*

A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units

Some of the grid squares are obstacles.

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.

*/

package main

import "fmt"

func main() {
	fmt.Println(robotsim([]int{4, -1, 3}, [][2]int{}))
	fmt.Println(robotsim([]int{4, -1, 4, -2, 4}, [][2]int{{2, 4}}))
}

func robotsim(c []int, p [][2]int) int {
	dx := [...]int{0, 1, 0, -1}
	dy := [...]int{1, 0, -1, 0}

	m := make(map[[2]int]struct{})
	for _, p := range p {
		m[p] = struct{}{}
	}

	var x, y, di, d int
	for _, c := range c {
		switch c {
		case -2:
			di = (di + 3) & 3
		case -1:
			di = (di + 1) & 3
		default:
			for i := 0; i < c; i++ {
				nx := x + dx[di]
				ny := y + dy[di]
				if _, f := m[[2]int{nx, ny}]; f {
					break
				}
				x = nx
				y = ny
				d = max(d, x*x+y*y)
			}
		}
	}
	return d
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
