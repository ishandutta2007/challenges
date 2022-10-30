/*

A donut distribution (for lack of a better term) is a random distribution of points in a 2-dimensional plane, forming a donut-like shape.
The distribution is defined by two parameters: the radius r and spread s, in which the distance to the origin follows a normal (Gaussian) distribution around r, with a standard deviation s.
The angular distribution is uniform in the range [0,2π).

The challenge

Given a radius r and spread s, your code should yield the Cartesian ((x,y)) coordinates of a single point chosen from this distribution.

Remarks

Running your code multiple times with the same input should result in the specified distribution.
Outputting polar coordinates is too trivial and not allowed.
You can output Cartesian coordinates in any way allowed by the default I/O rules.
This includes complex values.

Valid approaches

Several algorithms can be used to yield the desired distribution, including but not limited to

Choose a from the uniform distribution [0,2π) and b from the normal distribution (r,s).
Let x = b*cos(a) and y = b*sin(a).

Choose a from the uniform distribution [0,4) and b from the normal distribution (r,s).
Let x+y*i = b*i^a.

Choose a,b,c all from the normal distribution (0,1).
Let d = a+b*i and x+y*i = d/abs(d) * (c*s+r).

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	test(1e4, [][2]float64{
		{1, 0.1},
		{3, 1},
		{1, 0},
		{100, 5},
	})
}

func test(n int, p [][2]float64) {
	for i := 0; i < n; i++ {
		for _, v := range p {
			x, y := sample(v[0], v[1])
			fmt.Printf("%.6f %.6f ", x, y)
		}
		fmt.Println()
	}
}

func sample(r, s float64) (x, y float64) {
	a := rand.Float64() * 2 * math.Pi
	b := rand.NormFloat64()*s + r
	x = b * math.Cos(a)
	y = b * math.Sin(a)
	return
}
