%{

An linear discrete convolution is an operation that turns two vectors of numbers into a third vector of numbers by multiplying elements inside-out.
Formally, for two vectors a and b with elements 0 to n - 1, the discrete linear convolution of a and b can be computed with this loop:

for i = 0 to 2*n - 2
    c[i] = 0;
    for j = 0 to n - 1
        if i - j >= 0 and i - j < n
            c[i] = c[i] + a[j] * b[i - j];

As an example, the convolution of a = { 1, 2, 3, 4 } and b = { 5, 6, 7, 8 } is c = { 5, 16, 34, 60, 61, 52, 32 }. These convolutions appear when doing long multiplication, for example:

1234 * 5678 =
         20 24 28 32
      15 18 21 24
   10 12 14 16
 5  6  7  8
--------------------
 5 16 34 60 61 52 32
--------------------
      32
     52
    61
   60
  34
 16
 5
--------------------
 7006652

Your task is to write a program or function that, given two arrays (or similar) a and b of non-negative integers of equal length n and optionally, n and an output array c, computes the linear discrete convolution of a and b and returns it, assigns it to the parameter c. or prints it out.
You may also take input from the user while or before your code is running. The following constraints apply:

    Your program must run in subquadratic or o(n 2) time. An algorithm like the pseudo-code above that runs in quadratic time Θ(n 2) is invalid.
    You may assume that all integers in in- and output are in the range from 0 to 65535, this also applies to n.
    You may not claim that your algorithm runs in subquadratic time because n has an upper bound.
    The results must be exact.
    This is code golf, the shortest code in octets wins.
    You may not use existing library routines or similar to compute a Fourier transform or a number theoretic transform or the respective inverse transformations.

%}

% https://en.wikipedia.org/wiki/Convolution_theorem
function r = convolve(x, y)
	n = length(x);
	m = length(y);
	x = horzcat(x, zeros(1, m-1));
	y = horzcat(y, zeros(1, n-1));
	r = ifft(fft(x) .* fft(y));
end

format long g
convolve([1, 2, 3, 4], [5, 6, 7, 8])
convolve([32], [2])
convolve([], [])
