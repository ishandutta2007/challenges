/*

Your challenge (if you choose to accept it) is to implement big integer multiplication in the shortest code possible.

Rules:

Take two integers (decimal form) as ASCII strings from the command line parameters of your program. If your language doesn't support command line parameters, I'll accept stdin or similar input mechanisms.
Output should be in ASCII decimal form, via a standard output mechanism (e.g. stdout)
Must support both positive and negative integers, as well as zero.
Must support any length integer integers up to 2**63 characters long, or at least the maximum you can store in memory.
You may not use any in-built classes or functionality that handles big integers.
The largest data type you may use is a 64-bit unsigned integer.
You may not use floating point operations.
You do not have to implement checks for valid inputs.
Example:

> multiply.exe 1234567890 987654321
1219326311126352690
Enjoy :)

*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void
usage(void)
{
	fprintf(stderr, "usage: <number> ...\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	mpz_t r, v;
	int i;

	if (argc < 2)
		usage();

	mpz_init(r);
	mpz_init(v);
	mpz_set_str(r, argv[1], 0);
	for (i = 2; i < argc; i++) {
		mpz_set_str(v, argv[i], 0);
		mpz_mul(r, r, v);
	}

	gmp_printf("%Zd\n", r);

	mpz_clear(r);
	mpz_clear(v);
	return 0;
}
