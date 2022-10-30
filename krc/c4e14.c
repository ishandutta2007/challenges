// Define a macro swap(t, x, y) that interchanges two arguments of type t.
// Block structure will help.

#include <stdio.h>

#define swap(t, x, y)  \
	{              \
		t z;   \
		z = y; \
		y = x; \
		x = z; \
	}

int
main(void)
{
	const char *s, *t;
	double x, y;
	int a, b;

	a = 30;
	b = 40;
	swap(int, a, b);
	printf("%d %d\n", a, b);

	s = "qwertyuiop";
	t = "asdfghjkl;";
	swap(const char *, s, t);
	printf("%s %s\n", s, t);

	x = 1.68;
	y = x / 2;
	swap(double, x, y);
	printf("%f %f\n", x, y);

	return 0;
}
