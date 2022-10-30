/*
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int
main(void)
{
	printf("signed char min: %d\n", SCHAR_MIN);
	printf("signed char max: %d\n", SCHAR_MAX);
	printf("signed short min: %d\n", SHRT_MIN);
	printf("signed short max: %d\n", SHRT_MAX);
	printf("signed int min: %d\n", INT_MIN);
	printf("signed int max: %d\n", INT_MAX);
	printf("signed long min: %ld\n", LONG_MIN);
	printf("signed long max: %ld\n", LONG_MAX);
	printf("signed long long min: %lld\n", LLONG_MIN);
	printf("signed long long max: %lld\n", LLONG_MAX);

	printf("unsigned char max: %u\n", UCHAR_MAX);
	printf("unsigned short max: %u\n", SHRT_MAX);
	printf("unsigned int max: %u\n", INT_MAX);
	printf("unsigned long max: %lu\n", LONG_MAX);
	printf("unsigned long long max: %llu\n", LLONG_MAX);

	printf("float min: %f\n", FLT_MIN);
	printf("float max: %f\n", FLT_MAX);
	printf("double min: %f\n", DBL_MIN);
	printf("double max: %f\n", DBL_MAX);

	return 0;
}
