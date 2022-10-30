/*

AES in ECB mode
The Base64-encoded content in this file has been encrypted via AES-128 in ECB mode under the key

"YELLOW SUBMARINE".
(case-sensitive, without the quotes; exactly 16 characters; I like "YELLOW SUBMARINE" because it's exactly 16 bytes long, and now you do too).

Decrypt it. You know the key, after all.

Easiest way: use OpenSSL::Cipher and give it AES-128-ECB as the cipher.

*/

package main

import (
	"bufio"
	"crypto/aes"
	"encoding/base64"
	"flag"
	"fmt"
	"io"
	"os"
)

var (
	key = flag.String("k", "YELLOW SUBMARINE", "use key")

	status = 0
)

func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		decrypt("<stdin>", os.Stdin, []byte(*key))
	} else {
		for _, name := range flag.Args() {
			f, err := os.Open(name)
			if ek(err) {
				continue
			}
			ek(decrypt(name, bufio.NewReader(f), []byte(*key)))
			f.Close()
		}
	}
	os.Exit(status)
}

func ek(err error) bool {
	if err != nil {
		fmt.Fprintln(os.Stderr, "aes-ecb-decrypt: ", err)
		status = 1
		return true
	}
	return false
}

func decrypt(name string, r io.Reader, key []byte) error {
	cipher, err := aes.NewCipher(key)
	if err != nil {
		return fmt.Errorf("%v: %v", name, err)
	}

	buf, err := io.ReadAll(r)
	if err != nil {
		return fmt.Errorf("%v: %v", name, err)
	}

	src, err := base64.StdEncoding.DecodeString(string(buf))
	if err != nil {
		return fmt.Errorf("%v: %v", name, err)
	}

	dst := make([]byte, aes.BlockSize)
	for i := 0; i < len(src); i += aes.BlockSize {
		cipher.Decrypt(dst, src[i:])
		fmt.Printf("%s", dst)
	}
	return nil
}
