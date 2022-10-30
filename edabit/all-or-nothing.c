/*

Suppose a student can earn 100% on an exam by getting the answers all correct or all incorrect.
Given a potentially incomplete answer key and the student's answers,
write a function that determines whether or not a student can still score 100%.
Questions with missing answers are marked with an underscore, "_".

Notes

Test has at least one question.

*/

#include <stdio.h>

int
possiblyperfect(const char *k, const char *s)
{
	size_t i, x, y, z;

	x = y = z = 0;
	for (i = 0; k[i] && s[i]; i++) {
		if (k[i] == '_')
			z++;
		else if (k[i] == s[i])
			x++;
		else
			y++;
	}

	if (k[i] != '\0' || s[i] != '\0')
		return -1;

	return x + z == i || y + z == i;
}

int
main(void)
{
	printf("%d\n", possiblyperfect("A_C_B", "ADCEB"));
	printf("%d\n", possiblyperfect("B_B", "BCD"));
	printf("%d\n", possiblyperfect("T_FFF", "FFTTT"));
	printf("%d\n", possiblyperfect("BA__", "BACC"));
	printf("%d\n", possiblyperfect("ABA_", "BACC"));
	printf("%d\n", possiblyperfect("ABC_", "BACC"));
	printf("%d\n", possiblyperfect("B_", "CA"));
	printf("%d\n", possiblyperfect("BA", "CA"));
	printf("%d\n", possiblyperfect("B", "B"));
	printf("%d\n", possiblyperfect("_T__", "TFFF"));
	printf("%d\n", possiblyperfect("_T__", "TTFT"));
	printf("%d\n", possiblyperfect("_TTT", "TTFT"));
	printf("%d\n", possiblyperfect("_TTT", "TTTT"));

	return 0;
}
