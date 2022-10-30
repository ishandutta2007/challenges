/*

Sleep Sort is an integer sorting algorithm I found on the Internet. It opens an output stream, and for each input numbers in parallel, delay for the number seconds and output that number.
Because of the delays, the highest number will be outputted last. I estimate it has O(n + m), where n is the number of elements and m is the highest number.

Here is the original code in Bash

#!/bin/bash
function f() {
    sleep "$1"
    echo "$1"
}
while [ -n "$1" ]
do
    f "$1" &
    shift
done
wait

Here is the pseudocode

sleepsort(xs)
 output = []
 fork
   for parallel x in xs:
     sleep for x seconds
     append x to output
 wait until length(output) == length(xs)
 return output

Your task is to implement Sleep Sort as a function in the programming language of your choice. You can neglect any concurrency factors such as race conditions and never lock any shared resources. The shortest code wins. The function definition counts toward the code length.

The input list is limited to non-negative integers only, and the length of the input list is expected to reasonably long (test at least 10 numbers) so race conditions never happen. and assuming race conditions never happen.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(sleepsort([]uint{3, 5, 6, 1, 9, 2, 6, 6, 7, 8, 10, 4, 2}))
}

func sleepsort(a []uint) []uint {
	ch := make(chan uint)
	for i := range a {
		go worker(a[i], ch)
	}

	var r []uint
	for len(r) != len(a) {
		select {
		case v := <-ch:
			r = append(r, v)
		}
	}
	return r
}

func worker(n uint, ch chan uint) {
	time.Sleep(time.Duration(n) * time.Second)
	ch <- n
}
