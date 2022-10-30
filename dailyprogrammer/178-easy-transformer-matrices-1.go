/*

(Easy): Transformers: Matrices in Disguise, pt. 1

Or, rather, transformations. Today we'll be doing a bit of basic geometry.
We'll be writing a program which will take a point in 2-dimensional space, represented as (X, Y) (where X and Y can be decimal and negative),
transform them a number of times in different ways and then find the final position of the point.

Your program must be able to do the following:

Translations - ie. offsetting the X and Y co-ordinates by a given amount http://i.imgur.com/3jI4sGI.png

Rotations by an arbitrary angle around a given point http://i.imgur.com/9c0ji7c.png

Scale relative to a point http://i.imgur.com/vHUfXv2.png

Reflection over the X or Y axis http://i.imgur.com/X6JH6pT.png

Formal Inputs & Outputs

Input
You will take an starting point (X, Y), such as:

(3, 4)
On new lines, you will then take commands in the format:

translate(A, B)     - translate by (A, B)
rotate(A, B, C)     - rotate around (A, B) by angle C (in radians) clockwise
scale(A, B, C)      - scale relative to (A, B) with scale-factor C
reflect(axis)       - reflect over the given axis
finish()            - end input and print the modified location

Where axis is one of X or Y.

Output

Print the final value of (X, Y) in the format:

(2.5, -0.666666)

Test Case

Test Case Input
(0, 5)
translate(3, 2)
scale(1,3,0.5)
rotate(3,2,1.57079632679)
reflect(X)
translate(2,-1)
scale(0,0,-0.25)
rotate(1,-3,3.14159265359)
reflect(Y)

Test Case Output
(-4, -7)

Notes
I want to say two things. First, this may be a good opportunity to learn your language's 2-D drawing capabilities - every time a command is given, represent it on an image like I have done with the examples,
so you can see the path the co-ordinate has taken. Secondly, this is a multi-part challenge. I'm not sure how many parts there will be, however it may be a good idea to prepare for more possible commands (or, if you're crazy enough to use Prolog -
you know who you are - write an EBNF parser like last time, lol.) If you know how, it would be clever to start using matrices for transformations now rather than later.

*/

package main

import (
	"fmt"
	"io"
	"math"
	"strings"
)

func main() {
	fmt.Println(run([]string{
		"(0, 5)",
		"translate(3, 2)",
		"scale(1,3,0.5)",
		"rotate(3,2,1.57079632679)",
		"reflect(X)",
		"translate(2,-1)",
		"scale(0,0,-0.25)",
		"rotate(1,-3,3.14159265359)",
		"reflect(Y)",
		"finish()",
	}))
}

type point struct {
	x, y float64
}

func run(cmds []string) (point, error) {
	var p point
	for _, cmd := range cmds {
		err := transform(&p, cmd)
		if err == io.EOF {
			break
		}
		if err != nil {
			return p, err
		}
	}
	return p, nil
}

func transform(p *point, cmd string) error {
	var (
		op rune
		c  [1]rune
		f  [3]float64

		c1 = []any{&c[0]}
		f2 = []any{&f[0], &f[1]}
		f3 = []any{&f[0], &f[1], &f[2]}
	)

	tab := []struct {
		op     rune
		format string
		args   []any
	}{
		{'p', "(%f,%f)", f2},
		{'t', "translate(%f,%f)", f2},
		{'s', "scale(%f,%f,%f)", f3},
		{'r', "rotate(%f,%f,%f)", f3},
		{'l', "reflect(%c)", c1},
		{'f', "finish()", nil},
	}

	cmd = strings.Replace(cmd, " ", "", -1)
	cmd = strings.Replace(cmd, "\t", "", -1)
	for _, p := range tab {
		n, err := fmt.Sscanf(cmd, p.format, p.args...)
		if n == len(p.args) && err == nil {
			op = p.op
			break
		}
	}

	switch op {
	case 'p':
		position(p, f[0], f[1])
	case 't':
		translate(p, f[0], f[1])
	case 's':
		scale(p, f[0], f[1], f[2])
	case 'r':
		rotate(p, f[0], f[1], f[2])
	case 'l':
		reflect(p, c[0])
	case 'f':
		return io.EOF
	default:
		return fmt.Errorf("invalid command %q", cmd)
	}
	return nil
}

func position(p *point, x, y float64) {
	p.x, p.y = x, y
}

func translate(p *point, dx, dy float64) {
	p.x, p.y = p.x+dx, p.y+dy
}

func scale(p *point, x, y, s float64) {
	p.x = s*(p.x-x) + x
	p.y = s*(p.y-y) + y
}

func rotate(p *point, x, y, c float64) {
	si, co := math.Sincos(-c)
	nx := co*(p.x-x) - si*(p.y-y) + x
	ny := si*(p.x-x) + co*(p.y-y) + y
	p.x = nx
	p.y = ny
}

func reflect(p *point, a rune) {
	switch a {
	case 'x', 'X':
		p.y = -p.y
	case 'y', 'Y':
		p.x = -p.x
	}
}
