%{

Given a matrix of integers, test if it's rank-one, meaning that every row is a multiple of the same vector. For example, in

 2   0  -20  10  
-3   0   30 -15
 0   0   0   0

every row is a multiple of 1 0 -10 5.

The same definition also works with columns in place of rows. Alternatively, a matrix is rank-one if it's like a multiplication table:

 *    1   0  -10  5
    ----------------
 2 |  2   0  -20  10  
-3 | -3   0   30 -15
 0 |  0   0   0   0

We've assigned row labels r[i]and column labels c[j] so that each matrix entry M[i][j] is the product of the corresponding labels as M[i][j] = r[i] * c[j].

Input:

An integer matrix as a 2D container of your choice. For example, a list of lists, a 2D array, or similar. You shouldn't take the width or height as additional inputs unless the array format requires it.

The matrix may be non-square. It will have at least one nonzero entry -- you don't have to deal with empty or zero matrices.

You can assume the integers won't cause overflow issues.

Output:

A consistent value for rank-one matrices, and a different consistent value for other matrices.

Built-ins:

You may not use any built-in to computes rank or directly check rank one. You may use other built-ins like eigenvalues, decompositions, etc, but I encourage upvoting answers that don't have built-ins do most of the work.

Test cases:

Rank-one:

[[2, 0, -20, 10], [-3, 0, 30, -15], [0, 0, 0, 0]]
[[0, 0, 0], [0, 3, 0], [0, 0, 0]]
[[-10]]
[[0, 0, 0], [0, 4, 11], [0, -4, -11]]

Not rank-one:

[[-2, 1], [2, 4]]
[[0, 0, 3], [-22, 0, 0]]
[[1, 2, 3], [2, 4, 6], [3, 6, 10]]
[[0, -2, 0, 0], [0, 0, 0, 1], [0, 0, -2, 0]]

%}

m1 = [[2 0 -20 10]; [-3 0 30 -15]; [0 0 0 0]]
m2 = [[0 0 0]; [0 3 0]; [0 0 0]]
m3 = [[-10]]
m4 = [[0 0 0]; [0 4 11]; [0 -4 -11]]

m5 = [[-2 1]; [2 4]]
m6 = [[0 0 3]; [-22 0 0]]
m7 = [[1 2 3]; [2 4 6]; [3 6 10]]
m8 = [[0 -2 0 0]; [0 0 0 1]; [0 0 -2 0]]

assert(rank(m1) == 1);
assert(rank(m2) == 1);
assert(rank(m3) == 1);
assert(rank(m4) == 1);

assert(rank(m5) != 1);
assert(rank(m6) != 1);
assert(rank(m7) != 1);
assert(rank(m8) != 1);
