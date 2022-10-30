/*

Challenge: You Are The Teacher

Everyone knows that simple task of receiving a grade, and telling if the student:

        is approved,
        will attend the summer school, or
        failed.

In this challenge, you must write a program that does that, but using the maximum of one if statement (also ternary operators count as if).

The grade will be an integer from 0 to 10.

situation   outputs
-------------------------
grade >= 7: Approved
grade >= 3: Summer School
grade  < 3: Failed

You can do whatever you want, write in any language.

Fastest working answer wins.

*/

#include <stdio.h>

const char *
grade(int g)
{
	static const char *tab[] = {
	    "Approved",
	    "Summer School",
	    "Failed",
	};
	return tab[(g < 7) + (g < 3)];
}

int
main(void)
{
	int i;

	for (i = 0; i <= 20; i++)
		printf("%d %s\n", i, grade(i));

	return 0;
}
