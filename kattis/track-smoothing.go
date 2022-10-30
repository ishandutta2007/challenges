/*

Bob has the task to plan a racing track of a specific length.
He thought it is a great idea to just form a convex polygon that has exactly the required length.
Then he was told that racing cars cannot drive such sharp corners like in his plan.

He has to ensure some minimal radius for all curves in his track.
Bobs loves the shape of his track, so he don’t want to change it too much.
His plan is to scale the track down around the balance point of the polygon that specifies his track.
Then, he wants to draw the new track with a line that has a constant distance to the scaled track.
The chosen distance should be minimal distance that fulfils the given minimum radius constraint.
He asks you to write a program to calculate the scale factor for a given track and minimum radius so that the resulting track has the same length as the one of his original plan.

Bob made some drawings of the first test case:

Figure 1: Original track and scaled down track

Figure 2: Scaled down track and resulting track

Input

The input starts with the number of test cases t (0<t≤100).
Every test case starts with a line consisting of two integers: the minimal required radius r and the number of points n of the original track polygon (0≤r≤1000; 3≤n≤10000).
Then n lines follow, where each line specifies 2D-coordinates as two integers xi and yi (−10000≤xi,yi≤10000). (0,0) is the lower left corner.
These are the coordinates of the original track in counterclockwise direction. You may safely assume that the area of the given polygon is non-empty.

Output

For each test case print out one line. If it is possible to construct a course according to the above description, output the scaling factor,
“Not possible” otherwise. The factor must have a relative or absolute error smaller than 10−5.

*/

package main

import (
	"math"
)

func main() {
	test(20, []vec2{
		{10, 0},
		{110, 0},
		{130, 20},
		{0, 150},
		{0, 10},
	}, 0.730494)

	test(1, []vec2{
		{0, 0},
		{1, 0},
		{2, 0},
		{2, 1},
		{0, 1},
	}, "Not possible")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r float64, p []vec2, v interface{}) {
	u := course(r, p)
	switch v := v.(type) {
	case float64:
		assert(math.Abs(u.(float64)-v) < 1e-5)
	case string:
		assert(u == v)
	}
}

func course(r float64, p []vec2) interface{} {
	d := track(p)
	t := (d - 2*r*math.Pi) / d
	if t < 0 {
		return "Not possible"
	}
	return t
}

func track(p []vec2) float64 {
	n := len(p)
	if n == 0 {
		return 0
	}

	d := distance(p[n-1], p[0])
	for i := 1; i < n; i++ {
		d += distance(p[i], p[i-1])
	}
	return d
}

type vec2 struct {
	x, y float64
}

func distance(p, q vec2) float64 {
	dx := p.x - q.x
	dy := p.y - q.y
	return math.Hypot(dx, dy)
}
