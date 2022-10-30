/*

Try to imagine a world in which you might have to stay home for 14 days at any given time. Do you have enough TP to make it through?

Although the number of squares per roll of TP varies significantly, we'll assume each roll has 500 sheets, and the average person uses 57 sheets per day.

Create a function that will receive a dictionary with two key/values:

    "people" ⁠— Number of people in the household.
    "tp" ⁠— Number of rolls.

Return a statement telling the user if they need to buy more TP!
Examples

tp_checker({ "people": 4, "tp": 1 }) ➞ "Your TP will only last 2 days, buy more!"

tp_checker({ "people": 3, "tp": 20 }) ➞ "Your TP will last 58 days, no need to panic!"

tp_checker({ "people": 4, "tp": 12 }) ➞ "Your TP will last 26 days, no need to panic!"

Notes

Stay safe, and happy coding!

*/

package main

import "fmt"

func main() {
	m1 := map[string]int{"people": 4, "tp": 1}
	m2 := map[string]int{"people": 2, "tp": 4}
	m3 := map[string]int{"people": 3, "tp": 20}
	m4 := map[string]int{"people": 4, "tp": 12}
	m5 := map[string]int{"people": 6, "tp": 8}
	m6 := map[string]int{"people": 1, "tp": 1}

	assert(tpcheck(m1) == "Your TP will only last 2 days, buy more!")
	assert(tpcheck(m2) == "Your TP will last 17 days, no need to panic!")
	assert(tpcheck(m3) == "Your TP will last 58 days, no need to panic!")
	assert(tpcheck(m4) == "Your TP will last 26 days, no need to panic!")
	assert(tpcheck(m5) == "Your TP will only last 11 days, buy more!")
	assert(tpcheck(m6) == "Your TP will only last 8 days, buy more!")
}

func tpcheck(m map[string]int) string {
	tp := m["tp"] * 500
	sh := m["people"] * 57
	nd := sh * 14
	if tp <= nd {
		return fmt.Sprintf("Your TP will only last %d days, buy more!", tp/sh)
	}
	return fmt.Sprintf("Your TP will last %d days, no need to panic!", tp/sh)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
