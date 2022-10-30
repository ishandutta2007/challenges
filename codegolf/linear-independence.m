%{

Given a set of vectors all of the same positive finite dimension, output a falsey value if they are linearly dependent and a truthy value if they are linearly independent.
A set of vectors v1, v2, ... is linearly dependent if for some scalars a1, a2, ... not all equal to 0, a1v1 + a2v2 + ... = 0. (0 is the zero vector.)

Note: Using an inbuilt function to find the rank of a matrix or test vectors for linear dependence is not allowed.

Note 2: All input will be formed from integers.

Test cases (input -> output):

[[0,1],[2,3]] -> True
[[1,2],[2,4]] -> False
[[2,6,8],[3,9,12]] -> False
[[1,2],[2,3],[3,4]] -> False
[[1,0,0],[0,1,0],[0,0,1]] -> True
[[0]] -> False
[] -> True
[[1,1],[0,1],[1,0]] -> False
[[1,2,3],[1,3,5],[0,0,0]] -> False

%}

function r = linear_independence(M)
	s = size(M);
	r = false;
	
	if length(s) != 2 || s(1) != s(2)
		return;
	end
	
	if det(M) != 0
		r = true;
	end
end

assert(linear_independence([[0 1]; [2 3]]) == true);
assert(linear_independence([[1 2]; [2 4]]) == false);
assert(linear_independence([[2 6 8]; [3 9 12]]) == false);
assert(linear_independence([[1 2]; [2 3]; [3 4]]) == false);
assert(linear_independence([[1 0 0]; [0 1 0]; [0 0 1]]) == true);
assert(linear_independence([[0]]) == false);
assert(linear_independence([]) == true);
assert(linear_independence([[1 1]; [0 1]; [1 0]]) == false);
assert(linear_independence([[1 2 3]; [1 3 5]; [0 0 0]]) == false);
