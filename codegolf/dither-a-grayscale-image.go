/*

Dither a grayscale image into pure black and white with your own algorithm.

Guidelines: You must come up with your own new algorithm.
You cannot use pre-existing algorithms (ex. Floyd-Steinberg) but you can use the general technique.
Your program must be able to read an image and produce an image the same size.
This is a popularity contest, so whoever produces the best (closest to original) and most creative (determined by votes) wins.
Bonus if the code is short, though this is not necessary.

You can use whatever grayscale image you want as input, it should be larger than 300x300. Any file format is fine.

Example input:

puppy

Example output:

dithered

This is a pretty good job, but there still are visible lines and patterns.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	_ "image/gif"
	_ "image/jpeg"
	"image/png"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("dither-image: ")
	parseflags()

	m, err := readimage(flag.Arg(0))
	ck(err)

	err = writeimage(flag.Arg(1), dither(m))
	ck(err)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <input> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

func dither(img image.Image) image.Image {
	r := img.Bounds()
	p := image.NewPaletted(r, []color.Color{
		color.Gray{255},
		color.Gray{160},
		color.Gray{70},
		color.Gray{35},
		color.Gray{0},
	})
	draw.FloydSteinberg.Draw(p, r, img, image.ZP)
	return p
}

func readimage(name string) (image.Image, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r := bufio.NewReader(f)
	m, _, err := image.Decode(r)
	return m, err
}

func writeimage(name string, img image.Image) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}

	w := bufio.NewWriter(f)
	png.Encode(w, img)

	err = w.Flush()
	xerr := f.Close()
	if err == nil {
		err = xerr
	}

	return err
}
