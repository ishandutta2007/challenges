%{

Introduction

The two most common trigonometric functions, sine and cosine (or sin and cos for short), can be extended to be matrix-valued functions. One way to compute the matrix-valued analogs is as follows:

Consider these two important trigonometric identities:

trig identities

Using these identities, we can derive the following equations for sin and cos:

trig functions

The matrix exponential exists for all square matrices and is given by:

matrix exponential

where A0 is the identity matrix I with the same dimensions as A. Using the matrix exponential, these two trigonometric functions (and thus all the other trigonometric functions) can be evaluated as functions of matrices.
The Challenge

Given a square matrix A, output the values of sin(A) and cos(A).

Rules

    Input and output may be in any convenient, reasonable format (2D array, your language's matrix format, etc.).
    You may write a single program, two independent programs, a single function, or two functions. If you choose to write two functions, code may be shared between them (such as imports and helper functions).
    The input matrix's values will always be integers.
    Your solution may have accuracy issues as the result of floating-point imprecision. If your language had magical infinite-precision values, then your solution should work perfectly (ignoring the fact that it would require infinite time and/or memory). However, since those magical infinite-precision values don't exist, inaccuracies caused by limited precision are acceptable. This rule is in place to avoid complications resulting from requiring a specific amount of precision in the output.
    Builtins which compute trigonometric functions for matrix arguments (including hyperbolic trig functions) are not allowed. Other matrix builtins (such as multiplication, exponentiation, diagonalization, decomposition, and the matrix exponential) are allowed.

Test Cases

Format: A -> sin(A), cos(A)

[[0]] -> [[0]], [[1]]
[[0, 2], [3, 5]] -> [[-0.761177343863758, 0.160587281888277], [0.240880922832416, -0.359709139143065]], [[0.600283445979886, 0.119962280223493], [0.179943420335240, 0.900189146538619]]
[[1, 0, 1], [0, 0, 0], [0, 1, 0]] -> [[0.841470984807897, -0.158529015192103, 0.841470984807897], [0, 0, 0], [0, 1, 0]], [[0.540302305868140, -0.459697694131860, -0.459697694131860], [0, 1, 0], [0, 0, 1]]
[[1, 0, 0, 0, 0], [0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 1, 0], [0, 0, 0, 0, 1]] -> [[0.841470984807897, 0, 0, 0, 0], [0, 0.841470984807897, 0, 0, 0], [0, 0, 0.841470984807897, 0, 0], [0, 0, 0, 0.841470984807897, 0], [0, 0, 0, 0, 0.841470984807897]], [[0.540302305868140, 0, 0, 0, 0], [0, 0.540302305868140, 0, 0, 0], [0, 0, 0.540302305868140, 0, 0], [0, 0, 0, 0.540302305868140, 0], [0, 0, 0, 0, 0.540302305868140]]
[[-3, 2, -6], [3, 0, 4], [4, -2, 7]] -> [[-0.374786510963954, 0.135652884035570, -1.35191037980742], [1.14843105375406, 0.773644542790111, 1.21625749577185], [1.21625749577185, -0.135652884035570, 2.19338136461532]], [[4.13614256031450, -1.91289828483056, 5.50873853927692], [-2.63939111203107, 1.49675144828342, -3.59584025444636], [-3.59584025444636, 1.91289828483056, -4.96843623340878]]

Further Reading

This excellent question over at Math.SE includes some alternate derivations of the matrix-valued analogs of trigonometric functions.

%}

function m = sinm(A)
	m = (expm(A*i) - expm(-A*i)) / (2*i);
end

function m = cosm(A)
	m = (expm(A*i) + expm(-A*i)) / 2;
end

A1 = [[0]]
[sinm(A1) cosm(A1)]

A2 = [[0, 2]; [3, 5]]
[sinm(A2) cosm(A2)]

A3 = [[1, 0, 1]; [0, 0, 0]; [0, 1, 0]]
[sinm(A3) cosm(A3)]

A4 = [[1, 0, 0, 0, 0]; [0, 1, 0, 0, 0]; [0, 0, 1, 0, 0]; [0, 0, 0, 1, 0]; [0, 0, 0, 0, 1]]
[sinm(A4) cosm(A4)]

A5 = [[-3, 2, -6]; [3, 0, 4]; [4, -2, 7]] 
[sinm(A5) cosm(A5)]
