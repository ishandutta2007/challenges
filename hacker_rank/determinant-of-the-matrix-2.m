%{

Let A be a 3 × 3 matrix with |A| = 5. Find each of the following -

    |AT|
    |2A|

Your answer should have first answer followed by the second answer separated by a line(resembling this) -

5
6

%}

A=[[5 0 0]; [0 1 0]; [0 0 1]]

% det(A) = det(A^T)
det(A)
det(transpose(A))

% a^n*det(A) = det(a*A) where n is the dimension of the nxn matrix
2**size(A, 1) * det(A)
det(2*A)
