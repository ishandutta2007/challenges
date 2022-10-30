/*

Your task is to implement the sieve of Sundaram and calculate the list of primes to 10000.

this is also an interesting article about it.

*/

package main

func main() {
	assert(len(sundaram(10000)) == 1229)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Sieve_of_Sundaram
// https://plus.maths.org/content/sundarams-sieve
func sundaram(n int) []int {
	k := (n - 2) / 2
	p := make([]bool, k+1)
	for i := 1; i <= k; i++ {
		for j := i; i+j+2*i*j <= k; j++ {
			p[i+j+2*i*j] = true
		}
	}

	var r []int
	if n > 2 {
		r = append(r, 2)
	}
	for i := 1; i <= k; i++ {
		if !p[i] {
			r = append(r, 2*i+1)
		}
	}
	return r
}
