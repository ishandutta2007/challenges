package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/gif"
	"log"
	"math"
	"os"
)

var (
	frames = flag.Int("frames", 120, "number of frames")
	width  = flag.Int("width", 512, "window width")
	height = flag.Int("height", 512, "window height")
	delay  = flag.Int("delay", 10, "delay between frames in 10ms units")
)

func main() {
	flag.Usage = usage
	flag.Parse()
	animate("rotating-square.gif", *width, *height, *frames, *delay)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options]")
	flag.PrintDefaults()
	os.Exit(2)
}

func animate(name string, width, height, frames, delay int) {
	anim := &gif.GIF{
		LoopCount: frames,
	}
	pal := genpal()
	for i := 0; i < frames; i++ {
		rect := image.Rect(0, 0, width, height)
		img := image.NewPaletted(rect, pal)

		theta := float64(i) / float64(frames) * 2 * math.Pi
		square(img, theta)

		anim.Delay = append(anim.Delay, delay)
		anim.Image = append(anim.Image, img)
	}

	f, err := os.Create(name)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	err = gif.EncodeAll(f, anim)
	if err != nil {
		log.Fatal(err)
	}
}

func genpal() []color.Color {
	pal := make([]color.Color, 256)
	for i := range pal {
		pal[i] = color.RGBA{uint8(i), uint8(i), uint8(i), 255}
	}
	return pal
}

func square(m *image.Paletted, theta float64) {
	rect := m.Bounds()
	width := float64(rect.Dx())
	height := float64(rect.Dy())

	xc := width / 2
	yc := height / 2
	l := 0.3 * math.Min(width, height)
	pts := [][4]float64{
		{xc - l, yc - l, xc + l, yc - l},
		{xc - l, yc - l, xc - l, yc + l},
		{xc + l, yc - l, xc + l, yc + l},
		{xc - l, yc + l, xc + l, yc + l},
	}
	for _, p := range pts {
		p[0], p[1] = rotate(p[0], p[1], xc, yc, theta)
		p[2], p[3] = rotate(p[2], p[3], xc, yc, theta)
		wuline(m, p[0], p[1], p[2], p[3])
	}
}

func rotate(x, y, xc, yc float64, theta float64) (xr, yr float64) {
	si, co := math.Sincos(theta)
	xr = co*(x-xc) - si*(y-yc) + xc
	yr = si*(x-xc) + co*(y-yc) + yc
	return
}

// https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
func wuline(m *image.Paletted, x0, y0, x1, y1 float64) {
	steep := math.Abs(y1-y0) > math.Abs(x1-x0)
	if steep {
		x0, y0 = y0, x0
		x1, y1 = y1, x1
	}
	if x0 > x1 {
		x0, x1 = x1, x0
		y0, y1 = y1, y0
	}

	dx := x1 - x0
	dy := y1 - y0
	gradient := 1.0
	if dx != 0 {
		gradient = dy / dx
	}

	xend := math.Round(x0)
	yend := y0 + gradient*(xend-x0)
	xgap := rfpart(x0 + 0.5)
	xpxl1 := xend
	ypxl1 := ipart(yend)
	if steep {
		plot(m, ypxl1, xpxl1, rfpart(yend)*xgap)
		plot(m, ypxl1+1, xpxl1, fpart(yend)*xgap)
	} else {
		plot(m, xpxl1, ypxl1, rfpart(yend)*xgap)
		plot(m, xpxl1, ypxl1+1, fpart(yend)*xgap)
	}

	intery := yend + gradient

	xend = math.Round(x1)
	yend = y1 + gradient*(xend-x1)
	xgap = fpart(x1 + 0.5)
	xpxl2 := xend
	ypxl2 := ipart(yend)
	if steep {
		plot(m, ypxl2, xpxl2, rfpart(yend)*xgap)
		plot(m, ypxl2+1, xpxl2, fpart(yend)*xgap)
	} else {
		plot(m, xpxl2, ypxl2, rfpart(yend)*xgap)
		plot(m, xpxl2, ypxl2+1, fpart(yend)*xgap)
	}

	if steep {
		for x := xpxl1 + 1; x <= xpxl2-1; x++ {
			plot(m, ipart(intery), x, rfpart(intery))
			plot(m, ipart(intery)+1, x, fpart(intery))
			intery = intery + gradient
		}
	} else {
		for x := xpxl1 + 1; x <= xpxl2-1; x++ {
			plot(m, x, ipart(intery), rfpart(intery))
			plot(m, x, ipart(intery)+1, fpart(intery))
			intery = intery + gradient
		}
	}
}

func plot(m *image.Paletted, x, y, c float64) {
	g := uint8(255 * c)
	m.SetColorIndex(int(x), int(y), g)
}

func rfpart(x float64) float64 {
	return 1 - fpart(x)
}

func ipart(x float64) float64 {
	return math.Floor(x)
}

func fpart(x float64) float64 {
	return x - math.Floor(x)
}
