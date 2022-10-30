/*

Create a function that reorders the digits of each numerical element in an array based on ascending (asc) or descending (desc) order.
Examples

reorderDigits([515, 341, 98, 44, 211], "asc") ➞ [155, 134, 89, 44, 112]

reorderDigits([515, 341, 98, 44, 211], "desc") ➞ [551, 431, 98, 44, 211]

reorderDigits([63251, 78221], "asc") ➞ [12356, 12278]

reorderDigits([63251, 78221], "desc") ➞ [65321, 87221]

reorderDigits([1, 2, 3, 4], "asc")  ➞ [1, 2, 3, 4]

reorderDigits([1, 2, 3, 4], "desc") ➞ [1, 2, 3, 4]

Notes

    Single-digit numbers should be ordered the same regardless of direction.
    Numbers in the array should be kept the same order.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
	"strconv"
)

func main() {
	test([]uint{515, 341, 98, 44, 211}, "asc", []uint{155, 134, 89, 44, 112})
	test([]uint{515, 341, 98, 44, 211}, "desc", []uint{551, 431, 98, 44, 211})

	test([]uint{63251, 78221}, "asc", []uint{12356, 12278})
	test([]uint{63251, 78221}, "desc", []uint{65321, 87221})

	test([]uint{1, 2, 3, 4}, "asc", []uint{1, 2, 3, 4})
	test([]uint{1, 2, 3, 4}, "desc", []uint{1, 2, 3, 4})

	test([]uint{12, 21, 15, 51}, "asc", []uint{12, 12, 15, 15})
	test([]uint{12, 21, 15, 51}, "desc", []uint{21, 21, 51, 51})
}

func test(a []uint, t string, r []uint) {
	p := reorder(a, t)
	fmt.Println(p)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reorder(a []uint, t string) []uint {
	p := make([]uint, len(a))
	for i := range a {
		p[i] = order(a[i], t)
	}
	return p
}

func order(v uint, t string) uint {
	b := []byte(fmt.Sprint(v))
	switch t {
	case "asc":
		sort.Slice(b, func(i, j int) bool { return b[i] < b[j] })
	case "desc":
		sort.Slice(b, func(i, j int) bool { return b[i] > b[j] })
	}
	n, _ := strconv.ParseUint(string(b), 10, 64)
	return uint(n)
}
