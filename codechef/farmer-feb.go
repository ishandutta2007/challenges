/*

Farmer Feb has three fields with potatoes planted in them. He harvested x potatoes from the first field, y potatoes from the second field and is yet to harvest potatoes from the third field.
Feb is very superstitious and believes that if the sum of potatoes he harvests from the three fields is a prime number (http://en.wikipedia.org/wiki/Prime_number), he'll make a huge profit.
Please help him by calculating for him the minimum number of potatoes that if harvested from the third field will make the sum of potatoes prime. At least one potato should be harvested from the third field.

Input

The first line of the input contains an integer T denoting the number of test cases. Each of the next T lines contain 2 integers separated by single space: x and y.

Output

For each test case, output a single line containing the answer.

Constraints
1 ≤ T ≤ 1000
1 ≤ x ≤ 1000
1 ≤ y ≤ 1000

*/

package main

import (
	"math"
	"math/big"
)

func main() {
	assert(potatoes(1, 3) == 1)
	assert(potatoes(4, 3) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func potatoes(x, y int64) int64 {
	for n := x + y + 1; n < math.MaxInt64; n++ {
		if isprime(n) {
			return n - (x + y)
		}
	}
	return -1
}

func isprime(n int64) bool {
	x := big.NewInt(n)
	return x.ProbablyPrime(2)
}
