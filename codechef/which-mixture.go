/*

Chef has A units of solid and B units of liquid. He combines them to create a mixture. What kind of mixture does Chef produce: a solution, a solid, or a liquid?

A mixture is called :

1) A solution if A>0 and B>0,

2) A solid if B=0, or

3) A liquid if A=0.

Input Format

The first line contains T denoting the number of test cases. Then the test cases follow.
Each test case contains two space-separated integers A and B on a single line.

Output Format

For each test case, output on a single line the type of mixture Chef produces, whether it is a Solution, Solid, or Liquid. The output is case sensitive.

Constraints
1≤T≤20
0≤A,B≤100
A+B>0

*/

package main

func main() {
	assert(mixture(10, 5) == "Solution")
	assert(mixture(0, 3) == "Liquid")
	assert(mixture(3, 0) == "Solid")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mixture(a, b int) string {
	switch {
	case a > 0 && b > 0:
		return "Solution"
	case b == 0 && a > 0:
		return "Solid"
	case a == 0 && b > 0:
		return "Liquid"
	}
	return "Invalid"
}
