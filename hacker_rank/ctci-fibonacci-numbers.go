/*

Check out the resources on the page's right side to learn more about recursion. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

The Fibonacci Sequence

The Fibonacci sequence appears in nature all around us, in the arrangement of seeds in a sunflower and the spiral of a nautilus for example.

Complete the recursive function

*/
package main

import "fmt"

func main() {
	for i := uint64(0); i <= 64; i++ {
		fmt.Println(fib(i))
	}
}

var cache = make(map[uint64]uint64)

func fib(n uint64) uint64 {
	if n <= 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	if cache[n] != 0 {
		return cache[n]
	}
	a := fib(n - 1)
	cache[n-1] = a
	b := fib(n - 2)
	cache[n-2] = b
	return a + b
}
