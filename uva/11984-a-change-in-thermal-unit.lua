#!/usr/bin/env lua

--[[

Measuring temperature and temperature differences are common task in many research and applications.
Unfortunately, there exists more than one unit of measuring temperatures.
This introduces a lot of confusion at times.
Two popular units of measurements are Celsius(C) and Fahrenheit (F).
The conversion of F from C is given by the formula:
F = 9/5*C + 32
In this problem, you will be given an initial temperature in C and an increase in temperature in F.
You would have to calculate the new temperature in C.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.
Each case contains a line with two integers C and d (0 ≤ C, d ≤ 100), where C represents the initial
temperature in Celsius and d represents the increase in temperature in Fahrenheit.

Output
For each case, print the case number and the new temperature in Celsius after rounding it to two digits
after the decimal point.

Sample Input
2
100 0
0 100

Sample Output
Case 1: 100.00
Case 2: 55.56

--]]

function cel2fahr(c)
	return 9.0/5*c + 32
end

function fahr2cel(f)
	return 5.0/9*(f - 32)
end

function increase(c, f)
	return fahr2cel(cel2fahr(c) + f)
end

print(increase(100, 0))
print(increase(0, 100))
