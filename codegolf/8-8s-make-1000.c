/*

Print the following output of a happy coincidence addition pattern:

   8
   8
   8
  88
+888
----
1000
Rules:

No leading spaces except the ones already present
There can be a trailing newline
+ sign needs to be displayed
Order of parcels needs to be the same
No winner. It is code-golf per language.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
display(void)
{
	static const int vals[] = {8, 8, 8, 88, 888};
	static const int pad = 4;

	size_t n;
	int i, r;

	r = 0;
	for (n = 0; n < nelem(vals); n++) {
		if (n + 1 >= nelem(vals))
			printf("%+*d\n", pad, vals[n]);
		else
			printf("%*d\n", pad, vals[n]);
		r += vals[n];
	}

	for (i = 0; i <= pad; i++)
		printf("-");
	printf("\n");

	printf("%*d\n\n", pad, r);
}

int
main(void)
{
	display();
	return 0;
}
