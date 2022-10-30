/*

So, I wrote myself a one-liner which printed out a snake on the console. It's a bit of fun, and I wondered how I might condense my code...

Here's a (short) example output:

                +
                 +
                  +
                   +
                   +
                   +
                  +
                   +
                    +
                    +
                    +
                     +
                     +
                      +
                      +
                       +
                      +
                     +
                     +
                    +

Here's the specs:

    In each line, a single non-whitespace character (whichever you like) is printed to the console, initially with 29 to 31 spaces padding to the left of it.
    Each iteration, a random decision is made between these three actions
        The amount of padding decreases by 1
        The amount of padding remains the same
        The amount of padding increases by 1

Do this 30 times, to print 30-segment long a snake to the console.

The shortest answer in bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	snake(29+rand.Intn(3), 30)
}

func snake(s, n int) {
	for i := 0; i < n; i++ {
		fmt.Printf("%s+\n", strings.Repeat(" ", s))
		s += 1 - rand.Intn(3)
	}
}
