/*

Draw the Ukrainian Flag
As you will probably know, there is a war going on in Ukraine. I noticed that it seems nobody has posted a Ukrainian flag challenge yet, so I thought I'd do it myself in support of Ukraine.

The Challenge
Here is the flag: Flag of Ukraine

The flag is divided horizontally across the middle into two equally sized stripes.
Stripe colors: (0, 87, 183) or #0557B7 (blue, top) and (255, 215, 0) or #FFD700 (yellow, bottom).

Colors must be exact if possible, otherwise use the closest available blue and yellow.
The image can be saved to a file or piped raw to STDOUT in any common image file format, or it can be displayed in a window.
The image must be sized at a 3:2 ratio, and at least 78 by 52 pixels.
Alternatively, output a block of text at least 78 characters wide made of non-whitespace characters that depicts the flag, using ANSI color codes to color it. (Use standard blue and yellow.)
Built-in flag images, flag-drawing libraries, or horrendously upscaling the Ukrainian flag emoji are prohibited.

This is code-golf, so shortest code wins!

*/

package main

import (
	"flag"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

var flags struct {
	width  int
	height int
}

func main() {
	parseflags()
	img := ukraine(flags.width, flags.height)
	png.Encode(os.Stdout, img)
}

func parseflags() {
	flag.IntVar(&flags.width, "width", 800, "image width")
	flag.IntVar(&flags.height, "height", 600, "image height")
	flag.Parse()
}

func ukraine(w, h int) *image.RGBA {
	r := image.Rect(0, 0, w, h)
	m := image.NewRGBA(r)

	r0 := image.Rect(0, 0, w, h/2)
	r1 := image.Rect(0, h/2, w, h)
	draw.Draw(m, r0, image.NewUniform(color.RGBA{0, 87, 183, 255}), image.ZP, draw.Src)
	draw.Draw(m, r1, image.NewUniform(color.RGBA{255, 215, 0, 255}), image.ZP, draw.Src)

	return m
}
