/*

Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip. 
You create a playlist so that:

Every song is played at least once
A song can only be played again only if K other songs have been played

Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.

Note:

0 <= K < N <= L <= 100


*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

long
playlistsdp(int N, int L, int K)
{
	static const long mod = 1000000007l;

	long *p, r;
	ssize_t n, i, j;

	n = L - N + 1;
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;

	p = calloc(n, sizeof(*p));
	if (!p)
		return -1;

	for (i = 0; i < n; i++)
		p[i] = 1;

	for (i = 2; i <= N - K; i++) {
		for (j = 1; j <= L - N; j++) {
			p[j] += p[j - 1] * i;
			p[j] %= mod;
		}
	}

	r = p[L - N];
	for (i = 2; i <= N; i++)
		r = (r * i) % mod;

	free(p);
	return r;
}

int
main(void)
{
	printf("%ld\n", playlistsdp(3, 3, 1));
	printf("%ld\n", playlistsdp(2, 3, 0));
	printf("%ld\n", playlistsdp(2, 3, 1));
	printf("%ld\n", playlistsdp(100, 100, 100));
	return 0;
}
