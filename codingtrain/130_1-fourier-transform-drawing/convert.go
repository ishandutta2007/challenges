package main

import (
	"bufio"
	"encoding/json"
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"log"
	"math"
	"os"
	"path/filepath"
)

type Vec2 struct {
	X, Y float64
}

type Rect struct {
	Min, Max Vec2
}

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	name := flag.Arg(0)
	pts, err := decode(name)
	check(err)

	txt := mkname(name, "txt")
	pic := mkname(name, "png")

	err = dump(txt, pts)
	check(err)

	img := mkimage(pts)
	imgfile, err := os.Create(pic)
	check(err)

	err = png.Encode(imgfile, img)
	check(err)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: drawing.json")
	flag.PrintDefaults()
	os.Exit(2)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func decode(name string) ([]Vec2, error) {
	var p struct {
		Drawing []Vec2
	}

	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	err = json.Unmarshal(data, &p)
	if err != nil {
		return nil, err
	}
	return p.Drawing, nil
}

func dump(name string, pts []Vec2) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}

	w := bufio.NewWriter(f)
	for _, p := range pts {
		fmt.Fprintf(w, "%f %f\n", p.X, p.Y)
	}
	w.Flush()

	return f.Close()
}

func bounds(p []Vec2) Rect {
	r := Rect{
		Min: Vec2{math.MaxFloat64, math.MaxFloat64},
		Max: Vec2{-math.MaxFloat64, -math.MaxFloat64},
	}
	for _, p := range p {
		r.Min.X = math.Min(r.Min.X, p.X)
		r.Min.Y = math.Min(r.Min.Y, p.Y)

		r.Max.X = math.Max(r.Max.X, p.X)
		r.Max.Y = math.Max(r.Max.Y, p.Y)
	}
	return r
}

func mkname(name, ext string) string {
	base := filepath.Base(name)
	bext := filepath.Ext(base)
	return fmt.Sprintf("%s.%s", base[:len(base)-len(bext)], ext)
}

func mkimage(pts []Vec2) *image.RGBA {
	r := bounds(pts)
	w := r.Max.X - r.Min.X
	h := r.Max.Y - r.Min.Y

	m := image.NewRGBA(image.Rect(0, 0, int(w+0.5), int(h+0.5)))
	draw.Draw(m, m.Bounds(), image.NewUniform(color.Black), image.ZP, draw.Src)

	for _, p := range pts {
		x := p.X + w/2
		y := p.Y + h/2

		x = math.Round(x)
		y = math.Round(y)

		m.Set(int(x), int(y), color.White)
	}

	return m
}
