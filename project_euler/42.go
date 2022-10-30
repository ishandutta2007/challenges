/*

Coded triangle numbers

The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

*/

package main

import (
	"encoding/csv"
	"fmt"
	"log"
	"math"
	"os"
)

func main() {
	words, err := readcsv("p042_words.txt")
	if err != nil {
		log.Fatal(err)
	}

	c := 0
	for _, w := range words {
		if istri(ascval(w)) {
			c++
		}
	}
	fmt.Println(c)
}

func readcsv(name string) ([]string, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r := csv.NewReader(f)
	recs, err := r.ReadAll()
	if err != nil {
		return nil, err
	}

	var vals []string
	for i := range recs {
		for j := range recs[i] {
			vals = append(vals, recs[i][j])
		}
	}

	return vals, nil
}

func ascval(str string) int {
	v := 0
	for _, r := range str {
		switch {
		case 'A' <= r && r <= 'Z':
			v += int(r) - 'A' + 1
		case 'a' <= r && r <= 'z':
			v += int(r) - 'a' + 1
		}
	}
	return v
}

// to be a triangle number, must satisfy
// Tn = 0.5n(n+1) for some n
// x = 0.5n(n+1)
// 2x = n(n+1)
// n^2 + n - 2x = 0
// n = (sqrt(1+8x) - 1) / 2 ->
// 1+8x must be odd and a perfect square
func istri(x int) bool {
	if x <= 0 {
		return false
	}

	t := 1 + 8*x
	if t&1 == 0 {
		return false
	}
	u := int(math.Sqrt(float64(t)))
	return u*u == t
}
