/*

Given an array of women and an array of men, either:

    Return "sizes don't match" if the two arrays have different sizes.
    If the sizes match, return an array of pairs, with the first woman paired with the first man, second woman paired with the second man, etc.

Examples

zipIt(["Elise", "Mary"], ["John", "Rick"])
 ➞ [["Elise", "John"], ["Mary", "Rick"]]

zipIt(["Ana", "Amy", "Lisa"], ["Bob", "Josh"])
 ➞ "sizes don't match"

zipIt(["Ana", "Amy", "Lisa"], ["Bob", "Josh", "Tim"])
 ➞ [["Ana", "Bob"], ["Amy", "Josh"],["Lisa", "Tim"]]

Notes

N/A

*/

package main

import "reflect"

func main() {
	test([]string{"Elise", "Mary"}, []string{"John", "Rick"}, [][2]string{{"Elise", "John"}, {"Mary", "Rick"}})
	test([]string{"Ana", "Amy", "Lisa"}, []string{"Bob", "Josh"}, "sizes don't match")
	test([]string{"Ana", "Amy", "Lisa"}, []string{"Bob", "Josh", "Tim"}, [][2]string{{"Ana", "Bob"}, {"Amy", "Josh"}, {"Lisa", "Tim"}})
	test([]string{"Ana", "Amy", "Lisa", "Katty"}, []string{"Bob", "Josh", "Tim"}, "sizes don't match")
	test([]string{"Katty", "Ana", "Amy", "Lisa"}, []string{"Bob", "Josh", "Tim", "Aaron"}, [][2]string{{"Katty", "Bob"}, {"Ana", "Josh"}, {"Amy", "Tim"}, {"Lisa", "Aaron"}})
}

func test(w, m []string, r interface{}) {
	assert(reflect.DeepEqual(zip(w, m), r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func zip(w, m []string) interface{} {
	if len(w) != len(m) {
		return "sizes don't match"
	}

	var p [][2]string
	for i := range w {
		p = append(p, [2]string{w[i], m[i]})
	}
	return p
}
