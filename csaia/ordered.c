/*

Boolean and integer variables and Conditionals. Write a program Ordered.java that reads in three integer command-line arguments, x, y, and z.
Define a boolean variable isOrdered whose value is true if the three values are either in strictly ascending order (x < y < z)
or in strictly descending order (x > y > z), and false otherwise. Print out the variable isOrdered using System.out.println(isOrdered).

        % java Ordered 10 17 49
        true

        % java Ordered 49 17 10
        true

        % java Ordered 10 49 17
        false

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void
usage(void)
{
	fprintf(stderr, "usage: x y z\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	int x, y, z;
	bool ord;

	if (argc != 4)
		usage();

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	z = atoi(argv[3]);

	ord = false;
	if (x < y && y < z)
		ord = true;
	if (x > y && y > z)
		ord = true;

	printf("%s\n", (ord) ? "true" : "false");

	return 0;
}
