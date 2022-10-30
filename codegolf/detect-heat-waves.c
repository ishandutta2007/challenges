/*

Background

The Royal Netherlands Meteorological Institute defines a heat wave* as a series of at least 5 consecutive days of ≥25°C weather (“summery weather”), such that at least 3 of those days are ≥30°C (“tropical weather”).

The tropical weather doesn't have to be measured consecutively: for example: 30, 25, 30, 26, 27, 28, 32, 30 is a 8-day long heat wave with 4 days of tropical weather.

*(Well, by Dutch standards.)

Challenge

Given a non-empty list of positive integers representing Celsius temperature measurements from successive days, decide whether that list contains a heat wave (as per the above definition).

The shortest answer in bytes wins.

Test cases

Falsey:

[30]
[29, 29, 29, 47, 30]
[31, 29, 29, 28, 24, 23, 29, 29, 26, 27, 33, 20, 26, 26, 20, 30]
[23, 31, 29, 26, 30, 24, 29, 29, 25, 27, 24, 28, 22, 20, 34, 22, 32, 24, 33]
[23, 24, 25, 20, 24, 34, 28, 32, 22, 20, 24]
[24, 28, 21, 34, 34, 25, 24, 33, 23, 20, 32, 26, 29, 29, 25, 20, 30, 24, 23, 21, 27]
[26, 34, 21, 32, 32, 30, 32, 21, 34, 21, 34, 31, 23, 27, 26, 32]
[29, 24, 22, 27, 22, 25, 29, 26, 24, 24, 20, 25, 20, 20, 24, 20]
[23, 33, 22, 32, 30]
[28, 21, 22, 33, 22, 26, 30, 28, 26, 23, 31, 22, 31, 25, 27, 27, 25, 28]
[27, 23, 42, 23, 22, 28]
[25, 20, 30, 29, 32, 25, 22, 21, 31, 22, 23, 25, 22, 31, 23, 25, 33, 23]
Truthy:

[30, 29, 30, 29, 41]
[1, 1, 25, 30, 25, 30, 25, 25, 25, 25, 25, 25, 25, 25, 40, 1, 1]
[31, 34, 34, 20, 34, 28, 28, 23, 27, 31, 33, 34, 29, 24, 33, 32, 21, 34, 30, 21, 29, 22, 31, 23, 26, 32, 29, 32, 24, 27]
[26, 29, 22, 22, 31, 31, 27, 28, 32, 23, 33, 25, 31, 33, 34, 30, 23, 26, 21, 28, 32, 22, 30, 34, 26, 33, 20, 27, 33]
[20, 31, 20, 29, 29, 33, 34, 33, 20]
[25, 26, 34, 34, 41, 28, 32, 30, 34, 23, 26, 33, 30, 22, 30, 33, 24, 20, 27, 23, 30, 23, 34, 20, 23, 20, 33, 20, 28]
[34, 23, 31, 34, 34, 30, 29, 31, 29, 21, 25, 31, 30, 29, 29, 28, 21, 29, 33, 25, 24, 30]
[22, 31, 23, 23, 26, 21, 22, 20, 20, 28, 24, 28, 25, 31, 31, 26, 33, 31, 27, 29, 30, 30]
[26, 29, 25, 30, 32, 28, 26, 26, 33, 20, 21, 32, 28, 28, 20, 34, 34]
[34, 33, 29, 26, 34, 32, 27, 26, 22]
[30, 31, 23, 21, 30, 27, 32, 30, 34, 29, 21, 31, 31, 31, 32, 27, 30, 26, 21, 34, 29, 33, 24, 24, 32, 27, 32]
[25, 33, 33, 25, 24, 27, 34, 31, 29, 31, 27, 23]

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
heatwave(int *a, size_t n)
{
	size_t s, t;
	size_t i;

	s = t = 0;
	for (i = 0; i < n; i++) {
		if (a[i] < 25)
			s = t = 0;

		s += (a[i] >= 25);
		t += (a[i] >= 30);
		if (s >= 5 && t >= 3)
			return true;
	}
	return false;
}

int
main(void)
{
	int a1[] = {30};
	int a2[] = {29, 29, 29, 47, 30};
	int a3[] = {31, 29, 29, 28, 24, 23, 29, 29, 26, 27, 33, 20, 26, 26, 20, 30};
	int a4[] = {23, 31, 29, 26, 30, 24, 29, 29, 25, 27, 24, 28, 22, 20, 34, 22, 32, 24, 33};
	int a5[] = {23, 24, 25, 20, 24, 34, 28, 32, 22, 20, 24};
	int a6[] = {24, 28, 21, 34, 34, 25, 24, 33, 23, 20, 32, 26, 29, 29, 25, 20, 30, 24, 23, 21, 27};
	int a7[] = {26, 34, 21, 32, 32, 30, 32, 21, 34, 21, 34, 31, 23, 27, 26, 32};
	int a8[] = {29, 24, 22, 27, 22, 25, 29, 26, 24, 24, 20, 25, 20, 20, 24, 20};
	int a9[] = {23, 33, 22, 32, 30};
	int a10[] = {28, 21, 22, 33, 22, 26, 30, 28, 26, 23, 31, 22, 31, 25, 27, 27, 25, 28};
	int a11[] = {27, 23, 42, 23, 22, 28};
	int a12[] = {25, 20, 30, 29, 32, 25, 22, 21, 31, 22, 23, 25, 22, 31, 23, 25, 33, 23};

	int a13[] = {30, 29, 30, 29, 41};
	int a14[] = {1, 1, 25, 30, 25, 30, 25, 25, 25, 25, 25, 25, 25, 25, 40, 1, 1};
	int a15[] = {31, 34, 34, 20, 34, 28, 28, 23, 27, 31, 33, 34, 29, 24, 33, 32, 21, 34, 30, 21, 29, 22, 31, 23, 26, 32, 29, 32, 24, 27};
	int a16[] = {26, 29, 22, 22, 31, 31, 27, 28, 32, 23, 33, 25, 31, 33, 34, 30, 23, 26, 21, 28, 32, 22, 30, 34, 26, 33, 20, 27, 33};
	int a17[] = {20, 31, 20, 29, 29, 33, 34, 33, 20};
	int a18[] = {25, 26, 34, 34, 41, 28, 32, 30, 34, 23, 26, 33, 30, 22, 30, 33, 24, 20, 27, 23, 30, 23, 34, 20, 23, 20, 33, 20, 28};
	int a19[] = {34, 23, 31, 34, 34, 30, 29, 31, 29, 21, 25, 31, 30, 29, 29, 28, 21, 29, 33, 25, 24, 30};
	int a20[] = {22, 31, 23, 23, 26, 21, 22, 20, 20, 28, 24, 28, 25, 31, 31, 26, 33, 31, 27, 29, 30, 30};
	int a21[] = {26, 29, 25, 30, 32, 28, 26, 26, 33, 20, 21, 32, 28, 28, 20, 34, 34};
	int a22[] = {34, 33, 29, 26, 34, 32, 27, 26, 22};
	int a23[] = {30, 31, 23, 21, 30, 27, 32, 30, 34, 29, 21, 31, 31, 31, 32, 27, 30, 26, 21, 34, 29, 33, 24, 24, 32, 27, 32};
	int a24[] = {25, 33, 33, 25, 24, 27, 34, 31, 29, 31, 27, 23};

	assert(heatwave(a1, nelem(a1)) == false);
	assert(heatwave(a2, nelem(a2)) == false);
	assert(heatwave(a3, nelem(a3)) == false);
	assert(heatwave(a4, nelem(a4)) == false);
	assert(heatwave(a5, nelem(a5)) == false);
	assert(heatwave(a6, nelem(a6)) == false);
	assert(heatwave(a7, nelem(a7)) == false);
	assert(heatwave(a8, nelem(a8)) == false);
	assert(heatwave(a9, nelem(a9)) == false);
	assert(heatwave(a10, nelem(a10)) == false);
	assert(heatwave(a11, nelem(a11)) == false);
	assert(heatwave(a12, nelem(a12)) == false);

	assert(heatwave(a13, nelem(a13)) == true);
	assert(heatwave(a14, nelem(a14)) == true);
	assert(heatwave(a15, nelem(a15)) == true);
	assert(heatwave(a16, nelem(a16)) == true);
	assert(heatwave(a17, nelem(a17)) == true);
	assert(heatwave(a18, nelem(a18)) == true);
	assert(heatwave(a19, nelem(a19)) == true);
	assert(heatwave(a20, nelem(a20)) == true);
	assert(heatwave(a21, nelem(a21)) == true);
	assert(heatwave(a22, nelem(a22)) == true);
	assert(heatwave(a23, nelem(a23)) == true);
	assert(heatwave(a24, nelem(a24)) == true);

	return 0;
}
