/*

You call your spouse to inform his/her most precious item is gone! Given an object of stolen items, return the most expensive item on the list.

Examples

mostExpensiveItem({
  piano: 2000,
}) ➞ "piano"

mostExpensiveItem({
  tv: 30,
  skate: 20,
}) ➞ "tv"

mostExpensiveItem({
  tv: 30,
  skate: 20,
  stereo: 50,
}) ➞ "stereo"

Notes

    There will only be one most valuable item (no ties).
    The object will always contain at least one item (no empty objects).

*/

package main

func main() {
	m1 := map[string]int{
		"tv":     30,
		"skate":  20,
		"stereo": 50,
	}
	m2 := map[string]int{
		"skate": 20,
	}
	m3 := map[string]int{
		"tv":    30,
		"skate": 20,
	}

	assert(expensive(m1) == "stereo")
	assert(expensive(m2) == "skate")
	assert(expensive(m3) == "tv")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func expensive(m map[string]int) string {
	var (
		s string
		u int
	)
	for k, v := range m {
		if u < v {
			s, u = k, v
		}
	}
	return s
}
