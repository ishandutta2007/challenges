/*

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

*/
package main

import "fmt"

func main() {
	fmt.Println(count("aA", "aAAbbbb"))
	fmt.Println(count("z", "ZZ"))
}

func count(j, s string) int {
	m := make(map[rune]bool)
	for _, r := range j {
		m[r] = true
	}

	c := 0
	for _, r := range s {
		if m[r] {
			c++
		}
	}
	return c
}
