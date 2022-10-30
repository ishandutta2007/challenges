/*

Time to call your lover to inform him/her what he/she lost in the burglary.

Given a dictionary of the stolen objects, return the 3rd most expensive item on the list. If that is not possible, because there are not enough items, return False.

Examples

third_most_expensive({}) ➞ False

third_most_expensive({"piano": 100}) ➞ False

third_most_expensive({"piano": 100, "stereo": 200 }) ➞ False

Notes

All prices will be of different monetary values.

*/

package main

func main() {
	assert(third(map[string]uint{}) == "")
	assert(third(map[string]uint{"piano": 100}) == "")
	assert(third(map[string]uint{"piano": 100, "stereo": 200}) == "")
	assert(third(map[string]uint{"piano": 100, "stereo": 200, "tv": 10}) == "tv")
	assert(third(map[string]uint{"piano": 100, "stereo": 200, "tv": 10, "timmy": 500}) == "piano")
	assert(third(map[string]uint{"computer": 1000, "piano": 500, "stereo": 200, "tv": 10, "timmy": 1}) == "stereo")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func third(m map[string]uint) string {
	if len(m) < 3 {
		return ""
	}

	var (
		n [3]string
		p [3]uint
		c int
	)
	for k, v := range m {
		switch {
		case v > p[2]:
			n[0], n[1], n[2] = n[1], n[2], k
			p[0], p[1], p[2] = p[1], p[2], v
			if c < 2 {
				c += 1
			}
		case p[2] > v && v > p[1]:
			n[0], n[1] = n[1], k
			p[0], p[1] = p[1], v
			if c < 2 {
				c += 2
			}
		case p[1] > v && v > p[0]:
			n[0] = k
			p[0] = v
			if c < 2 {
				c += 3
			}
		}
	}
	if c < 1 {
		n[1] = n[2]
	}
	if c < 2 {
		n[0] = n[1]
	}
	return n[0]
}
