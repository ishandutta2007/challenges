/*

This is a simple challenge.

The task is to write code that outputs a 448*448 square image with 100% transparency. The output should follow the standard image rules.

*/

package main

import (
	"flag"
	"image"
	"image/png"
	"os"
)

func main() {
	var w, h int
	flag.IntVar(&w, "width", 448, "window width")
	flag.IntVar(&h, "height", 448, "window height")
	flag.Parse()

	m := image.NewRGBA(image.Rect(0, 0, w, h))
	png.Encode(os.Stdout, m)
}
