/*

Create a function that takes a division equation $str and checks if it will return a whole number without decimals after dividing.

Examples

validDivision("6/3") ➞ true

validDivision("30/25") ➞ false

validDivision("0/3") ➞ true

Notes

Return "invalid" if division by zero.

*/

package main

import "fmt"

func main() {
	assert(divisible("6/3") == true)
	assert(divisible("30/25") == false)
	assert(divisible("0/3") == true)
	assert(divisible("13/12") == false)
	assert(divisible("329/329") == true)
	assert(divisible("0/0") == "invalid")
	assert(divisible("10/0") == "invalid")
	assert(divisible("20/5") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func divisible(s string) interface{} {
	var x, y int
	n, _ := fmt.Sscanf(s, "%d/%d", &x, &y)
	if n != 2 || y == 0 {
		return "invalid"
	}
	return x%y == 0
}
