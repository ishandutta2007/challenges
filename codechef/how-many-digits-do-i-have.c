/*

All submissions for this problem are available.
Write a program to obtain a number (N) from the user and
display whether the number is a one digit number, 2 digit number, 3 digit number or more than 3 digit number

*/

#include <stdio.h>
#include <string.h>

const char *
digits(int n)
{
	char b[80];
	int l;

	l = snprintf(b, sizeof(b), "%d", n);
	if (b[0] == '-')
		l--;

	switch (l) {
	case 1:
		return "1";
	case 2:
		return "2";
	case 3:
		return "3";
	}
	return "More than 3 digits";
}

int
main(void)
{
	printf("%s\n", digits(9));
	printf("%s\n", digits(90));
	printf("%s\n", digits(900));
	printf("%s\n", digits(9000));
	printf("%s\n", digits(-9245));
	printf("%s\n", digits(-92));
	return 0;
}
