/*

Write a function that returns 0 if the input is 1, and returns 1 if the input is 0.

Notes

Try completing this challenge without using any:

    Conditionals
    Ternary operators
    Negations
    Bit operators

*/

#include <stdio.h>

int
flip(int n)
{
	static const int tab[] = {1, 0};
	return tab[n];
}

int
main(void)
{
	printf("%d\n", flip(1));
	printf("%d\n", flip(0));
	return 0;
}
