/*

This exercise demonstrates the use of the String data type and command-line arguments.
Write a program HiFour.java that takes four first names as command-line arguments and prints a proper sentence with the names in the reverse of the order given.  

Examples:

> java-introcs HiFour Alice Bob Carol Dave
Hi Dave, Carol, Bob, and Alice.

> java-introcs HiFour Alejandro Bahati Chandra Deshi
Hi Deshi, Chandra, Bahati, and Alejandro.

*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	if (argc != 5) {
		fprintf(stderr, "usage: name1 name2 name3 name4\n");
		return 1;
	}

	printf("Hi %s, %s, %s, and %s.\n", argv[4], argv[3], argv[2], argv[1]);
	return 0;
}
