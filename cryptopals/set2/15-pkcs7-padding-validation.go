/*

PKCS#7 padding validation
Write a function that takes a plaintext, determines if it has valid PKCS#7 padding, and strips the padding off.

The string:

"ICE ICE BABY\x04\x04\x04\x04"
... has valid padding, and produces the result "ICE ICE BABY".

The string:

"ICE ICE BABY\x05\x05\x05\x05"
... does not have valid padding, nor does:

"ICE ICE BABY\x01\x02\x03\x04"
If you are writing in a language with exceptions, like Python or Ruby, make your function throw an exception on bad padding.

Crypto nerds know where we're going with this. Bear with us.

*/

package main

import (
	"crypto/aes"
	"errors"
	"flag"
	"fmt"
	"log"
	"os"
)

var (
	ErrInvalidPKCS7 = errors.New("invalid PKCS#7 padding")
)

var (
	blocksize = flag.Int("b", aes.BlockSize, "block size")

	status = 0
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("validate-pkcs7: ")
	flag.Parse()

	if !(0 < *blocksize && *blocksize <= 0xff) {
		log.Fatalf("invalid block size")
	}

	if flag.NArg() < 1 {
		ek(validate([]byte("ICE ICE BABY\x04\x04\x04\x04")))
		ek(validate([]byte("ICE ICE BABY\x05\x05\x05\x05")))
		ek(validate([]byte("ICE ICE BABY\x01\x02\x03\x04")))
	} else {
		for _, name := range flag.Args() {
			buf, err := os.ReadFile(name)
			if ek(err) {
				continue
			}
			ek(validate(buf))
		}
	}
	os.Exit(status)
}

func ek(err error) bool {
	if err != nil {
		fmt.Fprintln(os.Stderr, "validate-pkcs7:", err)
		status = 1
		return true
	}
	return false
}

func validate(plain []byte) error {
	if len(plain) == 0 || len(plain)%*blocksize != 0 {
		return ErrInvalidPKCS7
	}

	n := int(plain[len(plain)-1])
	if n == 0 || n > *blocksize || len(plain)-n < 0 {
		return ErrInvalidPKCS7
	}

	for i := 0; i < n; i++ {
		if plain[len(plain)-1-i] != byte(n) {
			return ErrInvalidPKCS7
		}
	}

	return nil
}
