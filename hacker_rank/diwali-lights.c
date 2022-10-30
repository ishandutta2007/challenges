/*

On the eve of Diwali, Hari is decorating his house with a serial light bulb set.
The serial light bulb set has N bulbs placed sequentially on a string which is programmed to change patterns every second.
If at least one bulb in the set is on at any given instant of time, how many different patterns of light can the serial light bulb set produce?

Note: Lighting two bulbs *-* is different from **-

*/

#include <gmp.h>

void
lights(mpz_t x, mpz_t n)
{
	mpz_t b, m;

	mpz_init_set_si(b, 2);
	mpz_init_set_si(m, 100000);
	mpz_powm(x, b, n, m);
	mpz_sub_ui(x, x, 1);
	mpz_clear(b);
	mpz_clear(m);
}

int
main(void)
{
	mpz_t x, n;

	mpz_init(x);
	mpz_init(n);

	mpz_set_si(n, 1);
	lights(x, n);
	gmp_printf("%Zd\n", x);

	mpz_set_si(n, 2);
	lights(x, n);
	gmp_printf("%Zd\n", x);

	mpz_clear(x);
	mpz_clear(n);

	return 0;
}
