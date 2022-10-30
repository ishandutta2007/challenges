/*

Task: Output the Swiss flag.

Happy Swiss National Day / Schweizer Bundesfeiertag / Fête nationale suisse / Festa nazionale svizzera / Fiasta naziunala svizra!

Details: The flag consists of a white (#FFFFFF) cross on a red (#FF0000) background. The cross consists of a 6x6 square with arms of size 6x7 glued to each side.
The cross is in the center of the 32x32 square background having a distance of 6 units to each side. (Source)

The output size can be chosen by the participant, but the image must exactly match these proportions, this means its size must be a multiple of 32.

*/

package main

import (
	"flag"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
	"strconv"
)

func main() {
	s := 1
	flag.Parse()
	if flag.NArg() >= 1 {
		s, _ = strconv.Atoi(flag.Arg(0))
	}

	m := swissflag(s)
	png.Encode(os.Stdout, m)
}

func swissflag(s int) *image.RGBA {
	n := 32 * s
	r := image.Rect(0, 0, n, n)
	m := image.NewRGBA(r)

	red := image.NewUniform(color.RGBA{255, 0, 0, 255})
	white := image.NewUniform(color.RGBA{255, 255, 255, 255})

	r0 := image.Rect(6, 6+7, 32-6, 6+7+6)
	r1 := image.Rect(6+7, 6, 6+7+6, 6+7+6+7)
	r0 = scale(r0, s)
	r1 = scale(r1, s)

	draw.Draw(m, r, red, image.ZP, draw.Src)
	draw.Draw(m, r0, white, image.ZP, draw.Src)
	draw.Draw(m, r1, white, image.ZP, draw.Src)

	return m
}

func scale(r image.Rectangle, s int) image.Rectangle {
	r.Min.X *= s
	r.Min.Y *= s
	r.Max.X *= s
	r.Max.Y *= s
	return r
}
