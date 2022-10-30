/*

Write a program that takes in a string or text file whose first line has the form

width height
and each subsequent line has the form

x y intensity red green blue
where:

width and height may be any positive integers.
x and y may be any integers.
intensity may be any non-negative integer.
red, green, and blue may be any integers from 0 to 255 inclusive.

Your program must output a truecolor image in any common lossless image file format whose dimensions are width by height.
Each x y intensity red green blue line represents a colorful star or orb that must be drawn on the image.
There may be any number of stars to draw, including 0. You may assume the string or file has a trailing newline.

The algorithm for drawing the image is as follows, though you may implement it in any way you like as long as the result is identical:

For every pixel (X,Y) in the image (where X is 0 at the leftmost edge and width-1 at the rightmost edge, and Y is 0 at the top edge and height-1 at the bottom edge), the color channel C ϵ {red, green, blue} (a value pinned between 0 to 255) is given by the equation:

color channel equation

Where the dist function is either Euclidean distance:

Euclidean distance equation

Or Manhattan distance:

Manhattan distance equation

Choose whichever distance function you prefer, based on golfability or aesthetics.

Each of the lines in the input besides the first is an element of the Stars set. So, for example, Sx represents the x value on one of the input lines, and SC represents either red, green, or blue, depending on which color channel is currently being calculated.

Examples
Example A
If the input is

400 150
-10 30 100 255 128 0
the output should be

Example A, Euclidean

if you're using Euclidean distance, and

Example A, Manhattan

if you're using Manhattan distance.

Example B
If the input is

200 200
100 100 10 255 255 255
20 20 40 255 0 0
180 20 40 255 255 0
180 180 40 0 255 0
20 180 40 0 0 255
the respective outputs for Euclidean and Manhattan distance should be

Example B, Euclidean and Example B, Manhattan.

Example C
If the input is

400 400
123 231 10 206 119 85
358 316 27 170 47 99
95 317 3 202 42 78
251 269 17 142 150 153
43 120 3 145 75 61
109 376 6 230 231 52
331 78 21 31 81 126
150 330 21 8 142 23
69 155 11 142 251 199
218 335 7 183 248 241
204 237 13 112 253 34
342 89 18 140 11 123
the output should be

Example C, Euclidean

if you're using Euclidean distance, and

Example C, Manhattan

if you're using Manhattan distance.

Example D
If the input is

400 400
123 231 5 206 119 85
358 316 5 170 47 99
95 317 5 202 42 78
251 269 5 142 150 153
43 120 5 145 75 61
109 376 5 230 231 52
331 78 5 31 81 126
150 330 5 8 142 23
69 155 5 142 251 199
218 335 5 183 248 241
204 237 5 112 253 34
342 89 5 140 11 123
the output should be

Example D, Euclidean

if you're using Euclidean distance, and

Example D, Manhattan

if you're using Manhattan distance.

Example E
If the input is

100 1
then the output should be a 100 pixel wide by 1 pixel tall image that is completely black.

Notes
Take the input string or the name of a text file that contains it from stdin or the command line, or you may write a function that takes in a string.
"Outputting" the image means either:
Saving it to a file with the name of your choice.
Printing the raw image file data to stdout.
Displaying the image, such as with PIL's image.show().
I won't be checking that your images are pixel perfect (Stack Exchange lossily compresses images anyway) but I will be very suspicious if I can visually tell any difference.
You may use graphics/image libraries.
Winning
The shortest submission in bytes wins. In case of ties, the earliest submission wins.

Fun Bonus: Give the input for a truly spectacular output image.

*/

package main

import (
	"image"
	"image/color"
	"image/png"
	"math"
	"os"
)

func main() {
	test("star1", 400, 150, []Star{{-10, 30, 100, 255, 128, 0}})

	test("star2", 200, 200, []Star{
		{100, 100, 10, 255, 255, 255},
		{20, 20, 40, 255, 0, 0},
		{180, 20, 40, 255, 255, 0},
		{180, 180, 40, 0, 255, 0},
		{20, 180, 40, 0, 0, 255},
	})

	test("star3", 400, 400, []Star{
		{123, 231, 10, 206, 119, 85},
		{358, 316, 27, 170, 47, 99},
		{95, 317, 3, 202, 42, 78},
		{251, 269, 17, 142, 150, 153},
		{43, 120, 3, 145, 75, 61},
		{109, 376, 6, 230, 231, 52},
		{331, 78, 21, 31, 81, 126},
		{150, 330, 21, 8, 142, 23},
		{69, 155, 11, 142, 251, 199},
		{218, 335, 7, 183, 248, 241},
		{204, 237, 13, 112, 253, 34},
		{342, 89, 18, 140, 11, 123},
	})

	test("star4", 400, 400, []Star{
		{123, 231, 5, 206, 119, 85},
		{358, 316, 5, 170, 47, 99},
		{95, 317, 5, 202, 42, 78},
		{251, 269, 5, 142, 150, 153},
		{43, 120, 5, 145, 75, 61},
		{109, 376, 5, 230, 231, 52},
		{331, 78, 5, 31, 81, 126},
		{150, 330, 5, 8, 142, 23},
		{69, 155, 5, 142, 251, 199},
		{218, 335, 5, 183, 248, 241},
		{204, 237, 5, 112, 253, 34},
		{342, 89, 5, 140, 11, 123},
	})

	test("star5", 100, 1, nil)
}

func test(name string, w, h int, s []Star) {
	writeimage(name+"_euclidean.png", stars(w, h, s, euclidean))
	writeimage(name+"_manhattan.png", stars(w, h, s, manhattan))
}

func writeimage(name string, m *image.RGBA) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}

	err = png.Encode(f, m)
	xerr := f.Close()
	if err == nil {
		err = xerr
	}
	return err
}

func stars(w, h int, s []Star, d Distance) *image.RGBA {
	m := image.NewRGBA(image.Rect(0, 0, w, h))
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			r, g, b := sum(s, d, float64(x), float64(y))
			m.Set(x, y, color.RGBA{uint8(r), uint8(g), uint8(b), 255})
		}
	}
	return m
}

func sum(s []Star, d Distance, x, y float64) (r, g, b float64) {
	for _, s := range s {
		l := d(s.x, s.y, x, y) + 1
		r += (s.i * s.r) / l
		g += (s.i * s.g) / l
		b += (s.i * s.b) / l
	}
	r = clamp(r, 0, 255)
	g = clamp(g, 0, 255)
	b = clamp(b, 0, 255)
	return
}

func clamp(x, a, b float64) float64 {
	if x < a {
		x = a
	} else if x > b {
		x = b
	}
	return x
}

func euclidean(x1, y1, x2, y2 float64) float64 {
	return math.Hypot(x2-x1, y2-y1)
}

func manhattan(x1, y1, x2, y2 float64) float64 {
	return math.Abs(x2-x1) + math.Abs(y2-y1)
}

type Star struct {
	x, y    float64
	i       float64
	r, g, b float64
}

type Distance func(float64, float64, float64, float64) float64
