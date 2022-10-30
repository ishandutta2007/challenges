/*

Create a program to display some approximation of a bell curve. You are free to use whatever method you wish for generating the data, but the data must be displayed vertically, as in oriented like so:

Other restrictions:

    Your code must create the approximation, that is, don't hardcode or take data from the internet.
    The shape must actually look like a bell.

This is a popularity-contest, so be creative.

*/

package main

import (
	"flag"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"math"
	"os"
)

func main() {
	w := flag.Int("width", 800, "image width")
	h := flag.Int("height", 600, "image height")
	flag.Parse()

	m := gen(*w, *h, color.RGBA{179, 209, 255, 255})
	png.Encode(os.Stdout, m)
}

func gen(w, h int, col color.RGBA) *image.RGBA {
	r := image.Rect(0, 0, w, h)
	m := image.NewRGBA(r)

	mu := float64(w) * 0.5
	sd := float64(w) * 0.1
	a := float64(h) * sd * math.Sqrt(2*math.Pi)

	draw.Draw(m, r, image.NewUniform(color.White), image.ZP, draw.Src)
	for x := 0; x < w; x++ {
		y := math.Round(normpdf(float64(x), a, mu, sd))
		p := image.Rect(x, h, x+1, h-int(y))
		c := image.NewUniform(col)
		draw.Draw(m, p, c, image.ZP, draw.Src)
	}

	return m
}

func normpdf(x, a, mu, sd float64) float64 {
	u := a / (sd * math.Sqrt(2*math.Pi))
	v := (x - mu) / sd
	return u * math.Exp(-0.5*v*v)
}
