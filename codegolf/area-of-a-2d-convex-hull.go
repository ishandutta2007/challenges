/*

You are given an array/list/vector of pairs of integers representing cartesian coordinates (x,y) of points on a 2D Euclidean plane; all coordinates are between −104 and 104, duplicates are allowed.
Find the area of the convex hull of those points, rounded to the nearest integer; an exact midpoint should be rounded to the closest even integer.
You may use floating-point numbers in intermediate computations, but only if you can guarantee that the final result will be always correct. This is code-golf, so the shortest correct program wins.

The convex hull of a set of points P is the smallest convex set that contains P. On the Euclidean plane, for any single point (x,y), it is the point itself;
for two distinct points, it is the line containing them, for three non-collinear points, it is the triangle that they form, and so forth.

A good visual explanation of what a convex hulls, is best described as imagining all points as nails in a wooden board, and then stretching a rubber band around them to enclose all the points:

Some test cases:

Input: [[50, -13]]
Result: 0

Input: [[-25, -26], [34, -27]]
Result: 0

Input: [[-6, -14], [-48, -45], [21, 25]]
Result: 400

Input: [[4, 30], [5, 37], [-18, 49], [-9, -2]]
Result: 562

Input: [[0, 16], [24, 18], [-43, 36], [39, -29], [3, -38]]
Result: 2978

Input: [[19, -19], [15, 5], [-16, -41], [6, -25], [-42, 1], [12, 19]]
Result: 2118

Input: [[-23, 13], [-13, 13], [-6, -7], [22, 41], [-26, 50], [12, -12], [-23, -7]]
Result: 2307

Input: [[31, -19], [-41, -41], [25, 34], [29, -1], [42, -42], [-34, 32], [19, 33], [40, 39]]
Result: 6037

Input: [[47, 1], [-22, 24], [36, 38], [-17, 4], [41, -3], [-13, 15], [-36, -40], [-13, 35], [-25, 22]]
Result: 3908

Input: [[29, -19], [18, 9], [30, -46], [15, 20], [24, -4], [5, 19], [-44, 4], [-20, -8], [-16, 34], [17, -36]]
Result: 2905

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]vec2{{50, -13}}, 0)
	test([]vec2{{-25, -26}, {34, -27}}, 0)
	test([]vec2{{-6, -14}, {-48, -45}, {21, 25}}, 400)
	test([]vec2{{4, 30}, {5, 37}, {-18, 49}, {-9, -2}}, 562)
	test([]vec2{{0, 16}, {24, 18}, {-43, 36}, {39, -29}, {3, -38}}, 2978)
	test([]vec2{{19, -19}, {15, 5}, {-16, -41}, {6, -25}, {-42, 1}, {12, 19}}, 2118)
	test([]vec2{{-23, 13}, {-13, 13}, {-6, -7}, {22, 41}, {-26, 50}, {12, -12}, {-23, -7}}, 2307)
	test([]vec2{{31, -19}, {-41, -41}, {25, 34}, {29, -1}, {42, -42}, {-34, 32}, {19, 33}, {40, 39}}, 6037)
	test([]vec2{{47, 1}, {-22, 24}, {36, 38}, {-17, 4}, {41, -3}, {-13, 15}, {-36, -40}, {-13, 35}, {-25, 22}}, 3908)
	test([]vec2{{29, -19}, {18, 9}, {30, -46}, {15, 20}, {24, -4}, {5, 19}, {-44, 4}, {-20, -8}, {-16, 34}, {17, -36}}, 2905)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p []vec2, r int) {
	a := area(p)
	fmt.Println(a)
	assert(a == r)
}

func area(p []vec2) int {
	c := jarvis(p)
	a := math.Abs(shoelace(c))

	r := math.Round(a)
	I, f := math.Modf(a)
	i := int(I)
	if f != 0.5 {
		return int(r)
	}
	if i&1 == 0 {
		return i
	}
	return i + 1
}

func shoelace(p []vec2) float64 {
	n := len(p)
	if n < 3 {
		return 0
	}

	s := 0
	for i := 0; i < n-1; i++ {
		s += (p[i+1].x + p[i].x) * (p[i].y - p[i+1].y)
	}
	s += (p[0].x + p[n-1].x) * (p[n-1].y - p[0].y)
	return float64(s) * 0.5
}

func jarvis(p []vec2) []vec2 {
	n := len(p)
	l := 0
	for i := 1; i < n; i++ {
		if p[i].x < p[l].x || (p[i].x == p[l].x && p[i].y < p[l].y) {
			l = i
		}
	}

	h := []vec2{}
	a := l
	for {
		h = append(h, p[a])
		b := (a + 1) % n
		for i := 0; i < n; i++ {
			if orientation(p[a], p[i], p[b]) == 2 {
				b = i
			}
		}
		a = b

		if a == l {
			break
		}
	}
	return h
}

func orientation(p, q, r vec2) int {
	v := (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y)
	if v == 0 {
		return 0
	}
	if v > 0 {
		return 1
	}
	return 2
}

type vec2 struct {
	x, y int
}
