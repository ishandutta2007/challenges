/*

Write a regular expression that matches only an even number. Numbers will be presented as strings.

Notes

This challenge is designed to use Regex only.

*/

package main

import (
	"fmt"
	"math/rand"
	"regexp"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(iseven("2341"))
	fmt.Println(iseven("132"))
	fmt.Println(iseven("29"))
	fmt.Println(iseven("5578"))
	for i := 0; i < 5; i++ {
		x := rand.Intn(7000) * 2
		y := rand.Intn(7000)*2 + 1
		fmt.Println(x, iseven(fmt.Sprint(x)))
		fmt.Println(y, iseven(fmt.Sprint(y)))
	}
}

func iseven(s string) bool {
	m, _ := regexp.MatchString("^\\d*[02468]$", s)
	return m
}
