/*

Challenge

Create the image of a pride flag (rainbow flag), i.e. a six coloured striped flag (from top to bottom): red, orange, yellow, green, blue, and violet.

Output

enter image description here
Example (R)

barplot(rep(1, 6), horiz = TRUE, axes = FALSE, space = 0, border = NA, col = c("darkviolet", "blue", "darkgreen", "yellow", "orange", "red"))

Rules

    The algo should actually create the image, not just load an existing one.
    You may use any colors reasonably recognizable as "red", "orange", "yellow, "green", "blue", and "violet".
    The flag may either be scalable (such as an SVG, or output that scales to window size) or at least size 200px by 300px.
    All coloured areas should be of the same size.

Every answer must include the resulting picture!

Credits: this post was inspired by the following post: Draw the flag of Tennessee.

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
	png.Encode(os.Stdout, pride(512, 300))
}

func pride(w, h int) *image.RGBA {
	ctab := []color.RGBA{
		{255, 0, 0, 255},
		{255, 165, 0, 255},
		{255, 255, 0, 255},
		{0, 100, 0, 255},
		{0, 0, 255, 255},
		{148, 0, 211, 255},
	}

	n := len(ctab)
	m := image.NewRGBA(image.Rect(0, 0, w, h))
	for i, c := range ctab {
		p := image.NewUniform(c)
		r := image.Rect(0, i*h/n, w, (i+1)*h/n)
		draw.Draw(m, r, p, image.ZP, draw.Src)
	}
	return m
}
