/*

Your task is to create a function that simulates a vending machine.

Given an amount of money (in cents ¢ to make it simpler) and a productNumber, the vending machine should output the correct product name and give back the correct amount of change.

The coins used for the change are the following: [500, 200, 100, 50, 20, 10]

The return value is an object with 2 properties:

    product: the product name that the user selected.
    change: an array of coins (can be empty, must be sorted in descending order).

Examples

vendingMachine(products, 200, 7) ➞ { product: "Crackers", change: [ 50, 20, 10 ] }

vendingMachine(products, 500, 0) ➞ "Enter a valid product number"

vendingMachine(products, 90, 1) ➞ "Not enough money for this product"

Notes

    The products are fixed and you can find them in the Tests tab.
    If productNumber is invalid (out of range) you should return the string: "Enter a valid product number".
    If money is not enough to buy a certain product you should return the string: "Not enough money for this product".
    If there's no change, return an empty array as the change.

*/

package main

import (
	"reflect"
)

func main() {
	test(500, 8, "Potato chips", []int{200, 50, 20, 10})
	test(500, 1, "Orange juice", []int{200, 200})
	test(200, 7, "Crackers", []int{50, 20, 10})
	test(100, 9, "Small snack", []int{20})
	test(1000, 6, "Condoms", []int{500})
	test(250, 4, "Cookies", []int{})
	test(500, 0, "Enter a valid product number", nil)
	test(90, 1, "Not enough money for this product", nil)
	test(0, 0, "Enter a valid product number", nil)
	test(81, 9, "Small snack", []int{})
	test(85, 9, "Small snack", []int{})
}

func test(m, p int, n string, r []int) {
	s, t := vend(m, p)
	assert(s == n)
	if len(t) == 0 {
		assert(len(t) == len(r))
	} else {
		assert(reflect.DeepEqual(t, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func vend(m, p int) (string, []int) {
	products := []struct {
		price int
		name  string
	}{
		1: {100, "Orange juice"},
		2: {200, "Soda"},
		3: {150, "Chocolate snack"},
		4: {250, "Cookies"},
		5: {180, "Gummy bears"},
		6: {500, "Condoms"},
		7: {120, "Crackers"},
		8: {220, "Potato chips"},
		9: {80, "Small snack"},
	}
	changes := []int{
		500, 200, 100, 50, 20, 10,
	}

	if p < 1 || p >= len(products) {
		return "Enter a valid product number", nil
	}

	t := products[p]
	if m < t.price {
		return "Not enough money for this product", nil
	}

	var c []int
	n := m - t.price
	l := len(changes)
	for i := 0; n > 0 && i < l; i++ {
		for n >= changes[i] {
			n -= changes[i]
			c = append(c, changes[i])
		}
	}

	return t.name, c
}
