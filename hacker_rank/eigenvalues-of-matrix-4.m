%{

Find the eigenvalues and eigenvectors of A-1 and A - 4I where I is identity matrix and A is: [[2 -1]; [-1 2]]

Your answer should have the eigenvalues of A-1 followed by eigenvalues of A - 4I each on a new line (with the smaller value coming first, for each pair):

5
6
2
3

%}

A = [[2 -1]; [-1 2]]
eig(A)
eig(A^-1)
eig(A - 4*I)
