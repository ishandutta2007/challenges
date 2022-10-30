/*

Create a function that takes an arr and returns the total amount of space between the two "1"s.

Examples

spaceApart([1, 0, 1, "1", 4, 3, 2, 3, 2, "1"]) ➞ 14

spaceApart(["1", 9, 20, 38, "1"]) ➞ 67

spaceApart([3, 2, 9, "1", 0, 0, -1, "1"]) ➞ "invalid"

Notes

Return "invalid" if a negative number exists inside arr or if there is more/less than two "1"s. Ignore any other string inside arr.

*/

package main

func main() {
	assert(apart([]interface{}{1, 0, 1, "1", 4, 3, 2, 3, 2, "1"}) == 14)
	assert(apart([]interface{}{"1", 9, 20, 38, "1"}) == 67)
	assert(apart([]interface{}{3, 2, 9, "1", 0, 0, -1, "1"}) == "invalid")
	assert(apart([]interface{}{"1"}) == "invalid")
	assert(apart([]interface{}{4, 3, "1", "2", 4, "1", "2", "9"}) == 4)
	assert(apart([]interface{}{"1", -593, 1, "1", 4, 3, 2, 33, 2}) == "invalid")
	assert(apart([]interface{}{"2", "a", 1, "1", 1, 3, 49, "1"}) == 53)
}

func apart(a []interface{}) interface{} {
	var (
		r    [2]int
		i, j int
	)
	for _, v := range a {
		switch v := v.(type) {
		case string:
			if v == "1" {
				if i >= len(a) {
					return "invalid"
				}
				r[i], i, j = j, i+1, 0
			}

		case int:
			if v < 0 {
				return "invalid"
			}
			j += v
		}
	}
	if i != 2 {
		return "invalid"
	}

	return r[1]
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
