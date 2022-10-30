/*

A fruit juice company tags their fruit juices by concatenating the first three letters of the words in a flavor's name and its capacity.

Create a function that creates the product IDs for the variety of fruit juices.

Examples

getDrinkID("apple", "500ml") ➞ "APP500"

getDrinkID("pineapple", "45ml") ➞ "PIN45"

getDrinkID("passion fruit", "750ml") ➞ "PASFRU750"

Notes

    Capacity will be given as a string and will always be given in ml.
    Return the product ID in UPPERCASE.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(drinkid("apple", "500ml") == "APP500")
	assert(drinkid("pineapple", "45ml") == "PIN45")
	assert(drinkid("orange", "750ml") == "ORA750")
	assert(drinkid("passion fruit", "1ml") == "PASFRU1")
	assert(drinkid("mango", "1000ml") == "MAN1000")
	assert(drinkid("very berry", "253ml") == "VERBER253")
	assert(drinkid("raspberry and lime", "350ml") == "RASANDLIM350")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func drinkid(w, c string) string {
	var (
		s string
		v int
	)

	fmt.Sscanf(c, "%d", &v)

	t := strings.Split(w, " ")
	for _, p := range t {
		r := []rune(p)
		if len(r) > 3 {
			r = r[:3]
		}
		s += strings.ToUpper(string(r))
	}

	return s + fmt.Sprint(v)
}
