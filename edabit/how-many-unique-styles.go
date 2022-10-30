/*

There are many different styles of music and many albums exhibit multiple styles. Create a function that takes an array of musical styles from albums and returns how many styles are unique.
Examples

uniqueStyles([
  "Dub, Dancehall",
  "Industrial, Heavy Metal",
  "Techno, Dubstep",
  "Synth-pop, Euro-Disco",
  "Industrial, Techno, Minimal"
]) ➞ 9

uniqueStyles([
  "Soul",
  "House, Folk",
  "Trance, Downtempo, Big Beat, House",
  "Deep House",
  "Soul"
]) ➞ 7

*/

package main

import (
	"strings"
)

func main() {
	assert(uniquestyles([]string{
		"Dub,Dancehall",
		"Industrial,Heavy Metal",
		"Techno,Dubstep",
		"Synth-pop,Euro-Disco",
		"Industrial,Techno,Minimal",
	}) == 9)

	assert(uniquestyles([]string{
		"Soul",
		"House,Folk",
		"Trance,Downtempo,Big Beat,House",
		"Deep House",
		"Soul",
	}) == 7)

	assert(uniquestyles([]string{
		"Black Metal,Avantgarde",
		"Funk",
		"Deep House,House",
		"Big Band",
		"Punk",
	}) == 7)

	assert(uniquestyles([]string{
		"Funk",
		"Funk",
		"Funk",
		"Funk",
		"Funk",
	}) == 1)
}

func uniquestyles(s []string) int {
	m := make(map[string]bool)
	c := 0
	for _, s := range s {
		t := strings.Split(s, ",")
		for _, t := range t {
			t = strings.ToLower(t)
			t = strings.TrimSpace(t)
			if !m[t] {
				m[t], c = true, c+1
			}
		}
	}
	return c
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
