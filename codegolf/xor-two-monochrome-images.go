/*

Challenge:
Take input of two black and white (monochrome) images and xor each pixel of the first, with each pixel of the second, add them to a new image and output the new image.

Some clarifications:
Size of pictures does not matter. Extension/Image format doesn't matter.
You can make it take input any extension and output any extension, as long as the extension is used to store digital images.
You can also use graphics to draw the output in eg: a picturebox if you wish.
Otherwise, save the output as a file. Input can be taken as a path to the image, or url.

One thing you can't do however, is I/O arrays, eg. of triplets(R,G,B).

Do NOT tamper with alpha. It should not be xored, it should be 255 (max value) for every pixel.

What do you mean xor each pixel?
You don't have to do it this way, but one way to xor two pixels is to take their RGB values and xor R1 with R2, G1 with G2, B1 with B2, and take the result, which is your new color

Since we have only two colors, obviously when the colors are the same the result would be (0,0,0) and when they are different (white is 255,255,255 and black is 0,0,0) in this case, the result would be 255,255,255.

Thus when two pixels are different, the result is a white pixel, else a black pixel

Example I/O:
Input 1: Input 2:

Input 1 Input 2

Output:

Output

This is code-golf so shortest code wins.

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("xor-image: ")
	parseflags()

	a, err := imload(flag.Arg(0))
	check(err)

	b, err := imload(flag.Arg(1))
	check(err)

	png.Encode(os.Stdout, xor(a, b))
}

func check(err error) {
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
	fmt.Fprintln(os.Stderr, "usage: [options] <image1> <image2>")
	flag.PrintDefaults()
	os.Exit(2)
}

func imload(name string) (*image.RGBA, error) {
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

func xor(a, b *image.RGBA) *image.RGBA {
	r := a.Bounds()
	s := b.Bounds()

	r = r.Intersect(s)
	m := image.NewRGBA(r)

	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			u := a.RGBAAt(x, y)
			v := b.RGBAAt(x, y)
			m.SetRGBA(x, y, color.RGBA{u.R ^ v.R, u.G ^ v.G, u.B ^ v.B, 255})
		}
	}
	return m
}
