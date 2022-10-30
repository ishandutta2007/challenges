/*

You are given two functions g(x) and h(x), each of which takes an integer x and returns the number ax+b (where a and b are integers defined in the function).

Your task is to write a function f(g,h) that takes these two functions, and returns a function k(x)=g(h(x)),
but where the procedure of k(x) is also simply of the form ax+b.

For example, given g(x)=2x+3 and h(x)=3x+4, you would need to return k(x)=6x+11, and not k(x)=2(3x+4)+3.

*/

package main

func main() {
	g1 := func(x int) int { return 2*x + 3 }
	h1 := func(x int) int { return 3*x + 4 }

	g2 := func(x int) int { return 405*x + 104 }
	h2 := func(x int) int { return 13*x + 13 }

	test(g1, h1)
	test(g2, h2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(g, h Linear) {
	f := compose(g, h)
	for i := -1000; i <= 1000; i++ {
		assert(f(i) == g(h(i)))
	}
}

func compose(g, h Linear) Linear {
	a, b := coeff(g)
	c, d := coeff(h)
	return func(x int) int {
		return a*c*x + a*d + b
	}
}

func coeff(f Linear) (int, int) {
	b := f(0)
	a := f(1) - b
	return a, b
}

type Linear func(int) int
