/*

Implement CTR, the stream cipher mode

The string:

L77na/nrFsKvynd6HzOoG7GHTLXsTVu9qvY/2syLXzhPweyyMTJULu/6/kXX0KSvoOLSFQ==

... decrypts to something approximating English in CTR mode, which is an AES block cipher mode that turns AES into a stream cipher, with the following parameters:

      key=YELLOW SUBMARINE
      nonce=0
      format=64 bit unsigned little endian nonce,
             64 bit little endian block count (byte count / 16)

CTR mode is very simple.

Instead of encrypting the plaintext, CTR mode encrypts a running counter, producing a 16 byte block of keystream, which is XOR'd against the plaintext.

For instance, for the first 16 bytes of a message with these parameters:

keystream = AES("YELLOW SUBMARINE",
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00")

... for the next 16 bytes:

keystream = AES("YELLOW SUBMARINE",
                "\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00")

... and then:

keystream = AES("YELLOW SUBMARINE",
                "\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00")

CTR mode does not require padding; when you run out of plaintext, you just stop XOR'ing keystream and stop generating keystream.

Decryption is identical to encryption. Generate the same keystream, XOR, and recover the plaintext.

Decrypt the string at the top of this function, then use your CTR function to encrypt and decrypt other things.
This is the only block cipher mode that matters in good code.

Most modern cryptography relies on CTR mode to adapt block ciphers into stream ciphers, because most of what we want to encrypt is better described as a stream than as a sequence of blocks. Daniel Bernstein once quipped to Phil Rogaway that good cryptosystems don't need the "decrypt" transforms. Constructions like CTR are what he was talking about.

*/

package main

import (
	"crypto/aes"
	"encoding/base64"
	"encoding/binary"
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("aes-ctr: ")

	key := flag.String("k", "YELLOW SUBMARINE", "key")
	flag.Parse()

	var (
		data []byte
		err  error
	)
	if flag.NArg() < 1 {
		data = []byte("L77na/nrFsKvynd6HzOoG7GHTLXsTVu9qvY/2syLXzhPweyyMTJULu/6/kXX0KSvoOLSFQ==")
	} else {
		data, err = os.ReadFile(flag.Arg(0))
	}
	ck(err)

	src, err := base64.StdEncoding.DecodeString(string(data))
	ck(err)

	nonce := make([]byte, aes.BlockSize)
	dst := decrypt([]byte(*key), nonce, src)
	fmt.Printf("%q\n", dst)
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func decrypt(key, nonce, src []byte) []byte {
	cipher, err := aes.NewCipher(key)
	ck(err)

	state := make([]byte, aes.BlockSize)
	ctr := get8(nonce[8:])
	copy(state, nonce)

	tmp := make([]byte, aes.BlockSize)
	dst := make([]byte, len(src))
	cnt := 0
loop:
	for {
		cipher.Encrypt(tmp, state)
		for i := 0; i < aes.BlockSize; i++ {
			if cnt >= len(src) {
				break loop
			}
			dst[cnt] = src[cnt] ^ tmp[i]
			cnt++
		}
		ctr++
		put8(state[8:], ctr)
	}

	return dst
}

func put8(b []byte, v uint64) {
	binary.LittleEndian.PutUint64(b, v)
}

func get8(b []byte) uint64 {
	return binary.LittleEndian.Uint64(b)
}
