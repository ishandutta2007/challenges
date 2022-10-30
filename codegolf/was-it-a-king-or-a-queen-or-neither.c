/*

Input
A calendar year from 927 to 2022.

Output
You can use any three distinguishable outputs. As an example,

“K” (short for King)

or

“Q” (short for Queen)

depending on which of the two England had in that year. If there was both a King and Queen in that year you can output either.

If there was no King or Queen for the whole of that year, your code must output something that is not one of those two messages.

Dates
Kings: 927-1553, 1603-1649, 1660-1702, 1714-1837, 1901-1952, 2022

Queens: 1553-1603, 1689-1694, 1702-1714, 1837-1901, 1952-2022

Neither: 1650-1659

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
inrange(const int a[][2], size_t n, int v)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (a[i][0] <= v && v <= a[i][1])
			return 1;
	}
	return 0;
}

int
identify(int y)
{
	static const int king[][2] = {
	    {927, 1553},
	    {1603, 1649},
	    {1660, 1702},
	    {1714, 1837},
	    {1901, 1952},
	    {2022, 2022},
	};
	static const int queen[][2] = {
	    {1553, 1603},
	    {1689, 1694},
	    {1702, 1714},
	    {1837, 1901},
	    {1952, 2022},
	};

	if (inrange(king, nelem(king), y))
		return 'K';
	if (inrange(queen, nelem(queen), y))
		return 'Q';
	return 'N';
}

int
main(void)
{
	assert(identify(927) == 'K');
	assert(identify(2022) == 'K');
	assert(identify(1659) == 'N');

	return 0;
}
