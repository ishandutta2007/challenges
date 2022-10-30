/*

My friend required some help with an assignment in school and I thought this would be a nice addition to be added as a challenge here as well.

Create a function that takes a sentence and returns a modified sentence abided by these rules:

    If you encounter a date within the sentence, in the format DD/MM/YY or DD.MM.YY, you have to change it over to DD/MM/YYYY or DD.MM.YYYY (same separator char).
    If you encounter a date within the sentence, in the format MonthName, DD. YY. you have to change it over to MonthName, DD. YYYY.
    If you encounter an invalid MonthName then leave it as is.
    For this challenge there is an arbitrary rule that if YY is less than 25 the year-prefix will be 20, otherwise, the year-prefix will be 19.
    Meaning 08/11/20 -> 08/11/2020 or 02/11/95 -> 02/11/1995

Examples

smallFavor("I was born on 11/02/98")
➞ "I was born on 11/02/1998"

smallFavor("I was born on 11/02/98 and what about you?")
➞ "I was born on 11/02/1998 and what about you?"

smallFavor("I was born on 02.11.19")
➞ "I was born on 02.11.2019"

smallFavor("I was born on February, 02. 98.")
➞ "I was born on February, 02. 1998."

smallFavor("I was born on January, 01. 15. and today is October, 08. 20.")
➞ "I was born on January, 01. 2015. and today is October, 08. 2020."

smallFavor("I was born on Fakemonthy, 01. 15. dont change invalid dates")
➞ "I was born on Fakemonthy, 01. 15. dont change invalid dates"

Notes

Don't forget to apply the arbitrary year-prefix rule defined above.

    DD/MM/YY -> DD/MM/YYYY
    DD.MM.YY -> DD.MM.YYYY
    Month, DD. YY. -> Month, DD. YYYY.
    DD|MM|YY -> DD|MM|YY (invalid separator, means it remains unchanged)

*/

package main

import (
	"bytes"
	"fmt"
	"regexp"
	"sort"
	"strings"
	"unicode"
)

func main() {
	assert(favor("I was born on 11/02/98") == "I was born on 11/02/1998")
	assert(favor("I was born on 11/02/98 and what about you?") == "I was born on 11/02/1998 and what about you?")
	assert(favor("I was born on 11.02.98") == "I was born on 11.02.1998")
	assert(favor("I was born on 11|02|98") == "I was born on 11|02|98")
	assert(favor("I was born on 02/11/19") == "I was born on 02/11/2019")
	assert(favor("I was born on 02.11.19") == "I was born on 02.11.2019")
	assert(favor("I was born on February, 02. 98.") == "I was born on February, 02. 1998.")
	assert(favor("I was born on January, 01. 15. and today is 08/10/20") == "I was born on January, 01. 2015. and today is 08/10/2020")
	assert(favor("I was born on January, 01. 15. and today is October, 08. 20.") == "I was born on January, 01. 2015. and today is October, 08. 2020.")
	assert(favor("I was born on Fakemonthy, 01. 15. dont change invalid dates") == "I was born on Fakemonthy, 01. 15. dont change invalid dates")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func favor(s string) string {
	return output(s, find(s))
}

func find(s string) []int {
	re := []*regexp.Regexp{
		regexp.MustCompile("\\s*([0-9]{2}(/|\\.)[0-9]{2}(/|\\.)[0-9]{2})\\s*"),
		regexp.MustCompile("\\s*(\\w+\\,+ [0-9]{2}\\. [0-9]{2}\\.)\\s*"),
	}

	var p [][]int
	for _, re := range re {
		i := re.FindAllStringIndex(s, -1)
		p = append(p, i...)
	}
	p = sanitize(s, p)

	sort.Slice(p, func(i, j int) bool {
		return p[i][0] < p[j][0]
	})

	var r []int
	for _, i := range p {
		j := i[1] - 1
		for j > 2 && !('0' <= s[j] && s[j] <= '9') {
			j--
		}
		r = append(r, j-1)
	}
	return r
}

func sanitize(s string, p [][]int) [][]int {
	months := []string{
		"january", "february", "march", "april",
		"may", "june", "july", "august",
		"september", "october", "november", "december",
	}

	j := 0
	for i, l := range p {
		t := strings.TrimSpace(s[l[0]:l[1]])
		if len(t) < 2 {
			continue
		}

		if !unicode.IsDigit(rune(t[0])) {
			v := strings.Split(t, " ")
			u := strings.ToLower(v[0])

			for _, m := range months {
				if u == m+"," {
					goto found
				}
			}
			continue
		}

	found:
		p[j], j = p[i], j+1
	}
	return p[:j]
}

func output(s string, l []int) string {
	w := new(bytes.Buffer)
	for i, j := 0, 0; i < len(s); i++ {
		if j < len(l) && i == l[j] {
			fmt.Fprint(w, mkyear(s[i:]))
			i, j = i+1, j+1
		} else {
			w.WriteByte(s[i])
		}
	}
	return w.String()
}

func mkyear(s string) int {
	y := int(10*(s[0]-'0') + (s[1] - '0'))
	if y < 25 {
		y += 2000
	} else {
		y += 1900
	}
	return y
}
