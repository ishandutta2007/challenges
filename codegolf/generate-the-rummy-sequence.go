/*

Your task is to take an input n and output element n of the Rummy Sequence, a sequence which I made (looking on OEIS will not help you).

Definition
Each element of the Rummy Sequence is a set of truthy or falsey values. Ex.: [true, false].

The steps to producing a member of the Rummy Sequence are quite simple:

Start out with the first index, [] (this is element 0).
Set the leftmost falsey to truthy. If there are no falseys to change, then increase the length of the list by 1 and set all members of the new list to falsey.
Repeat step 2 until reaching element n.
Example
Let's define our function as rummy(int n) (stuff in {} is a step taken to get to the answer):

>>> rummy(5)
{[]}
{[false]}
{[true]}
{[false, false]}
{[true, false]}
[true, true]
Rules
Standard loopholes apply.
Must work for inputs 0 through your language's upper numerical bound.
You may output in any way you see fit, provided that it is clear that the output is a set of truthy/falseys.
Trivia
I call this the "Rummy Sequence" because, starting at index 2, it defines the sets you would need to lay down in each round of Progressive Rummy, where falsey is a book and truthy is a run.

Test Cases
>>> rummy(0)
[]

>>> rummy(1)
[false]

>>> rummy(6)
[false, false, false]

>>> rummy(20)
[true, true, true, true, true]

>>> rummy(1000)
[true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(0, []bool{})
	test(1, []bool{false})
	test(5, []bool{true, true})
	test(6, []bool{false, false, false})
	test(20, []bool{true, true, true, true, true})
	test(1000, []bool{true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []bool) {
	p := rummy(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func rummy(n int) []bool {
	r := []bool{}
loop:
	for i := 0; i < n; i++ {
		for j := range r {
			if r[j] == false {
				r[j] = true
				continue loop
			}
		}

		r = append(r, false)
		for j := range r {
			r[j] = false
		}
	}

	return r
}
