/*

The Challenge

Create a program that brute-force* decodes the MD5-hashed string, given here: 92a7c9116fa52eb83cf4c2919599c24a which translates to code-golf
The Rules

    You may not use any built-in functions that decode the hash for you if the language you choose has such.
    You may not use an online service to decode the hash for you.
    This is code-golf, the program that accomplishes the task in the shortest amount of characters wins.

Good luck. May the brute-force be with you.

*Brute-Force definition: looping from a-zzz.. including abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=[]\;',./~!@#$%^&*()_+{}|:"`<>? in a string, hashing it,
and testing it against the hash given until the correct string that has been hashed has been found. Print the string to the program's output stream.

*/

package main

import (
	"bytes"
	"crypto/md5"
	"fmt"
)

func main() {
	var (
		hash  = "92a7c9116fa52eb83cf4c2919599c24a"
		alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=[]\\;',./~!@#$%^&*()_+{}|:\"`<>?"
		seed  = mkseed("code-golf", alpha)
	)
	fmt.Println(brute(hash, alpha, seed))
}

func brute(h, a string, d []int) string {
	var (
		r string
		p = d
	)
	for {
		s := mkstr(p, a)
		m := fmt.Sprintf("%x", md5.Sum([]byte(s)))
		if h == m {
			r = s
			break
		}
		p = iter(p, a)
	}
	return r
}

func iter(p []int, a string) []int {
	n := len(a)
	i := 0
	for ; i < len(p); i++ {
		if p[i]++; p[i] >= n {
			p[i] = 0
		} else {
			break
		}
	}
	if i >= len(p) {
		p = append(p, 0)
	}

	return p
}

func mkstr(p []int, a string) string {
	w := new(bytes.Buffer)
	for _, i := range p {
		w.WriteByte(a[i])
	}
	return w.String()
}

func mkseed(s, a string) []int {
	p := []int{}
loop:
	for i := range s {
		for j := range a {
			if s[i] == a[j] {
				p = append(p, j)
				continue loop
			}
		}
	}
	return p
}
