/*

Inspired by a tweet by Nathan W. Pyle

There is, now, a standard method of converting your boring, normal human name into a mysterious, ethereal Ghost Name™️. Ably described by Mr Pyle...

Use your first name:

a - add “t” after it

e - add “boo” after it

h - becomes “s”

n - add “oo” after it

r - add “eee” after it

y - add “oo” after it

that’s it that’s your ghost name

(Note that the rule for h is a substitution, not an append)

Well, needless to say we don't want to waste too many chars of code converting your name, time for some golfing!

The task:

    Convert a single-word string of a name into a Ghost Name™️
    Your code will accept a string and output a string
    Upper-case letters will still be converted. The appended strings will appear after an upper-case version of their letter, and an upper-case H will become an upper-case S.
    Spaces, punctuation, anything other than the prescribed letters will remain unchanged.

Rules:

    It's code golf, attempt to make the Ghost Name™️ conversion in as few bytes as possible.
    Please include a link to an online interpreter, such as TIO.

Test Cases

Andrew               > Atnoodreeeeboow
Stephanie            > Steboopsatnooieboo
Harry                > Satreeereeeyoo
Tim                  > Tim
Tonleeboo            > Tonoolebooebooboo
Great Britain        > Greeeebooatt Breeeitatinoo
L33t H4x0rz          > L33t S4x0reeez
cat🐱face🐱emoji       > catt🐱fatceboo🐱eboomoji

Satppyoo golfinoog!

*/

package main

import (
	"bytes"
	"unicode"
)

func main() {
	assert(ghostname("Andrew") == "Atnoodreeeeboow")
	assert(ghostname("Stephanie") == "Steboopsatnooieboo")
	assert(ghostname("Harry") == "Satreeereeeyoo")
	assert(ghostname("Tim") == "Tim")
	assert(ghostname("Tonleeboo") == "Tonoolebooebooboo")
	assert(ghostname("Great Britain") == "Greeeebooatt Breeeitatinoo")
	assert(ghostname("L33t H4x0rz") == "L33t S4x0reeez")
	assert(ghostname("cat🐱face🐱emoji") == "catt🐱fatceboo🐱eboomoji")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ghostname(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		p := string(r)
		switch unicode.ToLower(r) {
		case 'a':
			p += "t"
		case 'e':
			p += "boo"
		case 'h':
			if unicode.IsUpper(r) {
				p = "S"
			} else {
				p = "s"
			}
		case 'n':
			p += "oo"
		case 'r':
			p += "eee"
		case 'y':
			p += "oo"
		}
		w.WriteString(p)
	}
	return w.String()
}
