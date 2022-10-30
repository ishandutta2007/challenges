/*

Write a program or function that prints an input string around the discrete circle that has the minimum possible radius. For example, for input This is an example, your program should output:

  a si
 n     s
        i
e       h
x       T
a
m
 p
  le

Circle generation
You shall use the Midpoint circle algorithm to compute the coordinates of each point of the discrete circle. You can find examples on how to implement this algorithm on this Wikipedia page.

Here is the pseudo code of the algorithm (based on Wikipedia's C example):

integer x = radius
integer y = 0
int decisionCriterion = 1 - x

while y <= x
    point at coordinates (x,y) belongs to the circle   // Octant 1
    point at coordinates (y,x) belongs to the circle   // Octant 2
    point at coordinates (-x,y) belongs to the circle  // Octant 4
    point at coordinates (-y,x) belongs to the circle  // Octant 3
    point at coordinates (-x,-y) belongs to the circle // Octant 5
    point at coordinates (-y,-x) belongs to the circle // Octant 6
    point at coordinates (x,-y) belongs to the circle  // Octant 7
    point at coordinates (y,-x) belongs to the circle  // Octant 8

    y++
    if decisionCriterion <= 0
        decisionCriterion += 2 * y + 1
    else
        x--
        decisionCriterion += 2 * (y - x) + 1
end while
You may use a different algorithm if and only if it produces the exact same circles that the Midpoint circle algorithm produces, for all radiuses.

The circle must have the smallest possible radius that still allows to write all letters of the input.

If the circle ends up with more points than the number of characters in the string, then the last filling characters will be spaces .

The first character of the input must be printed on the point with coordinates (Radius,0). The subsequent characters are printed in an anticlockwise fashion.

Inputs
The input is a string of any ASCII characters between the space (32) and the tilde ~ (126).

You may assume the input will always be valid, shorter than 256 characters and at least 5 characters long.

The input may be taken from STDIN, or as a function parameter, or anything similar.

Outputs
You may output the result either to STDOUT, or return it as string from a function.

You may have trailing spaces, provided that it does not cause the line to exceed the longest line (the middle one) (as such, the middle line cannot have trailing spaces).

A trailing new line is permitted.

Test cases
Input: Hello, World!
Output:
  ,ol
     l
W     e
o     H
r
 l
  d!


Input: 4 8 15 16 23 42
Output:
  51
     8
1
6     4

 2   2
  3 4


Input: Programming Puzzles & Code golf
Output:
     gnim
  uP     ma
 z         r
 z         g
l           o
e           r
s           P

&

 C
  od     f
    e Gol


Input: Ash nazg durbatuluk, ash nazg gimbatul, ash nazg thrakatuluk agh burzum-ishi krimpatul.
Output:
            zan hsa ,
           g         ku
        ig             lu
      bm                 ta
     a                     b
    t                       r
   u                         u
   l                         d
  ,
                              g
 a                             z
 s                             a
h                               n

n                               h
a                               s
z                               A
g

t
h
 r
 a                             .
  k                           l
  a                           u
   t                         t
   u                         a
    l                       p
     u                     m
      k                  ri
        ag              k
          h          hi
            burzum-is
Scoring

This is code-golf, so the shortest answer in bytes wins.

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	render("This is an example")
	render("Hello, World!")
	render("4 8 15 16 23 42")
	render("Programming Puzzles & Code Golf")
	render("Ash nazg durbatuluk, ash nazg gimbatul, ash nazg thrakatuluk agh burzum-ishi krimpatul.")
}

func render(s string) {
	r := []rune(s)
	p, x0, y0, x1, y1 := enclosure(r)
	output(charmap(p, r), x0, y0, x1, y1)
}

func output(m map[[2]int]rune, x0, y0, x1, y1 int) {
	for y := y1; y >= y0; y-- {
		for x := x0; x <= x1; x++ {
			p := [2]int{x, y}
			if r, f := m[p]; f {
				fmt.Printf("%c", r)
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func charmap(p [][2]int, r []rune) map[[2]int]rune {
	m := make(map[[2]int]rune)
	for i := range r {
		m[p[i]] = r[i]
	}
	return m
}

func enclosure(r []rune) (p [][2]int, x0, y0, x1, y1 int) {
	n := len(r)
	for i := 0; i <= 2*n; i++ {
		p = pointcloud(i)
		if len(p) >= n {
			break
		}
	}

	x0, y0 = math.MaxInt, math.MaxInt
	x1, y1 = math.MinInt, math.MinInt
	for _, p := range p {
		x0 = min(x0, p[0])
		y0 = min(y0, p[1])
		x1 = max(x1, p[0])
		y1 = max(y1, p[1])
	}

	return
}

func pointcloud(r int) [][2]int {
	m := make(map[[2]int]bool)
	l := [][2]int{}

	x := r
	y := 0
	d := 1 - x
	for y <= x {
		p := [][2]int{
			{x, y},
			{y, x},
			{-x, y},
			{-y, x},
			{-x, -y},
			{-y, -x},
			{x, -y},
			{y, -x},
		}
		for _, v := range p {
			if !m[v] {
				l, m[v] = append(l, v), true
			}
		}

		if y++; d <= 0 {
			d += 2*y + 1
		} else {
			x--
			d += 2*(y-x) + 1
		}
	}

	sort.Slice(l, func(i, j int) bool {
		a := angle(l[i][1], l[i][0])
		b := angle(l[j][1], l[j][0])
		return a < b
	})

	return l
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

func angle(y, x int) float64 {
	t := math.Atan2(float64(y), float64(x))
	if t < 0 {
		t = 2*math.Pi + t
	}
	return t
}
