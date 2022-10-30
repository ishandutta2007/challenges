/*

A company conducted a coding test to hire candidates. N candidates appeared for the test, and each of them faced M problems.
Each problem was either unsolved by a candidate (denoted by 'U'), solved partially (denoted by 'P'), or solved completely (denoted by 'F').

To pass the test, each candidate needs to either solve X or more problems completely, or solve (X−1) problems completely, and Y or more problems partially.

Given the above specifications as input, print a line containing N integers. The ith integer should be 1 if the ith candidate has passed the test, else it should be 0.

Input:

The first line of the input contains an integer T, denoting the number of test cases.
The first line of each test case contains two space-separated integers, N and M, denoting the number of candidates who appeared for the test, and the number of problems in the test, respectively.
The second line of each test case contains two space-separated integers, X and Y, as described above, respectively.
The next N lines contain M characters each. The jth character of the ith line denotes the result of the ith candidate in the jth problem.
'F' denotes that the problem was solved completely, 'P' denotes partial solve, and 'U' denotes that the problem was not solved by the candidate.

Output:

For each test case, print a single line containing N integers. The ith integer denotes the result of the ith candidate. 1 denotes that the candidate passed the test, while 0 denotes that he/she failed the test.

Constraints

1≤T≤100
1≤N≤100
2≤M≤100
1≤X,Y≤M
1≤(X−1)+Y≤M

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	test([]string{
		"FUFFP",
		"PFPFU",
		"UPFFU",
		"PPPFP",
	}, 3, 2, "1100")

	test([]string{
		"PUPP",
		"UUUU",
		"UFUU",
	}, 1, 3, "101")

	test([]string{
		"PPP",
	}, 2, 2, "0")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s []string, x, y int, r string) {
	p := candidates(s, x, y)
	fmt.Println(p)
	assert(p == r)
}

func candidates(s []string, x, y int) string {
	w := new(bytes.Buffer)
	for i := range s {
		f, p := 0, 0
		for j := range s[i] {
			switch s[i][j] {
			case 'F':
				f++
			case 'P':
				p++
			}
		}
		if f >= x || (f == x-1 && p >= y) {
			w.WriteByte('1')
		} else {
			w.WriteByte('0')
		}
	}
	return w.String()
}
