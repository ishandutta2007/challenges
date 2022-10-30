// Write a program to print the corresponding Celsius to Fahrenheit table

#include <stdio.h>

void
temps(int lower, int upper, int step)
{
	float fahr, celsius;

	printf("Celsius | Fahrenheit\n");
	printf("--------|-----------\n");
	for (celsius = lower; celsius <= upper; celsius += step) {
		fahr = (9.0f / 5.0f * celsius) + 32.0f;
		printf(" %3.0f    |   %6.1f\n", celsius, fahr);
	}
}

int
main(void)
{
	temps(-30, 100, 10);
	return 0;
}
