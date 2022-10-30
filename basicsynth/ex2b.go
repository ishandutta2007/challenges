// Amplitude Envelope using Bresenham midpoint algorithm
package main

import (
	"flag"
	"fmt"
	"log"
	"math"
	"os"

	"github.com/qeedquan/go-media/snd/wav"
)

func main() {
	var sc SynthConfig
	sc.Init()

	// Middle C
	pitch := 48
	duration := 1.0
	volume := int(sc.SampleScale)

	flag.IntVar(&volume, "v", volume, "volume")
	flag.Float64Var(&duration, "d", duration, "duration")
	flag.IntVar(&pitch, "p", pitch, "pitch")
	flag.Parse()

	freq := sc.PitchToFreq(pitch)
	phaseinc := sc.FreqRad * freq
	phase := 0.0
	samples := int(float64(sc.SampleRate)*duration + 0.5)

	attack := int(0.2 * float64(sc.SampleRate))
	decay := int(0.3 * float64(sc.SampleRate))
	sustain := samples - (attack + decay)
	decaystart := samples - decay

	fmt.Printf("freq: %v phaseinc: %v\n", freq, phaseinc)
	fmt.Printf("attack: %v decay: %v sustain: %v decaystart: %v\n",
		attack, decay, sustain, decaystart)

	wf := &wav.File{
		Header: wav.Header{
			Channels:      2,
			SampleRate:    uint32(sc.SampleRate),
			BitsPerSample: 16,
		},
	}

	var ln Line
	ln.Init(attack, volume, 1)
	for i := 0; i < samples; i++ {
		if i < attack || i > decaystart {
			volume = ln.Step()
		} else if i == decaystart {
			ln.Init(decay, volume, -1)
		}

		Output16(wf, &sc, int16(float64(volume)*math.Sin(phase)))
		phase += phaseinc
		if phase >= 2*math.Pi {
			phase -= 2 * math.Pi
		}
	}

	f, err := os.Create("ex2b.wav")
	if err != nil {
		log.Fatal(err)
	}
	wav.Encode(wf, f)
	f.Close()
}

type Line struct {
	slope int
	dx2   int
	dy2   int
	err   int
	y     int
	max   int
	dir   int
}

func (l *Line) Init(dx, dy, dir int) {
	l.dir = dir
	l.max = dy
	l.y = 0

	if dx == 0 || dy == 0 {
		l.slope = 0
		l.dx2, l.dy2, l.err = 0, 0, 0
	} else if dx == dy {
		l.slope = 1
		l.dx2, l.dy2, l.err = 0, 0, 0
	} else {
		l.dx2 = dx * 2
		l.dy2 = dy * 2
		if l.dx2 > l.dy2 {
			l.slope = 2
			l.err = l.dy2 - dx
		} else {
			l.slope = 3
			l.err = l.dx2 - dy
		}
	}
}

func (l *Line) Step() int {
	switch l.slope {
	case 0:
		l.y = l.max
	case 1:
		l.y++
	case 2:
		if l.err >= 0 {
			l.err -= l.dx2
			l.y++
		}
		l.err += l.dy2
	case 3:
		m := -l.err/l.dx2 + 1
		l.y += m
		l.err += l.dx2 * m
		l.err -= l.dy2
	}
	if l.dir < 0 {
		return l.max - l.y
	}
	return l.y
}
