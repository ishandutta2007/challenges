/*

Write a program that takes R, G, and B values as command arguments and then displays that color some way.
It doesn't matter how, as long as at least 100 pixels have the color. Shortest code wins.

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
	"strconv"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 3 {
		usage()
	}

	r := atoi(flag.Arg(0))
	g := atoi(flag.Arg(1))
	b := atoi(flag.Arg(2))
	c := color.RGBA{r, g, b, 255}
	m := image.NewRGBA(image.Rect(0, 0, 100, 100))
	draw.Draw(m, m.Bounds(), image.NewUniform(c), image.ZP, draw.Src)
	png.Encode(os.Stdout, m)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] r g b")
	flag.PrintDefaults()
	os.Exit(2)
}

func atoi(s string) uint8 {
	n, _ := strconv.ParseInt(s, 0, 64)
	return uint8(n)
}
