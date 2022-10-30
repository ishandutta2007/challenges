/*

Gaussian blur is a method used for blurring images smoothly. It involves creating a matrix which will be used by convolving it with the pixels of an image.
In this challenge, your task is to construct that matrix used in Gaussian blur. You will take an input r which will be the radius of the blur and an input σ which will be the standard deviation in order to construct a matrix with dimensions (2 r + 1 × 2 r + 1).
Each value in that matrix will have an (x, y) value that depends on its absolute distance in each direction from the center and will be used to compute G(x, y) where the formula G is

formula

For example, if r = 2, we want to generate a 5 x 5 matrix. First, the matrix of (x, y) values is

(2, 2) (1, 2) (0, 2) (1, 2) (2, 2)
(2, 1) (1, 1) (0, 1) (1, 1) (2, 1)
(2, 0) (1, 0) (0, 0) (1, 0) (2, 0)
(2, 1) (1, 1) (0, 1) (1, 1) (2, 1)
(2, 2) (1, 2) (0, 2) (1, 2) (2, 2)

Then, let σ = 1.5 and apply G to each (x, y)

0.0119552 0.0232856 0.0290802 0.0232856 0.0119552
0.0232856 0.0453542 0.0566406 0.0453542 0.0232856
0.0290802 0.0566406 0.0707355 0.0566406 0.0290802
0.0232856 0.0453542 0.0566406 0.0453542 0.0232856
0.0119552 0.0232856 0.0290802 0.0232856 0.0119552

Normally in image blurring, this matrix would be normalized by taking the sum of all the values in that matrix and dividing by it. For this challenge, that is not needed and the raw values calculated by the formula is what the output should be.
Rules

    This is code-golf so the shortest code wins.
    The input r will be a nonnegative integer and σ will be a positive real number.
    The output must represent a matrix. It can be formatted as a 2d array, a string representing a 2d array, or something similar.
    Floating-point inaccuracies will not be counted against you.

Test Cases

(r, σ) = (0, 0.25)
2.54648

(1, 7)
0.00318244 0.00321509 0.00318244
0.00321509 0.00324806 0.00321509
0.00318244 0.00321509 0.00318244

(3, 2.5)
0.00603332 0.00900065 0.0114421  0.012395 0.0114421 0.00900065 0.00603332
0.00900065  0.0134274 0.0170696 0.0184912 0.0170696  0.0134274 0.00900065
 0.0114421  0.0170696 0.0216997  0.023507 0.0216997  0.0170696  0.0114421
  0.012395  0.0184912  0.023507 0.0254648  0.023507  0.0184912   0.012395
 0.0114421  0.0170696 0.0216997  0.023507 0.0216997  0.0170696  0.0114421
0.00900065  0.0134274 0.0170696 0.0184912 0.0170696  0.0134274 0.00900065
0.00603332 0.00900065 0.0114421  0.012395 0.0114421 0.00900065 0.00603332

(4, 3.33)
0.00339074 0.00464913 0.00582484 0.00666854 0.00697611 0.00666854 0.00582484 0.00464913 0.00339074
0.00464913 0.00637454 0.00798657  0.0091434 0.00956511  0.0091434 0.00798657 0.00637454 0.00464913
0.00582484 0.00798657  0.0100063  0.0114556   0.011984  0.0114556  0.0100063 0.00798657 0.00582484
0.00666854  0.0091434  0.0114556   0.013115  0.0137198   0.013115  0.0114556  0.0091434 0.00666854
0.00697611 0.00956511   0.011984  0.0137198  0.0143526  0.0137198   0.011984 0.00956511 0.00697611
0.00666854  0.0091434  0.0114556   0.013115  0.0137198   0.013115  0.0114556  0.0091434 0.00666854
0.00582484 0.00798657  0.0100063  0.0114556   0.011984  0.0114556  0.0100063 0.00798657 0.00582484
0.00464913 0.00637454 0.00798657  0.0091434 0.00956511  0.0091434 0.00798657 0.00637454 0.00464913
0.00339074 0.00464913 0.00582484 0.00666854 0.00697611 0.00666854 0.00582484 0.00464913 0.00339074

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(2, 1.5)
	test(0, 0.25)
	test(1, 7)
	test(3, 2.5)
	test(4, 3.33)
}

func test(r int, s float64) {
	m := gaussian(r, s)
	dump(m)
}

func dump(m [][]float64) {
	for i := range m {
		for j := range m[i] {
			fmt.Printf("%.8f ", m[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}

func gaussian(r int, s float64) [][]float64 {
	n := 2*r + 1
	m := make([][]float64, n)
	t := make([]float64, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}

	for i := range m {
		y := float64(i - n/2)
		for j := range m {
			x := float64(j - n/2)
			m[i][j] = kernel(x, y, s)
		}
	}

	return m
}

func kernel(x, y, s float64) float64 {
	return math.Exp(-(x*x+y*y)/(2*s*s)) / (2 * math.Pi * s * s)
}
