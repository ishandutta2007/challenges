/*

Given a long multi-sentence string, the goal is the count the occurrences of the following words: park, lake, Santa Fe.

The words can appear as substrings of other words, i.e, parked counts as an instance of park.

Santa Fe counts as one word (so the space matters). Both Santa and Fe appearing alone or out of order does not count as an instance of Santa Fe.

The output should be counts of the number of times the words park, lake, and Santa Fe appear in the input string, in any consistent and readable format and order.

For example, for an input of

I'm just parked out by the lake; the lake 80 miles from Santa Fe. That's where i'm parked, out by the lake.

the output would resemble

2 3 1

as there are 2
occurrences of park, 3 of lake and 1

of Santa Fe.

Good luck! If you want a fun song to test this on you can use the lyrics to Parked by the lake - Dean Summerwind (below) and use it as the input; The output ought to be 20 24 14.

Winning submission is the least number of bytes.

Lyrics to Parked by the Lake

*/

package main

import (
	"regexp"
)

func main() {
	assert(count("I'm just parked out by the lake; the lake 80 miles from Santa Fe. That's where i'm parked, out by the lake.") == [3]int{2, 3, 1})
	assert(count("parked coreparked coprak CSanta Felipe lakewood cabin") == [3]int{2, 1, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(s string) [3]int {
	re := regexp.MustCompile("(park|lake|Santa Fe)")
	p := re.FindAllString(s, -1)

	var r [3]int
	for _, p := range p {
		switch p {
		case "park":
			r[0]++
		case "lake":
			r[1]++
		case "Santa Fe":
			r[2]++
		}
	}
	return r
}
