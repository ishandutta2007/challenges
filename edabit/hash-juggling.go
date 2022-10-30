/*

Create a function that:

    Creates a sha256 hash from an array of strings.
    Sort the hash string, alphas first digits second, maintaining the original order of alphas and digits (e.g. "7a2f7fdf31a4b" would be sorted as "affdfab727314").
    Returns a new sha256 hash from the sorted string.

Examples

hashOps(["string1", "string2", "string3"]) ➞ "2d3b990149219819705bfe290571a9dcf5cf2a2528a2c711a57bd430ce32497f"

hashOps(["quick", "brown", "fox"] ) ➞ "7a2f7fdf31a4b14dd4f67e5ca8da3dabd7eac825eac259682e43d7e477b3d378"

hashOps(["i", "am", "not", "a", "crook"]) ➞ "d94ffa741e59d434b9e9e2ed32c2efc128238ba29eaa79cd0283d17a04a2d93f"

Notes

Remember to encode your strings.

*/

package main

import (
	"crypto/sha256"
	"fmt"
)

func main() {
	assert(hash([]string{"string1", "string2", "string3"}) == "2d3b990149219819705bfe290571a9dcf5cf2a2528a2c711a57bd430ce32497f")
	assert(hash([]string{"quick", "brown", "fox"}) == "7a2f7fdf31a4b14dd4f67e5ca8da3dabd7eac825eac259682e43d7e477b3d378")
	assert(hash([]string{"i", "am", "not", "a", "crook"}) == "d94ffa741e59d434b9e9e2ed32c2efc128238ba29eaa79cd0283d17a04a2d93f")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hash(s []string) string {
	h := sha256.New()
	for i := range s {
		h.Write([]byte(s[i]))
	}

	b := []byte(fmt.Sprintf("%x", h.Sum(nil)))
	p := cdsort(b)
	r := fmt.Sprintf("%x", sha256.Sum256(p))
	return r
}

func cdsort(b []byte) []byte {
	x := make([]byte, len(b))
	y := make([]byte, len(b))
	n := 0
	m := 0
	for _, c := range b {
		if !('0' <= c && c <= '9') {
			x[n], n = c, n+1
		} else {
			y[m], m = c, m+1
		}
	}
	return []byte(fmt.Sprintf("%s%s", x[:n], y[:m]))
}
