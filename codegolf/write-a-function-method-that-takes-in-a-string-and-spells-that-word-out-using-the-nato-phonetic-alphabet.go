/*

Write a program that takes in a string and spells that word out using the NATO Phonetic Alphabet.

The mapping is as follows:

'A' -> 'Alfa'
'B' -> 'Bravo'
'C' -> 'Charlie'
'D' -> 'Delta'
'E' -> 'Echo'
'F' -> 'Foxtrot'
'G' -> 'Golf'
'H' -> 'Hotel'
'I' -> 'India'
'J' -> 'Juliett'
'K' -> 'Kilo'
'L' -> 'Lima'
'M' -> 'Mike'
'N' -> 'November'
'O' -> 'Oscar'
'P' -> 'Papa'
'Q' -> 'Quebec'
'R' -> 'Romeo'
'S' -> 'Sierra'
'T' -> 'Tango'
'U' -> 'Uniform'
'V' -> 'Victor'
'W' -> 'Whiskey'
'X' -> 'Xray'
'Y' -> 'Yankee'
'Z' -> 'Zulu'
Example:

'Hello World' -> ['Hotel', 'Echo', 'Lima', 'Lima', 'Oscar', 'Whiskey', 'Oscar', 'Romeo', 'Lima', 'Delta']

The input can be any string, but will always be comprised of only letters and spaces. Case is irrelevant in the output, but the input may contain letters in uppercase, lowercase, or both. Spaces should be ignored in the output.

You can output in any reasonable format, but it must be a delimited set of NATO callsigns.

*/

package main

import (
	"fmt"
	"reflect"
	"unicode"
)

func main() {
	test("Hello World", []string{"Hotel", "Echo", "Lima", "Lima", "Oscar", "Whiskey", "Oscar", "Romeo", "Lima", "Delta"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p := nato(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func nato(s string) []string {
	m := map[rune]string{
		'A': "Alfa",
		'B': "Bravo",
		'C': "Charlie",
		'D': "Delta",
		'E': "Echo",
		'F': "Foxtrot",
		'G': "Golf",
		'H': "Hotel",
		'I': "India",
		'J': "Juliett",
		'K': "Kilo",
		'L': "Lima",
		'M': "Mike",
		'N': "November",
		'O': "Oscar",
		'P': "Papa",
		'Q': "Quebec",
		'R': "Romeo",
		'S': "Sierra",
		'T': "Tango",
		'U': "Uniform",
		'V': "Victor",
		'W': "Whiskey",
		'X': "Xray",
		'Y': "Yankee",
		'Z': "Zulu",
	}

	var p []string
	for _, r := range s {
		r = unicode.ToUpper(r)
		if t, ok := m[r]; ok {
			p = append(p, t)
		}
	}
	return p
}
