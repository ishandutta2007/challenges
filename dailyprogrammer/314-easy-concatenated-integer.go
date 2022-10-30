/*

Description

Given a list of integers separated by a single space on standard input, print out the largest and smallest values that can be obtained by concatenating the integers together on their own line.
This is from Five programming problems every Software Engineer should be able to solve in less than 1 hour, problem 4. Leading 0s are not allowed (e.g. 01234 is not a valid entry).

This is an easier version of #312I.

Sample Input

You'll be given a handful of integers per line. Example:

5 56 50

Sample Output

You should emit the smallest and largest integer you can make, per line. Example:

50556 56550

Challenge Input

79 82 34 83 69
420 34 19 71 341
17 32 91 7 46

Challenge Output

3469798283 8382796934
193413442071 714203434119
173246791 917463217

Bonus

EDIT My solution uses permutations, which is inefficient. Try and come up with a more efficient approach.

*/

package main

import (
	"bytes"
	"fmt"
	"sort"
)

func main() {
	test([]uint{34, 342}, [2]string{"34234", "34342"})
	test([]uint{34, 348}, [2]string{"34348", "34834"})
	test([]uint{5, 56, 50}, [2]string{"50556", "56550"})
	test([]uint{79, 82, 34, 83, 69}, [2]string{"3469798283", "8382796934"})
	test([]uint{420, 34, 19, 71, 341}, [2]string{"193413442071", "714203434119"})
	test([]uint{17, 32, 91, 7, 46}, [2]string{"173246791", "917463217"})
}

func test(a []uint, r [2]string) {
	p := minmax(a)
	fmt.Println(p)
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func minmax(a []uint) [2]string {
	sort.Slice(a, func(i, j int) bool {
		x := digits(a[i])
		y := digits(a[j])
		return cmp(x, y)
	})

	s := new(bytes.Buffer)
	t := new(bytes.Buffer)
	n := len(a)
	for i := 0; i < n; i++ {
		fmt.Fprint(s, a[i])
		fmt.Fprint(t, a[n-i-1])
	}

	return [2]string{s.String(), t.String()}
}

func digits(x uint) []uint {
	var d []uint
	for {
		d = append(d, x%10)
		if x /= 10; x == 0 {
			break
		}
	}
	return d
}

func cmp(x, y []uint) bool {
	n := len(x)
	m := len(y)
	for i, j := n-1, m-1; i >= 0 || j >= 0; i, j = i-1, j-1 {
		p := mod(i, n)
		q := mod(j, m)
		if x[p] < y[q] {
			return true
		} else if x[p] > y[q] {
			return false
		}
	}
	return false
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
