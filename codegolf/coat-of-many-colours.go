/*

Challenge

Given a list of unique colour names as input, sort them in the order that they first appear in Joseph's Amazing Technicolour Dreamcoat.

Example

Input:  green, blue, red, brown
Output: red, green, brown, blue

The full list of colours, in order, is:

 1. red
 2. yellow
 3. green
 4. brown
 5. scarlet
 6. black
 7. ochre
 8. peach
 9. ruby
10. olive
11. violet
12. fawn
13. lilac
14. gold
15. chocolate
16. mauve
17. cream
18. crimson
19. silver
20. rose
21. azure
22. lemon
23. russet
24. grey
25. purple
26. white
27. pink
28. orange
29. blue

Or as an array of strings:

["red","yellow","green","brown","scarlet","black","ochre","peach","ruby","olive","violet","fawn","lilac","gold","chocolate","mauve","cream","crimson","silver","rose","azure","lemon","russet","grey","purple","white","pink","orange","blue"]

Rules

    You may take input by any reasonable, convenient means (e.g., an array of strings, a delimited string, individual strings) as long as it's permitted by our standard I/O rules, but please specify your input method in your answer.
    You may do the same for your output.
    The input will only ever contain colours from the above list.
    Your solution should be able to handle empty inputs.
    You may choose whether all words in the input are consistently uppercase, lowercase or title case but your output's casing must match your input's.
    This is code-golf so lowest byte count in each language wins.
    As always, standard loopholes are forbidden.

Test cases

Input:  []
Output: []

Input:  ["green", "blue", "red", "brown"]
Output: ["red", "green", "brown", "blue"]

Input:  ["gold", "grey", "green"]
Output: ["green", "gold", "grey"]

Input:  ["ruby","yellow","red","grey"]
Output: ["red", "yellow", "ruby", "grey"]

Input:  ["gold", "green", "fawn", "white", "azure", "rose", "black", "purple", "orange", "silver", "ruby", "blue", "lilac", "crimson", "pink", "cream", "lemon", "russet", "grey", "olive", "violet", "mauve", "chocolate", "yellow", "peach", "brown", "ochre", "scarlet", "red"]
Output: ["red", "yellow", "green", "brown", "scarlet", "black", "ochre", "peach", "ruby", "olive", "violet", "fawn", "lilac", "gold", "chocolate", "mauve", "cream", "crimson", "silver", "rose", "azure", "lemon", "russet", "grey", "purple", "white", "pink", "orange", "blue"]

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]string{}, []string{})
	test([]string{"green", "blue", "red", "brown"}, []string{"red", "green", "brown", "blue"})
	test([]string{"gold", "grey", "green"}, []string{"green", "gold", "grey"})
	test([]string{"ruby", "yellow", "red", "grey"}, []string{"red", "yellow", "ruby", "grey"})
	test([]string{"gold", "green", "fawn", "white", "azure", "rose", "black", "purple", "orange", "silver", "ruby", "blue", "lilac", "crimson", "pink", "cream", "lemon", "russet", "grey", "olive", "violet", "mauve", "chocolate", "yellow", "peach", "brown", "ochre", "scarlet", "red"}, []string{"red", "yellow", "green", "brown", "scarlet", "black", "ochre", "peach", "ruby", "olive", "violet", "fawn", "lilac", "gold", "chocolate", "mauve", "cream", "crimson", "silver", "rose", "azure", "lemon", "russet", "grey", "purple", "white", "pink", "orange", "blue"})
}

func test(s, r []string) {
	p := colors(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func colors(s []string) []string {
	sort.Slice(s, func(i, j int) bool {
		return ci(s[i]) < ci(s[j])
	})
	return s
}

func ci(s string) int {
	tab := map[string]int{
		"red":       1,
		"yellow":    2,
		"green":     3,
		"brown":     4,
		"scarlet":   5,
		"black":     6,
		"ochre":     7,
		"peach":     8,
		"ruby":      9,
		"olive":     10,
		"violet":    11,
		"fawn":      12,
		"lilac":     13,
		"gold":      14,
		"chocolate": 15,
		"mauve":     16,
		"cream":     17,
		"crimson":   18,
		"silver":    19,
		"rose":      20,
		"azure":     21,
		"lemon":     22,
		"russet":    23,
		"grey":      24,
		"purple":    25,
		"white":     26,
		"pink":      27,
		"orange":    28,
		"blue":      29,
	}
	return tab[s]
}
