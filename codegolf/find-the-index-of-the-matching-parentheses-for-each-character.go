/*

The challenge is simple, find the matching parentheses for every one of the parentheses in a given string input

E.g.

()()() -> [1, 0, 3, 2, 5, 4]
Always start with the ending parentheses index before the starting parentheses, which is why () becomes [1,0], not [0,1], unless the parentheses is stacked e.g. (()), where the position of the parentheses must match the index so (()) is [3, 2, 1, 0]

Test Cases:
() -> [1, 0]
()(()) -> [1, 0, 5, 4, 3, 2]
()()() -> [1, 0, 3, 2, 5, 4]
((())) -> [5, 4, 3, 2, 1, 0]
(()(())) -> [7, 2, 1, 6, 5, 4, 3, 0]
You may output the indexes in the form of a list, or in the form of a string representation if so, but the output indexes must be distinguishable from each other e.g. 1 0

You are allowed to use 0-index or 1-indexed lists/arrays

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("()", []int{1, 0})
	test("()(())", []int{1, 0, 5, 4, 3, 2})
	test("()()()", []int{1, 0, 3, 2, 5, 4})
	test("((()))", []int{5, 4, 3, 2, 1, 0})
	test("(()(()))", []int{7, 2, 1, 6, 5, 4, 3, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []int) {
	p, err := parens(s)
	fmt.Println(p)
	assert(err == nil)
	assert(reflect.DeepEqual(p, r))
}

func parens(s string) ([]int, error) {
	m := make(map[int]int)
	t := []int{}
	p := []int{}
	for i, r := range s {
		switch r {
		case '(':
			p = append(p, i)
			t = append(t, i)
		case ')':
			n := len(t) - 1
			if n < 0 {
				return nil, fmt.Errorf("no open parentheses for closing parentheses at %d", i)
			}

			j := t[n]
			m[i] = j
			m[j] = i

			p = append(p, i)
			t = t[:n]
		}
	}
	if len(t) != 0 {
		return nil, fmt.Errorf("unclosed open parentheses")
	}

	for i := range p {
		p[i] = m[p[i]]
	}

	return p, nil
}
