/*

Print the numbers from 1 to 1000 without using any loop or conditional statements.

Don’t just write the printf() or cout statement 1000 times.

Be creative and try to find the most efficient way!

*/

#include <cstdio>

template <int N>
void gen()
{
	if (N < 1)
		return;
	gen<N-1>();
	printf("%d\n", N);
}

template <>
void gen<0>()
{
}

int main()
{
	gen<1000>();
	return 0;
}
