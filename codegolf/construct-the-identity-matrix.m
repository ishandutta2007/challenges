%{

The challenge is very simple. Given an integer input n, output the n x n identity matrix. The identity matrix is one that has 1s spanning from the top left down to the bottom right.
You will write a program or a function that will return or output the identity matrix you constructed. Your output may be a 2D array, or numbers separated by spaces/tabs and newlines.

Example input and output

1: [[1]]
2: [[1, 0], [0, 1]]
3: [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
4: [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
5: [[1, 0, 0, 0, 0], [0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 1, 0], [0, 0, 0, 0, 1]]

1
===
1

2
===
1 0
0 1

3
===
1 0 0
0 1 0
0 0 1

etc.

This is code-golf, so the shortest code in bytes wins.

%}

for i = 1:5
	disp(eye(i));
end
