package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	_ "image/jpeg"
	"image/png"
	"log"
	"math"
	"os"
	"sort"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("pixel-sorting: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	err := process(flag.Arg(0), flag.Arg(1))
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <input> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

func process(in, out string) error {
	m, err := readimage(in)
	if err != nil {
		return err
	}
	return writeimage(out, m, gethue(m))
}

func readimage(name string) (*image.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}

	m, _, err := image.Decode(f)
	if err != nil {
		return nil, err
	}

	r := m.Bounds()
	w := r.Dx()
	h := r.Dy()
	p := image.NewRGBA(image.Rect(0, 0, w, h))
	draw.Draw(p, p.Bounds(), m, image.ZP, draw.Src)

	return p, nil
}

func writeimage(name string, m *image.RGBA, v [][3]any) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}

	r := m.Bounds()
	w := r.Dx()
	h := r.Dy()

	p := image.NewRGBA(image.Rect(0, 0, w, h))
	px, py := 0, 0
	for _, v := range v {
		x := v[0].(int)
		y := v[1].(int)
		p.SetRGBA(px, py, m.RGBAAt(x, y))
		if px++; px >= w {
			px, py = 0, py+1
		}
	}

	err = png.Encode(f, p)
	xerr := f.Close()
	if err == nil {
		err = xerr
	}

	return err
}

func gethue(m *image.RGBA) [][3]any {
	var p [][3]any
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			hu, _, _ := rgb2hsv(m.RGBAAt(x, y))
			p = append(p, [3]any{x, y, hu})
		}
	}

	sort.Slice(p, func(i, j int) bool {
		return p[i][2].(float64) > p[j][2].(float64)
	})

	return p
}

func rgb2hsv(c color.RGBA) (h, s, v float64) {
	r := float64(c.R) / 255
	g := float64(c.G) / 255
	b := float64(c.B) / 255

	max := math.Max(r, math.Max(g, b))
	min := math.Min(r, math.Min(g, b))

	v = max
	if max == 0 || max == min {
		s = 0
		h = 0
	} else {
		s = (max - min) / max

		if max == r {
			h = 60*((g-b)/(max-min)) + 0
		} else if max == g {
			h = 60*((b-r)/(max-min)) + 120
		} else {
			h = 60*((r-g)/(max-min)) + 240
		}
	}
	if h < 0 {
		h += 360
	}
	h /= 360

	return
}
