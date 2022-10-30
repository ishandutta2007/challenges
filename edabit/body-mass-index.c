/*

Body Mass Index (BMI) is found by taking your weight in kilograms and dividing by the square of your height in meters. The BMI categories are:

Underweight: <18.5
Normal weight: 18.5–24.9
Overweight: 25–29.9
Obesity: BMI of 30 or greater

Create a function that will accept weight and height (in kilos, pounds, meters, or inches) and return the BMI and the associated category. Round the BMI to nearest tenth.

Notes

1 inch = .0254 meter
1 pound = 0.453592 kilo

*/

#include <stdio.h>
#include <string.h>

char *
bmi(char *b, size_t n, const char *w, const char *h)
{
	char s1[32], s2[32];
	double k, m, r;

	if (sscanf(w, "%lf %31s", &k, s1) != 2)
		return NULL;
	if (sscanf(h, "%lf %31s", &m, s2) != 2)
		return NULL;

	if (strstr(s1, "pound"))
		k *= 0.453592;
	else if (!strstr(s1, "kilo"))
		return NULL;

	if (strstr(s2, "inch"))
		m *= 0.0254;
	else if (!strstr(s2, "meter"))
		return NULL;

	r = k / (m * m);
	if (r < 18.5)
		snprintf(b, n, "%.1f Underweight", r);
	else if (18.5 <= r && r < 25)
		snprintf(b, n, "%.1f Normal weight", r);
	else if (25 <= r && r < 30)
		snprintf(b, n, "%.1f Overweight", r);
	else
		snprintf(b, n, "%.1f Obesity", r);

	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", bmi(b, sizeof(b), "205 pounds", "73 inches"));
	printf("%s\n", bmi(b, sizeof(b), "55 kilos", "1.65 meters"));
	printf("%s\n", bmi(b, sizeof(b), "154 pounds", "2 meters"));
	printf("%s\n", bmi(b, sizeof(b), "53.3 kilos", "1.7 meters"));
	printf("%s\n", bmi(b, sizeof(b), "76.8 kilos", "1.6 meters"));
	printf("%s\n", bmi(b, sizeof(b), "53.5 kilos", "1.7 meters"));
	printf("%s\n", bmi(b, sizeof(b), "155 pounds", "73 inches"));
	printf("%s\n", bmi(b, sizeof(b), "175 pounds", "70 inches"));
	return 0;
}
