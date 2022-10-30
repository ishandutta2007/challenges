/*

Goal
Generate (N) random line segments of uniform length (l), check if they cross the equidistant (t) parallel lines.

Simulation
What are we simulating? Buffon's needle. Smooth out the sand in your sandbox, draw a set of equally spaced parallel lines (call the distance in between t).
Take a straight stick of length l and drop it N times into the sandbox. Let the number of times it crossed a line be c. Then Pi = (2 * l * n) / (t * c)!

How are we simulating this?

Take input N,t,l With N, t, l all being positive integers

Do the following N times:

Generate a uniformly random integer coordinate x,y With 1 <= x, y <= 10^6
x,y is the center of a line segment of length l

Generate a uniformly random integer a With 1 <= a <= 180

Let P be the point where the line segment would cross the x-axis

Then a is the angle (x,y), P, (inf,0)

Count the number, c, of line segments that cross the line x = i*t for any integer i

Return (2 * l * N) / (t * c)

Specification

Input
Flexible, take input in any of the standard ways (eg function parameter,STDIN) and in any standard format (eg String, Binary)

Output
Flexible, give output in any of the standard ways (eg return, print)
White space, trailing and leading white space is acceptable
Accuracy, please provide at least 4 decimal places of accuracy (ie 3.1416)

Scoring
Shortest code wins!

Test Cases
Your output may not line up with these, because of random chance. But on average, you should get about this much accuracy for the given value of N, t, l.

Input (N,t,l)    ->  Output
-----------        ------
10,10,5          -> ?.????
10,100,50        -> ?.????
1000,1000,600    -> 3.????
10000,1000,700   -> 3.1???
100000,1000,700  -> 3.14??

TL;DR
These challenges are simulations of algorithms that only require nature and your brain (and maybe some re-usable resources) to approximate Pi. If you really need Pi during the zombie apocalypse, these methods don't waste ammo! There are nine challenges total.

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(sim(10, 10, 5))
	fmt.Println(sim(10, 100, 50))
	fmt.Println(sim(1000, 1000, 600))
	fmt.Println(sim(10000, 1000, 700))
	fmt.Println(sim(100000, 1000, 700))
	fmt.Println(sim(1000000, 10000, 1000))
	fmt.Println(sim(10000000, 10000, 10000))
}

func sim(N, t, l int) float64 {
	c := 0
	for i := 0; i < N; i++ {
		x := rand.NormFloat64()
		y := rand.NormFloat64()

		u := float64((1 + rand.Intn(1e6)) % t)
		v := x / math.Hypot(x, y)
		if u+math.Abs(v)*float64(l) > float64(t) {
			c++
		}
	}
	return float64(2*l*N) / float64(t*c)
}
