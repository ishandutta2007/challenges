/*

Fixed XOR
Write a function that takes two equal-length buffers and produces their XOR combination.

If your function works properly, then when you feed it the string:

1c0111001f010100061a024b53535009181c
... after hex decoding, and when XOR'd against:

686974207468652062756c6c277320657965
... should produce:

746865206b696420646f6e277420706c6179

*/
package main

import (
	"encoding/hex"
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("fixedxor: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}
	fmt.Printf("%x\n", fixedxor(flag.Arg(0), flag.Arg(1)))
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: fixedxor xor1 xor2")
	flag.PrintDefaults()
	os.Exit(2)
}

func fixedxor(xor1, xor2 string) []byte {
	x, err := hex.DecodeString(xor1)
	ck(err)

	y, err := hex.DecodeString(xor2)
	ck(err)

	if len(x) != len(y) {
		log.Fatalf("length mismatch %d != %d", len(x), len(y))
	}

	for i := range x {
		x[i] ^= y[i]
	}
	return x
}
