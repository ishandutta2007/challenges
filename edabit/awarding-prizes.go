/*

You are given a dictionary of names and the amount of points they have. Return a dictionary with the same names, but instead of points, return what prize they get.

"Gold", "Silver", or "Bronze" to the 1st, 2nd and 3rd place respectively. For all the other names, return "Participation" for the prize.
Examples

awardPrizes({
  "Joshua" : 45,
  "Alex" : 39,
  "Eric" : 43
}) ➞ {
  "Joshua" : "Gold",
  "Alex" : "Bronze",
  "Eric" : "Silver"
}

awardPrizes({
  "Person A" : 1,
  "Person B" : 2,
  "Person C" : 3,
  "Person D" : 4,
  "Person E" : 102
}) ➞ {
  "Person A" : "Participation",
  "Person B" : "Participation",
  "Person C" : "Bronze",
  "Person D" : "Silver",
  "Person E" : "Gold"
}

awardPrizes({
  "Mario" : 99,
  "Luigi" : 100,
  "Yoshi" : 299,
  "Toad" : 2
}) ➞ {
  "Mario" : "Bronze",
  "Luigi" : "Silver",
  "Yoshi" : "Gold",
  "Toad" : "Participation"
}

Notes

    There will always be at least three participants to recieve awards.
    No number of points will be the same amongst participants.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(
		map[string]int{
			"Joshua": 45,
			"Alex":   39,
			"Eric":   43,
		},
		map[string]string{
			"Joshua": "Gold",
			"Alex":   "Bronze",
			"Eric":   "Silver",
		},
	)

	test(
		map[string]int{
			"Person A": 1,
			"Person B": 2,
			"Person C": 3,
			"Person D": 4,
			"Person E": 102,
		},
		map[string]string{
			"Person A": "Participation",
			"Person B": "Participation",
			"Person C": "Bronze",
			"Person D": "Silver",
			"Person E": "Gold",
		},
	)

	test(
		map[string]int{
			"Mario": 99,
			"Luigi": 100,
			"Yoshi": 299,
			"Toad":  2,
		},
		map[string]string{
			"Mario": "Bronze",
			"Luigi": "Silver",
			"Yoshi": "Gold",
			"Toad":  "Participation",
		},
	)
}

func test(m map[string]int, r map[string]string) {
	p := award(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func award(m map[string]int) map[string]string {
	var p []person
	for k, v := range m {
		p = append(p, person{k, v})
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i].score < p[j].score
	})

	r := make(map[string]string)
	for i, q := range p {
		k := q.name
		switch n := len(p); {
		case i+1 >= n:
			r[k] = "Gold"
		case i+2 >= n:
			r[k] = "Silver"
		case i+3 >= n:
			r[k] = "Bronze"
		default:
			r[k] = "Participation"
		}
	}
	return r
}

type person struct {
	name  string
	score int
}
