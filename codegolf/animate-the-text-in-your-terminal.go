/*

The goal is to "animate" the string "Hello world" in your output so that each character gets capitalised after each other.

Your program can exit after each letter has been capitalised.

For example;

# Iteration 1
Hello world

# Iteration 2
hEllo world

# Iteration 3
heLlo world

# Iteration 4
helLo world

# Iteration 5
hellO world

# Iteration 6 (note: it should capitilize the space char (ie: a break between iteration 5 and iteration 7)
hello world

# Iteration 7
hello World

# Iteration 8
hello wOrld

# Iteration 9
hello woRld

# Iteration 10
hello worLd

# Iteration 11
hello worlD
It should only animate the string once and between each state there should be a 1 second delay.

Input

No input is required, but "Hello world" must be the string that is "animated".

Output

The string "Hello world" must be animated. The output must be as 1 line to create a sort of wave animation. An empty trailing new line is allowed. Example gif;

https://i.gyazo.com/be12b693063b463540c5bf1f03d2454a.gif

I saw this on a metasploit youtube video and thought the effect was pretty cool, which is where I recorded the gif from, so it's a little laggy, but I hope it illustrates the output fine

This is code-golf, lowest byte-count will be deemed the winner.

*/

package main

import (
	"fmt"
	"time"
	"unicode"
)

func main() {
	animate("Hello world", 1*time.Second)
}

func animate(text string, delay time.Duration) {
	r := []rune(text)
	n := len(r)
	for i := 0; i < n; i++ {
		fmt.Printf("\x1bc")
		for j := 0; j < n; j++ {
			c := r[j]
			if i == j {
				c = unicode.ToUpper(c)
			} else {
				c = unicode.ToLower(c)
			}
			fmt.Printf("%c", c)
		}
		time.Sleep(delay)
	}
	fmt.Println()
}
