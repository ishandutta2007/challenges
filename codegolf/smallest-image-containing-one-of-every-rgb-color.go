/*

Your objective is to create an image containing one pixel of every possible RGB color. The image with the smallest file size wins.

Rules:

The image must be a PNG.
The image must contain exactly one of every possible RGB color.

Acceptable image dimensions are:
1x16777216
2x8388608
4x4194304
8x2097152
16x1048576
32x524288
64x262144
128x131072
256x65536
512x32768
1024x16384
2048x8192
4096x4096
8192x2048
16384x1024
32768x512
65536x256
131072x128
262144x64
524288x32
1048576x16
2097152x8
4194304x4
8388608x2
16777216x1

*/

package main

import (
	"image"
	"image/color"
	"image/png"
	"os"
)

func main() {
	png.Encode(os.Stdout, gen())
}

func gen() *image.RGBA {
	s := 4096
	r := image.Rect(0, 0, s, s)
	m := image.NewRGBA(r)
	for y := 0; y < s; y++ {
		for x := 0; x < s; x++ {
			c := y<<12 | x
			p := color.RGBA{
				R: uint8(c),
				G: uint8(c >> 8),
				B: uint8(c >> 16),
				A: 255,
			}
			m.Set(x, y, p)
		}
	}
	return m
}
