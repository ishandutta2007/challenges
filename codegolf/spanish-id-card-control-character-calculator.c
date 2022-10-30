/*

This is a very very simple algorithm, that I am sure can be solved in many many different languages. In Spain ID cards (known as DNI) consist of 8 numbers and a control character.
The control character is calculated with the following algorithm: divide the number by 23, take the remainder of the operation and replace it with a character according to this table:

0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22
T  R  W  A  G  M  Y  F  P  D  X  B  N  J  Z  S  Q  V  H  L  C  K  E
If the DNI belongs to a foreign person living in Spain, the first digit is changed to X, Y or Z and it is called an NIE. In this case, the following substitutions are made before calculating the control character:

X Y Z
0 1 2
There are a lot of calculators online that help you get the control character, but, how short can you write that code?
Write an algorithm (program or function) that receives a string with the DNI number (that will always consist of 8 alphanumeric characters) and returns just the single control character calculated and nothing more (a trailing newline is accepted).

Notes:

The DNI is always written in uppercase, but in your algorithm you can choose the input and output to be upper- or lowercase, just be consistent.
In real life, some NIEs issued before 2008 have 8 digits after the X, Y or Z, but for the purposes of this game, you can consider they have 7 digits as they have nowadays.
You can consider that the input string will always have 8 characters, but if they are not in the "8 digits" format nor the "[XYZ] plus 7 digits" format, you must return an error (of your choice) or just throw an exception.
Test cases:
00000010 -> X (HRM Juan Carlos I's DNI number)
01234567 -> L
98765432 -> M
69696969 -> T
42424242 -> Y
Z5555555 -> W (Z=2)
Y0000369 -> S (Y=1)
A1234567 -> <Error code or exception>
1231XX12 -> <Error code or exception>
This is code-golf, so may the shortest code for each language win!

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long vlong;

vlong
code(const char *s)
{
	static const char *nie = "XYZ";

	const char *p;
	char b[16];
	int i, n;

	n = snprintf(b, sizeof(b), "%s", s);
	if (n != 8)
		return -1;

	p = strchr(nie, b[0]);
	if (p)
		b[0] = '0' + (p - nie);

	for (i = 0; b[i]; i++) {
		if (!isdigit(b[i]))
			return -1;
	}

	return strtoll(b, NULL, 10);
}

int
control(const char *s)
{
	static const char map[] = "TRWAGMYFPDXBNJZSQVHLCKE";

	vlong c;

	c = code(s);
	if (c < 0)
		return -1;
	return map[c % (sizeof(map) - 1)];
}

int
main(void)
{
	assert(control("00000010") == 'X');
	assert(control("01234567") == 'L');
	assert(control("98765432") == 'M');
	assert(control("69696969") == 'T');
	assert(control("42424242") == 'Y');
	assert(control("Z5555555") == 'W');
	assert(control("Y0000369") == 'S');
	assert(control("A1234567") == -1);
	assert(control("1231XX12") == -1);

	return 0;
}
