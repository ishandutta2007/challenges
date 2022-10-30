/*

Make a function that generates an array of 1,000 2-dimensional points, where both the x-coordinate and the y-coordinate are between 0.0 and 1.0. So (0.735, 0.167) and (0.456, 0.054) would be examples.
(Most computer languages have a simple random function that returns a double precision floating point number in this range, so you can use that to generate the coordinates. Python has random.random(), Java has Math.random(), Perl has rand(), etc. )

Create a program that finds the two points in this array that are closest to each other, and print that distance. As a reminder, the distance between the two points (x1, y1) and (x2, y2) is sqrt( (x1 - x2)2 + (y1 - y2)2 ).

Bonus 1: Do the same thing, but instead of using 1,000 points, use 1,000,000 points and see if you can create an algorithm that runs in a reasonable amount of time [edit: something like one minute or less].

Bonus 2: Do the same thing but for 3-dimensional points.

thanks to oskar_s for today's challenge at /r/dailyprogrammer_ideas ...

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
	"sort"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	for i := 0; i < 1000; i++ {
		test(i, true)
	}
	test(1000, false)
	test(1000000, false)
	test(10000000, false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, cmp bool) {
	p := gen(n)
	d := mindist(p)
	if cmp {
		e := mindistbf(p)
		assert(math.Abs(d-e) < 1e-8)
	} else {
		fmt.Println(d)
	}
}

/*

https://en.wikipedia.org/wiki/Closest_pair_of_points_problem
https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/closepoints.pdf
https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/

*/

type Point struct {
	x, y float64
}

func gen(n int) []Point {
	p := make([]Point, n)
	for i := range p {
		p[i] = Point{rand.Float64(), rand.Float64()}
	}
	return p
}

func mindistbf(p []Point) float64 {
	n := len(p)
	m := math.MaxFloat64
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			d := dist(p[i], p[j])
			if d < m {
				m = d
			}
		}
	}
	return m
}

func mindist(p []Point) float64 {
	sort.Slice(p, func(i, j int) bool {
		if p[i].x == p[j].x {
			return p[i].y < p[j].y
		}
		return p[i].x < p[j].x
	})
	return closest(p)
}

func closest(p []Point) float64 {
	n := len(p)
	if n <= 3 {
		return mindistbf(p)
	}

	m := n / 2
	mp := p[m]

	dl := closest(p[:m])
	dr := closest(p[m:])
	d := math.Min(dl, dr)

	sp := make([]Point, n)
	j := 0
	for i := 0; i < n; i++ {
		if math.Abs(p[i].x-mp.x) < d {
			sp[j], j = p[i], j+1
		}
	}
	return math.Min(d, stripclosest(sp[:j], d))
}

func stripclosest(sp []Point, d float64) float64 {
	sort.Slice(sp, func(i, j int) bool {
		if sp[i].y == sp[j].y {
			return sp[i].x < sp[j].x
		}
		return sp[i].y < sp[j].y
	})

	n := len(sp)
	m := d
	for i := 0; i < n; i++ {
		for j := i + 1; j < n && (sp[j].y-sp[i].y) < m; j++ {
			d := dist(sp[i], sp[j])
			if d < m {
				m = d
			}
		}
	}
	return m
}

func dist(p, q Point) float64 {
	dx := p.x - q.x
	dy := p.y - q.y
	return math.Hypot(dx, dy)
}
