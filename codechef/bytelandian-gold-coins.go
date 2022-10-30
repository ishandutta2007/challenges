/*

In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4.
But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?

*/

package main

import "fmt"

func main() {
	fmt.Println(profit(12))
	fmt.Println(profit(2))
	fmt.Println(profit(100))
	fmt.Println(profit(1e8))
	fmt.Println(profit(1e9))
	for i := uint64(0); i <= 1e6; i++ {
		fmt.Println(i, profit(i))
	}
}

func max(a, b uint64) uint64 {
	if a > b {
		return a
	}
	return b
}

var cache = make(map[uint64]uint64)

func profit(n uint64) uint64 {
	if cache[n] != 0 {
		return cache[n]
	}
	if n < 1 {
		return 0
	}
	a := profit(n / 2)
	cache[n/2] = a
	b := profit(n / 3)
	cache[n/3] = b
	c := profit(n / 4)
	cache[n/4] = c
	return max(n, a+b+c)
}
