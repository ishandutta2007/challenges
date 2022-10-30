/*

Write a program that will compare two lists, and append any elements in the second list that doesn't exist in the first.

input: ["a","b","c",1,4,], ["a", "x", 34, "4"]

output: ["a", "b", "c",1,4,"x",34, "4"]

*/

package main

import "fmt"

func main() {
	a := []interface{}{"a", "b", "c", 1, 4}
	b := []interface{}{"a", "x", 34, "4"}
	c := cmp(a, b)
	fmt.Println(c)
}

func cmp(a, b []interface{}) []interface{} {
	c := make([]interface{}, len(a))
	copy(c, a)
loop:
	for i := range b {
		for j := range a {
			if b[i] == a[j] {
				continue loop
			}
		}
		c = append(c, b[i])
	}
	return c
}
