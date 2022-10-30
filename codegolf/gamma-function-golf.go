/*

Given a real number t in (-10^9,13) (not including -10^9 or 13) as input, output Γ(t), also known as the Gamma function, which is defined as follows:

gamma function definition

You may not use a built-in Gamma function to solve this task, nor may you use built-in numeric or symbolic integration functions. Your output should be accurate to 6 significant figures or within 10^-6 of the actual value, whichever is less restrictive for the given value. Python's built-in Gamma function will be used for determining the actual value. You may assume Γ(t) is defined - that is, t is either a positive real number or a non-integer negative real number - and that |Γ(t)| ≤ 10^9. Here is a reference program that you may use to get the actual values, using Python's built-in Gamma function.

Examples

1 -> 1.000000
-2.5 -> -0.945309
3.14159265 -> 2.288038
-2.71828182846 -> -0.952682
12 -> 39916800.000000
0.5 -> 1.772454
8.675309 -> 20248.386956
-10.1 -> -0.000002

Rules

    This is code-golf, so shortest answer (in bytes) wins.
    Standard loopholes are forbidden.
    Input and output may be performed in whatever manner is considered standard for your language.
    You may write a full program, a function, or anything that is normally considered a valid answer for your language

Leaderboard

The Stack Snippet at the bottom of this post generates the leaderboard from the answers a) as a list of shortest solution per language and b) as an overall leaderboard.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

## Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

## Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

## Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the snippet:

## [><>](http://esolangs.org/wiki/Fish), 121 bytes

*/

package main

import (
	"math"
	"math/cmplx"
)

func main() {
	tab := [][2]float64{
		{1, 1.000000},
		{-2.5, -0.945309},
		{3.14159265, 2.288038},
		{-2.71828182846, -0.952682},
		{12, 39916800.000000},
		{0.5, 1.772454},
		{8.675309, 20248.386956},
		{-10.1, -0.000002},
	}
	for _, v := range tab {
		x := v[0]
		y := v[1]
		e := math.Abs(gamma(x) - y)
		assert(e < 1e-6)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Lanczos_approximation
func gamma(x float64) float64 {
	return real(cgamma(complex(x, 0)))
}

func cgamma(z complex128) complex128 {
	p := []complex128{
		676.5203681218851,
		-1259.1392167224028,
		771.32342877765313,
		-176.61502916214059,
		12.507343278686905,
		-0.13857109526572012,
		9.9843695780195716e-6,
		1.5056327351493116e-7,
	}

	var y complex128
	if real(z) < 0.5 {
		y = math.Pi / (cmplx.Sin(math.Pi*z) * cgamma(1-z))
	} else {
		z -= 1
		x := complex(0.99999999999980993, 0)
		for i := range p {
			x += p[i] / (z + complex(float64(i), 0) + 1)
		}
		t := z + complex(float64(len(p)), 0) - 0.5
		y = cmplx.Sqrt(2*math.Pi) * cmplx.Pow(t, z+0.5) * cmplx.Exp(-t) * x
	}
	return y
}
