/*

Create a program that converts a phone number with letters to one with only numbers.
Number	Letter
0	none
1	none
2	ABC
3	DEF
4	GHI
5	JKL
6	MNO
7	PQRS
8	TUV
9	WXYZ

Notes

    All inputs will be formatted as a string representing a proper phone number in the format XXX-XXX-XXXX or (XXX)XXX-XXXX, using numbers and capital letters.
    Check the Resources tab for more info on telephone keypads.

*/

#include <stdio.h>

char *
texttonum(char *s)
{
	size_t i;
	char c;

	for (i = 0; (c = s[i]); i++) {
		if ('A' <= c && c <= 'C')
			s[i] = '2';
		else if ('D' <= c && c <= 'F')
			s[i] = '3';
		else if ('G' <= c && c <= 'I')
			s[i] = '4';
		else if ('J' <= c && c <= 'L')
			s[i] = '5';
		else if ('M' <= c && c <= 'O')
			s[i] = '6';
		else if ('P' <= c && c <= 'S')
			s[i] = '7';
		else if ('T' <= c && c <= 'V')
			s[i] = '8';
		else if ('W' <= c && c <= 'Z')
			s[i] = '9';
	}
	return s;
}

int
main(void)
{
	char s1[] = "123-647-EYES";
	char s2[] = "(325)444-TEST";
	char s3[] = "653-TRY-THIS";
	char s4[] = "435-224-7613";
	char s5[] = "(33D)ONT-FAIL";
	char s6[] = "(025)445-6741";

	printf("%s\n", texttonum(s1));
	printf("%s\n", texttonum(s2));
	printf("%s\n", texttonum(s3));
	printf("%s\n", texttonum(s4));
	printf("%s\n", texttonum(s5));
	printf("%s\n", texttonum(s6));

	return 0;
}
