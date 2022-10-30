/*

Entries for this challenge will display an animated rotating Lissajous figure. The appearance of 3d rotation occurs as the x parameter is successively phase-shifted in each frame.

Input:

The a and b parameters (as per the wikipedia article) will be specified at the command line, or read from stdin.

Output:

This is ascii-art, so output will be displayed in a terminal emulator window or equivalent. Output size may be hardcoded, but the Lissajous figure must be at least big enough to fill a 80x24 window.

The animation frame rate will be approximately 50fps. Sleeping for 20ms between each frame is fine, as long as the time to calculate each frame is small compared with the fixed sleep time.
If your choice of language cannot calculate quick enough on your chosen platform, then you'll have to calculate the time to sleep dynamically.

Each frame will not be displayed until all calculation for that frame is complete. There is no need to clear the screen between each frame.

The figure will make a full 2*Pi rotation approximately every 4 seconds.

For each frame, a full closed curve must be generated. At least 1000 points must be calculated along the curve. Line-drawing in between points is not necessary.

Points of the curve will be plotted as # characters. The rest of the display area will be blank/whitespace.

This is code-golf, so the shortest answer in bytes (deemed acceptable by me) will be the accepted winner one week after this posting.

*/

package main

import (
	"flag"
	"image"
	"image/color"
	"image/gif"
	"io"
	"math"
	"math/rand"
	"os"
	"time"
)

var flags struct {
	freq    float64
	cycles  float64
	res     float64
	size    int
	nframes int
	delay   int
}

func main() {
	rand.Seed(time.Now().UnixNano())
	parseflags()

	palette := []color.Color{color.Black, color.RGBA{0x00, 0xff, 0x00, 1}}
	lissajous(os.Stdout, flags.freq, flags.cycles, flags.res, flags.size, flags.nframes, flags.delay, palette)
}

func parseflags() {
	flag.Float64Var(&flags.freq, "freq", rand.Float64()*3, "frequency")
	flag.Float64Var(&flags.cycles, "cycles", 5, "number of complete x oscillator revolutions")
	flag.Float64Var(&flags.res, "res", 0.001, "angular resolution")
	flag.IntVar(&flags.size, "size", 256, "image canvas covers [-size..+size]")
	flag.IntVar(&flags.nframes, "nframes", 128, "number of animation frames")
	flag.IntVar(&flags.delay, "delay", 8, "delay between frames in 10ms units")
	flag.Parse()
}

// The Go Programming Language, by Alan A. A. Donovan and Brian Kernighan
func lissajous(out io.Writer, freq, cycles, res float64, size, nframes, delay int, palette []color.Color) error {
	anim := gif.GIF{LoopCount: nframes}
	phase := 0.0
	for i := 0; i < nframes; i++ {
		rect := image.Rect(0, 0, 2*size+1, 2*size+1)
		img := image.NewPaletted(rect, palette)
		for t := 0.0; t < cycles*2*math.Pi; t += res {
			x := math.Sin(t)
			y := math.Sin(t*freq + phase)
			img.SetColorIndex(size+int(x*float64(size)+0.5), size+int(y*float64(size)+0.5), 1)
		}
		phase += 0.1
		anim.Delay = append(anim.Delay, delay)
		anim.Image = append(anim.Image, img)
	}
	return gif.EncodeAll(out, &anim)
}
