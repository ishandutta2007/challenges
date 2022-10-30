/*

Given an image, either as input (possibly in RGB triplets) or with the filename as input (you may assume the image has a specific filename, possibly without an extension), output an image representing a single color channel of the image.

You will also take another input, representing which channel to output.
The input can be one of any 3 distinct symbols. However, the symbols must be either a string or a number.
You cannot take a matrice to apply to the array as input however. (such as {1, 0, 0}, or {0, 1, 0}).

You will output the <input> channel of the input image. You may either save it to a file or output a set of RGB pairs.

Your program should have no limits on the size of the image (in px), and must support either .png, .jpg/.jpeg/.JPG, or RGB triplets as image formats. (it can support as many as you want however)

Test case:

violet original

Red channel:

violet red

Green channel:

violet green

Blue channel:

violet blue

And another test case, entirely of red. Original photo, red, green, and blue. (warning: the plain and red channel hurt to look at for too long)

2 more test cases:

Original, red, green, blue.

Original, red, green, blue.

The latter two test cases are from Images with all colors.

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
	log.SetFlags(0)
	log.SetPrefix("rgb-extractor: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 3 {
		usage()
	}

	m, err := load(flag.Arg(1))
	check(err)

	extract(m, flag.Arg(0))

	err = write(flag.Arg(2), m)
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <channel> <infile> <outfile>")
	flag.PrintDefaults()
	os.Exit(2)
}

func load(name string) (*image.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	m, _, err := image.Decode(f)
	if err != nil {
		return nil, err
	}

	r := m.Bounds()
	p := image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)
	return p, nil
}

func extract(m *image.RGBA, ch string) {
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := m.RGBAAt(x, y)
			switch ch {
			case "r", "R":
				c.G, c.B = 0, 0
			case "g", "G":
				c.R, c.B = 0, 0
			case "b", "B":
				c.R, c.G = 0, 0
			}
			m.SetRGBA(x, y, c)
		}
	}
}

func write(name string, m *image.RGBA) error {
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
