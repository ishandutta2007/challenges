/*

Your task today is to implement a time limit for getting input, a task I've found rather annoying to achieve in most languages.

You will create a program function which prompts the user for input. Immediatly after the user supplies input, print the message input received and end execution/return.
However, if the user waits for more than 10 seconds to provide input, output the message no input received and end execution/return.

Input must be from stdin (the console) or equivalent, not function or program arguments, however output can be either to stdout, your function's return value, or any other accepted output method.

You may ask for any amount of input, it can be a single character, a line, a word, or whatever method is shortest in your language as long as it waits for at least one character.

You must output as soon as the input is received, not after the 10 seconds have passed.

After 10 seconds have passed, you must end, you cannot continue waiting for input after no input received has been printed.

You may assume that input is not passed in the time between 10 seconds elapsing and text being printed to the screen, as this is an extremely small window. You may also assume that your language's builtin equivalent of sleep is consistently, absolutely perfect.

This is code-golf, fewest bytes wins!

*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

func main() {
	tc := time.After(10 * time.Second)
	ic := make(chan string)
	go input(ic)

	fmt.Printf("input> ")
	select {
	case <-tc:
		fmt.Println("no input received")
	case <-ic:
		fmt.Println("input received")
	}
}

func input(ic chan string) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()

	ic <- sc.Text()
}
