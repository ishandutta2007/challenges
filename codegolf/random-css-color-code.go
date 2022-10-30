/*

This blog post about generating random CSS color codes in JavaScript have multiple solutions for generating a random color in JavaScript. The shortest I can find is this:

'#'+(Math.random()*0xffffff).toString(16).slice(-6)

If you are not familiar with CSS color code read documentations here.

Can we do better? What about other languages?

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 10; i++ {
		fmt.Println(randcss())
	}
}

func randcss() string {
	return fmt.Sprintf("#%06X", rand.Intn(0x1000000))
}
