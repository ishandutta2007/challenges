package main

import "fmt"

func main() {
	A := []int{1, 2, 3}
	B := []int{}
	C := []int{}
	fmt.Println(hanoi(len(A), &A, &C, &B))
}

func hanoi(n int, s, t, a *[]int) int {
	m := 0
	if n > 0 {
		m += hanoi(n-1, s, a, t)

		*t = append(*t, (*s)[len(*s)-1])
		*s = (*s)[:len(*s)-1]
		m++

		fmt.Println("source:     ", *s)
		fmt.Println("target:     ", *t)
		fmt.Println("auxilliary: ", *a)
		fmt.Println()

		m += hanoi(n-1, a, t, s)
	}
	return m
}
