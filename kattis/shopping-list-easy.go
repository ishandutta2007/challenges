/*

Kelly, being the great programmer that she is, is frequently thinking of “the next big thing” for apps.
One morning Kelly thought of the brilliant idea to create a social network for grocery shopping lists.
Kelly wants to make her social network connect people that buy the same things from the grocery store so she needs your help coming up with a program to figure out when users are buying the same things at the grocery store so her site can run relevant ads.
Kelly wants to compare a user’s latest shopping list to all of their previous shopping lists and find out which items they buy every time they go to the store.

Input

The first line of the input will contain two space separated integers: n (1≤n≤20), the number of shopping lists, and m (1≤m≤20), the number of items on each of those lists.
Each of the following n lines is one of the shopping lists, containing m space-separated items each.
Each item is less than 11 characters long and made only of lowercase English characters.

Output

Output an integer n giving the number of items that are found on every list on the first line. On the next n lines, print these items in alphabetical order, one item per line.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([][]string{
		{"bread", "carrots", "cheese", "eggs", "milk"},
		{"milk", "carrots", "bread", "pasta", "yogurt"},
		{"corn", "bread", "kale", "spinach", "carrots"},
		{"milk", "bread", "cheese", "carrots", "yogurt"},
	}, []string{"bread", "carrots"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s [][]string, r []string) {
	p := intersect(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func intersect(s [][]string) []string {
	r := []string{}
	m := make(map[string]int)
	for i := range s {
		t := make(map[string]bool)
		for _, v := range s[i] {
			if t[v] {
				continue
			}
			m[v], t[v] = m[v]+1, true
		}
	}

	for k, v := range m {
		if v == len(s) {
			r = append(r, k)
		}
	}

	sort.Strings(r)
	return r
}
