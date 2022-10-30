/*

Your task is to create a program that will, given an input image, create an output image of the same size, where all pixels are ordered by hex value.

Your program may:

    Sort the pixels from left to right and then down or first sort down in columns and then right. In any case, the top left pixel is the smallest, and the bottom right is the largest.
    Use transparency, but this is not required.
    Sort by RGB, but you may use CMY, or any other format with at least 3 values. You can choose what values to sort on. (HSV may give some nice images)
    Use any well-known image format that most computers can open.

Rules:

    Output must be written to disk or be pipeable to a file.
    Input is given as a commandline argument, in the form of a relative path to the image, or piped in from the commandline.
    This is code golf, so shortest code in bytes wins!

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/png"
	"log"
	"os"
	"sort"
)

func main() {
	parseflags()

	m, err := imload(flag.Arg(0))
	ck(err)

	err = imwrite(imsort(m), flag.Arg(1))
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
	fmt.Fprintln(os.Stderr, "usage: [options] <infile> <outfile>")
	flag.PrintDefaults()
	os.Exit(2)
}

func imload(name string) (m image.Image, err error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	m, _, err = image.Decode(f)
	return
}

func imwrite(m image.Image, name string) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}
	err = png.Encode(f, m)
	xerr := f.Close()
	if err == nil {
		err = xerr
	}
	return err
}

func imsort(m image.Image) image.Image {
	r := m.Bounds()
	p := image.NewRGBA(r)

	var s []color.Color
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			s = append(s, m.At(x, y))
		}
	}

	sort.Slice(s, func(i, j int) bool {
		u := imcol(s[i])
		v := imcol(s[j])
		for n := range u {
			if u[n] < v[n] {
				return true
			}
			if u[n] > v[n] {
				return false
			}
		}
		return true
	})

	i := 0
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			p.Set(x, y, s[i])
			i++
		}
	}

	return p
}

func imcol(c color.Color) [4]uint32 {
	r, g, b, a := c.RGBA()
	return [4]uint32{r, g, b, a}
}
