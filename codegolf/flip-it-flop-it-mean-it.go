/*

Overview
Given an image in plain PPM (P3) format as input, for each pixel p in the image, replace each of the following 4 pixels' red, green, and blue with the floored average value of the respective channels of all 4 pixels:

p itself

The pixel located at p's location when the image is flipped vertically

The pixel located at p's location when the image is flipped horizontally

The pixel located at p's location when the image is flipped both vertically and horizontally

Output the resulting image in plain PPM (P3) format.

For further explanation, consider this 8x8 image, magnified to 128x128:

step 2 example

Let p be the red pixel. To calculate the new value for p (and the 3 blue pixels), the values of p and the 3 blue pixels will be averaged together:

p1 = (255, 0, 0)
p2 = (0, 0, 255)
p3 = (0, 0, 255)
p4 = (0, 0, 255)
p_result = (63, 0, 191)
Examples


PPM: input, output



PPM: input, output



PPM: input, output



PPM: input, output

Reference Implementation
#!/usr/bin/python

import sys
from itertools import *

def grouper(iterable, n, fillvalue=None):
    args = [iter(iterable)] * n
    return list(izip_longest(*args, fillvalue=fillvalue))

def flatten(lst):
    return sum(([x] if not isinstance(x, list) else flatten(x) for x in lst), [])

def pnm_to_bin(p):
    w,h = map(int,p[1].split(' '))
    data = map(int, ' '.join(p[3:]).replace('\n', ' ').split())
    bin = []
    lines = grouper(data, w*3)
    for line in lines:
        data = []
        for rgb in grouper(line, 3):
            data.append(list(rgb))
        bin.append(data)
    return bin

def bin_to_pnm(b):
    pnm = 'P3 {} {} 255 '.format(len(b[0]), len(b))
    b = flatten(b)
    pnm += ' '.join(map(str, b))
    return pnm

def imageblender(img):
    h = len(img)
    w = len(img[0])
    for y in range(w):
        for x in range(h):
            for i in range(3):
                val = (img[x][y][i] + img[x][~y][i] + img[~x][y][i] + img[~x][~y][i])//4
                img[x][y][i],img[x][~y][i],img[~x][y][i],img[~x][~y][i] = (val,)*4
    return img

def main(fname):
    bin = pnm_to_bin(open(fname).read().split('\n'))
    bin = imageblender(bin)
    return bin_to_pnm(bin)

if __name__ == '__main__':
    print main(sys.argv[1])
This program takes a single filename as input, formatted like the output of pngtopnm <pngfile> -plain, and outputs a single line of PPM data separated by spaces.

A Brief Description of the P3 Format
A PPM plaintext file generated from pngtopnm <pngfile> -plain will look like this:

P3
<width in pixels> <height in pixels>
<maximum value as defined by the bit depth, always 255 for our purposes>
<leftmost 24 pixels of row 1, in RGB triples, space-separated; like (0 0 0 1 1 1 ...)>
<next 24 pixels of row 1>
<...>
<rightmost (up to) 24 pixels of row 1>

<leftmost 24 pixels of row 2>
<next 24 pixels of row 2>
<...>
<rightmost (up to) 24 pixels of row 2>

<...>
This is the format that the example input and output files use. However, PNM is very loose about its formatting - any whitespace may separate values.
You could replace all newlines in the above file with a single space each, and still have a valid file.
For example, this file and this file are both valid, and represent the same image.
The only other requirements are that the file must end with a trailing newline, and there must be width*height RGB triplets following the 255.

Rules
This is code-golf, so the shortest valid solution wins.
You may input and output PPM data formatted in any convenient and consistent manner, so long as it is valid according to the PPM format described above. The only exception is that you must use the plain (P3) format, and not the binary (P6) format.
You must provide verification that your solution outputs the correct images for the above test images.
All images will have a bit-depth of 8 bits.
Extra reading: Netpbm format wikipedia page

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
	log.SetPrefix("flip-flop-image: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	m, err := readimage(flag.Arg(0))
	check(err)

	err = writeimage(flag.Arg(1), flipflop(m))
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <input> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

func readimage(name string) (*image.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	br := bufio.NewReader(f)
	m, _, err := image.Decode(br)
	if err != nil {
		return nil, err
	}

	r := m.Bounds()
	p := image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)

	return p, nil
}

func writeimage(name string, m *image.RGBA) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}
	w := bufio.NewWriter(f)

	err = png.Encode(w, m)
	w.Flush()

	xerr := f.Close()
	if err == nil {
		err = xerr
	}
	return err
}

func flipflop(m *image.RGBA) *image.RGBA {
	r := m.Bounds()
	w := r.Dx()
	h := r.Dy()
	p := image.NewRGBA(r)

	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			c1 := m.RGBAAt(x, y)
			c2 := m.RGBAAt(w-x-1, y)
			c3 := m.RGBAAt(x, h-y-1)
			c4 := m.RGBAAt(w-x-1, h-y-1)
			p.Set(x, y, average(c1, c2, c3, c4))
		}
	}

	return p
}

func average(c1, c2, c3, c4 color.RGBA) color.RGBA {
	r := (float64(c1.R) + float64(c2.R) + float64(c3.R) + float64(c4.R)) / 4
	g := (float64(c1.G) + float64(c2.G) + float64(c3.G) + float64(c4.G)) / 4
	b := (float64(c1.B) + float64(c2.B) + float64(c3.B) + float64(c4.B)) / 4
	r = clamp(r, 0, 255)
	g = clamp(g, 0, 255)
	b = clamp(b, 0, 255)
	return color.RGBA{uint8(r), uint8(g), uint8(b), 255}
}

func clamp(x, a, b float64) float64 {
	if x < a {
		x = a
	} else if x > b {
		x = b
	}
	return x
}
