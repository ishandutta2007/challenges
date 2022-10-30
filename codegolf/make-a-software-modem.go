/*

Objective
Design a modulator/demodulator pair to accurately transmit data as quickly as possible over simulated plain old telephone service (POTS).

Steps
Generate some random (/dev/random or the like) data that will take 3-4 seconds to transmit
Modulate the data with your modulator to produce an audio file
Pass the audio file through the POTS simulator. If you don't have Python/Scipy you can upload a file with the form, or do a JSON API request.
Demodulate the audio file back to binary data
Validate that the input and output are equal-ish* (limit 1 out of every 1000 bits can be corrupted)
Score is number of bits transmitted divided by the length of the audio file (bits/second)

Rules
Input file must be 3-4 seconds, 44.1 kHz, mono.
Run the simulator with an SNR of 30 dB (it's default)
The demodulator must reconstruct the transmitted data with a bit error rate of no more than 10-3 (1 per thousand bits).
No digital compression is allowed (i.e. zipping the data. It's outside the scope of the challenge.)
No attempting to shove data into frequencies above 4 kHz. (My filters aren't perfect, but they're reasonably POTS-like with a relatively small number of taps.)
If your modem protocol requires a short preamble (no more than 1 second) to synchronize/calibrate the receiver, it isn't penalized.
If possible, please host the audio file somewhere accessible so we can listen to a cacophony of beeps and boops.

Example
Here's an example notebook that demonstrates the modulation/demodulation with simple "on-off keying" (audio samples included!).
https://nbviewer.org/github/nicktimko/pots-sim/blob/master/OOK_simple_demo.ipynb

It would score 100 (bits/second). Note that it's transmitting with a much worse 5 dB SNR.

*/

package main

import (
	"flag"
	"fmt"
	"math"
	"math/rand"
	"os"
	"time"
)

type Option struct {
	samplerate float64 // sample rate
	baudrate   float64 // baud rate
	carrier    float64 // carrier frequency (hz)
	duration   float64 // signal duration (seconds)
	noisy      bool
}

var opt = Option{
	samplerate: 44100,
	baudrate:   100,
	carrier:    800,
	duration:   10,
	noisy:      true,
}

func main() {
	rand.Seed(time.Now().UnixNano())
	parseflags()

	data := gensym(2, int(opt.baudrate*opt.duration))
	txdata := modulate(data, opt.baudrate, opt.samplerate, opt.carrier, opt.duration)
	rxdata := demodulate(txdata, opt.baudrate, opt.samplerate, opt.carrier, opt.duration, opt.noisy)
	diff(data, rxdata)
}

func parseflags() {
	flag.Float64Var(&opt.samplerate, "samplerate", opt.samplerate, "sample rate")
	flag.Float64Var(&opt.baudrate, "baudrate", opt.baudrate, "baud rate")
	flag.Float64Var(&opt.carrier, "carrier", opt.carrier, "carrier frequency")
	flag.Float64Var(&opt.duration, "duration", opt.duration, "signal duration")
	flag.BoolVar(&opt.noisy, "noisy", opt.noisy, "simulate noisy environment")
	flag.Usage = usage
	flag.Parse()
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options]")
	flag.PrintDefaults()
	os.Exit(2)
}

/*

https://en.wikipedia.org/wiki/On%E2%80%93off_keying

On-Off Keying (OOK) Modulation

Simplest form of Amplitude-Shift Keying (ASK)
Uses one sinusoidal wave at a fixed frequency (carrier frequency) to transmit the data.
The symbols is a binary (0, 1) and maps to the following:

0 -> suppresses the sinusoidal wave, output 0 at that point.
1 -> output whatever the value the sinusoidal wave has at that point in time.

*/
func modulate(data []int, baudrate, samplerate, carrier, duration float64) []float64 {
	t := linspace(0, duration, 1/samplerate)
	m := make([]float64, len(t))
	for i := range t {
		j := clamp(int(t[i]*baudrate), 0, len(data)-1)
		m[i] = float64(data[j]) * math.Sin(2*math.Pi*carrier*t[i])
	}
	return m
}

/*

To demodulate OOK modulation:

1. Multiply the received signal with the modulated carrier wave, if we want to simulate a noisy environment add a random phase delay to the carrier wave,
   due to the robustness of using only binary symbols, it is robust to phase shifts.
2. Take the absolute value of that signal above to rectify it, this is to simplify the math when detecting the threshold for 0/1
3. A symbol makes up of N samples, which is basically duplicated data when we transmit, so take N sample average for each symbol.
4. Threshold the average value calculated. If it is larger than a threshold, output a 1, otherwise 0.
5. The threshold value is calculated as the (max(data) + min(data)) / 2

*/
func demodulate(data []float64, baudrate, samplerate, carrier, duration float64, noisy bool) []int {
	phase := 0.0
	if noisy {
		phase = 2 * math.Pi * rand.Float64()
	}

	t := linspace(0, duration, 1/samplerate)
	d := make([]float64, len(data))
	for i := range data {
		d[i] = data[i] * math.Sin(2*math.Pi*carrier*t[i]+phase)
		d[i] = math.Abs(d[i])
	}

	samplespersymbol := samplerate / baudrate
	symbolstarts := make([]float64, int(baudrate*duration))
	for i := range symbolstarts {
		symbolstarts[i] = float64(i) * samplespersymbol
	}

	var c []float64
	for _, s := range symbolstarts {
		c = append(c, sum(d[int(s):int(s+samplespersymbol)]))
	}

	mi, ma := minmax(c)
	threshold := (ma + mi) / 2

	r := make([]int, len(c))
	for i := range c {
		if c[i] > threshold {
			r[i] = 1
		}
	}

	return r
}

func linspace(start, end, step float64) []float64 {
	r := []float64{}
	for x := start; x <= end; x += step {
		r = append(r, x)
	}
	return r
}

func gensym(nsym, length int) []int {
	p := make([]int, length)
	for i := range p {
		p[i] = rand.Intn(nsym)
	}
	return p
}

func sum(x []float64) float64 {
	r := 0.0
	for i := range x {
		r += x[i]
	}
	return r
}

func minmax(x []float64) (mi, ma float64) {
	mi = math.MaxFloat64
	ma = -math.MaxFloat64
	for i := range x {
		mi = math.Min(mi, x[i])
		ma = math.Max(ma, x[i])
	}
	return
}

func clamp(x, a, b int) int {
	if x < a {
		x = a
	} else if x > b {
		x = b
	}
	return x
}

func diff(a, b []int) {
	n := len(a)
	m := len(b)
	if n != m {
		fmt.Printf("length mismatch: %d %d\n", n, m)
	}
	if n > m {
		n = m
	}

	for i := 0; i < n; i++ {
		if a[i] != b[i] {
			fmt.Printf("data mismatch: %d %d %d\n", i, a[i], b[i])
		}
	}
}
