/*

Construct a program or function that takes input in form of

<width>, <height>, <color1>, <color2>
and generates an output such that first row alternates between pixels of color <color1> and <color2> with a period of <height>.
For each row that follows, the period shall be <height> - <row number>. Note that <color1> always begins the row.

Sample Output

Input 120, 6, #000000, #FFFF00:

Sample Output

Input 80, 50, #000000, #FFFF00:

Sample Output 2

(Sample output has been scaled for clarity)

This is code-golf, so the shortest valid entry in bytes wins.

*/

package main

import (
	"image"
	"image/color"
	"image/png"
	"log"
	"os"
)

func main() {
	output("period-1.png", 120, 6, color.RGBA{0, 0, 0, 255}, color.RGBA{255, 255, 0, 255})
	output("period-2.png", 80, 50, color.RGBA{0, 0, 0, 255}, color.RGBA{255, 255, 0, 255})
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func output(name string, w, h int, c1, c2 color.RGBA) {
	f, err := os.Create(name)
	check(err)

	m := gen(w, h, c1, c2)
	check(png.Encode(f, m))
	check(f.Close())
}

func gen(w, h int, c1, c2 color.RGBA) *image.RGBA {
	c := []color.RGBA{c1, c2}
	r := image.Rect(0, 0, w, h)
	m := image.NewRGBA(r)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			i := (x / (h - y)) & 1
			m.SetRGBA(x, y, c[i])
		}
	}
	return m
}
