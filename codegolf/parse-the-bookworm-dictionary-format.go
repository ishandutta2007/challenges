/*

I've recently been indulging myself in some nostalgia in the form of Bookworm Deluxe:

In case you haven't seen it before, it's a word game where the goal is to connect adjacent tiles to form words.
In order to determine whether a string is a valid word, it checks it against its internal dictionary, which is stored in a compressed format that looks like this:

aa
2h
3ed
ing
s
2l
3iis
s
2rdvark
8s
4wolf
7ves

The rules for unpacking the dictionary are simple:

    Read the number at the start of the line, and copy that many characters from the beginning of the previous word. (If there is no number, copy as many characters as you did last time.)

    Append the following letters to the word.

So, our first word is aa, followed by 2h, which means "copy the first two letters of aa and append h," forming aah.
Then 3ed becomes aahed, and since the next line doesn't have a number, we copy 3 characters again to form aahing.
This process continues throughout the rest of the dictionary. The resulting words from the small sample input are:

aa
aah
aahed
aahing
aahs
aal
aaliis
aals
aardvark
aardvarks
aardwolf
aardwolves

Your challenge is to perform this unpacking in as few bytes as possible.

Each line of input will contain zero or more digits 0-9 followed by one or more lowercase letters a-z.
You may take input and give output as either a list of strings, or as a single string with words separated by any character other than 0-9/a-z.

Here is another small test case with a few edge cases not covered in the example:

abc cba 1de fg hi 0jkl mno abcdefghijk 10l
=> abc cba cde cfg chi jkl mno abcdefghijk abcdefghijl

You may also test your code on the full dictionary: input, output.

*/

package main

import (
	"fmt"
	"reflect"
	"strconv"
	"unicode"
)

func main() {
	test(
		[]string{"aa", "2h", "3ed", "ing", "s", "2l", "3iis", "s", "2rdvark", "8s", "4wolf", "7ves"},
		[]string{"aa", "aah", "aahed", "aahing", "aahs", "aal", "aaliis", "aals", "aardvark", "aardvarks", "aardwolf", "aardwolves"},
	)
	test(
		[]string{"abc", "cba", "1de", "fg", "hi", "0jkl", "mno", "abcdefghijk", "10l"},
		[]string{"abc", "cba", "cde", "cfg", "chi", "jkl", "mno", "abcdefghijk", "abcdefghijl"},
	)
}

func test(l, r []string) {
	p := parse(l)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func parse(l []string) []string {
	var (
		m int
		t string
		r []string
	)
	for i := range l {
		n, s := strtoi(l[i])
		if n < 0 {
			n = m
		}

		r = append(r, mkstr(t, n)+s)
		m = n
		t = r[len(r)-1]
	}
	return r
}

func strtoi(s string) (int, string) {
	var (
		i int
		r rune
	)
	for i, r = range s {
		if !unicode.IsDigit(r) {
			break
		}
	}

	n, err := strconv.Atoi(s[:i])
	if i == 0 || err != nil {
		n = -1
	}
	return n, s[i:]
}

func mkstr(s string, n int) string {
	m := 0
	for i, _ := range s {
		if m >= n {
			return s[:i]
		}
		m++
	}
	return s
}
