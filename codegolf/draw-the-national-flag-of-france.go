/*

There have been many other flag challenges posted but not one for the national flag of France. This week seems like an appropriate time.

Produce this flag in the fewest bytes possible:

French flag

    The image must be in a ratio of 3:2, with size at least 78 pixels wide and 52 pixels tall.
    Each stripe takes up one third of the width.
    The stripe colors from left to right are RGB: (0, 85, 164), (255, 255, 255), (239, 65, 53).
    The image can be saved to a file or piped raw to STDOUT in any common image file format, or it can be displayed.
    Alternatively, output a block of text at least 78 characters wide made of non-whitespace characters that depicts the flag, using ANSI color codes to color it. (Use standard blue, white, and red.)
    Built-in flag images/libraries are not allowed.

The shortest code in bytes wins.

*/

package main

import (
	"image"
	"image/color"
	"image/png"
	"os"
)

func main() {
	png.Encode(os.Stdout, france(600, 400))
}

func france(w, h int) *image.RGBA {
	m := image.NewRGBA(image.Rect(0, 0, w, h))
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			var col color.RGBA
			switch {
			case x < w*1/3:
				col = color.RGBA{0, 85, 164, 255}
			case x < w*2/3:
				col = color.RGBA{255, 255, 255, 255}
			default:
				col = color.RGBA{239, 65, 53, 255}
			}
			m.SetRGBA(x, y, col)
		}
	}
	return m
}
