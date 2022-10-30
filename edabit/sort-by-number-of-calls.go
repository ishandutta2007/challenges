/*

Create a function that takes a list of functions and sorts them in ascending order based on how many calls are needed for them to return a non-function.

Examples

f1 = _ => "hello"
// f1() ➞ "hello"

f2 = _ => _ => "edabit"
// f2()() ➞ "edabit"

f3 = _ => _ => _ => "user"
// f3()()() ➞ "user"

funcSort([f2, f3, f1]) ➞ [f1, f2, f3]
// [f2, f3, f1] ➞ [2, 3, 1] ➞ [1, 2, 3] ➞ [f1, f2, f3]

funcSort([f1, f2, f3]) ➞ [f1, f2, f3]
// [f1, f2, f3] ➞ [1, 2, 3] ➞ [1, 2, 3] ➞ [f1, f2, f3]

funcSort([f2, "func"]) ➞ ["func", f2]
// [f2, "func"] ➞ [2, 0] ➞ [0, 2] ➞ ["func", f2]

Notes

Treat non-functions as needing zero calls.
Every function will be called with empty parameters.
Every function will need to be called at least once.
The potentially returned values include Numbers, Booleans, and Strings, among others.

*/

package main

import "sort"

func main() {
	f1 := fun(1, "hello")
	f2 := fun(2, "edabit")
	f3 := fun(3, "user")
	assert(count(f1) == 1)
	assert(count(f2) == 2)
	assert(count(f3) == 3)

	fl := []func() interface{}{f2, f3, f1}
	sortfun(fl)
	for i := range fl {
		assert(count(fl[i]) == i+1)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fun(n int, v interface{}) func() interface{} {
	return func() interface{} {
		if n <= 0 {
			return v
		}
		return fun(n-1, v)
	}
}

func count(f func() interface{}) int {
	for n, ok := 0, false; ; n++ {
		f, ok = f().(func() interface{})
		if !ok {
			return n
		}
	}
}

func sortfun(f []func() interface{}) {
	sort.Slice(f, func(i, j int) bool {
		return count(f[i]) < count(f[j])
	})
}
