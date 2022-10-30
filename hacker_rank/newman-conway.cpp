#include <cstdio>
#include <cstdlib>
#include <map>

std::map<int, int> cache;

int newman_conway(int n)
{
	if (n <= 2)
		return 1;

	auto it = cache.find(n);
	if (it != cache.end())
		return it->second;

	auto P = newman_conway;
	cache[n] = P(P(n - 1)) + P(n - P(n - 1));
	return cache[n];
}

int main(int argc, char *argv[])
{
	auto N = 32;
	if (argc >= 2)
		N = atoi(argv[1]);
	int i;
	for (i = 1; i < N; i++)
	{
		printf("%d ", newman_conway(i));
		if (i + 1 < N && (i & 31) == 31)
			printf("\n");
	}
	if ((i & 31) != 31)
		printf("\n");
	return 0;
}
