/*

There's a file here. It's been base64'd after being encrypted with repeating-key XOR.

Decrypt it.

Here's how:

1. Let KEYSIZE be the guessed length of the key; try values from 2 to (say) 40.

2. Write a function to compute the edit distance/Hamming distance between two strings. The Hamming distance is just the number of differing bits. The distance between:
this is a test
and
wokka wokka!!!
is 37. Make sure your code agrees before you proceed.

3. For each KEYSIZE, take the first KEYSIZE worth of bytes, and the second KEYSIZE worth of bytes, and find the edit distance between them. Normalize this result by dividing by KEYSIZE.

4. The KEYSIZE with the smallest normalized edit distance is probably the key. You could proceed perhaps with the smallest 2-3 KEYSIZE values. Or take 4 KEYSIZE blocks instead of 2 and average the distances.

5. Now that you probably know the KEYSIZE: break the ciphertext into blocks of KEYSIZE length.

6. Now transpose the blocks: make a block that is the first byte of every block, and a block that is the second byte of every block, and so on.

7. Solve each block as if it was single-character XOR. You already have code to do this.

8. For each block, the single-byte XOR key that produces the best looking histogram is the repeating-key XOR key byte for that block. Put them together and you have the key.
This code is going to turn out to be surprisingly useful later on. Breaking repeating-key XOR ("Vigenere") statistically is obviously an academic exercise, a "Crypto 101" thing. But more people "know how" to break it than can actually break it, and a similar technique breaks something much more important.

*/
package main

import (
	"encoding/base64"
	"flag"
	"fmt"
	"log"
	"math"
	"os"
	"sort"
	"strings"
)

type score struct {
	keysize  int
	distance float64
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("break-repeat-xor: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	crack(flag.Arg(0))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: break-repeat-xor [options] file")
	flag.PrintDefaults()
	os.Exit(2)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

// idea is to find generate a list of key sizes to try
// first based on the minimal edit distances, since xoring
// the same byte against different outputs will make their distances
// closer, then we break the encrypted text into single characters
// xor and use letter frequency analysis to recover the xor byte
// combine them to get the key
func crack(name string) {
	enc, err := os.ReadFile(name)
	ck(err)

	enc, err = base64.StdEncoding.DecodeString(string(enc))
	ck(err)

	scores := guess(enc)
	if len(scores) == 0 {
		log.Fatalf("could not guess keysize")
	}

	key, dec := find(enc, scores[0].keysize)
	fmt.Printf("Key: %q\n\n", key)
	fmt.Printf("Decrypted Text:\n%s\n", dec)
}

func decrypt(enc, key []byte) []byte {
	dec := make([]byte, len(enc))
	for i := range enc {
		dec[i] = enc[i] ^ key[i%len(key)]
	}
	return dec
}

func find(enc []byte, keysize int) (key, dec []byte) {
	blocks := transpose(enc, keysize)
	for _, b := range blocks {
		_, c, _ := detect(b)
		key = append(key, c)
	}
	dec = decrypt(enc, key)
	return
}

func guess(enc []byte) []score {
	var s []score
	for i := 2; i <= 40; i++ {
		if len(enc) < 2*i {
			break
		}
		b1 := enc[0*i : 1*i]
		b2 := enc[1*i : 2*i]
		d := float64(edit(b1, b2))

		if len(enc) >= 4*i {
			b3 := enc[2*i : 3*i]
			b4 := enc[3*i : 4*i]
			d1 := float64(edit(b2, b3))
			d2 := float64(edit(b3, b4))
			d3 := float64(edit(b1, b3))
			d4 := float64(edit(b2, b4))
			d5 := float64(edit(b1, b4))
			d = (d + d1 + d2 + d3 + d4 + d5) / 6
		}

		s = append(s, score{i, d / float64(i)})
	}

	sort.Slice(s, func(i, j int) bool {
		return s[i].distance < s[j].distance
	})
	return s
}

func edit(a, b []byte) int {
	d := 0
	n := max(len(a), len(b))
	for i := 0; i < n; i++ {
		if i >= len(a) || i >= len(b) {
			d += 8
			continue
		}

		for j := uint(0); j < 8; j++ {
			if a[i]&(1<<j) != b[i]&(1<<j) {
				d++
			}
		}
	}
	return d
}

func transpose(enc []byte, keysize int) [][]byte {
	var b [][]byte
	for i := 0; i < keysize; i++ {
		var p []byte
		for n := i; n < len(enc); n += keysize {
			p = append(p, enc[n])
		}
		b = append(b, p)
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// the idea is to loop through all 256 possible values
// doing the xor transformation and then count the letter
// frequency of that. Then we compare it to the
// official english letter frequencies and measure the
// distance, we want to minimize that distance
// we add penalties to the distance decoding
// that are not printable escape codes or
// outside valid ascii or punctuations
func detect(enc []byte) (float64, byte, string) {
	buf := make([]byte, len(enc))
	dist := 1e7
	char := 0
	for c := 0; c < 256; c++ {
		xor(buf, enc, byte(c))

		freq := count(buf)
		d1 := distance(buf, letters[:])
		d2 := distance(buf, freq[:])
		d := math.Abs(d2 - d1)
		for i := range buf {
			if (buf[i] < 0x20 && buf[i] != '\n') || buf[i] >= 0x7f || strings.IndexByte("^|&@_{}", buf[i]) >= 0 {
				d += 1e4
			}
		}
		if d < dist {
			dist = d
			char = c
		}
	}

	xor(buf, enc, byte(char))
	return dist, byte(char), string(buf)
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
