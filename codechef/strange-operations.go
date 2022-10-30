/*

Given an array consisting of N integers, you have to do the following operation K times.

Find out the sum of all the elements in the array. Denote it by S.
Insert an integer in the array strictly greater than S. Hence, size of the array will increase by one.
Thus, at the end of the K operations, the array will have N + K elements. Find out the smallest possible value of the last number inserted in the array.
Since this number can be very large, you just have to tell whether it will be odd or even.

Input

The first line of each test file contains the number of test cases, T.
The description of the test cases follows this line. Each test case description consists of 2 lines.
The first line has the values of N and K, separated by a space.
The next line contains a single-space separated list of values of the elements in the array.

Output

For each test case, output a single line containing the answer to the problem.If the number is even print "even" and if the number is odd print "odd".

Constraints:
1 ≤ T ≤10
1 ≤ K ≤ 10^6
1 ≤ N ≤ 10^3
1 ≤ array element ≤ 10^9

*/

package main

func main() {
	assert(parity([]int{5, 7}, 3) == "even")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func parity(a []int, k int) string {
	s := 0
	for _, v := range a {
		s += v
	}

	l := 0
	for i := 0; i < k; i++ {
		l = s + 1
		s += l
	}

	if l&1 == 0 {
		return "even"
	}
	return "odd"
}
