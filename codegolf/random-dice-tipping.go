/*

In a standard dice (die) the numbers are arranged so that opposite faces add to seven. Write the shortest possible program in your preferred language which outputs a random throw followed by 9 random tippings.
A tipping is a quarter turn of the dice, e.g. if the dice is facing 5, all possible tippings are 1,3,4 and 6.

Example of desired output:

    1532131356

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 30; i++ {
		fmt.Println(roll())
	}
}

func roll() []int {
	var r []int
	for {
		n := len(r)
		if n >= 10 {
			break
		}

		v := rand.Intn(6) + 1
		if n == 0 || (r[n-1]+v != 7 && r[n-1] != v) {
			r = append(r, v)
		}
	}
	return r
}
