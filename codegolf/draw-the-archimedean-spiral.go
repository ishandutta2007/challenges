/*

Overview

I was playing with Desmos and discovered a really cool spiral:

Archimedian Spiral

Doing some research, I discovered that this spiral was the Archimedian spiral. Every point on the spiral is exactly θ away from the origin, where θ is the angle from the origin.
That is, any point on the spiral has the polar coordinates (θ,θ). This also has the consequence that the shortest distance between 2 arms of the spiral is exactly 2π if using radians or 360 if using degrees.

The Challenge

The basic spiral can be defined by the following formula in the polar coordinate system:

r=aθ

Where a is the multiplier of the distance between the arms. Your job is, given a floating point input for a, draw this spiral with at least one full rotation. You may output the image according to any image I/O defaults.

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"log"
	"math"
	"os"
)

var (
	width  = flag.Int("width", 800, "image width")
	height = flag.Int("height", 800, "image height")
	alpha  = flag.Float64("alpha", 1, "specify alpha")
	scale  = flag.Float64("scale", 5, "scale factor")
	period = flag.Float64("period", 50, "number of periods")
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	img := gen(*width, *height, *alpha, *scale, *period, color.RGBA{200, 0, 0, 255}, color.RGBA{255, 255, 255, 255})
	f, err := os.Create(flag.Arg(0))
	check(err)
	check(png.Encode(f, img))
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

func gen(width, height int, alpha, scale, period float64, fg, bg color.RGBA) *image.RGBA {
	bounds := image.Rect(0, 0, width, height)
	img := image.NewRGBA(bounds)
	draw.Draw(img, bounds, image.NewUniform(bg), image.ZP, draw.Src)
	for t := 0.0; t <= 2*math.Pi*period; t += 1e-4 {
		r := scale * (alpha * t)
		x := r*math.Cos(t) + float64(width)/2
		y := r*math.Sin(t) + float64(height)/2
		img.SetRGBA(int(x), int(y), fg)
	}
	return img
}
