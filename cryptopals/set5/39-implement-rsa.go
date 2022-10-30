/*

Implement RSA

There are two annoying things about implementing RSA. Both of them involve key generation; the actual encryption/decryption in RSA is trivial.

First, you need to generate random primes. You can't just agree on a prime ahead of time, like you do in DH. You can write this algorithm yourself, but I just cheat and use OpenSSL's BN library to do the work.

The second is that you need an "invmod" operation (the multiplicative inverse), which is not an operation that is wired into your language. The algorithm is just a couple lines, but I always lose an hour getting it to work.

I recommend you not bother with primegen, but do take the time to get your own EGCD and invmod algorithm working.

Now:

    Generate 2 random primes. We'll use small numbers to start, so you can just pick them out of a prime table. Call them "p" and "q".
    Let n be p * q. Your RSA math is modulo n.
    Let et be (p-1)*(q-1) (the "totient"). You need this value only for keygen.
    Let e be 3.
    Compute d = invmod(e, et). invmod(17, 3120) is 2753.
    Your public key is [e, n]. Your private key is [d, n].
    To encrypt: c = m**e%n. To decrypt: m = c**d%n
    Test this out with a number, like "42".
    Repeat with bignum primes (keep e=3).

Finally, to encrypt a string, do something cheesy, like convert the string to hex and put "0x" on the front of it to turn it into a number. The math cares not how stupidly you feed it strings.

*/

package main

import (
	"crypto/rand"
	"encoding/hex"
	"flag"
	"fmt"
	"log"
	"math/big"
	"strings"
)

type Key struct {
	P, Q *big.Int
	D    *big.Int
	N    *big.Int
	E    *big.Int
}

var flags struct {
	Bits int
}

func main() {
	parseflags()

	s := "the fox jumped over the brown thing"
	if flag.NArg() >= 1 {
		s = strings.Join(flag.Args(), " ")
	}
	// to be able to encrypt a message as a number in one go, the prime bits
	// must be at least as long as the message itself, or else it will wrap
	// in practice, we need to split up the message but here we just
	// take it length of the string and make the primes as big as it
	if flags.Bits < len(s)*4 {
		flags.Bits = len(s) * 4
	}
	k := genkey()
	if k == nil {
		log.Fatalf("failed to generate key")
	}
	printkey(k)

	c := encrypt(k, s)
	m := decrypt(k, c)
	fmt.Printf("STRING=%q\n", s)
	fmt.Printf("ENCRYPT=%v\n", c)
	fmt.Printf("DECRYPT=%q\n", m)
}

func parseflags() {
	flag.IntVar(&flags.Bits, "b", 100, "size of the primes in bits")
	flag.Parse()
}

func genkey() *Key {
	var k *Key

	times := 1000
	tries := 0
	for ; tries <= times; tries++ {
		k = &Key{
			P: genprime(),
			Q: genprime(),
			N: new(big.Int),
			D: new(big.Int),
			E: new(big.Int),
		}

		// P and Q has to be distinct prime
		if k.P.Cmp(k.Q) == 0 {
			continue
		}

		k.N.Mul(k.P, k.Q)

		one := new(big.Int).SetUint64(1)
		A := new(big.Int)
		B := new(big.Int)
		ET := new(big.Int)
		A.Sub(k.P, one)
		B.Sub(k.Q, one)
		ET.Mul(A, B)

		k.E.SetUint64(3)
		k.D.ModInverse(k.E, ET)

		// https://crypto.stackexchange.com/questions/12255/in-rsa-why-is-it-important-to-choose-e-so-that-it-is-coprime-to-%CF%86n
		// E is not relatively prime to phi(n) (ET) then it is not possible to decrypt it uniquely
		// we need it so that it is possible to decrypt it uniquely
		G := new(big.Int)
		G.GCD(nil, nil, ET, k.E)
		if G.Cmp(one) == 0 {
			break
		}
	}

	if tries >= times {
		return nil
	}

	return k
}

func genprime() *big.Int {
	P, err := rand.Prime(rand.Reader, flags.Bits)
	if err != nil {
		panic(err)
	}
	return P
}

func printkey(k *Key) {
	fmt.Printf("P=%v\n", k.P)
	fmt.Printf("Q=%v\n", k.Q)
	fmt.Printf("N=%v\n", k.N)
	fmt.Printf("E=%v\n", k.E)
	fmt.Printf("D=%v\n", k.D)
}

func encrypt(k *Key, s string) *big.Int {
	p := "0x" + hex.EncodeToString([]byte(s))
	m := new(big.Int)
	m.SetString(p, 0)

	c := new(big.Int)
	c.Exp(m, k.E, k.N)

	return c
}

func decrypt(k *Key, c *big.Int) string {
	m := new(big.Int)
	m.Exp(c, k.D, k.N)
	x := fmt.Sprintf("%x", m)
	s, _ := hex.DecodeString(x)
	return string(s)
}