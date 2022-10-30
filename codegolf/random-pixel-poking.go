/*

Your task is simple: write a program that will replace random pixels in a black 16px * 8px rectangle (width by height) with a white pixel.

The holes must be uniformly random, and you should output the 16px by 8 px image with the white pixels inserted.

Replace only 1 pixel per column (16 total replaced pixels)

You don't take any input, and you can't rely on the image being stored elsewhere on the computer.

This is code-golf so the program with the shortest bytecount wins!

*/

package main

import (
	"flag"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"math/rand"
	"os"
	"time"
)

func main() {
	var w, h int
	flag.IntVar(&w, "width", 800, "image width")
	flag.IntVar(&h, "height", 600, "image width")
	flag.Parse()

	rand.Seed(time.Now().UnixNano())
	png.Encode(os.Stdout, gen(w, h))
}

func gen(w, h int) *image.RGBA {
	r := image.Rect(0, 0, w, h)
	m := image.NewRGBA(r)
	draw.Draw(m, r, image.NewUniform(color.Black), image.ZP, draw.Src)
	for x := 0; x < w; x++ {
		y := rand.Intn(h)
		m.Set(x, y, color.White)
	}
	return m
}
