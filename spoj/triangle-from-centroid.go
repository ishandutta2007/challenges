/*

Given the length of side a of a triangle and the distances from the centroid
(the point of concurrence of the medians - red in the picture) to all sides: a, b and c,
calculate this triangle's area and the distance (blue line) from the orthocenter (the point of concurrence of the heights - green in the picture) to the centroid.

Input
In the first line integer n - the number of test cases (equal to about 1000).
The next n lines - 4 floating point values: the length of side a, and distances from the centroid to sides a, b and c.

Output
n lines consisting of 2 floating point values with 3 digits after the decimal point:
the area of the triangle and the distance from the orthocenter to centroid.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(3.0, 0.8660254038, 0.8660254038, 0.8660254038))
	fmt.Println(solve(657.8256599140, 151.6154399062, 213.5392629932, 139.4878846649))
}

/*

https://en.wikipedia.org/wiki/Euler_line
https://en.wikipedia.org/wiki/Circumscribed_circle#Other_properties

*/

func solve(a, ga, gb, gc float64) (A, H float64) {
	b := a * ga / gb
	c := a * ga / gc
	A = heron(a, b, c)
	H = height(a, b, c, A)
	return
}

func heron(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}

func diameter(a, b, c, A float64) float64 {
	return (a * b * c) / (4 * A)
}

func height(a, b, c, A float64) float64 {
	d := diameter(a, b, c, A)
	v := d*d - (a*a+b*b+c*c)/9
	if v > 0 {
		return math.Sqrt(v) * 2
	}
	return 0
}
