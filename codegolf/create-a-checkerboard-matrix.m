%{

Take a positive integer n as input, and output a n-by-n checkerboard matrix consisting of 1 and 0.

The top left digit should always be 1.

Test cases:

n = 1
1

n = 2
1 0
0 1

n = 3
1 0 1
0 1 0
1 0 1

n = 4
1 0 1 0
0 1 0 1
1 0 1 0
0 1 0 1

Input and output formats are optional. Outputting the matrix as a list of lists is accepted.

%}

function m = checkerboard(n)
	m = zeros(n);
	m(1:2:n, 1:2:n) = 1;
	m(2:2:n, 2:2:n) = 1;
end


for i = 1:1:10
	checkerboard(i)
end
