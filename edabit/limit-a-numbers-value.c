#include <assert.h>

double
limitnumber(double x, double a, double b)
{
	if (x < a)
		x = a;
	if (x > b)
		x = b;
	return x;
}

int
main(void)
{
	assert(limitnumber(5, 1, 10) == 5);
	assert(limitnumber(-3, 1, 10) == 1);
	assert(limitnumber(14, 1, 10) == 10);
	assert(limitnumber(4.6, 1, 10) == 4.6);
	assert(limitnumber(-100, -73, -70) == -73);
	assert(limitnumber(2, -73, -70) == -70);
	assert(limitnumber(-71.5, -73, -70) == -71.5);
	assert(limitnumber(7, 8, 8.1) == 8);
	assert(limitnumber(9, 8, 8.1) == 8.1);
	assert(limitnumber(8.05, 8, 8.1) == 8.05);
	assert(limitnumber(16, 16, 16) == 16);
	assert(limitnumber(-1, 16, 16) == 16);
	assert(limitnumber(800, 16, 16) == 16);
	return 0;
}
