/*

Given an input integer, output the volume corresponding to the value. The value will always be in the range [0,100].

*/

#include <stdio.h>
#include <stdlib.h>

const char *
volume(int x)
{
	static const char *art[] = {
	    " _/|\n"
	    "|  |\\/\n"
	    "|_ |/\\\n"
	    "  \\|\n",

	    " _/|\n"
	    "|  |\\\n"
	    "|_ |/\n"
	    "  \\|\n",

	    " _/| \\\n"
	    "|  |\\ \\\n"
	    "|_ |/ /\n"
	    "  \\| /\n",

	    " _/| \\ \\\n"
	    "|  |\\ \\ \\\n"
	    "|_ |/ / /\n"
	    "  \\| / /\n",

	};

	if (x <= 0)
		return art[0];
	else if (x < 33)
		return art[1];
	else if (x < 66)
		return art[2];
	return art[3];
}

int
main(void)
{
	int i;

	for (i = 0; i <= 100; i++)
		printf("%d\n%s\n", i, volume(i));
	return 0;
}
