/*

Create a function that takes a string containing both name and number of animals and plants that may or may not be found in Chitwan National Park. The function should return a array of tuples where first element in the tuple is animal name and second element in the tuple is number of that particular animal that is found in Chitwan National Park.
Animals Present in Chitwan National Park

animals = ["muggercrocodile", "one-hornedrhino", "python", "moth", "monitorlizard", "bengaltiger"]

Examples

faunaNumber("There are 24 one-hornedrhino, 50 python and 20000 mango.") ➞ [{"one-hornedrhino": 24}, {"python": 50}]
// Mango not present in animal array.

faunaNumber("There are 244 bengaltiger, 200 monitorlizard and 5000 apples.") ➞ [{"bengaltiger": 244}, {"monitorlizard": 200}]
// Apples not present in animal array.

Notes

    Input contains name and number of both animals and plants.
    If there is no match, return an empty array.

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	var tab = []struct {
		str string
		res []Fauna
	}{
		{
			"There are 24 one-hornedrhino, 50 python and 20000 mango.",
			[]Fauna{{"one-hornedrhino", 24}, {"python", 50}},
		},
		{
			"There are 244 bengaltiger, 200 monitorlizard and 5000 apples.",
			[]Fauna{{"bengaltiger", 244}, {"monitorlizard", 200}},
		},
		{
			"There are 2444 saltrees, 2000 cobra and 5000 mangotrees.",
			[]Fauna{},
		},
		{
			"There are 180 muggercrocodile, 20 krait and 500 taipan.",
			[]Fauna{{"muggercrocodile", 180}},
		},
	}

	for _, t := range tab {
		eq(faunas(t.str), t.res)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b []Fauna) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

type Fauna struct {
	Name  string
	Count int
}

func faunas(s string) []Fauna {
	animals := map[string]struct{}{
		"muggercrocodile": struct{}{},
		"one-hornedrhino": struct{}{},
		"python":          struct{}{},
		"moth":            struct{}{},
		"monitorlizard":   struct{}{},
		"bengaltiger":     struct{}{},
	}

	re := regexp.MustCompile("\\d+\\s*(\\w|-)+")
	m := re.FindAllString(s, -1)

	var p []Fauna
	for i := range m {
		var f Fauna

		fmt.Sscan(m[i], &f.Count, &f.Name)
		if _, ok := animals[f.Name]; ok {
			p = append(p, f)
		}
	}
	return p
}
