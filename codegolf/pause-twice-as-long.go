/*

Your challenge is to print the input, wait any amount of time, print the input, wait twice the time you initially waited, print the input again, and so on.
The initial delay must be less than 1 hour, and you must have an accuracy of +/- 5% in the subsequent delays. Other than that, there is no restriction on the delay time.

Example:

Input: hi.

Output: hi (1ms pause) hi (2ms pause) hi (4ms pause) hi (8ms pause) hi (16ms pause), etc.

Also allowed:

hi (1 minute pause) hi (2 minute pause) hi (4 minute pause) hi (8 minute pause) hi (16 minute pause), etc.

Input must be provided at the start of the program (STDIN, command-line parameter, function param, etc.) and will be a string.

The initial delay can't be 0.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	output("hi")
}

func output(s string) {
	d := 1 * time.Millisecond
	for {
		fmt.Println(s)
		time.Sleep(d)
		d *= 2
	}
}
