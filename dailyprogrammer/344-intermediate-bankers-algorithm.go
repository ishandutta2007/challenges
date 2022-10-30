/*

Description:
Create a program that will solve the banker’s algorithm.
This algorithm stops deadlocks from happening by not allowing processes to start if they don’t have access to the resources necessary to finish.
A process is allocated certain resources from the start, and there are other available resources. In order for the process to end, it has to have the maximum resources in each slot.

Ex:

Process	Allocation	Max	Available
A B C	A B C	A B C
P0	0 1 0	7 5 3	3 3 2
P1	2 0 0	3 2 2
P2	3 0 2	9 0 2
P3	2 1 1	2 2 2
P4	0 0 2	4 3 3

Since there is 3, 3, 2 available, P1 or P3 would be able to go first. Let’s pick P1 for the example. Next, P1 will release the resources that it held, so the next available would be 5, 3, 2.

The Challenge:

Create a program that will read a text file with the banker’s algorithm in it, and output the order that the processes should go in. An example of a text file would be like this:

[3 3 2]

[0 1 0 7 5 3]

[2 0 0 3 2 2]

[3 0 2 9 0 2]

[2 1 1 2 2 2]

[0 0 2 4 3 3]

And the program would print out:

P1, P4, P3, P0, P2

Bonus:
Have the program tell you if there is no way to complete the algorithm.

*/

package main

import "fmt"

func main() {
	fmt.Println(bankers(5, 3,
		[]int{3, 3, 2},
		[][]int{
			{0, 1, 0},
			{2, 0, 0},
			{3, 0, 2},
			{2, 1, 1},
			{0, 0, 2},
		},
		[][]int{
			{7, 5, 3},
			{3, 2, 2},
			{9, 0, 2},
			{2, 2, 2},
			{4, 3, 3},
		},
	))

	fmt.Println(bankers(3, 3,
		[]int{5, 5, 5},
		[][]int{
			{1, 2, 1},
			{2, 0, 1},
			{2, 2, 1},
		},
		[][]int{
			{2, 2, 4},
			{2, 1, 3},
			{3, 4, 1},
		},
	))

	fmt.Println(bankers(5, 3,
		[]int{2, 1, 0},
		[][]int{
			{1, 1, 2},
			{2, 1, 2},
			{4, 0, 1},
			{0, 2, 0},
			{1, 1, 2},
		},
		[][]int{
			{4, 3, 3},
			{3, 2, 2},
			{9, 0, 2},
			{7, 5, 3},
			{1, 1, 2},
		},
	))
}

/*

https://en.wikipedia.org/wiki/Banker's_algorithm
https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/

*/

func bankers(n, m int, avail []int, alloc [][]int, max [][]int) []int {
	need := make([][]int, n)
	for i := range need {
		need[i] = make([]int, m)
		for j := range need[i] {
			need[i][j] = max[i][j] - alloc[i][j]
		}
	}

	r := []int{}
	f := make([]bool, n)
	c := 0
	for i := 0; i < n; i++ {
	loop:
		for j := 0; j < n; j++ {
			if f[j] {
				continue
			}

			for k := 0; k < m; k++ {
				if need[j][k] > avail[k] {
					continue loop
				}
			}

			r = append(r, j)
			for k := 0; k < m; k++ {
				avail[k] += alloc[j][k]
			}

			f[j], c = true, c+1
		}
	}

	if c != n {
		return nil
	}
	return r
}
