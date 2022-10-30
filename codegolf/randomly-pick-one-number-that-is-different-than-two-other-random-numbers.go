/*

Two random numbers A and B have been generated to be either 1, 2, or 3

your job is to randomly pick a third number C that can also be 1, 2 or 3. But, C cannot equal A or B.

    A can equal B.
    If A = B, then C has only two numbers left it can be.
    If A ≠ B, C has only one number it can be.
    Assume A and B have already been chosen for you

This is how A and B would be created in Python

A = random.randrange(1,4)
B = random.randrange(1,4)

Assume this is already in your code.

This is the shortest I've come up with in Python

while True:
    C = random.randrange(1,4)
    if C != A and C != B:
        break

Here are some acceptable values for A, B and C.

    1,2,3
    1,1,2
    2,3,1
    3,3,2

Here are some unacceptable values for A, B and C.

    1,2,1
    2,3,3
    1,1,1
    3,2,3

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(sample(3))
}

func sample(n int) (a, b, c int) {
	a = 1 + rand.Intn(n)
	b = 1 + rand.Intn(n)
	for {
		c = 1 + rand.Intn(n)
		if c != a && c != b {
			break
		}
	}
	return
}
