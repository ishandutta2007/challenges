/*

Create a function that returns which chapter is nearest to the page you're on.
If two chapters are equidistant, return the chapter with the higher page number.

Examples

nearestChapter({
  "Chapter 1" : 1,
  "Chapter 2" : 15,
  "Chapter 3" : 37
}, 10) ➞ "Chapter 2"


nearestChapter({
  "New Beginnings" : 1,
  "Strange Developments" : 62,
  "The End?" : 194,
  "The True Ending" : 460
}, 200) ➞ "The End?"


nearestChapter({
  "Chapter 1a" : 1,
  "Chapter 1b" : 5
}, 3) ➞ "Chapter 1b"

Notes

All page numbers in the dictionary will be valid integers.

*/

package main

import (
	"sort"
)

func main() {
	assert(nearest([]Chapter{
		{"Chapter 1", 1},
		{"Chapter 2", 15},
		{"Chapter 3", 37},
	}, 10) == "Chapter 2")

	assert(nearest([]Chapter{
		{"New Beginnings", 1},
		{"Strange Developments", 62},
		{"The End?", 194},
		{"The True Ending", 460},
	}, 200) == "The End?")

	assert(nearest([]Chapter{
		{"Chapter 1a", 1},
		{"Chapter 1b", 5},
	}, 3) == "Chapter 1b")

	assert(nearest([]Chapter{
		{"Chapter 1a", 1},
		{"Chapter 1b", 5},
		{"Chapter 1c", 50},
		{"Chapter 1d", 100},
	}, 75) == "Chapter 1d")

	assert(nearest([]Chapter{
		{"Chapter 1a", 1},
		{"Chapter 1b", 5},
		{"Chapter 1c", 50},
		{"Chapter 1d", 100},
		{"Chapter 1e", 200},
	}, 150) == "Chapter 1e")

	assert(nearest([]Chapter{
		{"Chapter 1a", 1},
		{"Chapter 1b", 5},
		{"Chapter 1c", 50},
		{"Chapter 1d", 100},
		{"Chapter 1e", 200},
	}, 74) == "Chapter 1c")

	assert(nearest([]Chapter{
		{"Chapter 1a", 1},
		{"Chapter 1b", 5},
		{"Chapter 1c", 50},
		{"Chapter 1d", 100},
		{"Chapter 1e", 200},
		{"Chapter 1f", 400},
	}, 300) == "Chapter 1f")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Chapter struct {
	name string
	page int
}

func nearest(c []Chapter, p int) string {
	i := sort.Search(len(c), func(i int) bool {
		return c[i].page >= p
	})
	if i > 0 && p-c[i-1].page < c[i].page-p {
		i--
	}
	return c[i].name
}
