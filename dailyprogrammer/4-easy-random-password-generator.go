/*

You're challenge for today is to create a random password generator!

For extra credit, allow the user to specify the amount of passwords to generate.

For even more extra credit, allow the user to specify the length of the strings he wants to generate!

*/

package main

import (
	"crypto/rand"
	"flag"
	"fmt"
)

func main() {
	var (
		N uint
		L uint
	)
	flag.UintVar(&N, "n", 1, "number of passwords to generate")
	flag.UintVar(&L, "l", 32, "length of the passwords generated")
	flag.Parse()

	vocab := []rune{'@', '_', '<', '>', '?', '!', '#', '$', '%', '^', '&', '*', '(', ')'}
	for r := '0'; r <= '9'; r++ {
		vocab = append(vocab, r)
	}
	for r := 'a'; r <= 'z'; r++ {
		vocab = append(vocab, r)
	}
	for r := 'A'; r <= 'Z'; r++ {
		vocab = append(vocab, r)
	}

	pass := make([]rune, L)
	buf := make([]byte, L)
	for i := uint(0); i < N; i++ {
		_, err := rand.Read(buf)
		if err != nil {
			panic(err)
		}
		for j := range pass {
			pass[j] = vocab[int(buf[j])%len(vocab)]
		}
		fmt.Printf("%s\n", string(pass))
	}
}
