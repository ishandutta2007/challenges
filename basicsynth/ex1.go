// Generate a sound by calling the sin() function
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
	// Middle C
	pitch := 48
	duration := 1.0
	volume := 1.0

	flag.Float64Var(&volume, "v", volume, "volume")
	flag.Float64Var(&duration, "d", duration, "duration")
	flag.IntVar(&pitch, "p", pitch, "pitch")
	flag.Parse()

	var sc SynthConfig
	sc.Init()
	freq := sc.PitchToFreq(pitch)
	phaseinc := sc.FreqRad * freq
	phase := 0.0
	samples := uint32(float64(sc.SampleRate)*duration + 0.5)

	fmt.Printf("freq: %v phaseinc: %v\n", freq, phaseinc)

	wf := &wav.File{
		Header: wav.Header{
			Channels:      2,
			SampleRate:    uint32(sc.SampleRate),
			BitsPerSample: 16,
		},
	}
	for i := uint32(0); i < samples; i++ {
		OutputFloat(wf, &sc, volume*math.Sin(phase))
		phase += phaseinc
		if phase >= 2*math.Pi {
			phase -= 2 * math.Pi
		}
	}

	f, err := os.Create("ex1.wav")
	if err != nil {
		log.Fatal(err)
	}
	wav.Encode(wf, f)
	f.Close()
}
