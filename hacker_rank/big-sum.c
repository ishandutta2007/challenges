#include <gmp.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
sum(mpz_t x, mpz_t *a, size_t n)
{
	size_t i;

	mpz_set_d(x, 0);
	for (i = 0; i < n; i++)
		mpz_add(x, x, a[i]);
}

int
main(void)
{
	mpz_t a[5], r;
	size_t i;

	mpz_init(r);
	mpz_init_set_str(a[0], "1000000001", 10);
	mpz_init_set_str(a[1], "1000000002", 10);
	mpz_init_set_str(a[2], "1000000003", 10);
	mpz_init_set_str(a[3], "1000000004", 10);
	mpz_init_set_str(a[4], "1000000005", 10);
	sum(r, a, nelem(a));
	gmp_printf("sum is %Zd\n", r);

	for (i = 0; i < nelem(a); i++)
		mpz_clear(a[i]);
	mpz_clear(r);

	return 0;
}
