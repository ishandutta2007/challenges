/*

Implement PKCS#7 padding
A block cipher transforms a fixed-sized block (usually 8 or 16 bytes) of plaintext into ciphertext. But we almost never want to transform a single block; we encrypt irregularly-sized messages.

One way we account for irregularly-sized messages is by padding, creating a plaintext that is an even multiple of the blocksize. The most popular padding scheme is called PKCS#7.

So: pad any block to a specific block length, by appending the number of bytes of padding to the end of the block. For instance,

"YELLOW SUBMARINE"
... padded to 20 bytes would be:

"YELLOW SUBMARINE\x04\x04\x04\x04"

*/

package main

import (
	"bufio"
	"crypto/aes"
	"crypto/cipher"
	"flag"
	"fmt"
	"io"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("aes-pkcs7-ecb: ")

	skey := "YELLOW SUBMARINE"
	flag.Bool("e", true, "encrypt mode")
	flag.Bool("d", false, "decrypt mode")
	flag.StringVar(&skey, "k", skey, "key")
	flag.Usage = usage
	flag.Parse()

	key := []byte(skey)

	op := "e"
	flag.Visit(func(f *flag.Flag) {
		switch f.Name {
		case "e", "d":
			op = f.Name
		}
	})

	var (
		in  = os.Stdin
		out = os.Stdout
		err error
	)
	switch n := flag.NArg(); {
	case n >= 2:
		out, err = os.Create(flag.Arg(1))
		ck(err)
		fallthrough
	case n >= 1:
		in, err = os.Open(flag.Arg(0))
		ck(err)
	}

	defer in.Close()
	r := bufio.NewReader(in)
	w := bufio.NewWriter(out)

	cipher, err := aes.NewCipher(key)
	ck(err)
	switch op {
	case "e":
		encrypt(r, w, cipher, key)
	case "d":
		decrypt(r, w, cipher, key)
	default:
		log.Fatalf("unknown op %q", op)
	}
	ck(w.Flush())
	ck(out.Close())
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: aes-pkcs7-ecb [options] [input] [output]")
	flag.PrintDefaults()
	os.Exit(2)
}

func encrypt(r io.Reader, w io.Writer, cipher cipher.Block, key []byte) {
	var dst, src [aes.BlockSize]byte
	for run := true; run; {
		n, err := io.ReadFull(r, src[:])
		if err == io.EOF {
			for i := range src {
				src[i] = byte(len(src))
			}
			run = false
		} else if err == io.ErrUnexpectedEOF {
			for i := n; i < len(src); i++ {
				src[i] = byte(len(src) - n)
			}
			run = false
		} else if err != nil {
			ck(err)
		}

		cipher.Encrypt(dst[:], src[:])
		w.Write(dst[:])
	}
}

func decrypt(r io.Reader, w io.Writer, cipher cipher.Block, key []byte) {
	var dst, src, tmp [aes.BlockSize]byte
	var drain bool
	for {
		_, err := io.ReadFull(r, tmp[:])
		if err == io.EOF {
			break
		} else if err != nil {
			log.Fatalf("%v", err)
		}

		if drain {
			cipher.Decrypt(dst[:], src[:])
			w.Write(dst[:])
		} else {
			copy(src[:], tmp[:])
		}
		drain = !drain
	}

	cipher.Decrypt(dst[:], tmp[:])
	v := dst[len(dst)-1]
	if v == 0 || v > aes.BlockSize {
		log.Fatalf("invalid pkcs7 padding value %v", v)
	}
	for i := 0; i < int(v); i++ {
		n := len(dst)-1-i
		if dst[n] != v {
			log.Fatalf("invalid pkcs7 padding, expected %#x got %#x at pos %d", v, dst[n], n)
		}
	}
	w.Write(dst[:len(dst)-int(v)])
}
