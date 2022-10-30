/*

A zip bomb is a compressed file, designed so that unpacking it yields the biggest file possible.
These are fairly well known, and there are examples of 42 KB files which expand into multiple petabytes of data.

In this challenge, the goal is reversed. Instead of providing a compressed file which is then unpacked,
the goal is to provide an uncompressed file which is compressed in an unreasonably inefficient manner, ideally becoming larger than the original.

Rules:

You should provide a file between 10 KB and 1 GB, which will be compressed by your chosen algorithm.
You should also specify a compression algorithm, such as gzip or PNG.
If the algorithm allows things like a compression level to be set, different configurations count as different algorithms.
The algorithm can be lossless or lossy, and can be application specific (like PNG or MP3).

Submissions are scored based on the ratio of compressedoriginal. For example, an 80 KB file that "compresses" to 88 KB would get a score of 1.1. The highest scoring solution, per algorithm, wins.

*/

package main

import (
	"archive/zip"
	"bytes"
	"compress/gzip"
	"crypto/rand"
	"fmt"
)

func main() {
	for i := 1; i <= 1e8; i *= 10 {
		test(i)
	}
}

func test(n int) {
	p := gen(n)
	x := xzip(p)
	y := xgzip(p)
	fmt.Printf("orig %d zip %d gzip %d\n", len(p), len(x), len(y))
}

func gen(n int) []byte {
	b := make([]byte, n)
	rand.Read(b)
	return b
}

func xzip(b []byte) []byte {
	w := new(bytes.Buffer)
	z := zip.NewWriter(w)
	p, _ := z.Create("bigdata")
	p.Write(b)
	z.Close()
	return w.Bytes()
}

func xgzip(b []byte) []byte {
	w := new(bytes.Buffer)
	z, _ := gzip.NewWriterLevel(w, gzip.BestCompression)
	z.Write(b)
	z.Close()
	return w.Bytes()
}
