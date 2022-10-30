/*

Given 3 bytes or RGB as input, calculate the nearest CMYK values, and output them.

create either a function with parameters and return value or a program that operates on stdin/stdout
use the color profile of your choice, but provide a reference
input may be either separate numeric values in range [0;255] or a 6 digit hex string
output should be separate numeric values ranging either [0;1] or [0;100]
standard code golf: no loopholes, shortest code wins
extravagant ideas are welcome
sample data:

input             output
108,174,106       [0.3793103448275862, 0.0, 0.3908045977011494, 0.3176470588235294]
0,0,0             0,0,0,1
170,255,238       33,0,7,0
0x0088ff          1,0.4667,0,0
[250,235,215]     [0,6,14,1.96]
#123456           .7907,.3953,0,.6627
Uncalibrated mapping is fine and probably the easiest
No input validation required; floats are allowed (ranging from 0 to 255), but may also be rounded
Output format should be either clearly commented or obvious; i.e.:
CMYK in that order
does not matter if percentage [0;100] or pure numbers [0;1]
Testing should include the trivial example [0,0,0].
This site has the most digits of online tools that I could find. Does anyone know a tool that gives more than 4 digits?

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(rgb{108, 174, 106}, cmyk{0.3793103448275862, 0.0, 0.3908045977011494, 0.3176470588235294})
	test(rgb{0, 0, 0}, cmyk{0, 0, 0, 1})
	test(rgb{170, 255, 238}, cmyk{0.33, 0, 0.07, 0})
	test(rgb{0, 0x88, 0xff}, cmyk{1, 0.4667, 0, 0})
	test(rgb{250, 235, 215}, cmyk{0, 0.06, 0.14, 0.0196})
	test(rgb{0x12, 0x34, 0x56}, cmyk{.7907, .3953, 0, .6627})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p rgb, r cmyk) {
	const eps = 1e-2

	c := rgb2cmyk(p)
	fmt.Printf("%f %f %f %f\n", c.c, c.m, c.y, c.k)

	assert(math.Abs(c.c-r.c) < eps)
	assert(math.Abs(c.m-r.m) < eps)
	assert(math.Abs(c.y-r.y) < eps)
	assert(math.Abs(c.k-r.k) < eps)
}

type rgb struct {
	r, g, b uint8
}

type cmyk struct {
	c, m, y, k float64
}

func rgb2cmyk(p rgb) cmyk {
	r := float64(p.r) / 255
	g := float64(p.g) / 255
	b := float64(p.b) / 255

	c := cmyk{k: 1 - math.Max(r, math.Max(g, b))}
	if c.k != 1 {
		c.c = (1 - r - c.k) / (1 - c.k)
		c.m = (1 - g - c.k) / (1 - c.k)
		c.y = (1 - b - c.k) / (1 - c.k)
	}
	return c
}
