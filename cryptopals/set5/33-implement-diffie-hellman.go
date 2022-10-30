/*

Implement Diffie-Hellman

For one of the most important algorithms in cryptography this exercise couldn't be a whole lot easier.

Set a variable "p" to 37 and "g" to 5. This algorithm is so easy I'm not even going to explain it. Just do what I do.

Generate "a", a random number mod 37. Now generate "A", which is "g" raised to the "a" power mode 37 --- A = (g**a) % p.

Do the same for "b" and "B".

"A" and "B" are public keys. Generate a session key with them; set "s" to "B" raised to the "a" power mod 37 --- s = (B**a) % p.

Do the same with A**b, check that you come up with the same "s".

To turn "s" into a key, you can just hash it to create 128 bits of key material (or SHA256 it to create a key for encrypting and a key for a MAC).

Ok, that was fun, now repeat the exercise with bignums like in the real world. Here are parameters NIST likes:
p:
ffffffffffffffffc90fdaa22168c234c4c6628b80dc1cd129024
e088a67cc74020bbea63b139b22514a08798e3404ddef9519b3cd
3a431b302b0a6df25f14374fe1356d6d51c245e485b576625e7ec
6f44c42e9a637ed6b0bff5cb6f406b7edee386bfb5a899fa5ae9f
24117c4b1fe649286651ece45b3dc2007cb8a163bf0598da48361
c55d39a69163fa8fd24cf5f83655d23dca3ad961c62f356208552
bb9ed529077096966d670c354e4abc9804f1746c08ca237327fff
fffffffffffff

g: 2

This is very easy to do in Python or Ruby or other high-level languages that auto-promote fixnums to bignums, but it isn't "hard" anywhere.

Note that you'll need to write your own modexp (this is blackboard math, don't freak out), because you'll blow out your bignum library raising "a" to the 1024-bit-numberth power. You can find modexp routines on Rosetta Code for most languages.

*/

package main

import (
	"crypto/sha512"
	"fmt"
	"math/big"
	"math/rand"
	"time"
)

type DH struct {
	P, G *big.Int
	A, B *big.Int
	S    *big.Int
	K    [64]byte
}

func main() {
	dh := &DH{
		P: newint("37"),
		G: newint("5"),
	}
	gen(dh)
	print(dh)

	dh = &DH{
		P: newint("0xffffffffffffffffc90fdaa22168c234c4c6628b80dc1cd129024e088a67cc74020bbea63b139b22514a08798e3404ddef9519b3cd3a431b302b0a6df25f14374fe1356d6d51c245e485b576625e7ec6f44c42e9a637ed6b0bff5cb6f406b7edee386bfb5a899fa5ae9f24117c4b1fe649286651ece45b3dc2007cb8a163bf0598da48361c55d39a69163fa8fd24cf5f83655d23dca3ad961c62f356208552bb9ed529077096966d670c354e4abc9804f1746c08ca237327ffffffffffffffff"),
		G: newint("2"),
	}
	gen(dh)
	print(dh)
}

func print(dh *DH) {
	fmt.Printf("P=%v\n", dh.P)
	fmt.Printf("G=%v\n", dh.G)
	fmt.Printf("A=%v\n", dh.A)
	fmt.Printf("B=%v\n", dh.B)
	fmt.Printf("S=%v\n", dh.S)
	fmt.Printf("K=%v\n", dh.K)
	fmt.Printf("\n\n")
}

func newint(s string) *big.Int {
	v := new(big.Int)
	v.SetString(s, 0)
	return v
}

func randintm(m *big.Int) *big.Int {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	v := new(big.Int)
	v.Rand(r, m)
	return v
}

func exp(x, y, m *big.Int) *big.Int {
	v := new(big.Int)
	v.Exp(x, y, m)
	return v
}

func gen(dh *DH) {
	a := randintm(dh.P)
	b := randintm(dh.P)
	dh.A = exp(dh.G, a, dh.P)
	dh.B = exp(dh.G, b, dh.P)
	dh.S = exp(dh.B, a, dh.P)
	s := exp(dh.A, b, dh.P)
	if dh.S.Cmp(s) != 0 {
		panic("(A^b) mod p does not match (B^a) mod p")
	}

	// s is used to derive the hashing key, we can
	// use this key as input for AES keys or for MACs etc
	// when Bob sends Alice the encrypted data, alice can just
	// decrypt it by calculating her S which should match Bob's S
	// and rederive the hashing key to decrypt
	dh.K = sha512.Sum512(dh.S.Bytes())
}
