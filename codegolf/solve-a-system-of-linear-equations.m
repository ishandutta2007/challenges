%{

Write a program to solve a series of linear equations as short as possible. It must solve arbitrary number of equations problems.
They can inputted however you like, coefficients of augmented matrix is probably the easiest.
The program doesn't have to handle non-integer coefficients or solutions. No degenerate or invalid cases will be tested. The program must output the value of each variable or reduced row echelon form.

No equation solving libraries, matrix functions, or any way to automatically solve is allowed. You can simulate matrices with arrays or lists.

Example input (or equivalent):

m={{2,1,-1,8},{-3,-1,2,-11},{-2,1,2,-3}}

This represents 2x+y-z=8, -3x-y+2z=-11, -2x+y+2z=-3

Example output (or equivalent):

{2,3,-1}

This represents x=2, y=3, z=-1

%}

A = [[2, 1, -1]; [-3, -1, 2]; [-2, 1, 2]]
b = [8, -11, -3]
x = A^-1*b'
