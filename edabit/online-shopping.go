/*

Create a function that determines whether a shopping order is eligible for free shipping. An order is eligible for free shipping if the total cost of items purchased exceeds $50.00.
Examples

freeShipping({ "Shampoo": 5.99, "Rubber Ducks": 15.99 }) ➞ false

freeShipping({ "Flatscreen TV": 399.99 }) ➞ true

freeShipping({ "Monopoly": 11.99, "Secret Hitler": 35.99, "Bananagrams": 13.99 }) ➞ true

Notes

Ignore tax or additional fees when calculating the total order cost.

*/

package main

type Items map[string]float64

func main() {
	assert(freeship(Items{"Shampoo": 5.99, "Rubber Ducks": 15.99}) == false)
	assert(freeship(Items{"Flatscreen TV": 399.99}) == true)
	assert(freeship(Items{"Monopoly": 11.99, "Secret Hitler": 35.99, "Bananagrams": 13.99}) == true)
	assert(freeship(Items{"Scrabble": 12.32, "Jenga": 5.55, "Clue": 20.00}) == false)
	assert(freeship(Items{"Elephant Plushie": 40.55, "Octopus Plushie": 20.33, "Spongebob Plushie": 20.00}) == true)
}

func freeship(m Items) bool {
	r := 0.0
	for _, v := range m {
		r += v
	}
	return r > 50
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
