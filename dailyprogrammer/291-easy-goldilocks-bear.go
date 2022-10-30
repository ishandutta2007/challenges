/*

Once upon a time, there lived an adventurous little girl called Goldilocks. She explored the world with abandon, having a lot of fun.
During her latest foray into the woods, she found another bear home -- though this one is home to many more bears.
Having learned from her previous experiences, Goldilocks knows that trial and error is not an efficient way of finding the right chair and porridge to help herself to.

The task falls to you: given descriptions of Goldilocks' needs and of the available porridge/chairs at the dinner table, tell Goldilocks which chair to sit in so the chair does not break, and the porridge is at an edible temperature.
Formal Input

The input begins with a line specifying Goldilocks' weight (as an integer in arbitrary weight-units) and the maximum temperature of porridge she will tolerate (again as an arbitrary-unit integer).
This line is then followed by some number of lines, specifying a chair's weight capacity, and the temperature of the porridge in front of it.

Sample input:

100 80
30 50
130 75
90 60
150 85
120 70
200 200
110 100

Interpreting this, Goldilocks has a weight of 100 and a maximum porridge temperature of 80.
The first seat at the table has a chair with a capacity of 30 and a portion of porridge with the temperature of 50.
The second has a capacity of 130 and temperature of 60, etc.
Formal Output

The output must contain the numbers of the seats that Goldilocks can sit down at and eat up. This number counts up from 1 as the first seat.

Sample output:

2 5

Seats #2 and #5 have both good enough chairs to not collapse under Goldilocks, and porridge that is cool enough for her to eat.
Challenge Input

100 120
297 90
66 110
257 113
276 191
280 129
219 163
254 193
86 153
206 147
71 137
104 40
238 127
52 146
129 197
144 59
157 124
210 59
11 54
268 119
261 121
12 189
186 108
174 21
77 18
54 90
174 52
16 129
59 181
290 123
248 132

Finally...

Have a good challenge idea? Drop by r/dailyprogrammer_ideas and tell us about it! Just don't eat our porridge.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	g1 := [2]int{100, 80}
	a1 := [][2]int{
		{30, 50},
		{130, 75},
		{90, 60},
		{150, 85},
		{120, 70},
		{200, 200},
		{110, 100},
	}
	r1 := []int{2, 5}

	g2 := [2]int{100, 120}
	a2 := [][2]int{
		{297, 90},
		{66, 110},
		{257, 113},
		{276, 191},
		{280, 129},
		{219, 163},
		{254, 193},
		{86, 153},
		{206, 147},
		{71, 137},
		{104, 40},
		{238, 127},
		{52, 146},
		{129, 197},
		{144, 59},
		{157, 124},
		{210, 59},
		{11, 54},
		{268, 119},
		{261, 121},
		{12, 189},
		{186, 108},
		{174, 21},
		{77, 18},
		{54, 90},
		{174, 52},
		{16, 129},
		{59, 181},
		{290, 123},
		{248, 132},
	}
	r2 := []int{1, 3, 11, 15, 17, 19, 22, 23, 26}

	test(g1, a1, r1)
	test(g2, a2, r2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(g [2]int, a [][2]int, r []int) {
	p := goldilocks(g, a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func goldilocks(g [2]int, a [][2]int) []int {
	var r []int
	for i, v := range a {
		if g[0] <= v[0] && g[1] >= v[1] {
			r = append(r, i+1)
		}
	}
	return r
}
