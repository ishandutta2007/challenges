/*

Background
Slowsort is an in-place, stable sorting algorithm that has worse-than-polynomial time complexity. The pseudocode for Slowsort looks like this:

procedure slowsort(A[], i, j)          // Sort array range A[i ... j] in-place.
    if i ≥ j then
        return
    m := floor( (i+j)/2 )
    slowsort(A, i, m)                  // (1.1)
    slowsort(A, m+1, j)                // (1.2)
    if A[j] < A[m] then
        swap A[j] , A[m]               // (1.3)
    slowsort(A, i, j-1)                // (2)

(1.1) Sort the first half, recursively.
(1.2) Sort the second half, recursively.
(1.3) Find the maximum of the whole array by comparing the results of 1.1 and 1.2, and place it at the end of the list.
(2) Sort the entire list (except for the maximum now at the end), recursively.
The recurrence relation of the worst-case time complexity (the number of swaps when the condition for (1.3) is always true1) is:

T(1) = 0
T(n) = T(⌊n/2⌋)+T(⌈n/2⌉)+1+T(n−1)

The first 50 terms of the sequence are:

0, 1, 3, 6, 11, 18, 28, 41, 59, 82,
112, 149, 196, 253, 323, 406, 507, 626, 768, 933,
1128, 1353, 1615, 1914, 2260, 2653, 3103, 3610, 4187, 4834,
5564, 6377, 7291, 8306, 9440, 10693, 12088, 13625, 15327, 17194,
19256, 21513, 23995, 26702, 29671, 32902, 36432, 40261, 44436, 48957
This sequence seems to coincide with A178855.

A proof by @loopy wait (which gives rise to multiple alternative formulas):

Proof: start with A033485 (a(n) = a(n-1) + a(floor(n/2)), a(1) = 1) and verify that a(2n+1)-a(2n-1)=2a(n) (because a(2n+1) = a(2n) + a(n) = a(2n-1) + 2a(n)).
Also verify that if n is even 2a(n)=a(n-1)+a(n+1). If we substitute b(n)=a(2n-1) we get b(n)-b(n-1)=b(floor(n/2))+b(ceil(n/2)) which is already similar to T.
If we now set 2T+1=b we get back the recurrence defining T. As the initial terms also match this shows that T(n)=((A033485(2n-1)-1)/2 which (shifted by one) is also given as a formula for A178855.

Challenge
Evaluate the sequence T(n). sequence default I/O applies; you can choose one of the following:

Without input, output the entire sequence T(1),T(2),T(3),⋯ infinitely
Given n>0, output T(n) (corresponding to nth value under 1-indexing)
Given n≥0, output T(n+1) (corresponding to nth value under 0-indexing)
Given n>0, output the first n terms, i.e. T(1),T(2),⋯,T(n)
Standard code-golf rules apply. The shortest code in bytes wins.

1 Don't ask me how, I don't know if it can actually happen.

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 50; i++ {
		fmt.Println(T(i))
	}
}

func T(n int) int {
	if n <= 1 {
		return 0
	}
	return T(n/2) + T(n/2+(n&1)) + 1 + T(n-1)
}
