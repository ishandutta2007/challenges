/*

The challenge is simply; output the following six 2D integer arrays:

[[ 1, 11, 21, 31, 41, 51],
 [ 3, 13, 23, 33, 43, 53],
 [ 5, 15, 25, 35, 45, 55],
 [ 7, 17, 27, 37, 47, 57],
 [ 9, 19, 29, 39, 49, 59]]

[[ 2, 11, 22, 31, 42, 51],
 [ 3, 14, 23, 34, 43, 54],
 [ 6, 15, 26, 35, 46, 55],
 [ 7, 18, 27, 38, 47, 58],
 [10, 19, 30, 39, 50, 59]]

[[ 4, 13, 22, 31, 44, 53],
 [ 5, 14, 23, 36, 45, 54],
 [ 6, 15, 28, 37, 46, 55],
 [ 7, 20, 29, 38, 47, 60],
 [12, 21, 30, 39, 52]]

[[ 8, 13, 26, 31, 44, 57],
 [ 9, 14, 27, 40, 45, 58],
 [10, 15, 28, 41, 46, 59],
 [11, 24, 29, 42, 47, 60],
 [12, 25, 30, 43, 56]]

[[16, 21, 26, 31, 52, 57],
 [17, 22, 27, 48, 53, 58],
 [18, 23, 28, 49, 54, 59],
 [19, 24, 29, 50, 55, 60],
 [20, 25, 30, 51, 56]]

[[32, 37, 42, 47, 52, 57],
 [33, 38, 43, 48, 53, 58],
 [34, 39, 44, 49, 54, 59],
 [35, 40, 45, 50, 55, 60],
 [36, 41, 46, 51, 56]]

What are these 2D integer arrays? These are the numbers used in a magic trick with cards containing these numbers:

https://i.stack.imgur.com/OtNyd.png

The magic trick asks someone to think of a number in the range [1, 60], and give the one performing the magic trick all the cards which contain this number.
The one performing the magic trick can then sum the top-left numbers (all a power of 2) of the given cards to get to the number the person was thinking of.
Some additional explanation of why this works can be found here.

Challenge rules:
You can output the six 2D integer arrays in any reasonable format. Can be printed with delimiters; can be a 3D integer array containing the six 2D integer arrays; can be a string-list of lines; etc.
You are allowed to fill the bottom right position of the last four cards with a negative value in the range [-60, -1] or character '*' instead of leaving it out to make the 2D integer arrays rectangular matrices
(no, you are not allowed to fill them with 0 or a non-integer like null/undefined as alternative, with the exception of * since a star is also used in the actual cards).
The order of the numbers in the matrices is mandatory. Although it doesn't matter for the physical magic trick, I see this challenge mainly as a matrix-kolmogorov-complexity one, hence the restriction on order.
The order of the matrices themselves in the output list can be in any order, since it's clear from the top-left card which matrix is which.

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.

*/

package main

import "fmt"

func main() {
	output()
}

func output() {
	A1 := [][]int{
		{1, 11, 21, 31, 41, 51},
		{3, 13, 23, 33, 43, 53},
		{5, 15, 25, 35, 45, 55},
		{7, 17, 27, 37, 47, 57},
		{9, 19, 29, 39, 49, 59},
	}

	A2 := [][]int{
		{2, 11, 22, 31, 42, 51},
		{3, 14, 23, 34, 43, 54},
		{6, 15, 26, 35, 46, 55},
		{7, 18, 27, 38, 47, 58},
		{10, 19, 30, 39, 50, 59},
	}

	A3 := [][]int{
		{4, 13, 22, 31, 44, 53},
		{5, 14, 23, 36, 45, 54},
		{6, 15, 28, 37, 46, 55},
		{7, 20, 29, 38, 47, 60},
		{12, 21, 30, 39, 52},
	}

	A4 := [][]int{
		{8, 13, 26, 31, 44, 57},
		{9, 14, 27, 40, 45, 58},
		{10, 15, 28, 41, 46, 59},
		{11, 24, 29, 42, 47, 60},
		{12, 25, 30, 43, 56},
	}

	A5 := [][]int{
		{16, 21, 26, 31, 52, 57},
		{17, 22, 27, 48, 53, 58},
		{18, 23, 28, 49, 54, 59},
		{19, 24, 29, 50, 55, 60},
		{20, 25, 30, 51, 56},
	}

	A6 := [][]int{
		{32, 37, 42, 47, 52, 57},
		{33, 38, 43, 48, 53, 58},
		{34, 39, 44, 49, 54, 59},
		{35, 40, 45, 50, 55, 60},
		{36, 41, 46, 51, 56},
	}

	fmt.Println(A1)
	fmt.Println(A2)
	fmt.Println(A3)
	fmt.Println(A4)
	fmt.Println(A5)
	fmt.Println(A6)
}
