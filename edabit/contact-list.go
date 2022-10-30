/*

Write a sorting function that takes in an array of names and sorts them by last name either alphabetically (ASC) or reverse-alphabetically (DESC).

Notes

    An array with a single name should be trivially returned.
    An empty array, or an input of null or undefined should return an empty array.

*/

package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	fmt.Println(sortcontacts([]string{"John Locke", "Thomas Aquinas", "David Hume", "Rene Descartes"}, "ASC"))
	fmt.Println(sortcontacts([]string{"Paul Erdos", "Leonhard Euler", "Carl Gauss"}, "DESC"))
	fmt.Println(sortcontacts([]string{"Michael Phelps", "Jesse Owens", "Michael Jordan", "Usain Bolt"}, "DESC"))
	fmt.Println(sortcontacts([]string{"Al Gore", "Barack Obama"}, "ASC"))
	fmt.Println(sortcontacts([]string{"Albert Einstein"}, "ASC"))
	fmt.Println(sortcontacts([]string{}, "DESC"))
	fmt.Println(sortcontacts(nil, "DESC"))
}

func sortcontacts(s []string, t string) []string {
	t = strings.ToLower(t)
	p := append([]string{}, s...)
	sort.Slice(p, func(i, j int) bool {
		x := lastname(p[i])
		y := lastname(p[j])

		switch t {
		case "asc":
			fallthrough
		default:
			return x < y
		case "desc":
			return y < x
		}
	})
	return p
}

func lastname(s string) string {
	t := strings.Split(s, " ")
	if len(t) < 2 {
		return ""
	}
	return t[1]
}
