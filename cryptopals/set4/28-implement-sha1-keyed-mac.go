/*

Implement a SHA-1 keyed MAC
Find a SHA-1 implementation in the language you code in.

Don't cheat. It won't work.
Do not use the SHA-1 implementation your language already provides (for instance, don't use the "Digest" library in Ruby, or call OpenSSL; in Ruby, you'd want a pure-Ruby SHA-1).

Write a function to authenticate a message under a secret key by using a secret-prefix MAC, which is simply:
SHA1(key || message)

Verify that you cannot tamper with the message without breaking the MAC you've produced, and that you can't produce a new MAC without knowing the secret key.

*/

package main

import (
	"bytes"
	"crypto/sha1"
	"encoding/hex"
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("sha1-mac: ")

	var (
		skey = "sekret"
		smac = ""
	)

	flag.Bool("v", false, "verify mode")
	flag.Bool("s", true, "sign mode")
	flag.StringVar(&skey, "k", skey, "key")
	flag.StringVar(&smac, "m", smac, "mac")
	flag.Usage = usage
	flag.Parse()

	key := []byte(skey)

	var mac [sha1.Size]byte
	h, err := hex.DecodeString(smac)
	ck(err)
	copy(mac[:], h)

	if flag.NArg() < 1 {
		usage()
	}

	op := "s"
	flag.Visit(func(f *flag.Flag) {
		switch f.Name {
		case "s", "v":
			op = f.Name
		}
	})

	data, err := os.ReadFile(flag.Arg(0))
	ck(err)
	data = append(key, data...)
	sum := sha1.Sum(data)

	switch op {
	case "s":
		fmt.Printf("%x\n", sum)
	case "v":
		if bytes.Compare(sum[:], mac[:]) == 0 {
			log.Fatalf("authenticated")
		} else {
			log.Fatalf("gtfo")
		}
	default:
		log.Fatalf("unknown op %q", op)
	}
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: sha1-mac [options] input")
	flag.PrintDefaults()
	os.Exit(2)
}
