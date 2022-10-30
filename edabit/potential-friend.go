/*

Given two sets of two people's different interests, return whether both people have at least two things in common or have exact interests.
Return true if there's a potential friend!

Examples

is_potential_friend(
  ["sports", "music", "chess"],
  ["coding", "music", "netfli", "chess"]
) ➞ true

is_potential_friend(
  ["cycling", "technology", "drawing"],
  ["dancing", "drawing"]
) ➞ false

is_potential_friend(
  ["history"],
  ["history"]
) ➞ true

Notes

Sets of interests may have varied lengths.

*/

package main

func main() {
	assert(potential([]string{"sports", "music", "chess"}, []string{"coding", "music", "netfli", "chess"}) == true)
	assert(potential([]string{"cycling", "technology", "reading"}, []string{"dancing", "planes", "politics"}) == false)
	assert(potential([]string{"history"}, []string{"gaming", "drawing", "coding", "history"}) == false)
	assert(potential([]string{"films"}, []string{"films"}) == true)
	assert(potential([]string{"sports", "music", "chess"}, []string{"coding", "music", "netflix", "chess"}) == true)
	assert(potential([]string{"cycling", "technology", "drawing"}, []string{"dancing", "drawing"}) == false)
	assert(potential([]string{"history", "acting", "cards"}, []string{"history", "acting", "cards"}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func potential(s, t []string) bool {
	m := make(map[string]int)
	for _, v := range s {
		m[v] |= 1
	}

	c := 0
	for _, v := range t {
		m[v] |= 2
		if m[v] == 3 {
			c++
		}
	}
	return (c == len(s) && c == len(t)) || c >= 2
}
