#!/usr/bin/env Rscript

"

To normalize a vector is to scale it to a length of 1 (a unit vector), whilst keeping the direction consistent.

For example, if we wanted to normalize a vector with 3 components, u, we would first find its length:

    |u| = sqrt(ux2 + uy2 + uz2)

...and then scale each component by this value to get a length 1 vector.

    û = u ÷ |u|

The Challenge

Your task is to write a program or function which, given a non-empty list of signed integers, interprets it as a vector, and normalizes it. This should work for any number of dimensions, for example (test cases rounded to two decimal places):

[20]           -> [1]
[-5]           -> [-1]
[-3, 0]        -> [-1, 0]
[5.5, 6, -3.5] -> [0.62, 0.68, -0.40]
[3, 4, -5, -6] -> [0.32, 0.43, -0.54, -0.65]
[0, 0, 5, 0]   -> [0, 0, 1, 0]

Rules:

    You can assume the input list will:
        Have at least one non-zero element
        Only contain numbers within your language's standard floating point range
    Your output should be accurate to at least two decimal places. Returning 'infinite precision' fractions / symbolic values is also allowed, if this is how your language internally stores the data.
    Submissions should be either a full program which performs I/O, or a function. Function submissions can either return a new list, or modify the given list in place.
    Builtin vector functions/classes are allowed. Additionally, if your language has a vector type which supports an arbitrary number of dimensions, you can take one of these as input.

This is a code-golf contest, so you should aim to achieve the shortest solution possible (in bytes).

"

normalize <- function(x) {
	x / sqrt(sum(x^2));
}

normalize(c(20));
normalize(c(-5));
normalize(c(-3, 0));
normalize(c(5.5, 6, -3.5));
normalize(c(3, 4, -5, -6));
normalize(c(0, 0, 5, 0));
