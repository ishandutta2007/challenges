/*

In semantic versioning a piece of software can be represented in a format like this example: 6.1.9.

    The first number is the major version.
    The second number is the minor version.
    The third number is the patch (bug fixes).

Write three separate functions, one to retrieve each element in the semantic versioning specification.

*/

#include <cstdio>

template <size_t N>
int revision(const char *s)
{
	unsigned r[3];

	if (sscanf(s, "%u.%u.%u", &r[0], &r[1], &r[2]) != 3)
		return -1;

	return r[N];
}

auto major = &revision<0>;
auto minor = &revision<1>;
auto patch = &revision<2>;

int main(void)
{
	printf("%d\n", major("6.1.9"));
	printf("%d\n", minor("6.1.9"));
	printf("%d\n", patch("6.1.9"));
	printf("%d\n", major("2.1.0"));
	printf("%d\n", minor("2.1.0"));
	printf("%d\n", patch("2.1.0"));
	printf("%d\n", major("5.12.13"));
	printf("%d\n", minor("5.12.13"));
	printf("%d\n", patch("5.12.13"));
	return 0;
}
