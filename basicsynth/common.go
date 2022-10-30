// https://sourceforge.net/projects/basicsynth/
// http://basicsynth.com/
package main

import (
	"math"

	"github.com/qeedquan/go-media/math/ga"
	"github.com/qeedquan/go-media/snd/wav"
)

type SynthConfig struct {
	// table to convert pitch index to frequency
	Tuning [128]float64
	// table to convert cents +-1200 to frequency multiplier
	Cents [2401]float64
	// pre-calculated multiplier for frequency to radians (2pi/samplerate)
	FreqRad float64
	// sample rate
	SampleRate int
	// multiplier to convert internal sample values into output values
	SampleScale float64
}

func (c *SynthConfig) Init() {
	c.InitEx(44100, 16384)
}

func (c *SynthConfig) InitEx(samplerate, wavetablen int) {
	c.SampleRate = samplerate
	c.SampleScale = float64((1 << 15) - 1)

	// a musical scale is a set of of musical notes ordered
	// by a fundamental frequency/pitch

	// use an equal tempered tuning system at A4=440 (Western standard)
	// Middle C = C4 = index 48
	// http://www.contrabass.com/pages/frequency.html
	// A1 = 13.75 HZ
	// C1 = A1*2^(3/12)
	// each musical step is is 2^(1/12)
	freq := 13.75 * math.Pow(2.0, 0.25)
	step := math.Pow(2, 1.0/12)
	for i := range c.Tuning {
		c.Tuning[i] = freq
		freq *= step
	}

	// a cent is a logarithmic measure of a scale, so its 1/100 step is
	// 1 note (1/1200)
	freq = -1200
	for i := range c.Cents {
		c.Cents[i] = math.Pow(2, freq/1200)
		freq++
	}

	c.FreqRad = 2 * math.Pi / float64(samplerate)
}

func (c *SynthConfig) PitchToFreq(pitch int) float64 {
	if pitch < 0 || pitch > 127 {
		return c.Tuning[0] * math.Pow(2, float64(pitch)/12)
	}
	return c.Tuning[pitch]
}

func OutputFloat(w *wav.File, c *SynthConfig, v float64) {
	v = ga.Clamp(v, -1, 1) * c.SampleScale
	Output16(w, c, int16(v))
}

func Output16(w *wav.File, c *SynthConfig, vi int16) {
	for i := uint16(0); i < w.Header.Channels; i++ {
		w.Samples = append(w.Samples, uint8(vi&0xff))
		w.Samples = append(w.Samples, uint8(vi>>8))
	}
}
