/*

You have to create a code which prints

:)
a random number of times from 1 to 255 inclusive. Your output may not contain any whitespace.

Your score :
The count in bytes

EDIT : Also show 3 outputs of your code

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	smiley(1 + rand.Intn(255))
}

func smiley(n int) {
	for i := 0; i < n; i++ {
		fmt.Printf(":)\n")
	}
}
