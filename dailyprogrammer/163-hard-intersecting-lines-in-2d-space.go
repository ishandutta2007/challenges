/*

Descripton:
Given a typical x/y coordinate system we can plot lines. It would be interesting to know which lines intersect.

Input:
A series of lines from 1 to many to put in our 2-D space. The data will be in the form:

(label) (x1 y1) (x2 y2)
(label) will be a letter A-Z

(x1 y1) will be the coordinates of the starting point on line

(x2 y2) will be the coordinates of the ending point on line

example input:
A -2.5 .5 3.5 .5
B -2.23 99.99 -2.10 -56.23
C -1.23 99.99 -1.10 -56.23
D 100.1 1000.34 2000.23 2100.23
E 1.5 -1 1.5 1.0
F 2.0 2.0 3.0 2.0
G 2.5 .5 2.5 2.0
Max X can be 1,000,000,000.00

Max Y can be 1,000,000,000.00

Output:
The program will list which lines intersect. And which have 0 intersects.

Example Output:
Intersecting Lines:
A B
A C
A E
A G
F G
No intersections:
D
Difficulty:
This is a coder_d00d(tm) unknown difficulty challenge. It could be easy. Could be hard. But it seems cool for a Friday.

If you want to make it easier: input is only 2 lines and you return yes/no

If you want to make it harder: output is the 2 lines and the (x y) point they intersect at.

*/

package main

import "fmt"

func main() {
	intersections([]line{
		{'A', point{-2.5, .5}, point{3.5, .5}},
		{'B', point{-2.23, 99.99}, point{-2.10, -56.23}},
		{'C', point{-1.23, 99.99}, point{-1.10, -56.23}},
		{'D', point{100.1, 1000.34}, point{2000.23, 2100.23}},
		{'E', point{1.5, -1}, point{1.5, 1.0}},
		{'F', point{2.0, 2.0}, point{3.0, 2.0}},
		{'G', point{2.5, .5}, point{2.5, 2.0}},
	})
}

type point struct {
	x, y float64
}

type line struct {
	name rune
	a, b point
}

func intersections(l []line) {
	var (
		m = make(map[rune]bool)
		p [][2]rune
		q []rune
	)

	n := len(l)
	for i := 0; i < n; i++ {
		x := l[i].name
		for j := i + 1; j < n; j++ {
			y := l[j].name
			if intersect(l[i], l[j]) {
				p = append(p, [2]rune{x, y})
				m[x], m[y] = true, true
			}
		}
		if !m[x] {
			q = append(q, x)
		}
	}

	fmt.Printf("Intersecting Lines:\n")
	for _, c := range p {
		fmt.Printf("%c %c\n", c[0], c[1])
	}

	fmt.Printf("No intersections:\n")
	for _, c := range q {
		fmt.Printf("%c\n", c)
	}
}

// https://bryceboe.com/2006/10/23/line-segment-intersection-algorithm/
func intersect(l1, l2 line) bool {
	A, B := l1.a, l1.b
	C, D := l2.a, l2.b
	return ccw(A, C, D) != ccw(B, C, D) && ccw(A, B, C) != ccw(A, B, D)
}

func ccw(A, B, C point) bool {
	return (C.y-A.y)*(B.x-A.x) >= (B.y-A.y)*(C.x-A.x)
}
