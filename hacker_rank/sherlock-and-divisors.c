// Watson gives an integer N to Sherlock and asks him:
// What is the number of divisors of that are divisible by 2?

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t
divisorsfs(uint64_t n)
{
	uint64_t i, c;

	c = 0;
	for (i = 2; i <= n; i++) {
		if ((n % i) == 0 && (i % 2) == 0)
			c++;
	}
	return c;
}

uint64_t
divisors(uint64_t n)
{
	uint64_t i, c;

	if (n % 2 != 0)
		return 0;

	// i <= n/i is another way to represent i <= sqrt(n)
	// check if n is divislbe by i, if it isn't continue
	// if it is, we add 2 because they are factor pair of 2
	// (we got rid of one factor of 2 initially by dividing by 2)
	c = 0;
	n /= 2;
	for (i = 1; i <= n / i; i++) {
		if (n % i != 0)
			continue;
		if (i != n / i)
			c += 2;
		else
			c++;
	}
	return c;
}

int
main(void)
{
	uint64_t i;
	for (i = 0; i < 1024; i++)
		printf("%" PRIu64 " %" PRIu64 " %" PRIu64 "\n", i, divisorsfs(i), divisors(i));
	return 0;
}
