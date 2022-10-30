/*

The flag of Bangladesh is very simple. It looks like below:

enter image description here

The flag will be in bottle green (#006a4e) and rectangular in size in the proportion of length to width of 10:6, with a red circle in near middle.
The red circle (#f42a41) will have a radius of one-fifth of the length of the flag. This image will help you to understand the proportions properly:

enter image description here

In this Graphical output challenge, you need to draw the flag of Bangladesh like first image. Standard loopholes apply, Shortest code wins.

Resolution cannot be 0px, or echo style answers not supported.

Minimum resolution is 286*176

*/

package main

import (
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

func main() {
	png.Encode(os.Stdout, bangladesh(10, 6, 100))
}

func bangladesh(w, h, s int) *image.RGBA {
	bg := color.RGBA{0x00, 0x6a, 0x4e, 0xff}
	fg := color.RGBA{0xf4, 0x2a, 0x41, 0xff}
	ci := &Circle{
		cx:  (w/2 - 1) * s,
		cy:  h / 2 * s,
		r:   w / 5 * s,
		col: fg,
	}

	r := image.Rect(0, 0, w*s, h*s)
	m := image.NewRGBA(r)
	draw.Draw(m, r, image.NewUniform(bg), image.ZP, draw.Src)
	draw.Draw(m, r, ci, image.ZP, draw.Over)

	return m
}

type Circle struct {
	cx, cy, r int
	col       color.RGBA
}

func (c *Circle) Bounds() image.Rectangle {
	return image.Rect(c.cx-c.r, c.cy-c.r, c.cx+c.r, c.cy+c.r)
}

func (c *Circle) At(x, y int) color.Color {
	var col color.RGBA
	dx := x - c.cx
	dy := y - c.cy
	if dx*dx+dy*dy < c.r*c.r {
		col = c.col
	}
	return col
}

func (c *Circle) ColorModel() color.Model {
	return color.RGBAModel
}
