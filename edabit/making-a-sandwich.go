/*

Given an array of ingredients i and a string flavour f as input, create a function that returns the array but with the elements bread around the selected ingredient.
Examples

makeSandwich(["tuna", "ham", "tomato"], "ham") ➞ ["tuna", "bread", "ham", "bread", "tomato"]

makeSandwich(["cheese", "lettuce"], "cheese") ➞ ["bread", "cheese", "bread", "lettuce"]

makeSandwich(["ham", "ham"], "ham") ➞ ["bread", "ham", "bread", "bread", "ham", "bread"]

Notes

    You will always get valid inputs.
    Make two separate sandwiches if two of the same elements are next to each other (see example #3).

*/

package main

import "fmt"

func main() {
	fmt.Println(makesandwich([]string{"tuna", "ham", "tomato"}, "ham"))
	fmt.Println(makesandwich([]string{"cheese", "lettuce"}, "cheese"))
	fmt.Println(makesandwich([]string{"ham", "ham"}, "ham"))
	fmt.Println(makesandwich([]string{"t", "h", "t"}, "h"))
	fmt.Println(makesandwich([]string{"c", "l"}, "c"))
	fmt.Println(makesandwich([]string{"h", "h"}, "h"))
}

func makesandwich(s []string, v string) []string {
	var p []string
	for i := range s {
		if s[i] == v {
			p = append(p, "bread")
			p = append(p, s[i])
			p = append(p, "bread")
		} else {
			p = append(p, s[i])
		}
	}
	return p
}
