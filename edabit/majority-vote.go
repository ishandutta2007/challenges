/*

Create a function that returns the majority vote in an array. A majority vote is an element that occurs > N/2 times in an array (where N is the length of the array).
Examples

majorityVote(["A", "A", "B"]) ➞ "A"

majorityVote(["A", "A", "A", "B", "C", "A"]) ➞ "A"

majorityVote(["A", "B", "B", "A", "C", "C"]) ➞ "None"

Notes

	The frequency of the majority element must be strictly greater than 1/2.
	If there is no majority element, return "None".

*/

package main

func main() {
	assert(majority([]string{"A", "A", "B"}) == "A")
	assert(majority([]string{"A", "A", "A", "B", "C", "A"}) == "A")
	assert(majority([]string{"A", "B", "B", "A", "C", "C"}) == "None")
	assert(majority([]string{"A", "A", "B"}) == "A")
	assert(majority([]string{"A", "B", "B", "B", "A", "A"}) == "None")
	assert(majority([]string{"B", "B", "B"}) == "B")
	assert(majority([]string{"A", "B", "B"}) == "B")
	assert(majority([]string{"A", "A", "B"}) == "A")
	assert(majority([]string{"A", "A", "A", "B", "C", "A"}) == "A")
	assert(majority([]string{"B", "A", "B", "B", "C", "A", "B", "B"}) == "B")
	assert(majority([]string{"A", "B", "B", "A", "C", "C"}) == "None")
	assert(majority([]string{"A", "B"}) == "None")
	assert(majority([]string{}) == "None")
	assert(majority([]string{"C", "D"}) == "None")
	assert(majority([]string{"X", "Q", "Y", "X"}) == "X")
	assert(majority([]string{"ZZ", "UU", "AA", "BB"}) == "None")
	assert(majority([]string{"R"}) == "R")
}

func majority(s []string) string {
	p := "None"
	c := 0
	m := make(map[string]int)
	for _, s := range s {
		m[s]++
		if n := m[s]; n > c {
			p, c = s, n
		} else if n == c {
			p = "None"
		}
	}
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
