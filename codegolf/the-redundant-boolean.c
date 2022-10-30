/*

Introduction
Classically, booleans are one bit; true or false, 1 or 0. Leading zeros would just be redundant. For example, 001 means the same as 00001 or just 1.

The 32-bit boolean
Given a truthy/falsey value, output the equivalent 32-bit boolean as a string. (Or as a number if for some reason your language supports leading zeros.)

Your program doesn't have to work for every truthy/falsy type, only what your programming language work best for.

Example i/o
Input >> Output

truthy >> 00000000000000000000000000000001
falsey >> 00000000000000000000000000000000

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char *
boolean(bool b, char *s)
{
	sprintf(s, "%032d", b);
	return s;
}

int
main(void)
{
	char s[64];

	assert(!strcmp(boolean(true, s), "00000000000000000000000000000001"));
	assert(!strcmp(boolean(false, s), "00000000000000000000000000000000"));

	return 0;
}
