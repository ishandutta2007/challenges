/*

create a program that will take user input and tell them their age in months, days, hours, and minutes

*/

package main

import "fmt"

func main() {
	fmt.Println(age(18))
}

func age(year int) (months, days, hours, minutes int) {
	months = 12 * year
	days = months * 365
	hours = days * 24
	minutes = hours * 60
	return
}
