/*

Write a function redundant that takes in a string str and returns
a function that returns str.

Notes

Your function should return a function, not a string.

*/

package main

import "fmt"

func main() {
	f1 := redundant("apple")
	f2 := redundant("pear")
	f3 := redundant("")

	fmt.Println(f1())
	fmt.Println(f2())
	fmt.Println(f3())
}

func redundant(s string) func() string {
	return func() string {
		return s
	}
}
