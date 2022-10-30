/*


Have the function FindIntersection(strArr) read the array of strings stored in strArr which will contain 2 elements:
the first element will represent a list of comma-separated numbers sorted in ascending order, the second element will represent a second list of comma-separated numbers (also sorted).
Your goal is to return a comma-separated string containing the numbers that occur in elements of strArr in sorted order. If there is no intersection, return the string false.

Examples

Input: ["1, 3, 4, 7, 13", "1, 2, 4, 13, 15"]
Output: 1,4,13

Input: ["1, 3, 9, 10, 17, 18", "1, 4, 9, 10"]
Output: 1,9,10

*/

package main

import (
	"encoding/csv"
	"fmt"
	"reflect"
	"strconv"
	"strings"
)

func main() {
	test("1, 3, 4, 7, 13", "1, 2, 4, 13, 15", []int{1, 4, 13})
	test("1, 3, 9, 10, 17, 18", "1, 4, 9, 10", []int{1, 9, 10})
	test("", "", []int{})
}

func test(s, t string, r []int) {
	p := intersect(s, t)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func intersect(s, t string) []int {
	a, err := csv2int(s)
	b, xerr := csv2int(t)
	if err != nil || xerr != nil {
		return nil
	}

	r := []int{}
	for i, j := 0, 0; i < len(a) && j < len(b); {
		switch {
		case a[i] < b[j]:
			i++
		case b[j] < a[i]:
			j++
		default:
			r = append(r, a[i])
			i++
			j++
		}
	}
	return r
}

func csv2int(s string) ([]int, error) {
	r := csv.NewReader(strings.NewReader(s))
	p, err := r.ReadAll()
	if err != nil {
		return nil, err
	}

	var v []int
	for i := range p {
		for j := range p[i] {
			t := strings.TrimSpace(p[i][j])
			n, err := strconv.Atoi(t)
			if err != nil {
				return nil, err
			}
			v = append(v, n)
		}
	}
	return v, nil
}
