/*

In ACM-ICPC contests, there are usually three people in a team. For each person in the team, you know their scores in three skills - hard work, intelligence and persistence.

You want to check whether it is possible to order these people (assign them numbers from 1 to 3) in such a way that for each 1 ≤ i ≤ 2, i+1-th person is stricly better than the i-th person.

A person x is said to be better than another person y if x doesn't score less than y in any of the skills and scores more than y in at least one skill.

Determine whether such an ordering exists.

Input

The first line fo the input contains an integer T denoting the number of test cases.

Each test consists of three lines. Each of these lines contains three space separated integers s1, s2 and s3 denoting the scores of one member of the team in each of the three skills, in the given order.

Output

For each test case, output a single line containing "yes" if such an ordering exists or "no" if doesn't exist (without quotes).

Constraints
1 ≤ T ≤ 1000
1 ≤ s1, s2, s3 ≤ 100

*/

package main

func main() {
	assert(order(
		[3]int{1, 2, 3},
		[3]int{2, 3, 4},
		[3]int{2, 3, 5},
	) == true)

	assert(order(
		[3]int{1, 2, 3},
		[3]int{2, 3, 4},
		[3]int{2, 3, 4},
	) == false)

	assert(order(
		[3]int{5, 6, 5},
		[3]int{1, 2, 3},
		[3]int{2, 3, 4},
	) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func order(a, b, c [3]int) bool {
	if a == b || b == c || c == a {
		return false
	}

	tab := [][3][3]int{
		{a, b, c},
		{a, c, b},
		{b, a, c},
		{b, c, a},
		{c, a, b},
		{c, b, a},
	}
	for _, t := range tab {
		if check(t[0], t[1], t[2]) {
			return true
		}
	}
	return false
}

func check(a, b, c [3]int) bool {
	return greater(a, b) && greater(b, c)
}

func greater(a, b [3]int) bool {
	for i := range a {
		if a[i] < b[i] {
			return false
		}
	}
	return true
}
