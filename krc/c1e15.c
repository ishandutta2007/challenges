// Rewrite the temperature conversion program of Section 1.2 to use a function
// for conversion.

#include <stdio.h>

float
celsius(float fahr)
{
	return 5.0f / 9.0f * (fahr - 32.0f);
}

int
main(void)
{
	int lower, upper, step;
	float fahr;

	lower = 0;
	upper = 300;
	step = 20;

	printf("fahr celsius\n");
	fahr = lower;
	while (fahr <= upper) {
		printf("%4.0f %7.1f\n", fahr, celsius(fahr));
		fahr += step;
	}
	return 0;
}
