/*

Your challenge is to make an infinite loading screen, that looks like this:

Loading...\

Or, to be more specific:

    Take no input.
    Output Loading..., with a trailing space, but no trailing newline.
    Infinitely cycle through the chars |, /, - and \: every 0.25 seconds, overwrite the last one with the next in the sequence. You can overwrite just the last character, or delete and rewrite the whole line, as long Loading... remains unchanged.

Rules

    The output text must look exactly as specified. Trailing newlines/spaces are acceptable.
    You should not wait 0.25 seconds before initially showing output - the first frame should be printed as soon as the program is run.
    Your program should be able to run indefinitely. For example, if you use a counter for frames, the counter should never cause an error by exceeding the maximum in your language.
    Although the waiting period between each "frame" should be 0.25 seconds, obviously this will never be exact - an error margin of 10% or so is allowed.
    You may submit a function, but it must print to stdout.
    You can submit an answer in a non-console (but still text-based) environment, as long as it is capable of producing the loading animation.
    This is code-golf, so the shortest solution (in bytes) wins. Standard code-golf loopholes apply.
    If possible, please provide a gif of your loading screen in action.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	tab := []rune{'|', '/', '-', '\\'}
	fmt.Printf("Loading...")
	for i := 0; ; i = (i + 1) & 3 {
		fmt.Printf("%c", tab[i])
		time.Sleep(250 * time.Millisecond)
		fmt.Printf("\b")
	}
}
