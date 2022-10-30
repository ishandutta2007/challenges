/*

Challenge:

Given a number, take the largest prime strictly less than it, subtract it from this number, do this again to this new number with the biggest prime less than it, and continue doing this until it's less than 3.
If it reaches 1, your program should output a truthy value, else, the program should output a falsey value.

Examples:
All of these should give a truthy value:

3
4
6
8
10
11
12
14
16
17
18
20
22
23
24
26
27
29
30
32
34
35
37
38
40
41
42
44
46
47
48
50
All of these should give falsey values:

5
7
9
13
15
19
21
25
28
31
33
36
39
43
45
49
Rules:
You can either write a program or function.
You can assume that the input is bigger than 2.
Standard loopholes apply
This is code-golf so the shortest answer wins!

*/

package main

import (
	"math/big"
)

func main() {
	truthy := []int64{
		3,
		4,
		6,
		8,
		10,
		11,
		12,
		14,
		16,
		17,
		18,
		20,
		22,
		23,
		24,
		26,
		27,
		29,
		30,
		32,
		34,
		35,
		37,
		38,
		40,
		41,
		42,
		44,
		46,
		47,
		48,
		50,
	}

	falsey := []int64{
		5,
		7,
		9,
		13,
		15,
		19,
		21,
		25,
		28,
		31,
		33,
		36,
		39,
		43,
		45,
		49,
	}

	for _, v := range truthy {
		assert(reachable(v) == true)
	}
	for _, v := range falsey {
		assert(reachable(v) == false)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reachable(n int64) bool {
	if n < 3 {
		return false
	}

	for m := n - 1; n > 1 && m > 1; m-- {
		if isprime(m) {
			n -= m
			m = n
		}
	}
	return n == 1
}

func isprime(n int64) bool {
	x := big.NewInt(n)
	return x.ProbablyPrime(2)
}
