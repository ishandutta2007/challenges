/*

Chef is going on a road trip and needs to apply for inter-district and inter-state travel e-passes.
It takes A minutes to fill each inter-district e-pass application and B minutes for each inter-state e-pass application.

His journey is given to you as a binary string S of length N where 0 denotes crossing from one district to another district (which needs an inter-district e-pass), and a 1 denotes crossing from one state to another (which needs an inter-state e-pass).

Find the total time Chef has to spend on filling the various forms.

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains two lines of input.
First line contains three space separated integers N,A and B.
Second line contains the string S.

Output Format

For each testcase, output in a single line the total time Chef has to spend on filling the various forms for his journey.

Constraints
1≤T≤10^2
1≤N,A,B≤10^2
Si∈{′0′,′1′}

*/

package main

func main() {
	assert(paperwork("00", 1, 2) == 2)
	assert(paperwork("01", 1, 1) == 2)
	assert(paperwork("1101", 2, 1) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func paperwork(s string, a, b int) int {
	z, o := 0, 0
	for _, r := range s {
		switch r {
		case '0':
			z++
		case '1':
			o++
		}
	}
	return z*a + o*b
}
