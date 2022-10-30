/*

Given a unordered array of the vertices of a convex polygon, find its area.

Examples

polygon([[2, 5], [5, 1], [-4, 3]]) ➞ 15.0

polygon([[-1, 1], [1, 1], [-1, -1], [1, -1]]) ➞ 4.0

polygon([[2, 2], [11, 2], [4, 10], [9, 7]]) ➞ 45.5

polygon([[5, 3], [3, 4], [12, 8], [5, 11], [9, 5]]) ➞ 39.0

Notes

    A convex polygon has all interior angles less than 180 degrees.
    The first example has only 3 vertices so this list is ordered by default.

*/

package main

import (
	"image"
	"math"
	"sort"
)

func main() {
	test([]image.Point{{2, 5}, {5, 1}, {-4, 3}}, 15)
	test([]image.Point{{-1, 1}, {1, 1}, {-1, -1}, {1, -1}}, 4)
	test([]image.Point{{2, 2}, {11, 2}, {4, 10}, {9, 7}}, 45.5)
	test([]image.Point{{-1, 1}, {1, 8}, {1, -3}, {3, 1}, {3, -1}}, 24)
	test([]image.Point{{5, 3}, {3, 4}, {12, 8}, {5, 11}, {9, 5}}, 39)
	test([]image.Point{{77, 10}, {92, 71}, {51, 9}, {62, 84}, {29, 94}}, 3274.5)
	test([]image.Point{{8199, 8629}, {424, 4349}, {5026, 68}, {7682, 3184}, {7561, 9036}, {1813, 8798}, {5360, 92}, {9676, 6684}, {4597, 9802}, {760, 2765}, {5872, 557}, {4446, 423}}, 59253602.0)
}

func test(p []image.Point, r float64) {
	assert(math.Abs(polygon(p)-r) < 1e-8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://www.geeksforgeeks.org/find-simple-closed-path-for-a-given-set-of-points/
https://en.wikipedia.org/wiki/Shoelace_formula

Generate a simple closed path to sort the points so we can use the shoelace formula

*/

func polygon(p []image.Point) float64 {
	if len(p) < 3 {
		return 0
	}

	n := ylb(p)
	p[0], p[n] = p[n], p[0]
	sort.Slice(p[1:], func(i, j int) bool {
		d := orientation(p[0], p[i+1], p[j+1])
		if d == 0 {
			return dist(p[0], p[i+1]) < dist(p[0], p[j+1])
		}
		return d < 0
	})
	return math.Abs(shoelace(p))
}

func ylb(p []image.Point) int {
	ym := p[0].Y
	n := 0
	for i := 1; i < len(p); i++ {
		if p[i].Y < ym || (ym == p[i].Y && p[i].X < p[n].X) {
			ym = p[i].Y
			n = i
		}
	}
	return n
}

func dist(p1, p2 image.Point) int {
	return (p1.X-p2.X)*(p1.X-p2.X) + (p1.Y-p2.Y)*(p1.Y-p2.Y)
}

func orientation(p, q, r image.Point) int {
	return (q.Y-p.Y)*(r.X-q.X) - (q.X-p.X)*(r.Y-q.Y)
}

func shoelace(p []image.Point) float64 {
	n := len(p)
	if n < 3 {
		return 0
	}

	s := 0
	for i := 0; i < n-1; i++ {
		s += (p[i+1].X + p[i].X) * (p[i].Y - p[i+1].Y)
	}
	s += (p[0].X + p[n-1].X) * (p[n-1].Y - p[0].Y)
	return float64(s) * 0.5
}
