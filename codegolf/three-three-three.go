/*

Write a program that produces an output such that:

    At least three distinct characters appear.
    The number of occurrences of each character is a multiple of 3.

For example, A TEA AT TEE is a valid output since each of the 4 distinct characters, A, E, T and (space), occurs 3 times.

Of course, a challenge about the number 3 needs to have a third requirement. So:

    The program itself must also follow the first two requirements. (This means your program will be at least 9 bytes long.)

You must write a full program, not a function. Be sure to show your program's output in your answer.

Also, to keep things interesting, you are highly encouraged:

    not to use comments to meet requirement 3 if you can help it
    to produce output that isn't just a string repeated 3 times
    to make the output different from the program itself (for languages that can automatically output the contents of its own program, you can contribute to this community wiki).

This is code-golf. Shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
	"unicode"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(three(10))
}

func three(n int) string {
	var r, t []rune
	for i := 0; i < n; {
		v := rune(rand.Intn(unicode.MaxRune))
		if !unicode.IsPrint(v) {
			continue
		}
		for j := 0; j < 3; j++ {
			t = append(t, v)
		}
		i++
	}

	p := rand.Perm(len(t))
	for i := range p {
		r = append(r, t[p[i]])
	}

	return string(r)
}
