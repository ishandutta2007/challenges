/*

Most of us LOST fans out there remember the computer that Desmond had to type the characters "4 8 15 16 23 42" in every 108 minutes or the world would end (or would it?).

The challenge here is to create a program that would do the same thing by requiring that every 108 seconds the input 4 8 15 16 23 42 is entered or it will display the message

Sorry, the world has ended with status code -1
It should warn the user at 100 seconds that they need to enter a number with the message

Enter, Quick!
The program must be able to read input at any time and if it is the correct input it will reset the timer. If incorrect input is given nothing happens.

The program should run indefinitely. So the timeline after the last valid input looks like

From 0 to 99 seconds: no output
At 100 seconds: Enter, Quick!
At 108 seconds: Sorry, the world has ended with status code -1.

This is code golf so the shortest answer (in bytes) that accomplishes this task wins! Good Luck!

*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

func main() {
	status := simulate(100*time.Second, 108*time.Second)
	os.Exit(status)
}

func simulate(warntime, endtime time.Duration) int {
	ch := make(chan int)
	go input(ch)

	warn := time.NewTicker(warntime)
	end := time.NewTicker(endtime)
	for {
		select {
		case value := <-ch:
			if value == -1 {
				return 0
			}
			warn.Reset(warntime)
			end.Reset(endtime)

		case <-warn.C:
			fmt.Println("Enter, Quick!")
			warn.Stop()

		case <-end.C:
			fmt.Println("Sorry, the world has ended with status code -1")
			return -1
		}
	}
}

func input(ch chan int) {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		if scanner.Text() == "4 8 15 16 23 42" {
			ch <- 1
		}
	}
	ch <- -1
}
