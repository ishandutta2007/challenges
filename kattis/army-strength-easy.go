/*

Note that this is an easier version of the problem armystrengthhard.

The next MechaGodzilla invasion is on its way to Earth. And once again, Earth will be the battleground for an epic war.
MechaGodzilla’s army consists of many nasty alien monsters, such as Space Godzilla, King Gidorah, and MechaGodzilla herself.
To stop them and defend Earth, Godzilla and her friends are preparing for the battle.

Each army consists of many different monsters. Each monster has a strength that can be described by a positive integer.
The larger the value, the stronger the monster. The war will consist of a series of battles.
In each battle, the weakest of all the monsters that are still alive is killed.
If there are several weakest monsters, but all of them in the same army, one of them is killed at random.
If both armies have at least one of the weakest monsters, a random weakest monster of MechaGodzilla’s army is killed.
The war is over if in one of the armies all monsters are dead. The dead army lost, the other one won. You are given the strengths of all the monsters. Find out who wins the war.

Input

The first line of the input file contains an integer T≤50 specifying the number of test cases. Each test case is preceded by a blank line.

Each test case starts with line containing two positive integers NG and NM – the number of monsters in Godzilla’s and in MechaGodzilla’s army. You can assume that NG,NM≤500.

Two lines follow. The first one contains NG positive integers – the strengths of the monsters in Godzilla’s army.
Similarly, the second one contains NM positive integers – the strengths of the monsters in MechaGodzilla’s army. All strengths are at most 10000.

Output

For each test case, output a single line with a string that describes the outcome of the battle.
If it is sure that Godzilla’s army wins, output the string “Godzilla”.
If it is sure that MechaGodzilla’s army wins, output the string “MechaGodzilla”. Otherwise, output the string “uncertain”.

*/

package main

import (
	"sort"
)

func main() {
	assert(winner([]int{1}, []int{1}) == "Godzilla")
	assert(winner([]int{1, 3, 2}, []int{5, 5}) == "MechaGodzilla")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func winner(a, b []int) string {
	sort.Ints(a)
	sort.Ints(b)

	x, y := 0, 0
	for x < len(a) && y < len(b) {
		if a[x] < b[y] {
			x++
		} else {
			y++
		}
	}

	if x < y {
		return "Godzilla"
	}
	if x > y {
		return "MechaGodzilla"
	}
	return "Uncertain"
}
