/*

Challenge

Given a colour raster image* with the same width and height, output the image transformed under Arnold's cat map. (*details see below)

Definition

Given the size of the image N we assume that the coordinates of a pixel are given as numbers between 0 and N-1.

Arnold's cat map is then defined as follows:

A pixel at coordinates [x,y] is moved to [(2*x + y) mod N, (x + y) mod N].

This is nothing but a linear transform on torus: The yellow, violet and green part get mapped back onto the initial square due to the mod N.

visualization

This map (let's call it f) has following properties:

    It is bijective, that means reversible: It is a linear transformation with the matrix [[2,1],[1,1]]. Since it has determinant 1 and and it has only integer entries, the inverse also has only integer entries and is given by [[1,-1],[-1,2]], this means it is also bijective on integer coordinates.

    It is a torsion element of the group of bijective maps of N x N images, that means if you apply it sufficiently many times, you will get the original image back: f(f(...f(x)...)) = x The amount of times the map applied to itself results in the identity is guaranteed to be less or equal to 3*N. In the following you can see the image of a cat after a given number of iterated applications of Arnold's cat map, and an animation of what a repeated application looks like:

multiple repeated applications
Details

    Your program does not necessarily have to deal with images, but 2D-arrays/matrices, strings or similar 2D-structures are acceptable too.

    It does not matter whether your (0,0) point is on the bottom left or on the top left. (Or in any other corner, if this is more convenient in your language.) Please specify what convention you use in your submission.

Testcases

In matrix form ([1,2,3,4] is the top row, 1 has index (0,0), 2 has index (1,0), 5 has index (0,1))

 1     2     3     4
 5     6     7     8
 9    10    11    12
13    14    15    16

maps to:

 1    14    11     8
12     5     2    15
 3    16     9     6
10     7     4    13

 --------------------

 1     2     3
 4     5     6
 7     8     9

 map to:

 1     8     6
 9     4     2
 5     3     7

As image (bottom left is (0,0)):

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/draw"
	_ "image/gif"
	_ "image/jpeg"
	"image/png"
	"log"
	"os"
	"path/filepath"
)

var flags struct {
	prefix string
	outdir string
}

func main() {
	parseflags()

	m, err := loadimage(flag.Arg(0))
	ck(err)

	iterate(m, flags.prefix, flags.outdir)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flag.StringVar(&flags.prefix, "p", "", "image prefix")
	flag.StringVar(&flags.outdir, "o", ".", "output directory")
	flag.Parse()
	if flag.NArg() < 1 {
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

	return conv(m), nil
}

func conv(m image.Image) *image.RGBA {
	r := m.Bounds()
	p := image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)
	return p
}

func iterate(m *image.RGBA, prefix, outdir string) {
	a := conv(m)
	b := conv(m)

	r := a.Bounds()
	w := r.Dx()
	h := r.Dy()

	writeimage(m, prefix, outdir, 0)
	for i := 1; ; i++ {
		catmap(a, b)
		writeimage(b, prefix, outdir, i)

		// convergence of same size image is guaranteed
		// otherwise find fixed point
		if (w == h && equal(m, b)) || equal(a, b) {
			break
		}
		a, b = b, a
	}
}

func writeimage(m *image.RGBA, prefix, outdir string, iter int) (err error) {
	defer func() {
		if err != nil {
			fmt.Println(err)
		}
	}()

	name := fmt.Sprintf("%v/%v%v.png", outdir, prefix, iter)
	name = filepath.Clean(name)

	fmt.Println("writing", name)

	dir := filepath.Dir(name)
	os.MkdirAll(dir, 0755)

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

func catmap(a, b *image.RGBA) {
	r := a.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			nx := (2*x + y) % r.Dx()
			ny := (x + y) % r.Dy()
			b.SetRGBA(nx, ny, a.RGBAAt(x, y))
		}
	}
}

func equal(a, b *image.RGBA) bool {
	r := a.Bounds()
	s := b.Bounds()
	if r != s {
		return false
	}

	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			u := a.RGBAAt(x, y)
			v := b.RGBAAt(x, y)
			if u != v {
				return false
			}
		}
	}
	return true
}
