/*

Single-byte XOR cipher
The hex encoded string:

1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
... has been XOR'd against a single character. Find the key, decrypt the message.

You can do this by hand. But don't: write code to do it for you.

How? Devise some method for "scoring" a piece of English plaintext. Character frequency is a good metric. Evaluate each output and choose the one with the best score.

*/

package main

import (
	"encoding/hex"
	"flag"
	"fmt"
	"log"
	"math"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("detect-xor: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		detect("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736")
		return
	}

	for _, str := range flag.Args() {
		detect(str)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: detect-xor [options] hex ...")
	flag.PrintDefaults()
	os.Exit(2)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

// the idea is to loop through all 256 possible values
// doing the xor transformation and then count the letter
// frequency of that. Then we compare it to the
// official english letter frequencies and measure the
// distance, we want to minimize that distance
func detect(str string) {
	hex, err := hex.DecodeString(str)
	ck(err)

	buf := make([]byte, len(hex))
	dist := 1e7
	char := 0
	for c := 0; c < 256; c++ {
		xor(buf, hex, byte(c))
		freq := count(buf)
		d1 := distance(buf, letters[:])
		d2 := distance(buf, freq[:])
		d := math.Abs(d2 - d1)
		if d < dist {
			dist = d
			char = c
		}
	}

	xor(buf, hex, byte(char))
	fmt.Printf("xorchar: %q distance: %v\n", char, dist)
	fmt.Printf("%q\n", buf)
}

func xor(dst, src []byte, v byte) {
	for i := range dst {
		dst[i] = src[i] ^ v
	}
}

func count(buf []byte) (freq [256]float64) {
	for _, v := range buf {
		freq[v]++
	}
	for i := range freq {
		freq[i] = (freq[i] / float64(len(buf))) * 100
	}
	return
}

func distance(buf []byte, weights []float64) float64 {
	d := 0.0
	for _, v := range buf {
		d += float64(v) * weights[v]
	}
	return d
}

// https://en.wikipedia.org/wiki/Letter_frequency
var letters = [256]float64{
	'a': 8.167,
	'b': 1.492,
	'c': 2.782,
	'd': 4.253,
	'e': 12.702,
	'f': 2.228,
	'g': 2.015,
	'h': 6.094,
	'i': 6.966,
	'j': 0.153,
	'k': 0.772,
	'l': 4.025,
	'm': 2.406,
	'n': 6.749,
	'o': 7.507,
	'p': 1.929,
	'q': 0.095,
	'r': 5.987,
	's': 6.327,
	't': 9.056,
	'u': 2.758,
	'v': 0.978,
	'w': 2.360,
	'x': 0.150,
	'y': 1.974,
	'z': 0.074,
}
