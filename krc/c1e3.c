// Modify the temperature conversion program to print a heading above the table.
#include <stdio.h>

int
main(void)
{
	float fahr, cel;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Fahr\tCelsius\n");
	for (fahr = lower; fahr <= upper; fahr += step) {
		cel = (5.0 / 9) * (fahr - 32.0);
		printf("%3.0f\t%3.1f\n", fahr, cel);
	}
	return 0;
}
