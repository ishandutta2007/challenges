/*

Write a program or function that takes in a positive integer N and recreates this pattern of circles scaled to fit an N×N pixel image:

fancy circles

This image is a valid output example for N = 946.

In case it's not clear, all the small light-blue circles have the same radius and are positioned in the four dark-blue circles in the same way. The dark-blue circles have double that radius and are similarly positioned in the large light-blue circle.

Any two visually distinct colors may be used in place of the two shades of blue.

The background square does need to be colored.

Anti-aliasing is optional.

Save the image to a file, display it, or pipe the raw image data to stdout.

Any common image file format is allowed.

The shortest code in bytes wins.

Brownie points if you extend the recursive aspects of this circle pattern into further levels. (Keep this distinct from your challenge entry.)

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/png"
	"log"
	"math"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("circular-blues: ")

	var size int
	flag.IntVar(&size, "size", 946, "image size")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	fg := color.RGBA{91, 151, 228, 255}
	bg := color.RGBA{0, 64, 127, 255}
	f, err := os.Create(flag.Arg(0))
	check(err)
	check(png.Encode(f, blues(size, fg, bg)))
	check(f.Close())
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] output.png")
	flag.PrintDefaults()
	os.Exit(2)
}

/*

@kevin:

This approach determines the color of each individual pixel coordinate using recursive function c. c(x,y,0) renders a circle;
c(x,y,1) renders a circle with four circles cut out of it; c(x,y,2) renders the image in the OP. Anything larger than 2 earns me brownie points.

*/

func blues(size int, fg, bg color.RGBA) *image.RGBA {
	m := image.NewRGBA(image.Rect(0, 0, size, size))
	for y := 0; y < size; y++ {
		for x := 0; x < size; x++ {
			px := at(x, size)
			py := at(y, size)
			if in(px, py, 2) {
				m.SetRGBA(x, y, fg)
			} else {
				m.SetRGBA(x, y, bg)
			}
		}
	}
	return m
}

func at(s, size int) float64 {
	return (2 * float64(s) / float64(size)) - 1
}

func in(x, y float64, l int) bool {
	d := math.Sqrt(3) / 2
	if l == 0 {
		return (x*x)+(y*y) <= 1
	}

	pts := [][2]float64{
		{0.5, 0},
		{-0.5, 0},
		{0, d},
		{0, -d},
	}
	for _, p := range pts {
		if in((x+p[0])*2, (y+p[1])*2, l-1) {
			return false
		}
	}
	return in(x, y, 0)
}
