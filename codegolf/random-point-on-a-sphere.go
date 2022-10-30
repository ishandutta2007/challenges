/*

Write a program or function that takes no input and outputs a 3-dimensional vector of length 1

in a theoretically uniform random direction.

This is equivalent to a random point on the sphere described by
x2+y2+z2=1

resulting in a distribution like such

Random distribution of points on a sphere with radius 1.
Output

Three floats from a theoretically uniform random distribution for which the equation x2+y2+z2=1

holds true to precision limits.
Challenge remarks

    The random distribution needs to be theoretically uniform. That is, if the pseudo-random number generator were to be replaced with a true RNG from the real numbers, it would result in a uniform random distribution of points on the sphere.
    Generating three random numbers from a uniform distribution and normalizing them is invalid: there will be a bias towards the corners of the three-dimensional space.
    Similarly, generating two random numbers from a uniform distribution and using them as spherical coordinates is invalid: there will be a bias towards the poles of the sphere.
    Proper uniformity can be achieved by algorithms including but not limited to:
        Generate three random numbers x

x, y and z from a normal (Gaussian) distribution around 0 and normalize them.

    Implementation example

Generate three random numbers x, y and z from a uniform distribution in the range (−1,1).
Calculate the length of the vector by l=sqrt(x2+y2+z2). Then, if l>1, reject the vector and generate a new set of numbers. Else, if l≤1, normalize the vector and return the result.

    Implementation example

Generate two random numbers i and j from a uniform distribution in the range (0,1) and convert them to spherical coordinates like so:
θϕ=2×π×i=cos−1(2×j−1)
so that x, y and z can be calculated by
xyz=cos(θ)×sin(ϕ)=sin(θ)×sin(ϕ)=cos(ϕ)
    Implementation example

	Provide in your answer a brief description of the algorithm that you are using.
    Read more on sphere point picking on MathWorld.

Output examples

[ 0.72422852 -0.58643067  0.36275628]
[-0.79158628 -0.17595886  0.58517488]
[-0.16428481 -0.90804027  0.38532243]
[ 0.61238768  0.75123833 -0.24621596]
[-0.81111161 -0.46269121  0.35779156]

General remarks

    This is code-golf, so the answer using the fewest bytes in each language wins.
    Standard rules, I/O rules and loophole rules apply.
    Please include a Try it Online-link or equivalent to demonstrate your code working.
    Please motivate your answer with an explanation of your code.

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
	for i := 0; i < 10; i++ {
		p := sphpt()
		fmt.Println(p)
	}
}

func length(v [3]float64) float64 {
	return math.Sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2])
}

func normalize(v [3]float64) [3]float64 {
	l := length(v)
	if l == 0 {
		return [3]float64{}
	}
	return [3]float64{v[0] / l, v[1] / l, v[2] / l}
}

func sphpt() [3]float64 {
	return normalize([3]float64{
		rand.NormFloat64(),
		rand.NormFloat64(),
		rand.NormFloat64(),
	})
}
