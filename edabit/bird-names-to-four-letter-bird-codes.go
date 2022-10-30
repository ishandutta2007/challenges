/*

In the world of birding there are four-letter codes for the common names of birds. These codes are created by some simple rules:

    If the bird's name has only one word, the code takes the first four letters of that word.
    If the name is made up of two words, the code takes the first two letters of each word.
    If the name is made up of three words, the code is created by taking the first letter from the first two words and the first two letters from the third word.
    If the name is four words long, the code uses the first letter from all the words.

There are other ways codes are created, but this challenge will only use the four rules listed above.

In this challenge you will write a function that takes an array of strings of common bird names and create the codes for those names based on the rules above. The function will return an array of codes in the same order in which the input names were presented.
Examples:

birdCode(["Black-Capped Chickadee", "Common Tern"]) ➞ ["BCCH", "COTE"]

birdCode(["American Redstart", "Northern Cardinal"]) ➞ ["AMRE","NOCA"]

birdCode(["Bobolink", "American White Pelican"]) ➞ ["BOBO","AWPE"]

Notes

    The four-letter codes in the returned array should be in UPPER CASE.
    If a common name has a hyphen/dash, it should be considered a space.

*/

package main

import (
	"strings"
	"unicode"
)

func main() {
	test([]string{"Common Tern", "Black-Capped Chickadee"}, []string{"COTE", "BCCH"})
	test([]string{"American Redstart", "Northern Cardinal", "Pine Grosbeak", "Barred Owl", "Starling", "Cooper's Hawk", "Pigeon"}, []string{"AMRE", "NOCA", "PIGR", "BAOW", "STAR", "COHA", "PIGE"})
	test([]string{"Great Crested Flycatcher", "Bobolink", "American White Pelican", "Red-Tailed Hawk", "Eastern Screech Owl", "Blue Jay"}, []string{"GCFL", "BOBO", "AWPE", "RTHA", "ESOW", "BLJA"})
	test([]string{"Black-Crowned Night Heron", "Northern Mockingbird", "Eastern Meadowlark", "Dark-Eyed Junco", "Red-Bellied Woodpecker"}, []string{"BCNH", "NOMO", "EAME", "DEJU", "RBWO"})
	test([]string{"Scarlet Tanager", "Great Blue Heron", "Eastern Phoebe", "American Black Duck", "Mallard", "Canvasback", "Merlin", "Ovenbird"}, []string{"SCTA", "GBHE", "EAPH", "ABDU", "MALL", "CANV", "MERL", "OVEN"})
	test([]string{"Fox Sparrow", "White-Winged Crossbill", "Veery", "American Coot", "Sora", "Northern Rough-Winged Swallow", "Purple Martin"}, []string{"FOSP", "WWCR", "VEER", "AMCO", "SORA", "NRWS", "PUMA"})
}

func test(s, t []string) {
	s = birdcode(s)
	for i := range s {
		assert(s[i] == t[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func birdcode(s []string) []string {
	var a []string
	for _, s := range s {
		s = strings.Replace(s, "-", " ", -1)
		t := strings.Split(s, " ")
		r := make([][]rune, len(t))
		for i := range r {
			r[i] = []rune(t[i])
			for j := range r[i] {
				r[i][j] = unicode.ToUpper(r[i][j])
			}

			if len(r[i]) > 4 {
				r[i] = r[i][:4]
			}
			if len(r[i]) < 2 {
				a = append(a, s)
				continue
			}
		}

		p := s
		switch len(t) {
		case 1:
			p = string(r[0])

		case 2:
			p = string(r[0][:2]) + string(r[1][:2])

		case 3:
			p = string(r[0][0]) + string(r[1][0]) + string(r[2][:2])

		case 4:
			p = string(r[0][0]) + string(r[1][0]) + string(r[2][0]) + string(r[3][0])
		}
		a = append(a, p)
	}
	return a
}
