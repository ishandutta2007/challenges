/*

Chef is learning linear algebra. Recently, he learnt that for a square matrix M, trace(M) is defined as the sum of all elements on the main diagonal of M (an element lies on the main diagonal if its row index and column index are equal).

Now, Chef wants to solve some excercises related to this new quantity, so he wrote down a square matrix A with size N×N.
A square submatrix of A with size l×l is a contiguous block of l×l elements of A.
Formally, if B is a submatrix of A with size l×l, then there must be integers r and c (1≤r,c≤N+1−l) such that Bi,j=Ar+i−1,c+j−1 for each 1≤i,j≤l.

Help Chef find the maximum trace of a square submatrix of A.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains N space-separated integers Ai,1,Ai,2,…,Ai,N denoting the i-th row of the matrix A.

Output

For each test case, print a single line containing one integer — the maximum possible trace.

Constraints
1≤T≤100
2≤N≤100
1≤Ai,j≤100 for each valid  i,j

*/

package main

func main() {
	assert(maxtrace([][]int{
		{1, 2, 5},
		{6, 3, 4},
		{2, 7, 1},
	}) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxtrace(m [][]int) int {
	n := len(m)
	r := 0
	for i := 0; i < n; i++ {
		x, y := 0, 0
		for j, k := i, 0; j < n && k < n; j, k = j+1, k+1 {
			x += m[j][k]
			y += m[k][j]
		}
		r = max(r, max(x, y))
	}
	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
