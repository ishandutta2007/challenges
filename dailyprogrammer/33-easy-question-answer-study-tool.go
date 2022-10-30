/*

This would be a good study tool too. I made one myself and I thought it would also be a good challenge.

Write a program that prints a string from a list at random, expects input, checks for a right or wrong answer, and keeps doing it until the user types "exit".
If given the right answer for the string printed, it will print another and continue on. If the answer is wrong, the correct answer is printed and the program continues.

Bonus: Instead of defining the values in the program, the questions/answers is in a file, formatted for easy parsing.

Example file:
12 * 12?,144
What is reddit?,website with cats
Translate: hola,hello

    thanks to Iggyhopper for the challenge at /r/dailyprogrammer_ideas
*/

package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	study([][2]string{
		{"12*12?", "144"},
		{"What is reddit?", "website with cats"},
		{"Translate: hola", "hello"},
	})
}

func study(s [][2]string) {
	n := len(s)
	b := bufio.NewScanner(os.Stdin)
	for {
		i := rand.Intn(n)
		fmt.Println(s[i][0])
		if !b.Scan() {
			break
		}

		t := strings.TrimSpace(b.Text())
		t = strings.ToLower(t)
		if t == "exit" {
			break
		}

		if t == s[i][1] {
			fmt.Println("You are right!")
		} else {
			fmt.Println("You are wrong! the correct answer is:", s[i][1])
		}
		fmt.Println()
	}
}
