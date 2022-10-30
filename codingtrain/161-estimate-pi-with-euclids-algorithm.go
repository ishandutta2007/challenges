package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(estimate(1e6))
}

/*

The probability of two random numbers being coprime is 6/pi^2.

P(gcd(a, b) = 1) = 6/pi^2

Converting the probability into trial simulation gives the following

coprimes/total_trials = 6/pi^2

Solving for pi gives us

pi ~ sqrt(6*total_trials/coprimes)

*/

func estimate(n int) float64 {
	p := 0
	for i := 0; i < n; i++ {
		a := rand.Int()
		b := rand.Int()
		if gcd(a, b) == 1 {
			p++
		}
	}

	return math.Sqrt(float64(6*n) / float64(p))
}

func gcd(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}
