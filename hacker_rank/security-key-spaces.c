/*

K denotes a set called the key space. Any element of K is called a key.

Each element e in K uniquely determines a bijection from M to C denoted by E_e.
The E_e is called an encryption function.
Similarly for each d in K, we have a bijection from C to M, denoted by D_d,
and is called a decryption function

For example, consider the same shifting function that we dealt with in the previous challenge.
Now, suppose the amount of shifting we do is some e.
In the last challenge, e=1. Then e is a valid key representing the bijective function
f(x, e) = shift_x_by_e


For this task, consider a message that consists of decimal digits and a key, e,
which operates by shifting each digit by e places. Find the corresponding ciphertext.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
shift(const char *m, int e)
{
	const char A[] = "0123456789";
	size_t i;
	int n;

	for (i = 0; m[i]; i++) {
		if ('0' <= m[i] && m[i] <= '9')
			putchar(A[(m[i] - '0' + e) % (nelem(A) - 1)]);
		else
			putchar(m[i]);
	}
	printf("\n");
}

int
main(void)
{
	shift("982", 1);
	shift("391", 2);
	return 0;
}
