/*

Take a look at this chamomile flower:

https://i.stack.imgur.com/VuneQ.png

Pretty, isn't it? Well, what if I told you that this wasn't actually one flower?

A lot of flowers (including sunflowers, chamomiles, daisies and others) actually consist of many very small flowers (the black dots on sunflowers) on a flower head. These miniature flowers are called florets, and they are arranged in a very special way.

Basically, the nth floret's position on a flower head is (in polar coordinates):

where c = 1 (Note that 137.508 degrees = golden angle. You don't have to use this exact precision.)

This causes the florets to be formed in a spiral called Fermat's Spiral. The positioning of the florets also is connected with Fibonnaci numbers, but that's a tale for another time.

So, here's the challenge. Given an integer n as input, calculate the positions of the first n florets and plot them.
This is graphical-output, so I do actually want you to display the points in either a window of some sort or outputted as data in some common image format to STDOUT or a file.
Other than that, this challenge should be fairly straightforward. It's code-golf, so shortest code wins. GLHF!

Here is a sample picture of what an output might look like:

https://i.stack.imgur.com/xQk4x.png

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

var (
	width   = flag.Int("width", 512, "image width")
	height  = flag.Int("height", 512, "image height")
	florets = flag.Int("floret", 20000, "number of florets")
)

func main() {
	flag.Parse()
	m := gen(*width, *height, *florets)
	png.Encode(os.Stdout, m)
}

func gen(w, h, n int) *image.RGBA {
	m := image.NewRGBA(image.Rect(0, 0, w, h))
	draw.Draw(m, m.Bounds(), image.NewUniform(color.White), image.ZP, draw.Src)
	for i := 0; i < n; i++ {
		fx, fy := p2c(floret(i))
		px := fx + float64(w)/2
		py := fy + float64(h)/2
		ix := int(px + 0.5)
		iy := int(py + 0.5)
		m.Set(ix, iy, color.Black)
	}

	return m
}

func floret(n int) (r, t float64) {
	const (
		G = 2 * math.Pi * (1 - (1 / math.Phi))
		c = 1
	)
	t = float64(n) * G
	r = c * math.Sqrt(t)
	return
}

func p2c(r, t float64) (x, y float64) {
	x = r * math.Cos(t)
	y = r * math.Sin(t)
	return
}
