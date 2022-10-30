/*

A man named Thomas Malthus described what is now called a Malthusian Catastrophe. According to him, food production grows by a fixed amount, but population grows by a percentage. So, the food supply would soon be insufficient for the population.

Your job is to find out when that will occur. For this challenge, assume 1 population needs 1 unit of food production. Food production & population both start at 100. The year starts at 0.

The catastrophe happens when the population is larger than food production.

The function will pass: foodGrowth - an integer - Food production increase per year; and popMult - a floating-point number - The population growth multiplier per year.
Examples

malthusian(4255, 1.41) ➞ 20;
// { foodProd: 85,200, pop: 96,467.77..., year: 20 }

malthusian(9433, 1.09) ➞ 107;
// { foodProd: 1,009,431, pop: 1,010,730.28..., year: 107 }

malthusian(5879, 1.77) ➞ 12;
// { foodProd: 70,648, pop: 94,553.84..., year: 12 }

Notes

Return the year that the overtake happens, not the next year.

Make sure you don't make the mistake of adding a year, then calculating the changes to food & population. That way, you miss year 0.

If the population & food production are equal, that is not a catastrophe.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

unsigned
malthusian(unsigned f, double p)
{
	double x1, x2, pf, py;
	unsigned y;

	pf = f;
	py = p;
	for (y = 1; y < UINT_MAX; y++) {
		x1 = 100 + pf;
		x2 = 100 * py;
		if (x1 < x2)
			break;

		pf += f;
		py *= p;
	}
	return y;
}

int
main(void)
{
	assert(malthusian(3900, 1.26) == 31);
	assert(malthusian(3367, 1.16) == 51);
	assert(malthusian(2393, 1.86) == 9);
	assert(malthusian(6560, 1.66) == 14);
	assert(malthusian(8481, 1.35) == 26);
	assert(malthusian(3805, 1.98) == 9);
	assert(malthusian(9492, 1.06) == 166);
	assert(malthusian(8278, 1.35) == 26);
	assert(malthusian(1228, 1.91) == 7);
	assert(malthusian(4791, 1.25) == 34);
	assert(malthusian(8194, 1.12) == 78);
	assert(malthusian(7418, 1.63) == 15);
	assert(malthusian(8700, 1.18) == 51);
	assert(malthusian(1066, 1.78) == 8);
	assert(malthusian(811, 1.46) == 13);
	assert(malthusian(7836, 1.33) == 27);
	assert(malthusian(4082, 1.54) == 15);
	assert(malthusian(4859, 1.87) == 10);
	assert(malthusian(4656, 1.44) == 19);
	assert(malthusian(2214, 1.53) == 14);
	assert(malthusian(1240, 1.10) == 72);
	assert(malthusian(4434, 1.21) == 40);
	assert(malthusian(2995, 1.51) == 15);
	assert(malthusian(578, 1.10) == 62);
	assert(malthusian(9768, 1.47) == 20);
	assert(malthusian(1508, 1.10) == 74);
	assert(malthusian(6311, 1.54) == 17);
	assert(malthusian(5502, 1.70) == 13);
	assert(malthusian(3170, 1.68) == 12);
	assert(malthusian(7139, 1.10) == 93);
	assert(malthusian(7385, 1.56) == 16);
	assert(malthusian(5845, 1.66) == 14);
	assert(malthusian(9937, 1.74) == 13);
	assert(malthusian(6516, 1.13) == 69);
	assert(malthusian(1973, 1.85) == 9);
	assert(malthusian(8045, 1.65) == 15);
	assert(malthusian(9784, 1.12) == 79);
	assert(malthusian(4520, 1.11) == 79);
	assert(malthusian(217, 1.17) == 26);
	assert(malthusian(1840, 1.37) == 19);
	assert(malthusian(7702, 1.08) == 119);
	assert(malthusian(6217, 1.16) == 55);
	assert(malthusian(7812, 1.96) == 10);
	assert(malthusian(8381, 1.80) == 12);
	assert(malthusian(9284, 1.11) == 87);
	assert(malthusian(6068, 1.71) == 13);
	assert(malthusian(5486, 1.86) == 11);
	assert(malthusian(2197, 1.27) == 27);
	assert(malthusian(3182, 1.40) == 20);
	assert(malthusian(8196, 1.55) == 17);
	assert(malthusian(3513, 1.20) == 40);
	assert(malthusian(4152, 1.24) == 34);
	assert(malthusian(2886, 1.79) == 10);
	assert(malthusian(1646, 1.63) == 11);
	assert(malthusian(8030, 1.18) == 51);
	assert(malthusian(2514, 1.10) == 80);
	assert(malthusian(1345, 1.53) == 12);
	assert(malthusian(877, 1.96) == 6);
	assert(malthusian(2035, 1.26) == 28);
	assert(malthusian(6007, 1.52) == 17);

	return 0;
}
