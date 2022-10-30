/*

You have just been hired at a local home improvement store to help compute the proper costs of inventory. The current prices are out of date and wrong; you have to figure out which items need to be re-labeled with the correct price.

You will be first given a list of item-names and their current price. You will then be given another list of the same item-names but with the correct price. You must then print a list of items that have changed, and by how much.

Formal Inputs & Outputs

Input Description

The first line of input will be an integer N, which is for the number of rows in each list.
Each list has N-lines of two space-delimited strings: the first string will be the unique item name (without spaces), the second string will be the price (in whole-integer cents).
The second list, following the same format, will have the same unique item-names, but with the correct price.
Note that the lists may not be in the same order!

Output Description

For each item that has had its price changed, print a row with the item name and the price difference (in cents).
Print the sign of the change (e.g. '+' for a growth in price, or '-' for a loss in price). Order does not matter for output.

Sample Inputs & Outputs
Sample Input 1
4
CarriageBolt 45
Eyebolt 50
Washer 120
Rivet 10
CarriageBolt 45
Eyebolt 45
Washer 140
Rivet 10
Sample Output 1
Eyebolt -5
Washer +20
Sample Input 2
3
2DNail 3
4DNail 5
8DNail 10
8DNail 11
4DNail 5
2DNail 2
Sample Output 2
2DNail -1
8DNail +1

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]item{
		{"CarriageBolt", 45},
		{"Eyebolt", 50},
		{"Washer", 120},
		{"Rivet", 10},
	}, []item{
		{"CarriageBolt", 45},
		{"Eyebolt", 45},
		{"Washer", 140},
		{"Rivet", 10},
	}, []item{
		{"Eyebolt", -5},
		{"Washer", +20},
	})

	test([]item{
		{"2DNail", 3},
		{"4DNail", 5},
		{"8DNail", 10},
	}, []item{
		{"8DNail", 11},
		{"4DNail", 5},
		{"2DNail", 2},
	}, []item{
		{"2DNail", -1},
		{"8DNail", +1},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r []item) {
	p := mismatch(a, b)
	fmt.Printf("%+v\n", p)
	assert(reflect.DeepEqual(p, r))
}

type item struct {
	name  string
	value int
}

func mismatch(a, b []item) []item {
	m := make(map[string]int)
	for _, i := range a {
		m[i.name] = i.value
	}

	var r []item
	for _, i := range b {
		d := i.value - m[i.name]
		if d != 0 {
			r = append(r, item{i.name, d})
		}
	}

	sort.Slice(r, func(i, j int) bool {
		return r[i].name < r[j].name
	})

	return r
}
