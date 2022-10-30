/*

Detect AES in ECB mode
In this file are a bunch of hex-encoded ciphertexts.

One of them has been encrypted with ECB.

Detect it.

Remember that the problem with ECB is that it is stateless and deterministic; the same 16 byte plaintext block will always produce the same 16 byte ciphertext.

*/
package main

import (
	"bufio"
	"crypto/aes"
	"encoding/hex"
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("detect-aes-ecb: ")

	flag.Usage = usage
	flag.Parse()
	detect(flag.Arg(0))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: detect-aes-ecb [options] file")
	flag.PrintDefaults()
	os.Exit(2)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

// since the challenge wants a detection of aes-ecb, this means
// there must be some duplicate input, or else if it is completely random
// data, then it will be isomorphic to another piece of random data
// after encryption and that is impossible to detect.
// the idea is to scan through the hex cipher texts and detect
// any blocks contain any previously seen duplicate, if there is
// there is a chance it is ECB, if a cipher is done using a more
// secure method than ECB, then each block will be different from each other
func detect(name string) {
	var err error
	fd := os.Stdin
	if name != "" {
		fd, err = os.Open(name)
		ck(err)
	}
	rd := bufio.NewReader(fd)

	scan := bufio.NewScanner(rd)
	for line := 1; scan.Scan(); line++ {
		enc, err := hex.DecodeString(scan.Text())
		if err != nil {
			log.Fatalf("%v:%v: %v", name, line, err)
		}

		if len(enc)%aes.BlockSize != 0 {
			log.Fatalf("%v:%v: not multiple of AES block size", name, line)
		}

		var ip []int
		seen := make(map[[aes.BlockSize]byte]int)
		for i := 0; i < len(enc); i += aes.BlockSize {
			var data [aes.BlockSize]byte

			copy(data[:], enc[i:])
			if n, found := seen[data]; found {
				ip = append(ip, n)
			} else {
				n := i / aes.BlockSize
				ip = append(ip, n)
				seen[data] = n
			}
		}

		for i := range ip {
			if ip[i] != i {
				fmt.Printf("line %d %v\n", line, ip)
				break
			}
		}
	}
}
