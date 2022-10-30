/*

Convert hex to base64
The string:

49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
Should produce:

SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
So go ahead and make that happen. You'll need to use this code for the rest of the exercises.

*/

package main

import (
	"encoding/base64"
	"encoding/hex"
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("hex2base64: ")

	bflag := flag.Bool("b", false, "base64 to hex")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
	for _, str := range flag.Args() {
		if !*bflag {
			fmt.Printf("%s\n", hex2base64(str))
		} else {
			fmt.Printf("%s\n", base642hex(str))
		}
	}

}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func hex2base64(str string) string {
	buf, err := hex.DecodeString(str)
	ck(err)
	return base64.StdEncoding.EncodeToString(buf)
}

func base642hex(str string) string {
	buf, err := base64.StdEncoding.DecodeString(str)
	ck(err)
	return hex.EncodeToString(buf)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: hex2base64 [options] value ...")
	flag.PrintDefaults()
	os.Exit(2)
}
