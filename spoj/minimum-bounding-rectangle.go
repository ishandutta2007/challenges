/*

Compute the Minimum Bounding Rectangle (MBR) that surrounds the given set of 2D objects, i.e., the axis-aligned rectangle, which contains all of the specified objects and is the one with minimum area among all rectangles with this property.

Input
First, you are given t (t<100) - the number of test cases.

Each of the test cases starts with one integer n (n < 100) - the number of objects in the set. In the successive n lines, the descriptions of the objects follow.

Each object is described by one character and some parameters:

a point: p x y, where x and y are point coordinates.
a circle: c x y r, where x and y are the center coordinates and r is the radius of the circle.
a line segment: l x1 y1 x2 y2, where xi, yi are the coordinates of the endpoints of the line.
Successive test cases are separated by an empty line.

Output

For each of the test cases output four numbers - the coordinates of the two points that correspond to the lower left and the upper right corner of the MBR, in the following order:
first the x-coordinate of the lower left corner, then the y-coordinate of the lower left corner, the x-coordinate of the upper right corner and the y-coordinate of upper right corner.

You can assume that all object parameters are integers and that -1000 -1000 1000 1000 is a bounding rectangle for all of them.

Example
Input:
3
1
p 3 3

2
c 10 10 20
c 20 20 10

1
l 0 0 100 20

Output:
3 3 3 3
-10 -10 30 30
0 0 100 20
Test case description
test 1: points only    (2 pts)
test 2: circles only   (2 pts)
test 3: lines only     (2 pts)
test 4: mixed          (2 pts)
test 5: mixed          (2 pts)

*/

package main

import (
	"fmt"
	"image"
	"math"
)

func main() {
	assert(bounds([]string{
		"p 3 3",
	}) == image.Rect(3, 3, 3, 3))

	assert(bounds([]string{
		"c 10 10 20",
		"c 20 20 10",
	}) == image.Rect(-10, -10, 30, 30))

	assert(bounds([]string{
		"l 0 0 100 20",
	}) == image.Rect(0, 0, 100, 20))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bounds(s []string) image.Rectangle {
	var (
		x, y int
		X, Y int
		r    int
		b    image.Rectangle
	)
	if len(s) == 0 {
		return b
	}

	b.Min = image.Pt(math.MaxInt, math.MaxInt)
	b.Max = image.Pt(math.MinInt, math.MinInt)
	for i := range s {
		n, err := fmt.Sscanf(s[i], "p %d %d", &x, &y)
		if n == 2 && err == nil {
			b = refit(b, x, y)
			continue
		}

		n, err = fmt.Sscanf(s[i], "c %d %d %d", &x, &y, &r)
		if n == 3 && err == nil {
			b = refit(b, x-r, y-r)
			b = refit(b, x+r, y+r)
			continue
		}

		n, err = fmt.Sscanf(s[i], "l %d %d %d %d", &x, &y, &X, &Y)
		if n == 4 && err == nil {
			b = refit(b, x, y)
			b = refit(b, X, Y)
		}
	}

	return b
}

func refit(b image.Rectangle, x, y int) image.Rectangle {
	b.Min.X = min(b.Min.X, x)
	b.Min.Y = min(b.Min.Y, y)
	b.Max.X = max(b.Max.X, x)
	b.Max.Y = max(b.Max.Y, y)
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
