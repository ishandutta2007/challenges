/*

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.


*/
package main

import "fmt"

func main() {
	fmt.Println(fizzbuzz(15))
}

func fizzbuzz(n int) []string {
	var p []string
	for i := 1; i <= n; i++ {
		switch {
		case i%3 == 0 && i%5 == 0:
			p = append(p, "FizzBuzz")
		case i%3 == 0:
			p = append(p, "Fizz")
		case i%5 == 0:
			p = append(p, "Buzz")
		default:
			p = append(p, fmt.Sprint(i))
		}
	}
	return p
}
