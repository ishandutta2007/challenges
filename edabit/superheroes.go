/*

Create a function that takes an array of superheroes / superheroines names and returns an array of only superheroe names ending in "man". Return the names in alphabetical order.

Examples

superheroes(["Batman", "Superman", "Spider-man", "Hulk", "Wolverine", "Wonder-Woman"])
➞ ["Batman", "Spider-man", "Superman"]

superheroes(["Catwoman", "Deadpool", "Dr.Strange", "Captain-America", "Aquaman", "Hawkeye"])
➞ ["Aquaman"]

superheroes(["Wonder-Woman", "Catwoman", "Invisible-Woman"])
➞ []

Notes

Wonder-Woman, Catwoman and Invisible-Woman are superheroines.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
	"strings"
)

func main() {
	test([]string{"Batman", "Superman", "Spider-man", "Hulk", "Wolverine", "Wonder-Woman"}, []string{"Batman", "Spider-man", "Superman"})
	test([]string{"Catwoman", "Deadpool", "Dr.Strange", "Captain-America", "Aquaman", "Hawkeye"}, []string{"Aquaman"})
	test([]string{"Iron-man", "Thor", "Black-Panther", "Iceman", "Catwoman", "Invisible-Woman"}, []string{"Iceman", "Iron-man"})
	test([]string{"Batman", "Superman", "Spider-man", "Hulk", "Wolverine", "Deadpool", "Dr.Strange", "Captain-America", "Aquaman", "Hawkeye", "Iron-man", "Thor", "Black-Panther", "Iceman"}, []string{"Aquaman", "Batman", "Iceman", "Iron-man", "Spider-man", "Superman"})
	test([]string{"Wonder-Woman", "Catwoman", "Invisible-Woman"}, []string{})
}

func test(s, r []string) {
	p := superheroes(s)
	fmt.Println(p)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func superheroes(s []string) []string {
	var p []string
	for i := range s {
		t := strings.ToLower(s[i])
		if strings.HasSuffix(t, "man") && !strings.HasSuffix(t, "woman") {
			p = append(p, s[i])
		}
	}
	sort.Strings(p)
	return p
}
