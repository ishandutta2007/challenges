/*

Background

A linear recurrence relation is a description of a sequence, defined as one or more initial terms and a linear formula on last k terms to calculate the next term.
(For the sake of simplicity, we only consider homogeneous relations, i.e. the ones without a constant term in the formula.)

A formal definition of a linear recurrence relation looks like this, where yn
is the desired sequence (1-based, so it is defined over n≥1) and xi's and ai's are constants:

y[n] = x[n]                                1 <= n <= k
       a[1]y[n-1]+a[2]y[n-2]+⋯+a[k]y[n-k]  k < n

In this challenge, we will accelerate this sequence by converting it to a matrix form, so that the n-th term can be found by repeated squaring of the matrix in O(logn) steps, followed by inner product with the vector of initial terms.

For example, consider the famous Fibonacci sequence: its recurrence relation is y[n]=y[n-1]+y[n-2]
with k=2, and let's use the initial values x1=x2=1.

The recurrence relation can be converted to a matrix form:
[y[n-1]] =>  [y[n-1]]        => [0 1] [y[n-2]]
[y[n]]   =>  [y[n-1]+y[n-2]] => [1 1] [y[n-1]]

So multiplying the matrix once advances the sequence by one term. Since this holds for any n, it can be extended all the way until we reach the initial terms:

In general, one way to construct such a matrix is the following:

[y[n-k+1]] [0 1 0 ... 0]                  [y[n-k]]
[y[n-k+2]] [0 0 1 ... 0]                  [y[n-k+1]]
  ...      [    ...    ]                    ...
[y[n-1]]   [0 0 0 ... 1]                  [y[n-2]]
[y[n]]     [a[k] a[k-1] a[k-2] ... [a1]]  [y[n-1]]

Note that, if you reverse the vectors and the matrix in every dimension, the equation still holds, retaining the property of "advancing a term by matmul-ing once".
(Actually any permutation will work, given that the rows and columns of the matrix are permuted in the same way.)
Challenge

Given the list of coefficients a1,⋯,ak, construct a matrix that represents the recurrence relation (so that its powers can be used to accelerate the computation of n-th term of the sequence).

You can take the coefficients in reverse order, and you can optionally take the value k as a separate input. k (the number of terms) is at least 1.

Standard code-golf rules apply. The shortest code in bytes wins.
Test cases

In all cases, any other matrix that can be formed by permuting rows and columns in the same way is also valid.

Input
[1,1]
Output
[[0, 1],
 [1, 1]]

Input
[5]
Output
[[5]]

Input
[3, -1, 19]
Output
[[0,  1,  0],
 [0,  0,  1],
 [19, -1, 3]]
or reversed in both dimensions:
[[3, -1, 19],
 [1, 0,  0],
 [0, 1,  0]]
or cycled once in both dimensions:
[[3, 19, -1],
 [0, 0,  1],
 [1, 0,  0]]
etc.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 1}, [][]int{{0, 1}, {1, 1}})
	test([]int{5}, [][]int{{5}})
	test([]int{3, -1, 19}, [][]int{{0, 1, 0}, {0, 0, 1}, {19, -1, 3}})
}

func test(a []int, r [][]int) {
	m := matrix(a)
	fmt.Println(m)
	assert(reflect.DeepEqual(m, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func matrix(a []int) [][]int {
	n := len(a)
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	for i := 0; i < n-1; i++ {
		m[i][i+1] = 1
	}
	for i := range a {
		m[n-1][n-i-1] = a[i]
	}
	return m
}
