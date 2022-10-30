/*

This is a code-golf question.

Input

A list of non-negative integers in whatever format is the most convenient.

Output

The same list in sorted order in whatever format is the most convenient.

Restriction

    Your code must run in O(n log n) time in the worst case where nis the number of integers in the input. This means that randomized quicksort is out for example. However there are many many other options to choose from.
    Don't use any sorting library/function/similar. Also don't use anything that does most of the sorting work for you like a heap library. Basically, whatever you implement, implement it from scratch.

You can define a function if you like but then please show an example of it in a full program actually working. It should run successfully and quickly on all the test cases below.

Test cases

In: [9, 8, 3, 2, 4, 6, 5, 1, 7, 0]
Out:[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

In: [72, 59, 95, 68, 84]
Out:[59, 68, 72, 84, 95]

In: [2, 2, 1, 9, 3, 7, 4, 1, 6, 7]
Out:[1, 1, 2, 2, 3, 4, 6, 7, 7, 9]

In: [2397725, 1925225, 3304534, 7806949, 4487711, 8337622, 2276714, 3088926, 4274324,  667269]
Out:[667269,1925225, 2276714, 2397725,3088926, 3304534, 4274324, 4487711, 7806949, 8337622]

Your answers

Please state the sorting algorithm you have implemented and the length of your solution in the title of your answer.

O(n log n) time sorting algorithms

There are many O(n log n) time algorithms in existence. This table has a list of some of them.

*/

package main

import (
	"container/heap"
	"fmt"
	"reflect"
)

func main() {
	test([]int{9, 8, 3, 2, 4, 6, 5, 1, 7, 0}, []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
	test([]int{72, 59, 95, 68, 84}, []int{59, 68, 72, 84, 95})
	test([]int{2, 2, 1, 9, 3, 7, 4, 1, 6, 7}, []int{1, 1, 2, 2, 3, 4, 6, 7, 7, 9})
	test([]int{2397725, 1925225, 3304534, 7806949, 4487711, 8337622, 2276714, 3088926, 4274324, 667269}, []int{667269, 1925225, 2276714, 2397725, 3088926, 3304534, 4274324, 4487711, 7806949, 8337622})
}

func test(a, r []int) {
	p := heapsort(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func heapsort(a []int) []int {
	h := Ints(append([]int{}, a...))
	heap.Init(&h)
	for i := range a {
		a[i] = heap.Pop(&h).(int)
	}
	return a
}

type Ints []int

func (p Ints) Len() int           { return len(p) }
func (p Ints) Less(i, j int) bool { return p[i] < p[j] }
func (p Ints) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

func (p *Ints) Push(x interface{}) {
	*p = append(*p, x.(int))
}

func (p *Ints) Pop() interface{} {
	n := len(*p)
	x := (*p)[n-1]
	*p = (*p)[:n-1]
	return x
}
