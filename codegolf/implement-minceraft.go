/*

Introduction

The game Minecraft has a 1 in 10000 chance of showing "Minceraft" instead of "Minecraft" on the title screen.
Your challenge

Your challenge is to code a function or program that takes no input, and on average 1 of 10000 times, returns "Minceraft" and the rest of the time returns "Minecraft".
Scoring

This is code-golf, shortest wins!

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	const N = 10000
	for i := 0; i < N; i++ {
		var p [2]float64
		for j := 0; j < N; j++ {
			if minecraft() == "Mincecraft" {
				p[0]++
			} else {
				p[1]++
			}
		}
		fmt.Printf("%f %f\n", p[0], p[1])
	}
}

func minecraft() string {
	v := rand.Intn(10000)
	if v == 0 {
		return "Mincecraft"
	}
	return "Minecraft"
}
