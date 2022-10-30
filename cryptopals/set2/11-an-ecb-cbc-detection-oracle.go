/*

An ECB/CBC detection oracle

Now that you have ECB and CBC working:

Write a function to generate a random AES key; that's just 16 random bytes.

Write a function that encrypts data under an unknown key --- that is, a function that generates a random key and encrypts under it.

The function should look like:
encryption_oracle(your-input)
=> [MEANINGLESS JIBBER JABBER]

Under the hood, have the function append 5-10 bytes (count chosen randomly) before the plaintext and 5-10 bytes after the plaintext.

Now, have the function choose to encrypt under ECB 1/2 the time, and under CBC the other half (just use random IVs each time for CBC). Use rand(2) to decide which to use.

Detect the block cipher mode the function is using each time. You should end up with a piece of code that, pointed at a block box that might be encrypting ECB or CBC, tells you which one is happening.

*/
package main

import (
	"bufio"
	"crypto/aes"
	"crypto/cipher"
	crand "crypto/rand"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"os"
	"strings"
	"time"
)

var (
	times = flag.Int("n", 1e6, "number of times to run")
)

func main() {
	rand.Seed(time.Now().UnixNano())
	log.SetFlags(0)
	log.SetPrefix("aes-ebc-cbc-oracle: ")
	flag.Parse()

	detect(*times)
}

// the idea here is the same as challenge 8
// since ECB is stateless and deterministic, we can just fill the buffers
// with a known plaintext constant and then let it encrypt, the random 5-10 byte
// padding will at most affect the first block and the end blocks
// Since this is ECB or CBC detection, we can take advantage
// of the fact that if it is encrypted in CBC, the blocks should never be the same even if
// we fill it with a constant byte stream or random padding, so to distinguish between EBC/CBC
// just see if all the blocks are unique or not. If it is unique, then we assume it is CBC
func detect(N int) {
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	for n := 1; n <= N; n++ {
		msg := []byte(strings.Repeat("A", 256*aes.BlockSize*aes.BlockSize))
		enc, startpad, endpad, mode := encrypt(msg)

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

		xmode := 'C'
		for i := range ip {
			if ip[i] != i {
				xmode = 'E'
				break
			}
		}

		fmt.Fprintf(w, "#%d start pad: %d end pad %d: actual: %c predicted: %c\n",
			n, startpad, endpad, mode, xmode)
		if xmode != mode {
			fmt.Fprintf(w, "FAILED PREDICTION\n")
			break
		}
	}
}

func encrypt(src []byte) (dst []byte, startpad, endpad int, mode rune) {
	key := randn(16)
	iv := randn(aes.BlockSize)

	ebc, err := aes.NewCipher(key)
	ck(err)

	startpad = 5 + rand.Intn(6)
	endpad = 5 + rand.Intn(6)
	for i := 0; i < startpad; i++ {
		src = append([]byte{randb()}, src...)
	}
	for i := 0; i < endpad; i++ {
		src = append([]byte{randb()}, src...)
	}

	pad := len(src) % aes.BlockSize
	if pad == 0 {
		pad = aes.BlockSize
	} else {
		pad = aes.BlockSize - pad
	}
	for i := 0; i < pad; i++ {
		src = append(src, byte(pad))
	}

	dst = make([]byte, len(src))
	mode = 'E'
	if rand.Intn(100) > 50 {
		for i := 0; i < len(src); i += aes.BlockSize {
			ebc.Encrypt(dst[i:], src[i:])
		}
	} else {
		cbc := cipher.NewCBCEncrypter(ebc, iv)
		cbc.CryptBlocks(dst, src)
		mode = 'C'
	}

	return
}

func randn(n int) []byte {
	p := make([]byte, n)
	_, err := crand.Read(p)
	ck(err)
	return p
}

func randb() byte {
	return byte(rand.Intn(256))
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}
