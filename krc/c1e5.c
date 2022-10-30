// Modify the temperature conversion program to print the table in reverse
// order, that is, from 300 degrees to 0.

#include <stdio.h>

void
temps(int lower, int upper, int step)
{
	float fahr, celsius;

	printf("Celsius | Fahrenheit\n");
	printf("--------|-----------\n");
	for (fahr = upper; fahr >= lower; fahr -= step) {
		celsius = (5.0f / 9.0f) * (fahr - 32);
		printf(" %3.0f    |   %6.1f\n", celsius, fahr);
	}
}

int
main(void)
{
	temps(0, 300, 20);
	return 0;
}
