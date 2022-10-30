%{

The cross product of two three-dimensional vectors a⃗  and b⃗  is the unique vector c⃗ 

such that:

c⃗ is orthogonal to both a⃗  and b⃗ 

The magnitude of c⃗ is equal to the area of the parallelogram formed by a⃗  and b⃗ 

The directions of a⃗, b⃗ , and c⃗, in that order, follow the right-hand rule.

There are a few equivalent formulas for cross product, but one is as follows:

a⃗ ×b⃗ =det⎡⎣⎢i⃗ a1b1j⃗ a2b2k⃗ a3b3⎤⎦⎥

where i⃗, j⃗ , and k⃗ are the unit vectors in the first, second, and third dimensions.
Challenge

Given two 3D vectors, write a full program or function to find their cross product. Builtins that specifically calculate the cross product are disallowed.

Input

Two arrays of three real numbers each. If your language doesn't have arrays, the numbers still must be grouped into threes. Both vectors will have magnitude <216.
Note that the cross product is noncommutative (a⃗ ×b⃗ =−(b⃗ ×a⃗ )), so you should have a way to specify order.
Output

Their cross product, in a reasonable format, with each component accurate to four significant figures or 10−4, whichever is looser. Scientific notation is optional.
Test cases

[3, 1, 4], [1, 5, 9]
[-11, -23, 14]

[5, 0, -3], [-3, -2, -8]
[-6, 49, -10]

[0.95972, 0.25833, 0.22140],[0.93507, -0.80917, -0.99177]
[-0.077054, 1.158846, -1.018133]

[1024.28, -2316.39, 2567.14], [-2290.77, 1941.87, 712.09]
[-6.6345e+06, -6.6101e+06, -3.3173e+06]

This is code-golf, so the shortest solution in bytes wins.

%}

cross([3, 1, 4], [1, 5, 9])
cross([5, 0, -3], [-3, -2, -8])
cross([0.95972, 0.25833, 0.22140], [0.93507, -0.80917, -0.99177])
cross([1024.28, -2316.39, 2567.14], [-2290.77, 1941.87, 712.09])

