/*

Good Evening Golfers,

Your challenge, this evening, is logarithmic, and (as Abed would put it) "Meta"

Your goal is to write a program that takes an input from stdin or the command line, and returns the logarithm of that number, in the base of the length of your program in bytes.

So, if your program is 10 bytes, it must return the Log10 of the input number.

Rules:

Program must be longer then 1 character
Program must be able to accept floating point input in a form of your choice, or scientific format in a form of your choice with a minimum accuracy of 6 digits
Program must output to a minimum of 6 digits of accuracy in decimal or scientific format
Program must be entirely self contained, and must not access any files or network resources.
Your score in the natural logarithm of the amount of bytes in your source code.

Good luck.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char *argv[])
{
	double b, x;
	int i;

	b = 1072;
	for (i = 1; i < argc; i++) {
		x = atof(argv[i]);
		printf("%f\n", log(x) / log(b));
	}
	return 0;
}
