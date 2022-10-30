/*

Complete the extraLongFactorials function in the editor below. It should print the result and return.

extraLongFactorials has the following parameter(s):

n: an integer
Note: Factorials of  can't be stored even in a  long long variable. Big integers must be used for such calculations.
Languages like Java, Python, Ruby etc. can handle big integers, but we need to write additional code in C/C++ to handle huge values.

We recommend solving this challenge using BigIntegers.

*/

#include <gmp.h>

void
fact(mpz_t x, mpz_t n)
{
	mpz_t i;

	mpz_set_d(x, 1);
	if (mpz_cmp_si(n, 1) <= 0)
		return;

	mpz_init_set_si(i, 2);
	while (mpz_cmp(i, n) <= 0) {
		mpz_mul(x, x, i);
		mpz_add_ui(i, i, 1);
	}
	gmp_printf("%Zd: %Zd\n", n, x);
}

int
main(void)
{
	mpz_t x, n;

	mpz_init(x);

	mpz_init_set_ui(n, 30);
	fact(x, n);

	mpz_set_ui(n, 25);
	fact(x, n);

	mpz_set_ui(n, 1000);
	fact(x, n);

	mpz_set_ui(n, 1 << 16);
	fact(x, n);

	mpz_clear(x);
	mpz_clear(n);

	return 0;
}
