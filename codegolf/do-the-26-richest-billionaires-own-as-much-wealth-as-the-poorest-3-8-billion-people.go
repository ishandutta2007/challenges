/*

Introduction:
A few days ago I read this post with the same title when I came across it in the HNQ. In this question it is being discussed if the claim of president-candidate Bernie Sanders, who claimed the following:

Today the world's richest 26 billionaires, 26, now own as much wealth as the poorest 3.8 billion people on the planet, half of the world's population.
Link to video

is true or not. Please go to the question itself for answers and discussions there.

As for the actual challenge based on this claim:

Challenge:
Two inputs: a descending sorted number-list L and a number n (where n is 1≤n<length of L).
Output: the longest possible suffix sub-list of L for which the total sum is ≤ the sum of the first n values in list L.

Example:

Inputs: L = [500,200,150,150,125,100,75,75,55,50,40,30,30,20,10,10,8,5,5,5,3,2,2,1,0,-2,-3] and n=2.
Output: [125,100,75,75,55,50,40,30,30,20,10,10,8,5,5,5,3,2,2,1,0,-2,-3]

Why?

The first n=2 values of the list L ([500,200]) sum to 700. If we take all suffixes of the remaining numbers, as well as their sums:

Suffix:                                                                  Sum:

[-3]                                                                     -3
[-2,-3]                                                                  -5
[0,-2,-3]                                                                -5
[1,0,-2,-3]                                                              -4
[2,1,0,-2,-3]                                                            -2
[2,2,1,0,-2,-3]                                                          0
[3,2,2,1,0,-2,-3]                                                        3
[5,3,2,2,1,0,-2,-3]                                                      8
[5,5,3,2,2,1,0,-2,-3]                                                    13
[5,5,5,3,2,2,1,0,-2,-3]                                                  18
[5,5,5,5,3,2,2,1,0,-2,-3]                                                23
[10,5,5,5,5,3,2,2,1,0,-2,-3]                                             33
[10,10,5,5,5,5,3,2,2,1,0,-2,-3]                                          43
[20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]                                       63
[30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]                                    93
[30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]                                 123
[40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]                              163
[50,40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]                           213
[55,50,40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]                        268
[75,55,50,40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]                     343
[75,75,55,50,40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]                  418
[100,75,75,55,50,40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]              518
[125,100,75,75,55,50,40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]          643
[150,125,100,75,75,55,50,40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]      793
[150,150,125,100,75,75,55,50,40,30,30,20,10,10,5,5,5,5,3,2,2,1,0,-2,-3]  943
The longest suffix which has a sum lower than or equal to 700 is [125,100,75,75,55,50,40,30,30,20,10,10,8,5,5,5,3,2,2,1,0,-2,-3] with a sum of 643, so that is our result.

Challenge rules:
Values in the first n prefix aren't counted towards the output-suffix. I.e. inputs L = [10,5,5,3] and n=2 would result in [5,3], and not [5,5,3].
I/O is flexible. You can input L as a list/stream/array of integers/decimals/strings, a single delimited string, one by one through STDIN, etc.
You can output as a list/stream/array of integers/decimals/strings as well, print/return a delimited string, print a number on each newline, etc. Your call.
The output is guarantees to be non-empty. So you won't have to deal with test cases like L = [-5,-10,-13] and n=2 resulting in [].
Both (or either) the input and/or output may also be in ascending order instead of descending order if you choose to.

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.

Test cases:

Inputs: L=[500,200,150,150,125,100,75,75,55,50,40,30,30,20,10,10,8,5,5,5,3,2,2,1,0,-2,-3], n=2
Output: [125,100,75,75,55,50,40,30,30,20,10,10,8,5,5,5,3,2,2,1,0,-2,-3]

Inputs: L=[10,5,5,3], n=2
Output: [5,3]

Inputs: L=[7,2,1,-2,-4,-5,-10,-12], n=7
Output: [-12]

Inputs: L=[30,20,10,0,-10,-20,-30], n=1
Output: [20,10,0,-10,-20,-30]

Inputs: L=[100,35,25,15,5,5,5,5,5,5,5,5,5,5,5,5,5], n=1
Output: [15,5,5,5,5,5,5,5,5,5,5,5,5,5]

Inputs: L=[0,-5,-10,-15], n=2
Output: [-10,-15]

Inputs: L=[1000,999,998,900,800,766,525,525,400,340,120,110,80,77,33,12,0,-15,-45,-250], n=2
Output: [525,525,400,340,120,110,80,77,33,12,0,-15,-45,-250]

Inputs: L=[10,5,5], n=1
Output: [5,5]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{500, 200, 150, 150, 125, 100, 75, 75, 55, 50, 40, 30, 30, 20, 10, 10, 8, 5, 5, 5, 3, 2, 2, 1, 0, -2, -3}, 2, []int{125, 100, 75, 75, 55, 50, 40, 30, 30, 20, 10, 10, 8, 5, 5, 5, 3, 2, 2, 1, 0, -2, -3})
	test([]int{10, 5, 5, 3}, 2, []int{5, 3})
	test([]int{7, 2, 1, -2, -4, -5, -10, -12}, 7, []int{-12})
	test([]int{30, 20, 10, 0, -10, -20, -30}, 1, []int{20, 10, 0, -10, -20, -30})
	test([]int{100, 35, 25, 15, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, 1, []int{15, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5})
	test([]int{0, -5, -10, -15}, 2, []int{-10, -15})
	test([]int{1000, 999, 998, 900, 800, 766, 525, 525, 400, 340, 120, 110, 80, 77, 33, 12, 0, -15, -45, -250}, 2, []int{525, 525, 400, 340, 120, 110, 80, 77, 33, 12, 0, -15, -45, -250})
	test([]int{10, 5, 5}, 1, []int{5, 5})
	test([]int{}, 0, []int{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, l int, r []int) {
	p := wealth(a, l)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func wealth(a []int, l int) []int {
	x, y, n := 0, 0, len(a)
	for i := 0; i < l; i++ {
		x += a[i]
	}

	i := n - 1
	for ; i >= 0 && i >= l; i-- {
		if y+a[i] > x {
			break
		}
		y += a[i]
	}
	return a[i+1:]
}
