/*

When a bug jumps to a height y, its position can be plotted as a quadratic function with x as the time, and y as the vertical distance traveled.
For example, for a bug that jumps 9 cm up and is back on the ground after 6 seconds, its trajectory can be plotted as:

bug jump quadratic plot

Create a function that, given the max height of a vertical jump in cm and the current time in milliseconds,
returns the current position of the bug rounded to two decimal places, and its direction ("up" or "down").
If the bug is already back on the ground, return 0 for the position and "None" for the direction.

Examples

bugJump(9, 1000) ➞ [5, "up"]

bugJump(9, 4000) ➞ [8, "down"]

bugJump(9, 5500) ➞ [2.75, "down"]

bugJump(9, 7000) ➞ [0, "None"]

Notes

    Time and position both start at 0.
    You only need to translate the parabola (you don't need to scale it).

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(9, 1000, 5, "up")
	test(9, 4000, 8, "down")
	test(9, 5500, 2.75, "down")
	test(9, 7000, 0, "None")
	test(5, 2230, 5, "up")
	test(5, 2240, 5, "down")
	test(18, 8485, 0, "down")
	test(18, 8490, 0, "None")
	test(12, 1500, 8.14, "up")
	test(3, 2650, 2.16, "down")
}

func test(k, t, y float64, s string) {
	z, u := bugjump(k, t)
	fmt.Println(z, u)
	assert(math.Abs(z-y) < 1e-2)
	assert(s == u)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

We know the vertex height k and the initial point (0, 0) so we have the following system of equations:

y = a*(x-h)^2 + k where (h, k) is the vertex

0 = a*(0-h)^2 + k
k = a*(h-h)^2 + k
0 = a*(2*h-h)^2 + k

Solve for h and get
h = -sqrt(-k/a)

The problem says the parabola is not scaled, meaning a is 1, but since we are moving in a parabolic motion above ground,
this means that a is also negative so we end up with:

a = -1

*/

func bugjump(k, t float64) (y float64, s string) {
	a := -1.0
	h := -math.Sqrt(-k / a)
	x := -t / 1e3
	y = a*(x-h)*(x-h) + k
	switch {
	case x > h:
		s = "up"
	case y > 0:
		s = "down"
	default:
		y = 0
		s = "None"
	}
	return
}
