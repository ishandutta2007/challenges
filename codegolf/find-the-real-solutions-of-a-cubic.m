%{

Description
All cubic equations can be solved, and every cubic has at least one solution. The goal of this challenge is to find the real solutions to a given cubic using inputs, and (obviously) the smallest program size.

Rules
The solution must find the real solutions of a cubic correctly, using any method. The cubic must be in the standard form
ax3+bx2+cx+d=0

The first coefficient cannot be zero, as then it would be a quadratic. There must a different output if it is zero, and outputting nothing at all is acceptable.

Scoring
The score is based on the size of the program alone.

Inputs
The four coefficients of the cubic, a, b, c, and d.

The input may be formatted however you like.

Outputs
Every real solution to the cubic. There will either be three, or one for every cubic.

Example
With 3 solutions
Input:

1
3
0
-1
Output:

-2.879
-0.653
0.532
With 1 solution
Input:

1
1
1
1
Output:

-1
Additional Info
While you can use any method, you can find an image with the cubic equation (similar to the quadratic equation, can solve any cubic every time) equation can be found here.

You can learn more about cubics here.

%}

roots([1, 3, 0, -1])
roots([1, 1, 1, 1])
