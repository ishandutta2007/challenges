/*

Description

We'll call the consecutive distance rating of an integer sequence the sum of the distances between consecutive integers.
Consider the sequence 1 7 2 11 8 34 3. 1 and 2 are consecutive integers, but their distance apart in the sequence is 2.
2 and 3 are consecutive integers, and their distance is 4. The distance between 7 and 8 is 3. The sum of these distances is 9.

Your task is to find and display the consecutive distance rating of a number of integer sequences.

Input description

You'll be given two integers a and b on the first line denoting the number of sequences that follow and the length of those sequences, respectively.
You'll then be given a integer sequences of length b, one per line. The integers will always be unique and range from 1 to 100 inclusive.

Example input

6 11
31 63 53 56 96 62 73 25 54 55 64
77 39 35 38 41 42 76 73 40 31 10
30 63 57 87 37 31 58 83 34 76 38
18 62 55 92 88 57 90 10 11 96 12
26 8 7 25 52 17 45 64 11 35 12
89 57 21 55 56 81 54 100 22 62 50

Output description

Output each consecutive distance rating, one per line.
Example output

26
20
15
3
6
13

Challenge input

6 20
76 74 45 48 13 75 16 14 79 58 78 82 46 89 81 88 27 64 21 63
37 35 88 57 55 29 96 11 25 42 24 81 82 58 15 2 3 41 43 36
54 64 52 39 36 98 32 87 95 12 40 79 41 13 53 35 48 42 33 75
21 87 89 26 85 59 54 2 24 25 41 46 88 60 63 23 91 62 61 6
94 66 18 57 58 54 93 53 19 16 55 22 51 8 67 20 17 56 21 59
6 19 45 46 7 70 36 2 56 47 33 75 94 50 34 35 73 72 39 5

Notes / hints

Be careful that your program doesn't double up the distances. Consider the sequence 1 2. An incorrect algorithm might see 1 -> 2 and 2 -> 1 as two separate distances, resulting in a (wrong) consecutive distance rating of 2.
Visually, you should think of distances like this and not like that.

Bonus

Modify your program to work with any size gap between integers. For instance, we might want to find the distance rating of integers with a gap of 2, such as 1 and 3 or 7 and 9 rather than consecutive integers with a gap of 1.
Credit

This challenge was authored by /u/chunes, many thanks!

Have a good challenge idea? Consider submitting it to r/dailyprogrammer_ideas.

*/

package main

func main() {
	assert(distance([]int{1, 7, 2, 11, 8, 34, 3}) == 9)
	assert(distance([]int{31, 63, 53, 56, 96, 62, 73, 25, 54, 55, 64}) == 26)
	assert(distance([]int{77, 39, 35, 38, 41, 42, 76, 73, 40, 31, 10}) == 20)
	assert(distance([]int{30, 63, 57, 87, 37, 31, 58, 83, 34, 76, 38}) == 15)
	assert(distance([]int{18, 62, 55, 92, 88, 57, 90, 10, 11, 96, 12}) == 3)
	assert(distance([]int{26, 8, 7, 25, 52, 17, 45, 64, 11, 35, 12}) == 6)
	assert(distance([]int{89, 57, 21, 55, 56, 81, 54, 100, 22, 62, 50}) == 13)
	assert(distance([]int{76, 74, 45, 48, 13, 75, 16, 14, 79, 58, 78, 82, 46, 89, 81, 88, 27, 64, 21, 63}) == 31)
	assert(distance([]int{37, 35, 88, 57, 55, 29, 96, 11, 25, 42, 24, 81, 82, 58, 15, 2, 3, 41, 43, 36}) == 68)
	assert(distance([]int{54, 64, 52, 39, 36, 98, 32, 87, 95, 12, 40, 79, 41, 13, 53, 35, 48, 42, 33, 75}) == 67)
	assert(distance([]int{21, 87, 89, 26, 85, 59, 54, 2, 24, 25, 41, 46, 88, 60, 63, 23, 91, 62, 61, 6}) == 52)
	assert(distance([]int{94, 66, 18, 57, 58, 54, 93, 53, 19, 16, 55, 22, 51, 8, 67, 20, 17, 56, 21, 59}) == 107)
	assert(distance([]int{6, 19, 45, 46, 7, 70, 36, 2, 56, 47, 33, 75, 94, 50, 34, 35, 73, 72, 39, 5}) == 45)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func distance(a []int) int {
	m := make(map[int][]int)
	for i, v := range a {
		m[v] = append(m[v], i)
	}

	r := 0
	for i, v := range a {
		r += sum(m[v+1], i) + sum(m[v-1], i)
	}
	return r
}

func sum(a []int, i int) int {
	r := 0
	for _, j := range a {
		if j > i {
			r += j - i
		}
	}
	return r
}
