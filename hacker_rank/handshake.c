/*

At the annual meeting of Board of Directors of Acme Inc, every one starts shaking hands with everyone else in the room.
Given the fact that any two persons shake hand exactly once, Can you tell the total count of handshakes?

*/
#include <stdio.h>

int
handshake_slow(int n)
{
	int i, j, s;

	s = 0;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			s++;
	return s;
}

int
handshake(int n)
{
	if (n < 0)
		return 0;

	return (n * n - n) / 2;
}

int
main(void)
{
	int i;
	for (i = 0; i <= 100; i++)
		printf("%d %d %d\n", i, handshake_slow(i), handshake(i));
	return 0;
}
