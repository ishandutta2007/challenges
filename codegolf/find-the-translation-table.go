/*

Given two strings, find the translation table (substitution cipher) between the two, if the translation is not possible, output false.
The answer must be minimized and created from left-to-right. The first character to be translated between words must be the first in the translation table.
In addition to this, any letter that is not translated (in the same place as it was originally), should NOT be in the translation table.

Probably most easily defined through examples:
Valid Cases

"bat", "sap" => ["bt","sp"]

Notice the ordering, an output of ["tb","ps"] is not valid for this challenge.

"sense", "12n12" => ["se","12"]

Notice how the n isn't translated because it is a 1 to 1 relation.

"rabid", "snail" => ["rabd","snal"]

Notice how the i isn't translated because it is a 1 to 1 relation.

"ass", "all" => ["s","l"]

A is not included, it stays the same, s can map to l due to pattern match.

"3121212", "ABLBLBL" => ["312","ABL"]

Matches pattern perfectly.
Falsy Cases

"banana", "angular" => false

(not the same length, impossible).

"animal", "snails" => false

(each character can only be used ONCE on each side of the translation).

"can","cnn" => false

(n is implicitly used in translation, therefore, defining a translation table with n->a would be invalid)

Thusly, [aimal,sails] is an invalid answer, making this falsy.

"a1", "22" => false

See "caveats", this is listed as falsy. In this case, it's because a and 1 cannot both map to 2. (Each character can only be used ONCE on each side of the translation).

This answer seems to be a good benchmark: https://codegolf.stackexchange.com/a/116807/59376

If you have questions about the functionality of two unlisted word pairs, defer to this implementation.
I/O rules

    Input may be as a 2 element array or as 2 separate inputs.
    Output can be as an array or newline/space delimited, similar to how I have it shown.
    False output may be 0, -1 or false. Erroring/Empty output is also fine.
    You are guaranteed that a will not equal b and neither a nor b will be empty.
    a and b are printable-ASCII-only sequences of letters.

Caveats

    Translations must occur from left to right, see example 1.
    You must not output characters that remain the same.
    Your program may only take in two strings a and b.
    Each character can only be used ONCE on each side of the translation. This is what makes the translation from snails to animals impossible.
    Recursive replaces should not occur. Example of recursive replace: "a1","22"->[a1,12] where a is first replaced by a 1, then both resultant 1's are replaced with 2's.
    This is not correct, assume all translations occur independent of each other, meaning this is falsy. Meaning: "a1" with translation table of [a1,12] evaluates to 12 (not 22)

*/

package main

import (
	"bytes"
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test("bat", "sap", []string{"bt", "sp"})
	test("sense", "12n12", []string{"se", "12"})
	test("rabid", "snail", []string{"rabd", "snal"})
	test("ass", "all", []string{"s", "l"})
	test("3121212", "ABLBLBL", []string{"312", "ABL"})

	test("banana", "angular", nil)
	test("animals", "snails", nil)
	test("can", "cnn", nil)
	test("a1", "22", nil)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b string, r []string) {
	p := substitution(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

type symbol struct {
	char  rune
	count int
}

func substitution(a, b string) []string {
	h, x := frequency(a)
	g, y := frequency(b)
	m, n := mapping(x, y)
	l := duplicates(a, b)

	s, p := translate(a, g, m, l)
	t, q := translate(b, h, n, l)
	if !p || !q {
		return nil
	}
	return []string{s, t}
}

func frequency(s string) (map[rune]int, []symbol) {
	m := make(map[rune]int)
	for _, r := range s {
		m[r]++
	}

	p := make([]symbol, len(m))
	i := 0
	for k, v := range m {
		p[i], i = symbol{k, v}, i+1
	}

	sort.Slice(p, func(i, j int) bool {
		if p[i].count == p[j].count {
			return p[i].char < p[j].char
		}
		return p[i].count < p[j].count
	})

	return m, p
}

func mapping(x, y []symbol) (map[rune]rune, map[rune]rune) {
	if len(x) != len(y) {
		return nil, nil
	}

	m := make(map[rune]rune)
	n := make(map[rune]rune)
	for i := range x {
		if x[i].count != y[i].count {
			return nil, nil
		}

		c := x[i].char
		d := y[i].char
		m[c], n[d] = d, c
	}
	return m, n
}

func index(s string) map[rune][]int {
	m := make(map[rune][]int)
	for i, r := range s {
		m[r] = append(m[r], i)
	}
	return m
}

func duplicates(a, b string) map[rune]bool {
	m := make(map[rune]bool)
	i := index(a)
	j := index(b)
	for _, r := range a {
		if reflect.DeepEqual(i[r], j[r]) {
			m[r] = true
		}
	}
	return m
}

func translate(s string, h map[rune]int, m map[rune]rune, l map[rune]bool) (string, bool) {
	w := new(bytes.Buffer)
	f := make(map[rune]bool)
	for _, r := range s {
		c := m[r]
		if h[c]--; h[c] < 0 {
			return "", false
		}
		if !f[r] && !l[r] {
			w.WriteRune(r)
			f[r] = true
		}
	}
	return w.String(), true
}
