/*

it's a-me!

Today's task is simple: write a program, or a function that displays the idle small Mario sprite, from Super Mario Bros, on NES, over a blue background.

Any kind of entry is valid as long as it displays those 12 * 16 pixels anywhere on the screen / window / browser.

(EDIT: the displayed image can be scaled up if your language can't do pixel art. You can also output ASCII art or HTML art, but using the right colors.)

Image (zoomed 400%):

You must use the following colors:

    blue: #6B8CFF
    red: #B13425
    green/brown: #6A6B04
    orange: #E39D25

Shortest program (in number of characters) wins!

Standard loopholes apply (especially, no network connexion allowed), but hardcoding and displaying an image file in your program is allowed. (entries using this trick will be rank separately)

Here we go!

*/

package main

import (
	"bytes"
	"encoding/base64"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

func main() {
	png.Encode(os.Stdout, mario())
}

func mario() *image.RGBA {
	const data = `iVBORw0KGgoAAAANSUhEUgAAAAwAAAAQAgMAAABfD3aUAAAADFBMVEX///+IcADYKAD8mDiryfk1AAAAAXRSTlMAQObYZgAAAExJREFUeF4NyKsNgDAYRtEbSE19g+pW/cchTdgBLEjyGUaAfTAoBKE87KESeM24diOWm5gzTUnU74HrIQwJk3HuI49WLi34biLwO/YBwCQWPKWzdq0AAAAASUVORK5CYII=`

	b, _ := base64.StdEncoding.DecodeString(data)
	m, _ := png.Decode(bytes.NewReader(b))

	r := m.Bounds()
	p := image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)

	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := p.RGBAAt(x, y)
			if c == (color.RGBA{}) {
				p.SetRGBA(x, y, color.RGBA{0x6b, 0x8c, 0xff, 0xff})
			}
		}
	}
	return p
}
