/*

You and your sister have to share a large, circular cookie. The cookie is quite stale, so you must break it by striking it with a hammer.
When struck at point p, the cookie will break along the shortest chord containing p.
You follow the usual strategy of one person breaking the cookie into two parts and the other person choosing which part to take.
Thus, after the cookie is broken, you want to know which part is larger.

Input

Input consists of up to 200 test cases, one per line. Each test case is given as three real numbers r x y, where each value is in the range [0,20] with at most 8 digits past the decimal point.
All units are given in centimeters. The r value gives the radius of an origin-centered cookie.
The x and y values give the coordinates where the cookie is struck.
No strike will be within 0.001 cm of the edge of the cookie. Input ends at end of file.

Output

For each test case, print a line giving the area of the resulting two cookie pieces, larger piece first. Answers should be correct to within 0.001 square centimeters. If the hammer misses the cookie entirely, simply print out the word “miss”.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(10, 5, 0, [2]float64{252.740780, 61.418485})
	test(5.5, 5, 5, "miss")
	test(8, 3, 4.5, [2]float64{179.924668, 21.137262})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r, x, y float64, v interface{}) {
	const eps = 1e-6

	p := area(r, x, y)
	fmt.Println(p)
	switch y := v.(type) {
	case [2]float64:
		x := p.([2]float64)
		assert(math.Abs(x[0]-y[0]) < eps)
		assert(math.Abs(x[1]-y[1]) < eps)
	case string:
		assert(p == v)
	}
}

// http://mathworld.wolfram.com/CircularSegment.html
// r*r*acos((r-h)/r) - (r-h)*sqrt(2*r*h - h*h)
func area(r, x, y float64) interface{} {
	d := math.Hypot(x, y)
	if d >= r {
		return "miss"
	}

	h := r - d
	s := r*r*math.Acos((r-h)/r) - (r-h)*math.Sqrt(2*r*h-h*h)
	t := math.Pi*r*r - s
	if s < t {
		s, t = t, s
	}
	return [2]float64{s, t}
}
