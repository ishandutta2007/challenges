/*

This will be my very first post on stackexchange so bear with me.

Create a program that counts from 0 to 1,000,000,000. Now the trick is to not print all these characters but to only print how many zeroes are in that number. And keep track of the total amount of zeroes you've encountered. For example

10

Will output;

1
2

because 10 has 1 zero in it. The two represents how many 0's you've seen in total, in this case the only zero you have encountered previously is 0 itself so you've seen a total of 2 zeroes. The highest score will be given to the shortest code (no surprise here).

I hope that this is not too easy and that I've posted enough information, given the fact that I'm completely new here I'm not entirely sure about this.

*/

package main

import "fmt"

func main() {
	fmt.Println(count(10))
	fmt.Println(count(1e9))
}

func count(n int) (z, t int) {
	for i := 0; i <= n; i++ {
		z = zeros(i)
		t += z
	}
	return
}

func zeros(n int) int {
	c := 0
	for {
		if n%10 == 0 {
			c++
		}
		if n /= 10; n == 0 {
			break
		}
	}
	return c
}
