/*

Create a function that returns any of the items you can afford in the store with the money you have in your wallet. Sort the list in alphabetical order.

Examples

itemsPurchased({
  Water: "$1",
  Bread: "$3",
  TV: "$1,000",
  Fertilizer: "$20"
}, "$300") ➞ ["Bread", "Fertilizer", "Water"]

itemsPurchased({
  Apple: "$4",
  Honey: "$3",
  Fan: "$14",
  Bananas: "$4",
  Pan: "$100",
  Spoon: "$2"
  }, "$100") ➞ ["Apple", "Bananas", "Fan", "Honey", "Pan", "Spoon"]

itemsPurchased({
  Phone: "$999",
  Speakers: "$300",
  Laptop: "$5,000",
  PC: "$1200"},
"$1") ➞ "Nothing"

Notes

Return "Nothing" if you can't afford anything from the store.

*/

package main

import (
	"reflect"
	"sort"
	"strconv"
	"strings"
)

func main() {
	m1 := map[string]string{
		"Water":      "$1",
		"Bread":      "$3",
		"TV":         "$1,000",
		"Fertilizer": "$20",
	}
	w1 := []string{"Bread", "Fertilizer", "Water"}

	m2 := map[string]string{
		"Apple":   "$4",
		"Honey":   "$3",
		"Fan":     "$14",
		"Bananas": "$4",
		"Pan":     "$100",
		"Spoon":   "$2",
	}
	w2 := []string{"Apple", "Bananas", "Fan", "Honey", "Pan", "Spoon"}

	m3 := map[string]string{
		"Phone":    "$999",
		"Speakers": "$300",
		"Laptop":   "$5,000",
		"PC":       "$1200",
	}
	w3 := "Nothing"

	test(m1, "$300", w1)
	test(m2, "$100", w2)
	test(m3, "$1", w3)
}

func test(m map[string]string, c string, r interface{}) {
	p := purchase(m, c)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func purchase(m map[string]string, c string) interface{} {
	var r []string
	w := dollars(c)
	for k, v := range m {
		p := dollars(v)
		if w >= p {
			r = append(r, k)
		}
	}

	if len(r) == 0 {
		return "Nothing"
	}

	sort.Strings(r)
	return r
}

func dollars(s string) int {
	s = strings.Replace(s, ",", "", -1)
	s = strings.Replace(s, "$", "", -1)
	v, _ := strconv.Atoi(s)
	return v
}
