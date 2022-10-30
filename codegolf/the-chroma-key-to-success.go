/*

The RGB color value #00FF00 is a rather important one: it is used to make movies, TV shows, weather announcements, and more. It is the famous "TV green" or "green screen" color.

The Challenge
Your task is to write a program that takes two input images, both in PNG format (or in your image library's image object type) and of the same dimensions.
One image can be any old image. The other one is the image that will have a background of the color #00FF00.
The output image will consist of the second image overlaid over the first, with no #00FF00 color present (except in the first image).
Input and output may be done with files, a GUI, etc. You are allowed to take an array of RGB values as input, as seen here. You may assume that an image has only pixels of full opacity.

Basically...
Make a program that takes every #00FF00 pixel in one image and replace it with the corresponding pixel in the background image.

Test Cases
Generously provided by @dzaima: Background:
my profile image

Foreground:

dennis
Output:
output

Of course, standard loopholes are strictly forbidden. This includes using an online resource to do it for you.
This is code-golf, so may the shortest code win and the best programmer prosper...

*/

package main

import (
	"bufio"
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
	log.SetPrefix("chroma-key: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 3 {
		usage()
	}

	pic, err := loadimage(flag.Arg(0))
	check(err)

	bg, err := loadimage(flag.Arg(1))
	check(err)

	colorkey(pic, bg)

	err = writeimage(flag.Arg(2), pic)
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <image> <background> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

func loadimage(name string) (*image.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r := bufio.NewReader(f)
	m, _, err := image.Decode(r)
	if err != nil {
		return nil, err
	}

	b := m.Bounds()
	p := image.NewRGBA(b)
	draw.Draw(p, b, m, image.ZP, draw.Src)
	return p, nil
}

func colorkey(pic, bg *image.RGBA) {
	r := pic.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := pic.RGBAAt(x, y)
			if c.R == 0 && c.G == 255 && c.B == 0 {
				pic.SetRGBA(x, y, bg.RGBAAt(x, y))
			}
		}
	}
}

func writeimage(name string, m *image.RGBA) error {
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
