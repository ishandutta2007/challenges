/*

Given an image, output the [width in pixels of a full vertical section]1 (if one exists). If no vertical section exists, output 0.

Input may be provided as a local file or a nested array. If you choose to take input as a nested array, white pixels should be represented by a truthy value while non-white pixels should be represented by a falsey value.

1. the number of contiguous, all-white columns

You can assume that

no image will be larger than 1000 square pixels

there will be no more than one full vertical section per image

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/draw"
	_ "image/gif"
	_ "image/jpeg"
	_ "image/png"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("verticals: ")

	parseflags()

	img, err := loadimage(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(count(img))
}

func parseflags() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <image>")
	flag.PrintDefaults()
	os.Exit(2)
}

func loadimage(name string) (*image.RGBA, error) {
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

func count(m *image.RGBA) int {
	r := m.Bounds()
	v := 0
	c := 0
	for x := r.Min.X; x < r.Max.X; x++ {
		if c++; !vertical(m, x) {
			c = 0
		}
		v = max(v, c)
	}
	return v
}

func vertical(m *image.RGBA, x int) bool {
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		c := m.RGBAAt(x, y)
		if c.R != 255 || c.G != 255 || c.B != 255 {
			return false
		}
	}
	return true
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
