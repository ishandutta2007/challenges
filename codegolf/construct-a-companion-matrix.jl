#!/usr/bin/env julia

#=

You have a number of polynomials who are lonely, so make them some companions (who won’t threaten to stab)!

For a polynomial of degree n, there is an n by n companion cube matrix for it. You need to make a function that accepts a list of coefficients for a polynomial in either ascending (a + bx +cx^2 + …) or descending (ax^n + bx^(n-1) + cx^(n-2)+…) order (but not both) and output the companion matrix.

for a polynomial c0 + c1x + c2x^2 + ... + cn-1x^(n-1) + x^n, its companion matrix is

     (0, 0, 0, ..., -c0  ),
     (1, 0, 0, ..., -c1  ),
     (0, 1, 0, ..., -c2  ),
     (...................),
     (0, 0, ..., 1, -cn-1)
note that the coefficient for x^n is 1. For any other value, divide all the rest of the coefficients by x^n's. Additionally, the 1's are offset from the diagonal.

If the language you’re using already contains a function or module that does this, you can’t use it – you must write your own.

For instance, if you had 4x^2 – 7x + 12, the coefficients in ascending order are (12, -7, 4) and descending order (4, -7, 12). The function or program should output [(0, -3.0), (1, 1.75)] for either order. Specify which order your code accepts. Minimum polynomial should be a quadratic. Coefficients are restricted to real numbers.

Below are examples – your output does not have to match the pretty formatting but it should output the rows (in the ()) of the matrix in order.

Ascending order:

input:
    [3., 7., -5., 4., 1.]
output:
    [(0, 0, 0, -3.),
     (1, 0, 0, -7.),
     (0, 1, 0,  5.),
     (0, 0, 1, -4.)]

input:
    [-4., -7., 13.]
output:
    [(0, 0.30769231),
     (1, 0.53846154)]

input:
    [23., 1., 92., 8., -45., 88., 88.]
output:
    [(0, 0, 0, 0, 0, -0.26136364),
     (1, 0, 0, 0, 0, -0.01136364),
     (0, 1, 0, 0, 0, -1.04545455),
     (0, 0, 1, 0, 0, -0.09090909),
     (0, 0, 0, 1, 0,  0.51136364),
     (0, 0, 0, 0, 1, -1.        )]
Descending order:

input:
    [1., 4., -5., 7., 3.]
output:
    [(0, 0, 0, -3.),
     (1, 0, 0, -7.),
     (0, 1, 0,  5.),
     (0, 0, 1, -4.)]

input:
    [13., -7., -4.]
output:
    [(0, 0.30769231),
     (1, 0.53846154)]

input:
    [88., 88., -45., 8., 92.,1., 23.]
output:
    [(0, 0, 0, 0, 0, -0.26136364),
     (1, 0, 0, 0, 0, -0.01136364),
     (0, 1, 0, 0, 0, -1.04545455),
     (0, 0, 1, 0, 0, -0.09090909),
     (0, 0, 0, 1, 0,  0.51136364),
     (0, 0, 0, 0, 1, -1.        )]

=#

using LinearAlgebra

function companion(c::Array)
    n = length(c)
    k = c[n]
    [I(n-=1)[:,2:n] -c[1:n]/k]
end

println(companion([3, 7, -5, 4, 1]))
println(companion([-4, -7, 13]))
println(companion([23., 1., 92., 8., -45., 88., 88.]))
