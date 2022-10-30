/*

This is my first code golf question, and a very simple one at that, so I apologise in advance if I may have broken any community guidelines.

The task is to print out, in ascending order, all of the prime numbers less than a million. The output format should be one number per line of output.

The aim, as with most code golf submissions, is to minimise code size. Optimising for runtime is also a bonus, but is a secondary objective.

*/

package main

import "fmt"

func main() {
	ch := make(chan int)
	go generate(ch)
	for {
		prime := <-ch
		if prime >= 1e6 {
			break
		}
		fmt.Println(prime)
		ch1 := make(chan int)
		go filter(ch, ch1, prime)
		ch = ch1
	}
}

func generate(ch chan<- int) {
	for i := 2; ; i++ {
		ch <- i
	}
}

func filter(in <-chan int, out chan<- int, prime int) {
	for {
		i := <-in
		if i%prime != 0 {
			out <- i
		}
	}
}
