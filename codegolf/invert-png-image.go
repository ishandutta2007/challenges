/*

Create program or function that takes file name as an argument or reads it from standard input, and completes the following task:

    Read image from a png file (name given as argument).
    Reverse colors in that image, so that for example dark green (0, 75, 30) would become (255, 180, 225) (because 255-0=255, 255-75=180 and 255-30=225). You should not change alpha channel value.
    Output that image to a file called a.png (in png format), or show it in GUI window.

This is code-golf. Standard loopholes apply.

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/draw"
	"image/png"
	"log"
	"os"
)

func main() {
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	err := process(flag.Arg(0), flag.Arg(1))
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <infile> <outfile>")
	flag.PrintDefaults()
	os.Exit(2)
}

func invert(m *image.RGBA) {
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := m.RGBAAt(x, y)
			c.R = ^c.R
			c.G = ^c.G
			c.B = ^c.B
			m.SetRGBA(x, y, c)
		}
	}
}

func conv(m image.Image) *image.RGBA {
	p, _ := m.(*image.RGBA)
	if p != nil {
		return p
	}

	r := m.Bounds()
	p = image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)
	return p
}

func process(in, out string) error {
	r, err := os.Open(in)
	if err != nil {
		return err
	}
	defer r.Close()

	m, _, err := image.Decode(r)
	if err != nil {
		return err
	}

	p := conv(m)
	invert(p)

	w, err := os.Create(out)
	if err != nil {
		return err
	}

	err = png.Encode(w, p)
	xerr := w.Close()
	if err == nil {
		err = xerr
	}

	return err
}
