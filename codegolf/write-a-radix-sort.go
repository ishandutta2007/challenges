/*

Goal
As the title suggests, write a radix sort function (either MSB or LSB is fine) that accepts two parameters:

an array of values of any type (you can assume that they are all of the same type / class, etc.)
a function (or function pointer, depending on your language) that takes a single parameter of the same type as the objects given in the array and returns the coerced integer key of the object.
Implementation may mutate the array or operate out-of-place, but must return the sorted array.

Tips
If array indexing in your language is affected by the byte-size of each index, you can assume that the objects referenced in the array are pointers rather than values.
If the size of an array pointed to in a function parameter cannot be determined in your language, then add another parameter to your radix sort signature, passing the size in bytes of your array, or number of elements in your array, whichever you prefer:
void *rsort(void *arr, size_t length, int(*key)(const void *));

Bonus
A bonus reduction of 20% to your score will be given if your implementation memoizes the keys of the objects in the array so that the function provided only needs to be called once for each object in the array.

tl;dr
Write a radix sort with this signature, or as close as possible to this signature:

void *rsort(void *arr, int(*key)(const void *));

*/

package main

import "fmt"

func main() {
	test([]uint{170, 45, 75, 90, 802, 24, 2, 66})
	test([]uint{1, 2, 3, 4, 10, 4, 56, 43, 1000})
	test([]uint{9, 8, 7, 6, 5, 4, 3, 2, 1, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []uint) {
	radixsort(a)
	fmt.Println(a)
	assert(sorted(a))
}

// https://www.geeksforgeeks.org/radix-sort/
func radixsort(a []uint) {
	m := maxv(a)
	for e := uint(1); m/e > 0; e *= 10 {
		countsort(a, e)
	}
}

func countsort(a []uint, e uint) {
	n := len(a)
	r := make([]uint, n)
	c := [10]uint{}

	for i := 0; i < n; i++ {
		k := (a[i] / e) % 10
		c[k]++
	}

	for i := 1; i < 10; i++ {
		c[i] += c[i-1]
	}

	for i := n - 1; i >= 0; i-- {
		k := (a[i] / e) % 10
		r[c[k]-1] = a[i]
		c[k]--
	}

	copy(a, r)
}

func maxv(a []uint) uint {
	m := uint(0)
	for i := 0; i < len(a); i++ {
		if a[i] > m {
			m = a[i]
		}
	}
	return m
}

func sorted(a []uint) bool {
	for i := 1; i < len(a); i++ {
		if a[i] < a[i-1] {
			return false
		}
	}
	return true
}
