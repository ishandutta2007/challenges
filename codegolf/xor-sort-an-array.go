/*

Given a key, and an array of strings, shuffle the array so that it is sorted when each element is XOR'd with the key.

XOR'ing two strings
To XOR a string by a key, XOR each of the character values of the string by its pair in the key, assuming that the key repeats forever. For example, abcde^123 looks like:

       a        b        c        d        e
       1        2        3        1        2
--------------------------------------------
01100001 01100010 01100011 01100100 01100101
00110001 00110010 00110011 00110001 00110010
--------------------------------------------
01010000 01010000 01010000 01010101 01010111
--------------------------------------------
       P        P        P        U        W
Sorting
Sorting should always be done Lexicographically of the XOR'd strings. That is, 1 < A < a < ~ (Assuming ASCII encoding)

Example
"912", ["abcde", "hello", "test", "honk"]

-- XOR'd
["XSQ]T", "QT^U^", "MTAM", "Q^\R"]
-- Sorted
["MTAM", "QT^U^", "Q^\R", "XSQ]T"]
-- Converted back
["test", "hello", "honk", "abcde"]

Notes
Key will always be at least 1 character
Key and Input will only consist of printable ASCII.
XOR'd strings may contain non-printable characters.
Input and Output may be done through the Reasonable Methods
Standard Loopholes are forbidden.
You may take Key and Input in any order.

Test Cases
key, input -> output
--------------------
"912", ["abcde", "hello", "test", "honk"] -> ["test", "hello", "honk", "abcde"]
"taco", ["this", "is", "a", "taco", "test"] -> ["taco", "test", "this", "a", "is"]
"thisisalongkey", ["who", "what", "when"] -> ["who", "what", "when"]
"3", ["who", "what", "when"] -> ["what", "when", "who"]

*/

package main

import (
	"bytes"
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test("912", []string{"abcde", "hello", "test", "honk"}, []string{"test", "hello", "honk", "abcde"})
	test("taco", []string{"this", "is", "a", "taco", "test"}, []string{"taco", "test", "this", "a", "is"})
	test("thisisalongkey", []string{"who", "what", "when"}, []string{"who", "what", "when"})
	test("3", []string{"who", "what", "when"}, []string{"what", "when", "who"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(k string, s, r []string) {
	p := xorsort(k, s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func xorsort(k string, s []string) []string {
	var (
		n = len(s)
		p = make([][2]string, n)
		r = make([]string, n)
	)

	for i := range s {
		p[i] = [2]string{s[i], xorstr(k, s[i])}
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i][1] < p[j][1]
	})

	for i := range r {
		r[i] = p[i][0]
	}
	return r
}

func xorstr(k, s string) string {
	n := len(s)
	m := len(k)
	if m == 0 {
		return ""
	}

	w := new(bytes.Buffer)
	for i := 0; i < n; i++ {
		w.WriteByte(s[i] ^ k[i%m])
	}
	return w.String()
}
