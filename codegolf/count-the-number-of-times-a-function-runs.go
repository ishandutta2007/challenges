/*

This is a teaser a friend of mine sent. It seems straightforward, but I can't seem to get my head around it, probably due to my lack of sleep.

    You have 16 bits available.
    Compose a function, and find a way to know when the function has run approximately one million times.
    You MAY NOT use any additional memory space other than the 16 bits given.
    Recursion may be used for efficiency, but, again, you MAY NOT use memory definition inside the recursion frames: only the 16 bits.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	var c Counter
	for i := 0; i < 50; i++ {
		c.Reset()
		for j := 0; j < 1e7; j++ {
			if c.Run() {
				fmt.Println(j, float64(j)/1e6)
				break
			}
		}
	}
}

type Counter struct {
	val uint16
}

func (c *Counter) Reset() {
	c.val = 0
}

func (c *Counter) Run() bool {
	v := rand.Intn(17)
	if v == 16 && c.val < 62501 {
		c.val++
	}
	return c.val == 62500
}
