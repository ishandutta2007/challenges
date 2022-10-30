/*

Background

The Zundoko Kiyoshi function originates from this tweet by kumiromilk. Translated from Japanese, it reads roughly as follows:

    The test for my Java lecture had a problem that said "Implement and describe your own function".
	I made it continuously output either "zun" or "doko" randomly; if the sequence "zun", "zun", "zun", "zun", "doko" appears, it outputs "ki-yo-shi!" and terminates. Then I got full marks and earned a unit.

This is in reference to Kiyoshi Hikawa's song Kiyoshi no Zundoko Bushi: when he sings the aforementioned line, the crowd cheers "ki-yo-shi!" in response.
Task

Write a program or function that takes no input and replicates the behavior outlined in the tweet:

    Repeatedly output either zun or doko, choosing uniformly randomly each time.
    If the sequence ["zun", "zun", "zun", "zun", "doko"] appears in the output, output ki-yo-shi! and halt.

Example output:

doko
zun
zun
doko
doko
zun
zun
zun
zun
zun
doko
ki-yo-shi!

Rules

    This is code-golf, so shortest answer in bytes wins.
    Your output can be a list of strings, or each string printed with some delimiter.
    Your output has to be non-deterministic.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	sim()
}

func sim() {
	choices := []string{"zun", "doko"}
	phrase := []string{"zun", "zun", "zun", "zun", "doko"}

	for i := 0; i < len(phrase); i++ {
		j := rand.Intn(len(choices))
		if choices[j] != phrase[i] {
			i = -1
		}
		fmt.Println(choices[j])
	}
	fmt.Println("ki-yo-shi!")
}
