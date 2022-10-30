/*

Implement CBC mode
CBC mode is a block cipher mode that allows us to encrypt irregularly-sized messages, despite the fact that a block cipher natively only transforms individual blocks.

In CBC mode, each ciphertext block is added to the next plaintext block before the next call to the cipher core.

The first plaintext block, which has no associated previous ciphertext block, is added to a "fake 0th ciphertext block" called the initialization vector, or IV.

Implement CBC mode by hand by taking the ECB function you wrote earlier, making it encrypt instead of decrypt (verify this by decrypting whatever you encrypt to test), and using your XOR function from the previous exercise to combine them.

The file here is intelligible (somewhat) when CBC decrypted against "YELLOW SUBMARINE" with an IV of all ASCII 0 (\x00\x00\x00 &c)

*/

package main

import (
	"crypto/aes"
	"crypto/cipher"
	"encoding/base64"
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("aes-cbc: ")

	skey := "YELLOW SUBMARINE"
	siv := ""
	lib := false

	flag.Bool("e", true, "encrypt mode")
	flag.Bool("d", false, "decrypt mode")
	flag.BoolVar(&lib, "l", lib, "use library provided CBC crypt")
	flag.StringVar(&skey, "k", skey, "key")
	flag.StringVar(&siv, "v", siv, "iv")
	flag.Usage = usage
	flag.Parse()

	if flag.NArg() < 1 {
		usage()
	}

	key := []byte(skey)
	iv := make([]byte, aes.BlockSize)
	copy(iv, siv[:])

	op := "e"
	flag.Visit(func(f *flag.Flag) {
		switch f.Name {
		case "e", "d":
			op = f.Name
		}
	})

	data, err := os.ReadFile(flag.Arg(0))
	ck(err)

	switch op {
	case "e":
		if lib {
			xencrypt(key, iv, data)
		} else {
			encrypt(key, iv, data)
		}
	case "d":
		data, err = base64.StdEncoding.DecodeString(string(data))
		ck(err)
		if lib {
			xdecrypt(key, iv, data)
		} else {
			decrypt(key, iv, data)
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
	fmt.Fprintln(os.Stderr, "usage: aes-cbc [options] input")
	flag.PrintDefaults()
	os.Exit(2)
}

func pkcs7pad(dec []byte) []byte {
	n := len(dec) % aes.BlockSize
	if n == 0 {
		n = aes.BlockSize
	} else {
		n = aes.BlockSize - n
	}
	for i := 0; i < n; i++ {
		dec = append(dec, byte(n))
	}
	return dec
}

func xencrypt(key, iv, dec []byte) {
	dec = pkcs7pad(dec)
	enc := make([]byte, len(dec))

	c, err := aes.NewCipher(key)
	ck(err)

	b := cipher.NewCBCEncrypter(c, iv)
	b.CryptBlocks(enc, dec)

	p := base64.StdEncoding.EncodeToString(enc)
	for i := 0; i < len(p); i += 60 {
		fmt.Printf("%s\n", p[i:i+min(60, len(p)-i)])
	}
}

func xdecrypt(key, iv, enc []byte) {
	dec := make([]byte, len(enc))

	c, err := aes.NewCipher(key)
	ck(err)

	b := cipher.NewCBCDecrypter(c, iv)
	b.CryptBlocks(dec, enc)

	p := dec[len(dec)-1]
	dec = dec[:len(dec)-int(p)]
	fmt.Printf("%s", dec)
}

func encrypt(key, iv, dec []byte) {
	dec = pkcs7pad(dec)
	enc := make([]byte, len(dec))

	c, err := aes.NewCipher(key)
	ck(err)

	s := make([]byte, aes.BlockSize)
	copy(s, iv)
	for i := 0; i < len(dec); i += aes.BlockSize {
		for j := 0; j < aes.BlockSize; j++ {
			dec[i+j] ^= s[j]
		}
		c.Encrypt(enc[i:i+aes.BlockSize], dec[i:i+aes.BlockSize])
		copy(s, enc[i:])
	}

	p := base64.StdEncoding.EncodeToString(enc)
	for i := 0; i < len(p); i += 60 {
		fmt.Printf("%s\n", p[i:i+min(60, len(p)-i)])
	}
}

func decrypt(key, iv, enc []byte) {
	if len(enc)%aes.BlockSize != 0 {
		log.Fatalf("encrypted input is not block aligned")
	}
	dec := make([]byte, len(enc))

	c, err := aes.NewCipher(key)
	ck(err)

	s := make([]byte, aes.BlockSize)
	copy(s, iv)
	for i := 0; i < len(enc); i += aes.BlockSize {
		c.Decrypt(dec[i:i+aes.BlockSize], enc[i:i+aes.BlockSize])
		for j := 0; j < aes.BlockSize; j++ {
			dec[i+j] ^= s[j]
		}
		copy(s, enc[i:])
	}

	p := dec[len(dec)-1]
	dec = dec[:len(dec)-int(p)]
	fmt.Printf("%s", dec)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
