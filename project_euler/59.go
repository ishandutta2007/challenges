/*

XOR decryption

Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using p059_cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.

*/

package main

import (
	"bytes"
	"encoding/csv"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {
	err := process("p059_cipher.txt")
	if err != nil {
		log.Fatal(err)
	}
}

func process(name string) error {
	f, err := os.Open(name)
	if err != nil {
		return err
	}
	defer f.Close()

	r := csv.NewReader(f)
	recs, err := r.ReadAll()
	if err != nil {
		return err
	}

	var c []int
	for i := range recs {
		for j := range recs[i] {
			v, _ := strconv.Atoi(recs[i][j])
			c = append(c, v)
		}
	}
	p := make([]int, len(c))

	var k [3]int
	for k[0] = 'a'; k[0] <= 'z'; k[0]++ {
		for k[1] = 'a'; k[1] <= 'z'; k[1]++ {
			for k[2] = 'a'; k[2] <= 'z'; k[2]++ {
				xor(k[:], c, p)
				if valid(p) {
					fmt.Printf("sum=%d\n", sum(p))
					fmt.Printf("key=%s\n", i2s(k[:]))
					fmt.Println(i2s(p))
				}
			}
		}
	}
	return nil
}

func sum(p []int) int {
	s := 0
	for i := range p {
		s += p[i]
	}
	return s
}

func i2s(p []int) string {
	w := new(bytes.Buffer)
	for i := range p {
		w.WriteByte(byte(p[i]))
	}
	return w.String()
}

func xor(k, c, p []int) {
	for i := range c {
		p[i] = c[i] ^ k[i%len(k)]
	}
}

func valid(p []int) bool {
	for i := range p {
		if !(32 <= p[i] && p[i] <= 127) {
			return false
		}
	}

	w := []string{"the", "to", "be", "of", "and", "a", "in", "that", "have"}
	s := strings.ToLower(i2s(p))
	for i := range w {
		if strings.Index(s, w[i]) < 0 {
			return false
		}
	}

	return true
}
