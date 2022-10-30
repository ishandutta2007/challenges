%{

The central tendency measures (mean, mode and median) sometimes aren't enough descriptives in a data set analysis. For example, given two arrays A=[15, 15, 15, 14, 16] and B=[2, 7, 14, 22, 30] the mean is μ=15 in both cases, however the values of second array are clearly more spread out from the average value. The standard deviation (also called sigma, the greek lowercase letter σ) measures the spread of the values in a data set and transform the "clearly more spread out than" assertion in a proofed statistical assertion. You can find more information in the Resources tab.

The standard deviation is calculated following five steps:

    Obtain the mean of the data set.
    For each value in the set calculate the absolute difference between the value and the mean.
    Square each value obtained and sum them cumulatively.
    Divide the result by the data set length.
    Get the square root of the value obtained.

Given an array of values return the standard deviation rounded to the nearest hundredth.
Examples

standardDeviation([3, 5, 7]) ➞ 1.63
// |(3-5)|+|(5-5)|+|(7-5)| = 2² + 0 + 2² = 8 / 3 = square root of 2.66 = 1.63

standardDevition([5, 5, 5]) ➞ 0
// Values aren't deviating from the mean.

standardDeviation([-3, -5, -7]) ➞ 1.63
// Remember: absolute differences!

Notes

    All given arrays are valid, no exceptions to handle.
    Arrays can contain either positive or negative integers.
    Remember to round to the nearest hundredth at the end.

%}

function standard_deviation()
	test([3, 5, 7], 1.63);
	test([5, 5, 5], 0);
	test([-3, -5, -7], 1.63);
	test([15, 15, 15, 14, 16], 0.63);
	test([1, 2, 3, 4, 5], 1.41);
	test([-24, 3, -15, 131, 8, 42, 11, -70, 12, 0, 33, 48, 20, 20, 20], 41.43);
	test([-10, -1, -100], 44.70);
	test([18, 18, 18], 0);
	test([2, 7, 14, 22, 30], 10.00);
end

function test(v, r)
	assert(abs(std(v, 1)-r) < 1e-1);
end

standard_deviation();
