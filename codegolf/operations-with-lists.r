#!/usr/bin/env Rscript

comment <-
"

Inspired by this question.

Given a list containing numbers, print:

    The sum and product of the numbers in the list
    The average and median
    The differences between each term in the list (e.g. [1,2,3] -> [1,1]: 1+1=2, 2+1=3)
    The list, sorted ascending
    The minimum and maximum of the list
    The standard deviation of the list

For reference:

Standard Deviation

σ=1N∑i=1N(xi−μ)2−−−−−−−−−−−−−⎷

Where μ
is the mean average, xi is the ith term in the list, and N

is the length of the list.

Shortest code wins. Good luck!

"

printf <- function(...) invisible(print(sprintf(...)))

stats <- function(l) {
	printf("Sum:     %f", Reduce(`+`, l));
	printf("Product: %f", Reduce(`*`, l));
	printf("Min:     %f", min(l));
	printf("Max:     %f", max(l));
	printf("Mean:    %f", mean(l));
	printf("Median:  %f", median(l));
	printf("Stddev:  %f", sd(l));
	printf("Difference: %f", diff(l, differences=1));
}

stats(c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
